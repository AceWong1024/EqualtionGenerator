#include "equaltionGenerator.h"

using namespace std;

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

string EqualtionGenerator::getEqual(vector<int> & num, vector<char> & oper) {
	//position of brackets
	int lbrack = -1, rbrack = -1;
	bool flag = rander.getRanNum(0, 1) ? true : false;
	if (flag) {
		for (int i = 0; i < num.size() - 1; ++i) {
			if (lbrack != -1) {
				int isR = rander.getRanNum(lbrack + 1, num.size() - 1);
				rbrack = isR;
				break;
			}
			else {
				int isL = rander.getRanNum(1, num.size()) % num.size();
				if (isL == 0) {
					lbrack = i;
				}
			}
		}
	}

	//generate equaltions
	int length = oper.size() + num.size();
	string equaltion;
	for (int i = 0; i < length; ++i) {
		if (i % 2 == 0)
			equaltion += to_string(num[i / 2]);
		else
			equaltion += oper[i / 2];
	}
	//insert brackets
	if (flag && lbrack != -1 && rbrack != -1) {
		equaltion.insert(2 * lbrack, 1, '(');
		if (rbrack == num.size() - 1)
			equaltion.insert(2 * rbrack, 1, ')');
		else
			equaltion.insert(2 * rbrack, 1, ')');
	}
	
	return equaltion;
}