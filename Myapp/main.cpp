#include <iostream>
#include <stdlib.h>
#include <string>
#include "equaltionGenerator.h"
#include "rwOperator.h"
#include "Random.h"
using namespace std;

/*
	返回值:
	文件错误 2	
	参数错误 1s
	正常 0
*/
int chosenProgram(int nums, int maxnum, string exerFile, string ansFile) {
	//if "-r"
	if (maxnum != 0) {
		EqualtionGenerator generator;
		vector<char> oper = generator.getOper(generator.rander.getRanNum(1, 3));
		vector<int> num = generator.getNums(oper.size() + 1, 0, maxnum);
		
		vector<string> equaltions;
		
		//position of brackets
		int lbrack = -1, rbrack = -1;
		bool flag = generator.rander.getRanNum(0, 1) ? true : false;
		if (flag) {
			for (int i = 0; i < num.size() - 1; ++i) {
				if (lbrack != -1) {
					int isR = generator.rander.getRanNum(lbrack + 1, num.size() - 1);
					rbrack = isR;
					break;
				}
				else {
					int isL = generator.rander.getRanNum(1, num.size()) % num.size();
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

		if (flag && lbrack!=-1 && rbrack != -1) {
			equaltion.insert(2 * lbrack, 1, '(');
			if(rbrack == num.size() - 1)
				equaltion.insert(2 * rbrack, 1, ')');
			else
				equaltion.insert(2 * rbrack + 1, 1, ')');
		}
		cout << oper.size() << endl;
		cout << num.size() << endl;
		cout << equaltion << endl;
	}
	if (!exerFile.empty() && ansFile.empty()) {

	}

	return 0;
}

int main(int argc, char** argv) {
	int nums = 1;
	int maxnum = 0;
	string exerFile, ansFile;

	if (argc == 1) {
		cout << "Parameter error!" << endl;
	}
	else {
		int i = 1;
		string temp;
		for (; i < argc; ++i) {
			temp = argv[i];
			if (temp == "-n") {
				nums = atoi(argv[i + 1]);
				i += 2;
				cout << "pro a" << nums << endl;
				chosenProgram(nums, 10, exerFile, ansFile);
			}
			else if (temp == "-r") {
				maxnum = atoi(argv[i + 1]);
				i += 2;
				/*cout << "pro r" << maxnum << endl;*/
			}
			else if (temp == "-a") {
				ansFile = argv[i + 1];
				i += 2;
				/*cout << "pro a" << ansFile << endl;*/
			}
			else if (temp == "-e") {
				exerFile = argv[i + 1];
				i += 2;
				/*cout << "pro e" << exerFile << endl;*/
			}
			else {
				cout << "Parameter error!" << endl;
				errno = 1;
				break;
			}
			if (errno != 1) {
				cout << "hello world" << endl;
			}
		}
	}
	system("pause");
	return 0;
}