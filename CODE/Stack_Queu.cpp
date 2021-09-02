#include<iostream>
#include<conio.h>
using namespace std;
const int Max = 100;

typedef struct tagNode
{
	int number;
	tagNode* pNext;
}NODE;
typedef struct tagList
{
	NODE* pHead;
	NODE* pTail;
}LIST;
void CreateStack(LIST& S)
{
	S.pHead = NULL;
	S.pTail = NULL;
}
NODE* CreateNode(int x)		
{
	NODE* p;
	p = new NODE;
	if (p == NULL)
		exit(1);
	p->number = x;
	p->pNext = NULL;
	return p;
}
int IsEmpty(LIST& s)
{
	if (s.pHead == NULL)
		return 1;
	else
		return 0;
}
void Push(LIST& s, NODE* Temp)
{
	if (s.pHead == NULL)
	{
		s.pHead = Temp;
		s.pTail = Temp;
	}
	else
	{
		Temp->pNext = s.pHead;
		s.pHead = Temp;
	}
}
int Pop(LIST& s, int& Trave)
{
	NODE* p;
	if (IsEmpty(s) != 1)
	{
		p = s.pHead;
		Trave = p->number;
		s.pHead = s.pHead->pNext;
		if (s.pHead == NULL)
			s.pTail = NULL;
		delete p;
		return 1;
	}
	return 0;
}
int main()
{
	LIST s;
	int x, tv, i;
	NODE* p;
	CreateStack(s);
	for (i = 2; i <= 5; i++)
	{
		p = CreateNode(i);
		Push(s, p);
		cout << i << " ";
	}
	tv = Pop(s,x);
	if (tv == 1)
		cout << "\nThe value's taken from STACK : " << x << endl;
}