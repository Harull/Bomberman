#pragma once
#include <vector>
#include "Object.h"
#include "Coords.h"
#include "Player.h"
#include "Macro.h"

class Object;
enum AmountOfFreeBlockPerCavity
{
    AM_NONE = 0, LOW = 3, MID = 6, HIGH = 10
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

    /// <summary>
    /// Nous donne les coordonn�es de la prochaine case en avan�ant dans la direction indiqu�e, et depuis les coordonn�es indiqu�es
    /// </summary>
    /// <param name="_coordinates">Les coords du point initial (dans notre cas position du joueur attendue)</param>
    /// <param name="_direction">La direction dans laquelle se dirige notre joueur</param>
    /// <returns></returns>
    static Coords GetNextWall(const Coords& _coordinates, const Direction& _direction)
    {
        return GetInstance().IGetNextWall(_coordinates, _direction);
    }
    /// <summary>
    /// T�l�porte l'objet aux coordonn�es initiale, aux coordonn�es souhait�e. 
    /// Laissant � l'ancienne position un objet vide
    /// </summary>
    /// <param name="_current">Coordonn�es actuelle de l'objet</param>
    /// <param name="_towards">Coordonn�es souhait�es de l'objet</param>
    static void MovePawnToCoordinates(Pawn* _currentPawn, const Coords& _towards, const bool _updateScreen = false)
    {
        GetInstance().IMovePawnToCoordinates(_currentPawn, _towards, _updateScreen);
    }
    /// <summary>
    /// Get notre Grille
    /// </summary>
    static std::vector<std::vector<Object*>> GetGrid()
    {
        return GetInstance().grid;
    }
    /// <summary>
    /// Affiche notre grille
    /// </summary>
    static void DisplayGrid()
    {
        GetInstance().IDisplayGrid();
    }
    static std::pair<int, int> GetHeightWidth()
    {
        return GetInstance().heightWidth;
    }

private:
    Grid();


private:
    std::vector<std::vector<Object*>> grid;
    std::pair<int, int> heightWidth;

    Coords IGetNextWall(const Coords& _coordinates, const Direction& _direction);
    void IMovePawnToCoordinates(Pawn* _current, const Coords& _towards, const bool _updateScreen = false);
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
    /// Remplis la grille en fonction de la taille des cavit� et du nombre de cavit�s
    /// </summary>
    /// <param name="_amount">Repr�sente un �num pour la taille des cavit�s g�n�r�es</param>
    /// <param name="_numberOfCavity">Repr�sebte par un int le nombre de cavit�s � g�n�rer</param>
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
    /// Lib�re le coin et les cases directe voisines du coins
    /// </summary>
    /// <param name="_toFreed">Le coin a lib�rer</param>
    void FreeGridCorner(Object* _toFreed);
    /// <summary>
    /// Lib�re tous les coins de la map
    /// </summary>
    void FreeAllGridCorners();
    /// <summary>
    /// Nous retourne dans un Object*, un Block* al�atoire �tant BREAKABLE;
    /// </summary>
    /// <returns></returns>
    Object* GetRandomBreakableBlock();
    /// <summary>
    /// V�rifier que au moins un Bloc* BREAKABLE existe dans notre grid
    /// </summary>
    /// <returns></returns>
    bool CheckAtLeastOneBreakableBlockInArray();
    /// <summary>
    /// Transforme un Object* (fille attendu) en Object* M�re
    /// </summary>
    /// <param name="_toTransform"></param>
    void TransformInMotherObject(Object*& _toTransform);
    // M�thode r�cursive permettant transformer tous les Block* BREAKABLE en Object* (vide)
    // _toTransform>   Object de d�part   <
    // _currentEmptyBlockCount>   Nombre de block vide g�n�r�s actuel   <
    // _freeBlockNeededCount>   Nombre de block vide demand�   <
    // Pr�cisions : 
    // La m�thode prend un objet de d�part, et de mani�re r�cursive trace un chemin
    // et ce jusqu'� ce que le nombre de block vide actuel < nombre de block vide demand� pour former la cavit�
    void TransformAllBreakableBlockNeighborInMotherObject(Object*& _toTransform,
        int& _currentEmptyBlockCount, const int _freeBlockNeededCount);
    /// <summary>
    /// Uptate le block aux coordonn�es indiqu�es
    /// </summary>
    void UpdateCoordinates(const Coords& _cordinates);

};

