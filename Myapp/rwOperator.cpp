#include "rwOperator.h"

RwOperator::RwOperator()
{
}


RwOperator::~RwOperator()
{
}

bool RwOperator::writeEqual(vector<string>& equals) {
	ofstream outFile;
	outFile.open("exercises.txt");
	
	for (int i = 1; i <= equals.size(); ++i) {
		outFile << i << "." ;
		outFile << equals[i - 1].data() << endl;
	}
	outFile.close();
	return true;
}

bool RwOperator::writeAns(vector<string>& equals) {
	ofstream outFile;
	outFile.open("answers.txt");

	for (int i = 1; i <= equals.size(); ++i) {
		outFile << i << ".";
		outFile << equals[i - 1].data() << endl;
	}
	outFile.close();
	return true;
}

vector<string> RwOperator::readString(string filename) {
	ifstream inFile;
	inFile.open(filename);

	vector<string> equaltions;
	char temp[100];
	while (inFile.getline(temp, 100, '.'))
	{
		inFile.getline(temp, 100);
		string tempstr = temp;
		equaltions.push_back(tempstr);
		memset(temp, 100, '\0');
	}
	return equaltions;
}