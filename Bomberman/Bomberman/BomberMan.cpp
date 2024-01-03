#include "BomberMan.h"
#include "Coords.h"
#include "Macro.h"
#include <conio.h>
#include <thread>
#include "Functions.h"

BomberMan::BomberMan()
{
	players = std::vector<Player*>();
	InitPlayerName();
	SetPlayerStartPositions();
}

BomberMan::~BomberMan()
{
	macro::DeleteVectorWParamPointer(players);
}

void BomberMan::InitPlayerName()
{
	std::string _currentPlayer;
	for (int _i = 1; _i < 3; _i++)
	{
		_currentPlayer = "Joueur " + STR(_i);
		players.push_back(new Player(macro::AskTypeAnsFromSring<std::string>
			(_currentPlayer + ", quel est votre username?"), _i));
	}
	CLS;
}

void BomberMan::InitPossibleSpawns(std::vector<Coords>& _possibleSpawns)
{
	std::pair<int, int> _heightWidth = Grid::GetHeightWidth();

	const int _arrayHeight[2]{ 0 , _heightWidth.first - 1 };
	const int _arrayWidth[2]{ 0 , _heightWidth.second - 1 };

	for (int _i = 0; _i < sizeof(_arrayHeight) / sizeof(_arrayHeight[0]); _i++)
	{
		for (int _j = 0; _j < sizeof(_arrayWidth) / sizeof(_arrayWidth[0]); _j++)
		{
			_possibleSpawns.push_back(Coords({ _arrayHeight[_i] , _arrayWidth[_j] }));
		}
	}
}

void BomberMan::SetPlayerStartPositions()
{
	std::vector<Coords> _arrayOfPossibleSpawnCoords;
	InitPossibleSpawns(_arrayOfPossibleSpawnCoords);
	
	for (auto _player : players)
	{
		int _randomNumber = macro::RandomMaxMin(STTC_C(int,_arrayOfPossibleSpawnCoords.size()-1));
		_player->TeleportPawnToCoordinates(_arrayOfPossibleSpawnCoords[_randomNumber]);
		_arrayOfPossibleSpawnCoords.erase(_arrayOfPossibleSpawnCoords.begin() + _randomNumber);
	}
	
}

void BomberMan::GameLoop()
{
	Grid::DisplayGrid();
	std::thread _playerOneCommandsLoop(&PlayerCommandLoop, players[0], KeyBindings({ 122,115,113,100 }));
	std::thread _playerTwoCommandsLoop(&PlayerCommandLoop, players[1], KeyBindings({ 72,80,75,77 }));

	_playerOneCommandsLoop.join();
	_playerTwoCommandsLoop.join();
}



void BomberMan::Start()
{
	GameLoop();

}
