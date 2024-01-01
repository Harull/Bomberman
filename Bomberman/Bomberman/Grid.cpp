#include "Grid.h"
#include "Macro.h"
#include "Block.h"

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

void Grid::IMovePawnToCoordinates(Pawn* _current, const Coords& _towards)
{
	Object*& _finalObject = grid[_towards.coordinates.first][_towards.coordinates.second];
	delete _finalObject;
	_finalObject = _current;

	Coords _initialLocation = _current->GetCoords();
	if (_initialLocation != Coords({0,0}))
	{
		int _first = _initialLocation.coordinates.first, _second = _initialLocation.coordinates.second;
		grid[_first][_second] = new Object(Coords({ _first, _second }));
	}

	_current->SetCoordinates(_towards);
}


void Grid::IDisplayGrid()
{
	int _yL = heightWidth.first;
	int _xL = heightWidth.second;
	
	for (int _i = 0; _i < 3; _i++)
	{
		if (_i == 0 || _i == 2)
		{
			std::cout << DARK_GRAY;
			for (int _i = 0; _i < _xL + 2; _i++)
			{
				std::cout << "\xDB\xDB";
			}
			std::cout << WHITE << std::endl;
			continue;
		}

		for (auto _vector : grid)
		{
			std::cout << DARK_GRAY << "\xDB\xDB" << WHITE;
			for (Object* _object : _vector)
			{
				std::cout << *_object;
			}
			std::cout << DARK_GRAY << "\xDB\xDB" << WHITE;
			ENDL;
		}
	}
}

void Grid::Init()
{
	InitHeightWidth();
	InitGrid();
	InitBreakableBlocks();	
}

void Grid::InitHeightWidth()
{
	int& _y = heightWidth.first;
	int& _x = heightWidth.second;

	_y = macro::AskTypeAnsFromSring<int>("Quelle hauteur de la map voulez vous ?", 10, 45,
		"La hauteur doit être comprise entre 10 et 45");
	_x = macro::AskTypeAnsFromSring<int>("Quelle longueur de la map voulez vous ?", 10, 45,
		"La longueur doit être comprise entre 10 et 45");

	if (_y %2 == 0)
	{
		_y += 1;
	}
	if (_x % 2 == 0)
	{
		_x += 1;
	}

	//forcer un nombre de case impair x)
}

void Grid::InitGrid()
{
	bool _choice = macro::AskTypeAnsFromSring<int>("Choisissez un type de génération:\n1-Classique\n2-Aléatoire", 1, 2) - 1;

	if (_choice == 0)
	{
		GenerateClassicGrid();
	}
	else
	{
		GenerateLabyrinthicGrid();
	}
}

void Grid::InitBreakableBlocks()
{
	// Paramètres recommandés
	// HIGH : 625blck => 15	||	ceil(41 / totb)
	// MID : 625blck => 25	||	ceil(25 / totb)
	// LOW : 625blck => 35	||	ceil(18 / totb)
	AmountOfFreeBlockPerCavity _enum;
	int _answerToWitchEnum = macro::AskTypeAnsFromSring<int>(
		"1|High void gen\n2|Mid void gen\n3|Low void gen\n4|No void (déconseillé)", 1, 4);
	_enum = _answerToWitchEnum == 1 ? HIGH : _answerToWitchEnum == 2 ? MID
		: _answerToWitchEnum == 3 ? LOW : AM_NONE;
	switch (_enum)
	{
	case AM_NONE:
		FillAll();
		break;
	case LOW:
		FillGridWBreakableBlocks(AmountOfFreeBlockPerCavity::LOW, INT_C(ceil(18 / heightWidth.first * heightWidth.second)));
		break;
	case MID:
		FillGridWBreakableBlocks(AmountOfFreeBlockPerCavity::MID, INT_C(ceil(25 / heightWidth.first * heightWidth.second)));
		break;
	case HIGH:
		FillGridWBreakableBlocks(AmountOfFreeBlockPerCavity::HIGH, INT_C(ceil(41 / heightWidth.first * heightWidth.second)));
		break;
	default:
		std::cerr << "Error InitBreakableBlocks" << std::endl;
		break;
	}

	FreeAllGridCorners();
}

void Grid::GenerateClassicGrid()
{
	std::vector<Object*> _toPushBack;

	for (int _y = 0; _y < heightWidth.first ; _y++)
	{
		for (int _i = 0; _i < heightWidth.second; _i++)
		{
			if (_y % 2 == 0)
			{
				_toPushBack.push_back(new Object(Coords({_y,_i})));
				continue;
			}
			else
			{
				if (_i % 2 == 1)
				{
					int _randInt = macro::RandomMaxMin(3);
					if (_randInt == 3)
					{
						_toPushBack.push_back(new Block(Coords({ _y,_i }), SOLID));
						continue;
					}
					_toPushBack.push_back(new Block(Coords({ _y,_i }), UNBREAKABLE));
					continue;
				}
				_toPushBack.push_back(new Object(Coords({ _y,_i })));
			}
		}
		grid.push_back(_toPushBack);
		_toPushBack.clear();
	}
}

//TODO
void Grid::GenerateLabyrinthicGrid()
{
	//TODO
	std::vector<Object*> _toPushBack;

	for (int _y = 0; _y < heightWidth.first; _y++)
	{
		for (int _i = 0; _i < heightWidth.second; _i++)
		{
			//TODO

		}
	}
}

