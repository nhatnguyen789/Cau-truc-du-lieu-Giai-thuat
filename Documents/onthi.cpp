#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;
struct Sach
{
	int masosach;
	char tensach[50];
	char tentg[50];
	char nhaxuatban[50];
	int namxuatban;
	int trangthai;
};
typedef struct tagNode
{
	Sach* data;
	struct tagNode* pNext;
}Node;

typedef struct tagList
{
	Node* pHead;
	Node* pTail;
}List;

void CreateList(List& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
Sach* Themsach()
{
	Sach* a = new Sach;
	cout << "ma so sach" << endl;
	cin >> a->masosach;
	cout << "tensach: " << endl;
	cin.ignore();
	gets_s(a->tensach);
	cout << "tentg: " << endl;
	cin.ignore();
	gets_s(a->tentg);
	cout << "ten nha xuat ban: " << endl;
	cin.ignore();
	gets_s(a->nhaxuatban);
	cout << "nam san xuat" << endl;
	cin >> a->namxuatban;
	cout << "trang thai:(1. chua muon,0.da muon)" << endl;
	cin >> a->trangthai;
	if ((a->trangthai == 1)||(a->trangthai == 0))
	{
		return a;
	}
	else 
	{
		cout << "nhap sai ";
		return 0;
	}

}
Node* CreateNode(Sach *a)
{
	Node* p;
	p = new Node;
	if (p == NULL)
		exit(1);
	p->data = a;
	p->pNext = NULL;
	return p;
}

void AddHead(List& l, Node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = l.pHead;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}