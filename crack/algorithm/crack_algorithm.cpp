#include "crack_algorithm.h"
#include <iostream>
using namespace std;

namespace crack_algorithm {

	void replaceStr(char* str) {
		if (nullptr == str) {
			return;
		}

		char* cursor = str;
		while (*cursor != '\0') {
			if (' ' == *cursor) {
				//move the rest str;
				char* begin = cursor;
				char* end = begin;
				while (*end != '\0') {
					end++;
				}

				while (end != begin) {
					*(end + 2) = *end;
					--end;
				}

				*begin = '%';
				*(begin + 1) = '2';
				*(begin + 2) = '0';
				cursor = cursor + 3;
				continue;
			}

			++cursor;
		}
	}

	/*
	* 好处就是字符所在的位置能够一次到位
	* 但是这个代码可阅读性是在是太低
	*/
	void replaceSpace(char *str) {
		if (nullptr == str) {
			return;
		}

		int i, j;
		int len = (int)strlen(str);
		int cc = 0;
		for (i = 0; i < len; ++i) {
			if (str[i] == ' ') {
				++cc;
			}
		}

		int tc = 0;
		for (i = len - 1; i >= 0; --i) {
			if (str[i] == ' ') {
				++tc;
			}
			else {
				break;
			}
		}
		cc -= tc;

		j = i;
		i = cc;
		while (j >= 0) {
			if (str[j] == ' ') {
				--cc;
				str[j + 2 * cc] = '%';
				str[j + 2 * cc + 1] = '2';
				str[j + 2 * cc + 2] = '0';
			}
			else {
				str[j + 2 * cc] = str[j];
			}
			--j;
		}
		if (2 * i > tc) {
			str[len - tc + 2 * i] = 0;
		}
	}

	void replaceStrUnitTest() {
		char str[256] = "       ";
		char str2[256] = "       ";
		replaceStr(str);
		replaceStr(str2);
		cout << str << "\n" << str2 << endl;
	}

	string compressStr(string str) {
		if (str.empty()) {
			return str;
		}

		string ret;
		int index = 0;
		int length = str.length();
		int current = 0;

		while (index < length) {
			current = index;
			while (str[current] == str[index] && index < length) {
				++index;
			}

			ret.append(1, str[current]).append(1, '0' + index - current);
		}

		if (ret.length() < length) {
			return ret;
		}

		return str;
	}

	void compressStrUnitTest() {
		string ret = compressStr("aaaaaaaa");
		cout << "result:\n" << ret.c_str() << endl;
	}

	void setMatrix(vector<vector<int>>& matrix) {
		if (matrix.empty()) {
			return;
		}

		vector<pair<int, int>> zeroCoordinate;
		int rows = matrix.size();
		int cols = matrix[0].size();
		for (int row = 0; row < rows; ++row) {
			for (int col = 0; col < cols; ++col) {
				if (0 == matrix[row][col]) {
					zeroCoordinate.push_back(pair<int,int>(row, col));
				}
			}
		}

		for (int index = 0; index < zeroCoordinate.size(); ++index) {
			int rowIndex  = zeroCoordinate[index].first;
			int colIndex = zeroCoordinate[index].second;
			//row
			for (int col = 0; col < matrix[rowIndex].size(); ++col) {
				matrix[rowIndex][col] = 0;
			}
			//col
			for (int row = 0; row < matrix.size(); ++row) {
				matrix[row][colIndex] = 0;
			}
		}
	}

	ostream& operator<<(ostream& out, vector<vector<int>> vec) {
		for (int row = 0; row < vec.size(); ++row) {
			for (int col = 0; col < vec[row].size(); ++col) {
				out << vec[row][col] << " ";
			}

			out << endl;
		}

		return out;
	}

	void setMatrixUnitTest() {
		vector<vector<int>> matrix = {
			{1, 2, 3, 4, 5, 6},
			{2, 3, 0, 5, 6, 7},
			{3, 5, 7, 8, 0, 1}
		};

		cout << "origin:\n" << matrix;
		setMatrix(matrix);
		cout << "result:\n" << matrix;
	}

}


