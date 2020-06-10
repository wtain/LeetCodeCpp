#pragma once

#include <cstdlib>
#include <cmath>
#include <sstream>
#include <ostream>

struct GeoCoords
{
	double Latitude;
	double Longitude;

	GeoCoords() : Latitude(0.0), Longitude(0.0) {}
	GeoCoords(const double lat, const double lon) : Latitude(lat), Longitude(lon) {}

	double LengthSquare() const
	{
		return Latitude * Latitude + Longitude * Longitude;
	}

	GeoCoords DistanceAbsolute(const GeoCoords& other) const
	{
		return GeoCoords(std::abs(Latitude - other.Latitude), std::abs(Longitude - other.Longitude));
	}

	friend bool operator < (const GeoCoords& left, const GeoCoords& right)
	{
		return left.Latitude < right.Latitude && left.Longitude < right.Longitude;
	}

	friend bool operator <= (const GeoCoords& left, const GeoCoords& right)
	{
		return left.Latitude <= right.Latitude && left.Longitude <= right.Longitude;
	}

	friend GeoCoords operator - (const GeoCoords& left, const GeoCoords& right)
	{
		return GeoCoords(left.Latitude - right.Latitude, left.Longitude - right.Longitude);
	}

	friend GeoCoords operator + (const GeoCoords& left, const GeoCoords& right)
	{
		return GeoCoords(left.Latitude + right.Latitude, left.Longitude + right.Longitude);
	}

	GeoCoords operator / (const double r) const
	{
		return GeoCoords(Latitude / r, Longitude / r);
	}

	GeoCoords operator * (const double r) const
	{
		return GeoCoords(Latitude * r, Longitude * r);
	}

	GeoCoords operator * (const GeoCoords& c) const
	{
		return GeoCoords(Latitude * c.Latitude, Longitude * c.Longitude);
	}

	friend std::ostream& operator<< (std::ostream& stream, const GeoCoords& coords)
	{
		stream << "(" << coords.Latitude << ", " << coords.Longitude << ")";
		return stream;
	}
};
