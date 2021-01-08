#pragma once
#include <string>
#include <vector>
#include <list>
using namespace std;

namespace crack_algorithm {

	//�ַ���
	void replaceStr(char* str);
	void replaceStrUnitTest();

	string compressStr(string str);
	void compressStrUnitTest();

	void setMatrix(vector<vector<int>>& matrix);
	void setMatrixUnitTest();

	bool isCircleStr(std::string str1, std::string str2);
	bool isCircleStr2(std::string str1, std::string str2);
	void isCircleStrUnitTest();

	//����ƥ��
	void validBracketTest();

	//����
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
	* ȷ���Ƿ�Ϊ���ĶԳ�������������
	* ����˼·�����ĳ����ԳƱ����Ƚ�ֵ�Ƿ���ͬ
	* 1.ֱ�������µķ�ת������ԭ���ݽ��бȽϼ��ɵõ�������Ƚϱ���
	* 2.�ҵ����ĵ㣬ͬʱʹ�����ĵ������������Ҳ�����ݽ��жԳƱȽϡ�
	*   2.1 ����ʹ�ÿ���ָ���ҵ����ĵ�λ�ã�ע����ż���жϡ�
	*   2.2 ���ݵıȽϿ��Խ���ջ�ṹ����ɣ��ݹ�orѭ����
	* 3.���Ϸ�����ʱ��Ϳռ临�Ӷȶ�ΪO(n),��ʵ���Խ���ԭ�е��������ݽ��д����Ż�Ч��
	*/

	template<typename T>
	ListNode<T>* reverseList(ListNode<T>* pHead);

	//�������
	template<typename T>
	void traverseList(ListNode<T>* pHead);

	bool isSymmetryListVer1(ListNode<int>* pHead);
	void isSymmetryListUnitTest();
};