#pragma once
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include "Random.h"
using namespace std;
class EqualtionGenerator
{
private:
	
public:
	Random rander;
	EqualtionGenerator();
	~EqualtionGenerator();
	std::vector<int> getNums(int amount,int min,int max);
	std::vector<char> getOper(int amount);
	string getEqual(vector<int>&, vector<char>&);
};

