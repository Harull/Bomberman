#pragma once
#include <vector>
#include "Object.h"
#include "Coords.h"
#include "Player.h"
#include "Macro.h"

//Init Singleton
class Object;
enum AmountOfFreeBlockPerCavity
{
    NONE = 0, LOW = 3, MID = 6, HIGH = 10
};


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
    static void DisplayGrid()
    {
        GetInstance().IDisplayGrid();
    }

private:
    Grid();


private:
    std::vector<std::vector<Object*>> grid;
    std::pair<int, int> heightWidth;

    Coords IGetNextWall(const Coords& _coordinates, const Direction& _direction);
    void IMoveToCoordinates(const Coords& _current, const Coords& _towards);
    void IDisplayGrid();

private:
    //LES INITS
    void Init();
    void InitHeightWidth();
    void InitGrid();
    void InitBreakableBlocks();

    void GenerateClassicGrid();
    //TODO
    void GenerateLabyrinthicGrid();

    /// <summary>
    /// Remplis la grille en fonction de la taille des cavité et du nombre de cavités
    /// </summary>
    /// <param name="_amount">Représente un énum pour la taille des cavités générées</param>
    /// <param name="_numberOfCavity">Représebte par un int le nombre de cavités à générer</param>
    void FillGridWBreakableBlocks(const AmountOfFreeBlockPerCavity& _amount,
        const int _numberOfCavity);
    /// <summary>
    /// Remplis tout les objects libres de l'array par des blocks de types BREAKABLE
    /// </summary>
    void FillAll();

    /// <summary>
    /// Retourne les voisins de l'Object (Hors diagonale) dans un vector de Object*
    /// </summary>
    /// <param name="_toCheckNeighbor">Object que l'on souhaite utiliser pour trouver ses voisins</param>
    /// <returns></returns>
    std::vector<Object*> GetNeighbors(Object* _toCheckNeighbor);
    /// <summary>
    /// Teste si l'objet est un block, et si il est un Breakable
    /// </summary>
    /// <param name="_object">Object a check</param>
    /// <returns></returns>
    bool IsABreakableBlock(Object* _object);
    /// <summary>
    /// Libère le coin et les cases directe voisines du coins
    /// </summary>
    /// <param name="_toFreed">Le coin a libérer</param>
    void FreeGridCorner(Object* _toFreed);
    /// <summary>
    /// Libère tous les coins de la map
    /// </summary>
    void FreeAllGridCorners();
    /// <summary>
    /// Nous retourne dans un Object*, un Block* aléatoire étant BREAKABLE;
    /// </summary>
    /// <returns></returns>
    Object* GetRandomBreakableBlock();
    /// <summary>
    /// Vérifier que au moins un Bloc* BREAKABLE existe dans notre grid
    /// </summary>
    /// <returns></returns>
    bool CheckAtLeastOneBreakableBlockInArray();
    /// <summary>
    /// Transforme un Object* (fille attendu) en Object* Mère
    /// </summary>
    /// <param name="_toTransform"></param>
    void TransformInMotherObject(Object*& _toTransform);
    // Méthode récursive permettant transformer tous les Block* BREAKABLE en Object* (vide)
    // _toTransform>   Object de départ   <
    // _currentEmptyBlockCount>   Nombre de block vide générés actuel   <
    // _freeBlockNeededCount>   Nombre de block vide demandé   <
    // Précisions : 
    // La méthode prend un objet de départ, et de manière récursive trace un chemin
    // et ce jusqu'à ce que le nombre de block vide actuel < nombre de block vide demandé pour former la cavité
    void TransformAllBreakableBlockNeighborInMotherObject(Object*& _toTransform,
        int& _currentEmptyBlockCount, const int _freeBlockNeededCount);

};

