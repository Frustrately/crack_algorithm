#pragma once
#include <string>
#include <vector>
#include <list>
using namespace std;

namespace crack_algorithm {

	//字符串
	void replaceStr(char* str);
	void replaceStrUnitTest();

	string compressStr(string str);
	void compressStrUnitTest();

	void setMatrix(vector<vector<int>>& matrix);
	void setMatrixUnitTest();

	bool isCircleStr(std::string str1, std::string str2);
	bool isCircleStr2(std::string str1, std::string str2);
	void isCircleStrUnitTest();

	//括号匹配
	void validBracketTest();

	//链表
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

	ListNode<int>* findListCircleEntrance(ListNode<int>* number1);
	ListNode<int>* findListCircleEntrance2(ListNode<int>* pList);
	void findListCircleEntranceUnitTest();

	/*
	* 确认是否为中心对称链表（回文链表）
	* 核心思路从中心出发对称遍历比较值是否相同
	* 1.直接生成新的翻转链表，与原内容进行比较即可得到结果，比较暴力
	* 2.找到中心点，同时使用中心的左侧的数据与右侧的数据进行对称比较。
	*   2.1 可以使用快慢指针找到中心的位置，注意奇偶的判断。
	*   2.2 内容的比较可以借助栈结构来完成（递归or循环）
	* 3.以上方法的时间和空间复杂度都为O(n),其实可以借助原有的链表内容进行处理，优化效率
	*/

	template<typename T>
	ListNode<T>* reverseList(ListNode<T>* pHead);

	//后序遍历
	template<typename T>
	void traverseList(ListNode<T>* pHead);

	bool isSymmetryListVer1(ListNode<int>* pHead);
	void isSymmetryListUnitTest();
};