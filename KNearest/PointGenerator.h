#pragma once

#include <sstream>

#include "Random.h"
#include "GeoCoords.h"
#include "BoundRectangle.h"

class PointGenerator
{
	Random random;
	mutable int n;
	BoundRectangle brec;

public:
	explicit PointGenerator(const Random& random, const BoundRectangle& brec)
		: random(random)
		, brec(brec)
		, n(0)
	{

	}

	PointOfInterest operator() () const
	{
		std::ostringstream stream;
		stream << "Point " << ++n;
		double lat = brec.HalfDimension.Latitude * 2.0 * (random.Generate() - 0.5);
		double lon = brec.HalfDimension.Longitude * 2.0 * (random.Generate() - 0.5);
		GeoCoords point = brec.Center + GeoCoords(lat, lon);
		return PointOfInterest(point, stream.str());
	}
};
