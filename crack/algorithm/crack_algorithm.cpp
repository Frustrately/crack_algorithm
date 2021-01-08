#include "crack_algorithm.h"
#include <iostream>
#include <stack>
#include <map>
using namespace std;

namespace {
	std::map<wchar_t, wchar_t> MapBracket = {
		{L'(', L')'},
		{L'[', L']'},
		{L'{', L'}'}
	};
};

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
	
	//这个是最蠢的方法，直接O(n^2) 逐个做字符串检查
	bool isCircleStr(std::string str1, std::string str2) {
		if (str1.length() != str2.length()) {
			return false;
		}

		for (int cursor = 0; cursor < str1.length(); ++cursor) {
			int cmpIndex = cursor;
			for (int index = 0; index < str2.length(); ++index) {
				if (str1[cmpIndex] != str2[index]) {
					break;
				}

				cmpIndex = (cmpIndex + 1) % str1.length();
				if (index == str2.length() - 1) {
					return true;
				}
			}
		}

		return false;
	}

	//直接将其中一个字符串拼接两遍，若另外一个字符串为其子串，则为循环的到的结果
	bool isCircleStr2(std::string str1, std::string str2) {
		if (str1.length() != str2.length()) {
			return false;
		}

		std::string strTemp;
		strTemp.append(str1);
		strTemp.append(str1);
		return std::string::npos != strTemp.find(str2);
	}

	bool isPairBracket(wchar_t leftBracket, wchar_t rightBracket) {
		auto itor = MapBracket.find(leftBracket);
		if (itor == MapBracket.end()) {
			return false;
		}

		return rightBracket == itor->second;
	}

	bool validBrackets(std::wstring strTest) {
		std::stack<wchar_t> checkStack;
		int length = strTest.length();
		for (int index = 0; index < length; ++index) {
			if (checkStack.empty()) {
				checkStack.push(strTest[index]);
				continue;
			} 

			wchar_t lastBracket = checkStack.top();
			if (isPairBracket(lastBracket, strTest[index])) {
				checkStack.pop();
			} else {
				checkStack.push(strTest[index]);
			}
		}

		return checkStack.empty();
	}

	void isCircleStrUnitTest() {
		//"waterbottle", "erbottlewat"
		bool ret = isCircleStr2("aacefba", "efbaaoc");
		cout << "isCircleStr ret:" << ret << endl;
	}

	void validBracketTest() {
		std::wstring strTest = L"{[()]}{}[]()((([()])))";
		bool ret = validBrackets(strTest);
		wcout << strTest.c_str() << ", result : " << ret << endl;
	}


	template<typename T>
	ostream& operator<<(ostream& out, ListNode<T>* pHead) {
		if (nullptr == pHead) {
			return out;
		}

		ListNode<T>* pNode = pHead;
		while (nullptr != pNode) {
			out << " " <<pNode->val;
			pNode = pNode->pNext;
		}

		return out;
	}

	//使用了O(n^2)的时间复杂度，挨个遍历。这里可以使用set来存储数据，用空间换时间
	template<typename T>
	void listDeduplication(ListNode<T>* pNode) {
		ListNode<T>* pCursor = pNode;
		while (nullptr != pCursor) {
			ListNode<T>* pPreCmpNode = pCursor;
			while (nullptr != pPreCmpNode->pNext) {
				if (pPreCmpNode->pNext->val == pCursor->val) {
					ListNode<T>* pRemoveNode = pPreCmpNode->pNext;
					pPreCmpNode->pNext = pRemoveNode->pNext;
					delete pRemoveNode;
				} else {
					pPreCmpNode = pPreCmpNode->pNext;
				}
			}

			pCursor = pCursor->pNext;
		}
	}

	void listDeduplicationUnitTest() {
		ListNode<int>* pNode5 = new ListNode<int>(1, nullptr);
		ListNode<int>* pNode4 = new ListNode<int>(3, pNode5);
		ListNode<int>* pNode3 = new ListNode<int>(2, pNode4);
		ListNode<int>* pNode2 = new ListNode<int>(1, pNode3);
		ListNode<int>* pNode1 = new ListNode<int>(1, pNode2);
		ListNode<int>* pNodeHead = new ListNode<int>(2, pNode1);
		listDeduplication(pNodeHead);

		ListNode<int>* pCurNode = pNodeHead;
		while (nullptr != pCurNode) {
			cout << "node:" << pCurNode->val << endl;
			pCurNode = pCurNode->pNext;
		}
	}

	template<typename T>
	ListNode<T>* reciprocalIndex(ListNode<T>* pHead, int count) {
		ListNode<T>* pTarget = pHead;
		ListNode<T>* pCursor = pHead;
		while (nullptr != pCursor && count > 0) {
			--count;
			pCursor = pCursor->pNext;
		}

		if (count > 0) {
			return nullptr;
		}

		while (nullptr != pCursor) {
			pCursor = pCursor->pNext;
			pTarget = pTarget->pNext;
		}

		return pTarget;
	}

	void reciprocalIndexUnitTest() {
		ListNode<int>* pNode5 = new ListNode<int>(5, nullptr);
		ListNode<int>* pNode4 = new ListNode<int>(4, pNode5);
		ListNode<int>* pNode3 = new ListNode<int>(3, pNode4);
		ListNode<int>* pNode2 = new ListNode<int>(2, pNode3);
		ListNode<int>* pNode1 = new ListNode<int>(1, pNode2);
		ListNode<int>* pNodeHead = new ListNode<int>(0, pNode1);

		ListNode<int>* pCurNode = pNodeHead;
		while (nullptr != pCurNode) {
			cout << "node:" << pCurNode->val << endl;
			pCurNode = pCurNode->pNext;
		}

		int count = 5;
		auto node = reciprocalIndex(pNodeHead, count);
		if (nullptr != node) {
			cout << "reciprocal " << count << ", ret : " << node->val << endl;
		}
	}

	//小于指定分割值的结点将被插入到头部。也可以将链表中的值按照与给定值的大小分割成两部分，然后再进行合并。
	template<typename T>
	void splitList(ListNode<T>** pHead, T splitValue) {
		ListNode<T>* pCursor = *pHead;
		ListNode<T>* pTempNode = nullptr;
		while (nullptr != pCursor && nullptr != pCursor->pNext) {
			if (pCursor->pNext->val < splitValue) {
				pTempNode = pCursor->pNext;
				pCursor->pNext = pCursor->pNext->pNext;
				pTempNode->pNext = *pHead;
				*pHead = pTempNode;
			}
			pCursor = pCursor->pNext;
		}
	}

	void splitListUnitTest() {
		ListNode<int>* pNode5 = new ListNode<int>(4, nullptr);
		ListNode<int>* pNode4 = new ListNode<int>(12, pNode5);
		ListNode<int>* pNode3 = new ListNode<int>(7, pNode4);
		ListNode<int>* pNode2 = new ListNode<int>(15, pNode3);
		ListNode<int>* pNode1 = new ListNode<int>(1, pNode2);
		ListNode<int>* pNodeHead = new ListNode<int>(10, pNode1);

		cout << pNodeHead;
		splitList(&pNodeHead, 9);
		cout << "\nresult:" << endl;
		cout << pNodeHead;
	}

	template<typename T>
	AssumeQueue<T>::AssumeQueue() {
	}

	template<typename T>
	AssumeQueue<T>::~AssumeQueue() {
		//todo clear list
	}

	template<typename T>
    T AssumeQueue<T>::popNode() {
		if (nullptr == m_pHead) {
			return T();
		}
		
		ListNode<T>* pRemove = m_pHead;
		if (m_pHead == m_pTail) {
			m_pTail = nullptr;
		}

		m_pHead = m_pHead->pNext;
		T ret = pRemove->val;
		delete pRemove;
		return ret;
	}

	template<typename T>
	AssumeQueue<T>::operator QueueContentRef() {
		return m_pHead;
	}

	template<typename T>
	void AssumeQueue<T>::pushNode(T node) {
		ListNode<T>* pNode = new ListNode<T>(node, nullptr);
		if (nullptr != m_pTail) {
			m_pTail->pNext = pNode;
		}

		m_pTail = pNode;
		if (nullptr == m_pHead) {
			m_pHead = pNode;
		}
	}

	void assumeQueueUnitTest() {
		AssumeQueue<int> assumeQueue;
		assumeQueue.pushNode(1);
		assumeQueue.pushNode(2);
		assumeQueue.pushNode(3);
		assumeQueue.pushNode(4);
		assumeQueue.pushNode(5);
		cout << (ListNode<int>*)assumeQueue;

		assumeQueue.popNode();
		assumeQueue.popNode();
		cout << (ListNode<int>*)assumeQueue;
	}

	crack_algorithm::ListNode<int>* addListNumber(ListNode<int>* number1, ListNode<int>* number2) {
		if (nullptr == number1) {
			return number2;
		}

		if (nullptr == number2) {
			return number1;
		}

		int carryNumber = 0, remainderNumber = 0, addResultNumber = 0;
		ListNode<int>* pCursor1 = number1;
		ListNode<int>* pCursor2 = number2;
		ListNode<int>* pRet = nullptr;
		ListNode<int>* pInsert = nullptr;

		while (nullptr != pCursor1) {
			addResultNumber = carryNumber + pCursor1->val;
			if (nullptr != pCursor2) {
				addResultNumber += pCursor2->val;
				pCursor2 = pCursor2->pNext;
			}

			carryNumber = addResultNumber / 10;
			remainderNumber = addResultNumber % 10;
			ListNode<int>* pNode = new ListNode<int>(remainderNumber, nullptr);
			if (nullptr == pRet) {
				pRet = pNode;
				pInsert = pNode;
			}
			else {
				pInsert->pNext = pNode;
				pInsert = pNode;
			}

			if (nullptr == pCursor1->pNext && nullptr != pCursor2) {
				pCursor1 = pCursor2;
				pCursor2 = nullptr;
			}
			else {
				pCursor1 = pCursor1->pNext;
			}
		}

		if (nullptr != pRet && nullptr != pInsert && 0 != carryNumber) {
			pInsert->pNext = new ListNode<int>(carryNumber, nullptr);
		}

		return pRet;
	}

	void addListNumberUnitTest() {
		ListNode<int>* pNode1 = new ListNode<int>(9, nullptr);
		ListNode<int>* pNodeHead = new ListNode<int>(9, pNode1);

		ListNode<int>* pNode21 = new ListNode<int>(7, nullptr);
		ListNode<int>* pNode11 = new ListNode<int>(5, pNode21);
		ListNode<int>* pNodeHead1 = new ListNode<int>(1, pNode11);

		ListNode<int>* pSum = addListNumber(pNodeHead, pNodeHead1);
		cout << pNodeHead << " +" << pNodeHead1 << " =" << pSum;
	}

}