void Grid::FillGridWBreakableBlocks(const AmountOfFreeBlockPerCavity& _amount, const int _numberOfCavity)
{
	FillAll();
	int _freeBlockNeededCount = static_cast<int>(_amount);
	if (_freeBlockNeededCount <= 0) return;
	int _currentEmptyBlockCount = 0;

	for (int _i = 0; _i < _numberOfCavity; _i++)
	{
		Object* _breakableBlock = GetRandomBreakableBlock();
		//recursive funct
		TransformAllBreakableBlockNeighborInMotherObject(_breakableBlock, _currentEmptyBlockCount, _freeBlockNeededCount);
		_currentEmptyBlockCount = 0;
	}
	
	
}

void Grid::FillAll()
{
	int _x = 0, _y = 0;
	for (std::vector<Object*>& _vector : grid)
	{
		_x = 0;
		for (Object*& _object : _vector)
		{
			if (*_object != Object())
			{
				_x++;
				continue;
			}
			delete _object;
			_object = new Block(Coords({_y,_x}),BREAKABLE);
			_x++;
		}
		_y++;
	}

}

std::vector<Object*> Grid::GetNeighbors(Object* _toCheckNeighbor)
{
	std::vector<Object*> _allNeightboor;
	INT_PAIR _coords = _toCheckNeighbor->GetCoords().coordinates;
	int _height = _coords.first, _width = _coords.second;
	Object* _currentNeighbor;

	struct Opti
	{
		bool conditionBool;
		Coords coordinates;

		Opti(const bool _conditionBool, const Coords& _coordinates)
		{
			conditionBool = _conditionBool;
			coordinates = _coordinates;
		}
	};

	Opti _arrayBool[4]{
		Opti(_height - 1 > 0, Coords({_height - 1, _width})),
		Opti(_width - 1 > 0, Coords({_height, _width - 1})),
		Opti(_height + 1 < grid.size(), Coords({_height + 1, _width})),
		Opti(_width + 1 < grid[_height].size(), Coords({_height, _width +1})),		
	};

	for (int _i = 0; _i < sizeof(_arrayBool)/sizeof(_arrayBool[0]); _i++)
	{
		Opti _currentOpti = _arrayBool[_i];
		if (!_currentOpti.conditionBool) continue;
		INT_PAIR _currentPair = _currentOpti.coordinates.coordinates;
		_currentNeighbor = grid[_currentPair.first][_currentPair.second];
		_allNeightboor.push_back(_currentNeighbor);
	}

	return _allNeightboor;
}

bool Grid::IsABreakableBlock(Object* _object)
{
	_object = grid[_object->GetCoords().coordinates.first][_object->GetCoords().coordinates.second];
	if (!dynamic_cast<Block*>(_object)) return false;
	if (_object->GetBlastResistance() != BREAKABLE) return false;	
	return true;
}

void Grid::FreeGridCorner(Object* _toFreed)
{
	TransformInMotherObject(_toFreed);
	std::vector<Object*> _arrayToFreedAswell = GetNeighbors(_toFreed);
	for (Object* _objToFreed : _arrayToFreedAswell)
	{
		TransformInMotherObject(_objToFreed);
	}
}

void Grid::FreeAllGridCorners()
{
	std::vector<Object*> _arrayCorners =
	{
		grid[0][0],
		grid[0][grid[0].size()-1],
		grid[grid.size()-1][0],
		grid[grid.size()-1][grid[grid.size()-1].size()-1]
	};

	for (Object* _corner : _arrayCorners)
	{
		FreeGridCorner(_corner);
	}
}

Object* Grid::GetRandomBreakableBlock()
{
	if (!CheckAtLeastOneBreakableBlockInArray()) return nullptr;
	while (true)
	{
		int _randomIndexY = macro::RandomMaxMin(STTC_C(int, grid.size()) - 1);
		int _randomIndexX = macro::RandomMaxMin(STTC_C(int, grid[_randomIndexY].size()-1));

		if (dynamic_cast<Block*>(grid[_randomIndexY][_randomIndexX]))
		{
			if (grid[_randomIndexY][_randomIndexX]->GetBlastResistance() == BREAKABLE)
				return grid[_randomIndexY][_randomIndexX];
		}
	}
	return nullptr;

}

bool Grid::CheckAtLeastOneBreakableBlockInArray()
{
	for (auto _vector : grid)
	{
		for (Object* _object : _vector)
		{
			if (dynamic_cast<Block*>(_object))
			{
				if (_object->GetBlastResistance() == BREAKABLE)
					return true;
			}
		}
	}
	return false;
}

void Grid::TransformInMotherObject(Object*& _toTransform)
{
	INT_PAIR _pair = _toTransform->GetCoords().coordinates;
	int _y = _pair.first, _x = _pair.second;

	delete _toTransform;
	_toTransform = new Object(Coords({ _y,_x }));
	grid[_y][_x] = _toTransform;
}

void Grid::TransformAllBreakableBlockNeighborInMotherObject(Object*& _toTransform,
	int& _currentEmptyBlockCount, const int _freeBlockNeededCount)
{
	if (!_toTransform)return;

	if (!(_currentEmptyBlockCount < _freeBlockNeededCount)) return;

	TransformInMotherObject(_toTransform);
	_currentEmptyBlockCount++;

	std::vector<Object*> _arrayObj = GetNeighbors(_toTransform);
	macro::ShuffleVector(_arrayObj);
	for (auto _obj : _arrayObj)
	{
		if (!(_currentEmptyBlockCount < _freeBlockNeededCount)) return;
		if (IsABreakableBlock(_obj))
			TransformAllBreakableBlockNeighborInMotherObject(_obj, _currentEmptyBlockCount, _freeBlockNeededCount);
	}
}
