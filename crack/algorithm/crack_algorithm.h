#pragma once
#include <string>
#include <vector>
using namespace std;

namespace crack_algorithm {

	//×Ö·û´®
	void replaceStr(char* str);
	void replaceStrUnitTest();

	string compressStr(string str);
	void compressStrUnitTest();

	void setMatrix(vector<vector<int>>& matrix);
	void setMatrixUnitTest();
};