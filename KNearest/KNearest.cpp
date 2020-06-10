
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <sstream>
#include <iostream>

#include "GeoCoords.h"
#include "BoundRectangle.h"
#include "PointOfInterest.h"
#include "DistPredicate.h"
#include "PointsMinHeap.h"
#include "QuadTree.h"
#include "Random.h"
#include "Generator.h"
#include "PointGenerator.h"

struct POIPredicate
{
	const GeoCoords center;

	explicit POIPredicate(const GeoCoords& center)
		: center(center) {}

	bool operator() (const PointOfInterest& p1, const PointOfInterest& p2) const
	{
		return (p1.Coordinates - center).LengthSquare() < (p2.Coordinates - center).LengthSquare();
	}
};

void FindInRangeSlow(const std::vector<PointOfInterest>& pois, std::vector<PointOfInterest>& results, const GeoCoords& center, const double R, const size_t M)
{
	std::vector<PointOfInterest> r;
	const double R2 = R * R;
	for (const auto& p : pois)
	{
		if ((p.Coordinates - center).LengthSquare() <= R2)
			r.push_back(p);
	}

	std::sort(std::begin(r), std::end(r), POIPredicate(center));
}

int main()
{
	const size_t N = 10000;
	GeoCoords center = GeoCoords(0, 0);
	const size_t M = 100;
	BoundRectangle brec(GeoCoords(0, 0), GeoCoords(5, 5));
	const double R = 2;

	Random rnd;
	std::vector<PointOfInterest> pois;
	std::generate_n(std::back_inserter(pois), N, PointGenerator(rnd, brec));

	//std::copy(std::begin(pois), std::end(pois), std::ostream_iterator<PointOfInterest>(std::cout, "\n"));
	//std::cout << std::endl;

	QuadTree tree(5, brec);

	for (const auto& poi : pois)
		tree.Insert(poi);

	std::cout << "Total: " << tree.Count() << std::endl;

	PointsMinHeap pois2(M, center);
	tree.FindInRange(pois2, center, R);

	return 0;
}

