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
	* �ô������ַ����ڵ�λ���ܹ�һ�ε�λ
	* �������������Ķ���������̫��
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
	
	char* compressStr(char* str) {
		if (nullptr == str) {
			return str;
		}

		return nullptr;
	}

	void compressStrUnitTest() {
	}

}


