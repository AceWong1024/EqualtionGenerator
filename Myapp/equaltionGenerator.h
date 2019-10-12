#pragma once
#include <vector>
#include "Random.h"
class EqualtionGenerator
{
private:
	
public:
	Random rander;
	EqualtionGenerator();
	~EqualtionGenerator();
	std::vector<int> getNums(int amount,int min,int max);
	std::vector<char> getOper(int amount);
};

