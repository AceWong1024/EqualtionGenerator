#include "equaltionGenerator.h"
#include "rwOperator.h"
#include "Random.h"
#include "CheckClass.h"
using namespace std;

/*
	返回值:
	文件错误 2	
	参数错误 1
	正常 0
*/
int chosenProgram(int nums, int maxnum, string exerFile, string ansFile) {
	RwOperator rwop;
	//if "-r"
	if (maxnum != 0) {
		EqualtionGenerator generator;
		
		vector<string> equaltions;
		vector<string> answers;
		string temp;
		double ans;
		for (int i = 0; i < nums ; ++i) {
			vector<char> oper = generator.getOper(generator.rander.getRanNum(1, 3));
			vector<int> num = generator.getNums(oper.size() + 1, 0, maxnum);
			sort(num.begin(), num.end());
			temp = generator.getEqual(num, oper);

			CheckClass check;
			check.len = temp.size();
			strcpy_s(check.str, temp.data());
			check.Split();
			check.Judge();
			ans = check.Calculate();
			//cout << "ans = " << ans << endl;
			if (ans >= 0) {
				equaltions.push_back(temp);
				answers.push_back(to_string(ans));
			}
			else {
				i--;
			}
		}
		
		rwop.writeEqual(equaltions);
		rwop.writeAns(answers);
	}
	//-e || -a
	if (!exerFile.empty() && !ansFile.empty()) {
		vector<string> questions;
		vector<string> stdans;
		vector<string> answer;
		
		questions = rwop.readString(exerFile);
		answer = rwop.readString(ansFile);

		vector<int> corret;
		vector<int> error;
		for (int i = 0; i < questions.size(); ++i) {
			double ans;
			CheckClass check;
			check.len = questions[i].size();
			strcpy_s(check.str, questions[i].data());
			check.Split();
			check.Judge();
			ans = check.Calculate();

			if (ans == atof(answer[i].data())) {
				corret.push_back(i);
			}
			else {
				error.push_back(i);
			}
		}
		cout << "Correct:" << corret.size() << '(';
		int i = 1;
		cout << corret[0];
		for (; i < corret.size(); ++i) {
			cout << ',' << corret[i];
		}
		cout << ')' << endl;

		cout << "Wrong:" << error.size() << '(';
		i = 1;
		cout << error[0];
		for (; i < error.size(); ++i) {
			cout << ',' << error[i];
		}
		cout << ')' << endl;
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
				i++;
				chosenProgram(nums, maxnum, exerFile, ansFile);
			}
			else if (temp == "-r") {
				maxnum = atoi(argv[i + 1]);
				i++;
				chosenProgram(nums, maxnum, exerFile, ansFile);
			}
			else if (temp == "-a") {
				ansFile = argv[i + 1];
				i++;
				chosenProgram(nums, maxnum, exerFile, ansFile);
			}
			else if (temp == "-e") {
				exerFile = argv[i + 1];
				i++;
				chosenProgram(nums, maxnum, exerFile, ansFile);
			}
			else {
				cout << "Parameter error! " <<endl;
				errno = 1;
				break;
			}
			/*if (errno != 1) {
				cout << "hello world " << temp << endl;
			}*/
		}
	}
	return 0;
}