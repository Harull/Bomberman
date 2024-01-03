#pragma once
#include "Player.h"
#include <conio.h>

struct KeyBindings
{
	const int up, down, left, right;
};

static void PlayerCommandLoop(Player* _playerInstance, KeyBindings _personnalsBindings)
{
	int _char;
	while (true)
	{
		if (_kbhit())
		{
			_char = _getch();
			if (_char == 224)_char = _getch();
			if (_char == _personnalsBindings.up)
			{
				_playerInstance->MovePawn(UP);
				continue;
			}
			if (_char == _personnalsBindings.down)
			{
				_playerInstance->MovePawn(DOWN);
				continue;
			}
			if (_char == _personnalsBindings.left)
			{
				_playerInstance->MovePawn(LEFT);
				continue;
			}
			if (_char == _personnalsBindings.right)
			{
				_playerInstance->MovePawn(RIGHT);
				continue;
			}
		}
	}
}