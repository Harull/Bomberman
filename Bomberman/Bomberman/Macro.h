#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <random>

#define STR(_x) std::to_string(_x)
#define ENDL std::cout << std::endl
#define WAIT_CLS ENDL ;system("pause"); system("cls")
#define INT_PAIR std::pair<int,int>
#define VECTOR_INT_PAIR std::vector<INT_PAIR>
#define STTC_C(x, y) static_cast<x>(y)
#define STTC_ARRAY_SIZE(x) sizeof(x)/ sizeof(x[0])
#define INT_C(y) STTC_C(int, y)

namespace macro
{
	template<typename T>
	static T AskTypeAnsFromSring(const std::string& _question, const T& _minRestriction = T(),
		const T& _maxRestriction = T(), const std::string& _restrictionStr = "Vous ne respectez pas les restrictions")
	{
		T _answer;
		bool _cond = true;

		do
		{
			std::cout << _question << std::endl;
			std::cin >> _answer;
			std::cout << std::endl;

			if (_minRestriction != T() && _maxRestriction != T())
			{
				_cond = _minRestriction <= _answer && _maxRestriction >= _answer;
			}
			if (!_cond)
			{
				system("cls");
				std::cout << _restrictionStr << std::endl;
			}

		} while (!_cond);
		system("cls");

		return _answer;
	}

	template<typename T>
	void DeleteVectorWParamPointer(std::vector<T>& _vect)
	{
		for (auto _vToDelete : _vect)
		{
			delete _vToDelete;
			_vToDelete = nullptr;
		}
	}

	template<typename T>
	void DeleteVectorWParamPointer(std::vector<T>* _vect)
	{
		DeleteVectorWParamPointer<T>(*_vect);
		delete _vect;
		_vect = nullptr;
	}

	static void Say(const std::string& _strToSay)
	{
		std::cout << _strToSay << std::endl;
	}

	template<typename T>
	int FindIndexInVectorWithItem(std::vector<T>& _vect, T& _toFind) //Sad on peut pas retourner directement l'iterator
	{
		int _index = 0;
		for (auto _value : _vect)
		{
			if (_value == _toFind) return _index;
			_index++;
		}
		return -1;
	}

	static int RandomMaxMin(const int _max, const int _min = 0)
	{
		std::mt19937 _rng(std::random_device{}());
		std::uniform_int_distribution<int> _distribution(_min, _max);
		return _distribution(_rng);
	}

	template<typename T>
	void ShuffleVector(std::vector<T>& _vectorToShffl)
	{
		const int _arraySize = STTC_C(int, _vectorToShffl.size());
		for (int _i = 0; _i < _arraySize; _i++)
		{
			int _whereToDel = RandomMaxMin(_arraySize - 1);
			T _buff = _vectorToShffl[_whereToDel];
			_vectorToShffl.erase(_vectorToShffl.begin() + _whereToDel);
			_vectorToShffl.emplace(_vectorToShffl.begin() + RandomMaxMin(_arraySize - 2), _buff);
		}
	}
}
