#pragma once
#include <string>
#include <vector>
#include <list>
using namespace std;

namespace crack_algorithm {

	//×Ö·û´®
	void replaceStr(char* str);
	void replaceStrUnitTest();

	string compressStr(string str);
	void compressStrUnitTest();

	void setMatrix(vector<vector<int>>& matrix);
	void setMatrixUnitTest();

	bool isCircleStr(std::string str1, std::string str2);
	bool isCircleStr2(std::string str1, std::string str2);
	void isCircleStrUnitTest();

	//À¨ºÅÆ¥Åä
	void validBracketTest();

	//Á´±í
	template<typename T>
	struct ListNode {
		T val;
		ListNode* pNext;

		ListNode() {}
		ListNode(T val, ListNode* next) : val(val), pNext(next) {}
	};

	template<typename T>
	void listDeduplication(ListNode<T>* pNode);
	void listDeduplicationUnitTest();

	template<typename T>
	ListNode<T>* reciprocalIndex(ListNode<T>* pHead, int count);
	void reciprocalIndexUnitTest();

	template<typename T>
	void splitList(ListNode<T>* pHead, T splitValue);
	void splitListUnitTest();

	template<typename T>
	class AssumeQueue{
	public:
		AssumeQueue();
		~AssumeQueue();
		void pushNode(T value);
		T popNode();

		typedef ListNode<T>* QueueContentRef;
		operator QueueContentRef();
		
	private:
		ListNode<T> *m_pHead = nullptr;
		ListNode<T> *m_pTail = nullptr;
	};

	void assumeQueueUnitTest();

	ListNode<int>* addListNumber(ListNode<int>* number1, ListNode<int>* number2);
	void addListNumberUnitTest();
};