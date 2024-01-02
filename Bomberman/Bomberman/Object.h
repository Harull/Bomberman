#pragma once
#include <iostream>
#include "Coords.h"
#include "Color.h"
#include <string>
using namespace std;

enum BlastResistance;

class Object
{
protected:
	std::string look; // S'intitialise avec 2 charact�res
	Coords coords;
	bool hasCollision, stopsExplosion;

public:
	std::string GetLook()const { return look; }
	Coords GetCoords()const { return coords; }
	bool GetHasCollision() const { return hasCollision; }
	virtual BlastResistance GetBlastResistance()const 
	{
		std::cerr << "Cet objet ne poss�de pas de r�sistance";
		return BlastResistance();
	}

public:
	Object();
	Object(const Coords& _coords);
	Object(const std::string& _look, const bool _hasCollision, const bool _stopsExplosions);
	Object(const Coords& coords, bool hasCollision, bool stopsExplosion);
		
public:
	virtual void Use();
	void SetCoordinates(const Coords& _coordinates) { coords = _coordinates; }


	//Se base sur le look, c�d sont �gaux si ils ont le m�me look;
	bool operator==(const Object& _other) const
	{
		return look == _other.look;
	}
	bool operator!=(const Object& _other) const
	{
		return !(look == _other.look);
	}
};

	

std::ostream& operator << (std::ostream& _stream, Object& _obj);