#include "equaltionGenerator.h"



EqualtionGenerator::EqualtionGenerator()
{
	srand((int)time(NULL));
}


EqualtionGenerator::~EqualtionGenerator()
{

}

std::vector<int> EqualtionGenerator::getNums(int amount,int min,int max) {
	std::vector<int> nums;
	for (int i = 0; i < amount; ++i) {
		nums.push_back(rander.getRanNum(min, max));
	}
	return nums;
}

std::vector<char> EqualtionGenerator::getOper(int amount) {
	std::vector<char> ope;
	char oper[4] = { '+','-','*','/' };
	for (int i = 0; i < amount; ++i) {
		ope.push_back(oper[rander.getRanNum(0, 3)]);
	}
	return ope;
}