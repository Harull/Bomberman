#include "Object.h"

Object::Object()
{
    look = "  ";
    coords = Coords();
    hasCollision = false;
    stopsExplosion = false;
}

Object::Object(const Coords& _coords)
{
    look = "  ";
    coords = _coords;
    hasCollision = false;
    stopsExplosion = false;
}

Object::Object(const std::string& _look, const bool _hasCollision,
    const bool _stopsExplosions)
{
    look = "  ";
    coords = Coords();
    hasCollision = _hasCollision;
    stopsExplosion = _stopsExplosions;
}

Object::Object(const Coords& coords, bool hasCollision, bool stopsExplosion)
    : coords(coords), hasCollision(hasCollision), stopsExplosion(stopsExplosion)
{
}



void Object::Use()
{
    look = "  ";
    coords = Coords();
    hasCollision = false;
    stopsExplosion = false;
}


std::ostream& operator<<(std::ostream& _stream, Object& _obj)
{
    return _stream << _obj.GetLook();
}
