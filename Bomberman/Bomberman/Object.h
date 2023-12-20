#pragma once
#include <iostream>
#include "Coords.h"

using namespace std;


class Object
{
	string look; // S'intitialise avec 2 charactères
	Coords coords;
	bool hasCollision, stopsExplosion;

public:
	virtual void Use();
	void SetCoordinates(const Coords& _coordinates) { coords = _coordinates; }
};

