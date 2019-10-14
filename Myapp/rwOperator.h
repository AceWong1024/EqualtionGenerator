#pragma once
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
class RwOperator
{
public:
	RwOperator();
	~RwOperator();
	bool writeEqual(vector<string> &);
	bool writeAns(vector<string>&);
	vector<string> readString(string filename);
};

