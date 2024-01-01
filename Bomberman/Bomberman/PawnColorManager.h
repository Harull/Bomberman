#pragma once
#include <vector>
#include <iostream>

struct Color
{
	std::string fgColor;
	std::string bgColor;
};

std::ostream& operator<<(std::ostream& _stream, Color& _color);

class PawnColorManager
{
public:
	PawnColorManager(const PawnColorManager&) = delete;
	static PawnColorManager& GetInst()
	{
		static PawnColorManager instance;
		return instance;
	}
	static std::string ChosePawnColor(const std::string& _name)
	{
		return GetInst().IChosePawnColor(_name);
	}
public:


private:
	std::vector<Color> colorsAvailable;

private:
	PawnColorManager();

	void InitColorsAvailable();

private:
	std::string IChosePawnColor(const std::string& _name);
};

