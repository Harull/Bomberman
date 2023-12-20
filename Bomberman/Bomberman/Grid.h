#pragma once
#include <vector>
#include "Object.h"

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

private:
    Grid();

private:
    std::vector<std::vector<Object*>> grid;



};

