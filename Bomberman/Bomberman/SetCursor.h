#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

static void SetCursorPosition(const int _x, const int _y)
{
    const char _xchr = char(_x), _ychr = char(_y);
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)_xchr, (SHORT)_ychr };
    SetConsoleCursorPosition(hOut, coord);
}

static void SetCursorPosition(pair<int, int> _pairInt)
{
    SetCursorPosition(_pairInt.first, _pairInt.second);
}
