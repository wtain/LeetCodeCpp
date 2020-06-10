#pragma once

#include <vector>

#include "DistPredicate.h"

class PointsMinHeap
{
	std::vector<PointOfInterest> m_points;
	DistPredicate m_predicate;
	const size_t m_capacity;
public:

	PointsMinHeap(const size_t capacity, GeoCoords center)
		: m_predicate(center)
		, m_capacity(capacity)
	{
		m_points.reserve(capacity);
	}

	void Add(const PointOfInterest& p)
	{
		m_points.push_back(p);
		std::push_heap(std::begin(m_points), std::end(m_points), m_predicate);
		if (m_points.size() > m_capacity)
			m_points.pop_back();
	}

	void Clear()
	{
		m_points.clear();
	}
};