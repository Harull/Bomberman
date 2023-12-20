#pragma once
#pragma once
#include <string>
#include <vector>
#include <iostream>

#define STR(_x) std::to_string(_x)
#define ENDL std::cout << std::endl
#define WAIT_CLS ENDL ;system("pause"); system("cls")
#define INT_PAIR std::pair<int,int>
#define VECTOR_INT_PAIR std::vector<INT_PAIR>

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

}
