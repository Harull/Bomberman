#pragma once
#include <iostream>

struct Coords
{
	std::pair<int, int> coordinates;

	Coords()
	{
		coordinates = { 0,0 };
	}

	Coords(const std::pair<int, int>& _coordinates)
	{
		coordinates = _coordinates;
	}

	bool operator==(const Coords& other) const
	{
		return coordinates == other.coordinates;
	}

	bool operator!=(const Coords& other) const
	{
		return coordinates != other.coordinates;
	}
};