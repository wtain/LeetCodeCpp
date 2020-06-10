#pragma once

#include <string>
#include <ostream>

#include "GeoCoords.h"

struct PointOfInterest
{
	GeoCoords Coordinates;
	std::string Name;

	PointOfInterest(const GeoCoords& coords, const std::string& name)
		: Coordinates(coords), Name(name) {}

	friend std::ostream& operator<< (std::ostream& stream, const PointOfInterest& poi)
	{
		stream << poi.Name << " " << poi.Coordinates;
		return stream;
	}
};
