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
	std::string look; // S'intitialise avec 2 charactères
	Coords coords;
	bool hasCollision, stopsExplosion;

public:
	std::string GetLook()const { return look; }
	Coords GetCoords()const { return coords; }
	virtual BlastResistance GetBlastResistance()const 
	{
		std::cerr << "Cet objet ne possède pas de résistance";
		return BlastResistance();
	}

public:
	Object();
	Object(const Coords& _coords);
	Object(const Coords& coords, bool hasCollision, bool stopsExplosion);
		
public:
	virtual void Use();
	void SetCoordinates(const Coords& _coordinates) { coords = _coordinates; }


	//Se base sur le look, càd sont égaux si ils ont le même look;
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