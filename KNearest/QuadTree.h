#pragma once

#include <vector>
#include <memory>

#include "GeoCoords.h"
#include "BoundRectangle.h"
#include "PointOfInterest.h"
#include "PointsMinHeap.h"

class QuadTree
{
	std::vector<PointOfInterest> m_data;

	BoundRectangle m_bbox;

	std::unique_ptr<QuadTree> m_pTopLeft;
	std::unique_ptr<QuadTree> m_pTopRight;
	std::unique_ptr<QuadTree> m_pBottomLeft;
	std::unique_ptr<QuadTree> m_pBottomRight;

public:

	QuadTree(const size_t nCapacity, BoundRectangle bbox)
		: m_bbox(bbox)
	{
		m_data.reserve(nCapacity);
	}

	bool AtCapacity() const
	{
		return m_data.size() == m_data.capacity();
	}

	bool Insert(const PointOfInterest& point)
	{
		if (!m_bbox.Contains(point.Coordinates))
			return false;

		if (!AtCapacity())
		{
			m_data.push_back(point);
			return true;
		}

		if (!m_pBottomLeft)
			subdivide();

		if (m_pBottomLeft->Insert(point))
			return true;

		if (m_pBottomRight->Insert(point))
			return true;

		if (m_pTopLeft->Insert(point))
			return true;

		if (m_pTopRight->Insert(point))
			return true;

		return false;
	}

	size_t Count() const
	{
		size_t count = m_data.size();
		if (m_pBottomLeft)
			count += m_pBottomLeft->Count();
		if (m_pTopLeft)
			count += m_pTopLeft->Count();
		if (m_pBottomRight)
			count += m_pBottomRight->Count();
		if (m_pTopRight)
			count += m_pTopRight->Count();
		return count;
	}

	void FindInRange(PointsMinHeap& pts, const GeoCoords& center, const double radius) const
	{
		pts.Clear();

		FindInRangeImpl(pts, center, radius);
	}

private:

	void FindInRangeImpl(PointsMinHeap& pts, const GeoCoords& center, const double radius) const
	{
		if (!m_bbox.IntersectsWith(center, radius))
			return;

		const double r2 = radius * radius;

		for (const auto& p : m_data)
			if ((p.Coordinates - center).LengthSquare() <= r2)
				pts.Add(p);

		if (m_pBottomLeft)
			m_pBottomLeft->FindInRangeImpl(pts, center, radius);

		if (m_pBottomRight)
			m_pBottomRight->FindInRangeImpl(pts, center, radius);

		if (m_pBottomLeft)
			m_pBottomLeft->FindInRangeImpl(pts, center, radius);

		if (m_pTopLeft)
			m_pTopLeft->FindInRangeImpl(pts, center, radius);

		if (m_pTopRight)
			m_pTopRight->FindInRangeImpl(pts, center, radius);
	}

	void subdivide()
	{
		GeoCoords quarterDimension = m_bbox.HalfDimension / 2;
		BoundRectangle leftTop = BoundRectangle(m_bbox.Center - quarterDimension, quarterDimension);
		BoundRectangle rightBottom = BoundRectangle(m_bbox.Center + quarterDimension, quarterDimension);
		GeoCoords quarterDimension2 = quarterDimension;
		quarterDimension2.Latitude = -quarterDimension2.Latitude;
		BoundRectangle leftBottom = BoundRectangle(m_bbox.Center - quarterDimension2, quarterDimension);
		BoundRectangle rightTop = BoundRectangle(m_bbox.Center + quarterDimension2, quarterDimension);

		m_pTopLeft = std::make_unique<QuadTree>(m_data.capacity(), leftTop);
		m_pBottomLeft = std::make_unique<QuadTree>(m_data.capacity(), leftBottom);
		m_pTopRight = std::make_unique<QuadTree>(m_data.capacity(), rightTop);
		m_pBottomRight = std::make_unique<QuadTree>(m_data.capacity(), rightBottom);
	}
};