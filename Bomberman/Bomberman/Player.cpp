#include "Player.h"
#include "Macro.h"
#include "Grid.h"

Player::Player(const std::string& _name, const int _id)
{
	id = _id;
	name = _name;
	pawn = new Pawn(_name);
	bombSac = std::vector<Bomb*>{ new Bomb() };
}

Player::~Player()
{
	delete pawn;
	pawn = nullptr;
	macro::DeleteVectorWParamPointer(bombSac);
}

void Player::MovePawn(const Direction& _direction)
{
	const int _height = pawn->GetCoords().coordinates.first;
	const int _width = pawn->GetCoords().coordinates.second;
	
	std::vector<std::vector<Object*>> _grid = Grid::GetGrid();

	switch (_direction)
	{
	case DI_NONE:
		return;
	case RIGHT:
		if (_width + 1 >= _grid[_height].size())return;
		if (_grid[_height][_width + 1]->GetHasCollision())return;
		pawn->Move(Coords({ _height, _width + 1 }), true);
		return;
	case LEFT:
		if (_width - 1 < 0)return;
		if (_grid[_height][_width - 1]->GetHasCollision())return;
		pawn->Move(Coords({ _height, _width - 1 }), true);
		return;
	case UP:
		if (_height - 1 < 0)return;
		if (_grid[_height - 1][_width]->GetHasCollision())return;
		pawn->Move(Coords({ _height - 1, _width}), true);
		return;
	case DOWN:
		if (_height + 1 >= _grid.size())return;
		if (_grid[_height + 1][_width]->GetHasCollision())return;
		pawn->Move(Coords({ _height + 1, _width }), true);
		return;
	default:
		break;
	}
}

void Player::TeleportPawnToCoordinates(const Coords& _coordinates)
{
	pawn->Move(_coordinates);
}

