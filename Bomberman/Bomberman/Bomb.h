#pragma once
#include "Object.h"

class Bomb
{
	bool isOverpowered;
	int horizontalRange, verticalRange;
	int delayBeforeExplosion, initialDelayBeforeExplosion;

public:
	void Explode();
	void Search();
};

