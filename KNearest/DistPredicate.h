#pragma once

#include "GeoCoords.h"
#include "PointOfInterest.h"

struct DistPredicate
{
	GeoCoords m_center;

	explicit DistPredicate(const GeoCoords& center)
		: m_center(center)
	{

	}

	bool operator() (const PointOfInterest& left, const PointOfInterest& right) const
	{
		return (left.Coordinates - m_center).LengthSquare() > (right.Coordinates - m_center).LengthSquare();
	}
};
