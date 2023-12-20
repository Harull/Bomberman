#include "Grid.h"
#include "Macro.h"

Grid::Grid()
{
	heightWidth = std::pair<int, int>();
	grid = std::vector<std::vector<Object*>>();
	Init();
}

Coords Grid::IGetNextWall(const Coords& _coordinates, const Direction& _direction)
{
	// TODO: insert return statement here
	return Coords();
}

void Grid::IMoveToCoordinates(const Coords& _current, const Coords& _towards)
{
}

void Grid::Init()
{
	InitHeightWidth();
	InitGrid();
}

void Grid::InitHeightWidth()
{
	//TODO
	macro::AskTypeAnsFromSring<int>("Quelle largeur de la map voulez vous ?");
	macro::AskTypeAnsFromSring<int>("Quelle longueur de la map voulez vous ?");
}

void Grid::InitGrid()
{
}
