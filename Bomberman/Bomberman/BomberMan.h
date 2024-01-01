#pragma once
#include "Grid.h"
#include "Player.h"
#include <vector>
#include "Macro.h"

class BomberMan
{
	std::vector<Player*> players;

public:
	BomberMan();
	~BomberMan();


private:
	void InitPlayerName();
	void InitPossibleSpawns(std::vector<Coords>& _possibleSpawns);
	void SetPlayerStartPositions();


private:
	void GameLoop();
public:
	void Start();
};



