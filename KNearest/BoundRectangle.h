#pragma once

#include "GeoCoords.h"

struct BoundRectangle
{
	GeoCoords Center;
	GeoCoords HalfDimension;

	BoundRectangle() {}

	BoundRectangle(const GeoCoords& center, const GeoCoords& halfDimension)
		: Center(center), HalfDimension(halfDimension) {}

	bool Contains(const GeoCoords& coords) const
	{
		return Center - HalfDimension <= coords &&
			coords < Center + HalfDimension;
	}

	bool IntersectsWith(const BoundRectangle& other) const
	{
		GeoCoords area = GeoCoords(std::max(HalfDimension.Latitude, other.HalfDimension.Latitude),
			std::max(HalfDimension.Longitude, other.HalfDimension.Longitude));
		return Center.DistanceAbsolute(other.Center) < area;
	}

	GeoCoords TopLeft() const
	{
		return Center - HalfDimension;
	}

	GeoCoords BottomRight() const
	{
		return Center + HalfDimension;
	}

	GeoCoords BottomLeft() const
	{
		return Center + HalfDimension * GeoCoords(1, -1);
	}

	GeoCoords TopRight() const
	{
		return Center + HalfDimension * GeoCoords(-1, 1);
	}

	bool IntersectsWith(const GeoCoords& center, const double radius) const
	{
		if (Contains(center))
			return true;

		const double r2 = radius * radius;

		if ((TopLeft() - center).LengthSquare() <= r2)
			return true;

		if ((BottomLeft() - center).LengthSquare() <= r2)
			return true;

		if ((TopRight() - center).LengthSquare() <= r2)
			return true;

		if ((BottomRight() - center).LengthSquare() <= r2)
			return true;

		return false;
	}
};