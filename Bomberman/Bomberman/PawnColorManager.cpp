#include "PawnColorManager.h"
#include "Color.h"
#include "Macro.h"
#include <assert.h>


PawnColorManager::PawnColorManager()
{
	colorsAvailable = std::vector<Color>();
	InitColorsAvailable();
}


void PawnColorManager::InitColorsAvailable()
{
	std::string _arrayOfBg[]{
		BG_BLACK,
	};

	std::string _arrayOfFg[]{
		ORANGE,
		RED,
		CYAN,
		PINK,
	};	

	for (int _i = 0; _i < STTC_ARRAY_SIZE(_arrayOfBg); _i++)
	{
		for (int _y = 0; _y < STTC_ARRAY_SIZE(_arrayOfFg); _y++)
		{
			colorsAvailable.push_back({ _arrayOfFg[_y], _arrayOfBg[_i] });
		}
	}
}

std::string PawnColorManager::IChosePawnColor(const std::string& _name)
{
	assert(colorsAvailable.size() > 0 && "Ya pas de choix de couleurs");

	std::string _pawnsLeft = _name + ", veuillez choisir un pion parmis les suivants:\n";
	for (int _i = 0; _i < colorsAvailable.size(); _i++)
	{
		_pawnsLeft += "Pion num\x82ro " + STR(_i + 1) + ": " + colorsAvailable[_i].fgColor +
			colorsAvailable[_i].bgColor + "\xDE\xDD" + COLORRESET + "\n";
	}

	int _index = macro::AskTypeAnsFromSring<int>(_pawnsLeft, 1, INT_C(colorsAvailable.size())) - 1;
	std::string _toReturn = colorsAvailable[_index].fgColor + colorsAvailable[_index].bgColor;
	colorsAvailable.erase(colorsAvailable.begin() + _index);
	return _toReturn;
}

std::ostream& operator<<(std::ostream& _stream, Color& _color)
{
	return _stream << _color.fgColor << _color.bgColor;
}
