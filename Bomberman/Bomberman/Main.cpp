#include "Grid.h"
#include <iostream>
#include "Macro.h"
#include <vector>
#include "Player.h"
#include "BomberMan.h"
#include <conio.h>

void Test();


int main()
{	
	BomberMan _bomberman;
	_bomberman.Start();
	return 0;
}

void Test()
{
	while (true)
	{
		if (_kbhit())
		{
			std::cout << _getch() << endl;
		}
	}
	
}