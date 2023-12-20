#pragma once
#include <vector>
#include "Object.h"
#include "Coords.h"
#include "Player.h"

//Init Singleton
class Object;

class Grid
{
public:

    Grid(const Grid&) = delete;

    static Grid& GetInstance()
    {
        static Grid instance;
        return instance;
    }

    static Coords GetNextWall(const Coords& _coordinates, const Direction& _direction)
    {
        return GetInstance().IGetNextWall(_coordinates, _direction);
    }
    static void MoveToCoordinates(const Coords& _current, const Coords& _towards)
    {
        GetInstance().IMoveToCoordinates(_current, _towards);
    }
    static std::vector<std::vector<Object*>> GetGrid()
    {
        return GetInstance().grid;
    }


private:
    Grid();


private:
    std::vector<std::vector<Object*>> grid;
    std::pair<int, int> heightWidth;

    Coords IGetNextWall(const Coords& _coordinates, const Direction& _direction);
    void IMoveToCoordinates(const Coords& _current, const Coords& _towards);

private:
    void Init();
    void InitHeightWidth();
    void InitGrid();
};

