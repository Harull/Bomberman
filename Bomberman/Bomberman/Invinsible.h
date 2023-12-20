#pragma once
#include "Bonus.h"

class Invinsible : public Bonus
{
	int actionTime;

public:
	void Use() override;
};

