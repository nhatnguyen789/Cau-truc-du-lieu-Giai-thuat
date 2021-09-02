#include<iostream>
using namespace std;

typedef struct tagDnode
{
	int Info;
	struct tagDnode* pPre;
	struct tagDnode *pNext;
}DNode;
typedef struct tagDList
{
	DNode* pHead;
	DNode* pTail;
}DList;
void CreateDList(DList& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
DNode* CreateDnode(int x)
{
	DNode* tam;
	tam = new DNode;
	if (tam == NULL)
	{
		cout << "khong con du bo nho:" << endl;
		exit(1);
	}
	else
	{
		tam->Info = x;
		tam->pNext = NULL;
		tam->pPre = NULL;
		return tam;
	}
}
void AddFirst(DList& l, DNode* tam)
{
	if (l.pHead == NULL)
	{
		l.pHead = tam;
		l.pTail = l.pHead;
	}
	else
	{
		tam->pNext = l.pHead;
		l.pHead->pPre = tam;
		l.pHead = tam;
	}
}
void AddEnd(DList& l, DNode* tam)
{
	if (l.pHead == NULL)
	{
		l.pHead = tam;
		l.pTail = l.pHead;
	}
	else
	{
		tam->pPre = l.pTail;
		l.pTail->pNext = tam;
		l.pTail = tam;
	}
}
void AddLastQ(DList& l, DNode* tam, DNode* q)
{
	DNode* p;
	p = q->pNext;
	if (q != NULL)
	{
		tam->pNext = p;
		tam->pPre = q;
		q->pNext = tam;
		if (p != NULL)
			p->pPre = tam;
		if (q == l.pTail)
			l.pTail = tam;
	}
	else
		AddFirst(l, tam);
}
void AddBeforeQ(DList& l, DNode* tam, DNode* q)
{
	DNode* p;
	p = q->pPre;
	if (q != NULL)
	{
		tam->pNext = q;
		q->pPre = tam;
		tam->pPre = p;
		if (p != NULL)
			p->pNext = tam;
		if (q == l.pHead)
			l.pHead = tam;
	}
	else
		AddEnd(l, tam);
}
void DeleteFirst(DList& l)
{
	DNode* p;
	if (l.pHead != NULL)
	{
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		if (l.pHead == NULL)
			l.pTail = NULL;

		else

			l.pHead->pPre = NULL;

		delete p;
	}

}
void DeleteEnd(DList& l)
{
	DNode* p;
	if (l.pHead != NULL) //tuc xau co hon mot phan tu
	{
		p = l.pTail;
		l.pTail = l.pTail->pPre;
		l.pTail->pNext = NULL;
		delete p;
		if (l.pTail == NULL)

			l.pHead = NULL;

	}
}
void DeleteLastQ(DList& l, DNode* q)
{
	DNode* p;//luu node dung sau node q
	if (q != NULL)
	{
		p = q->pNext;
		if (p != NULL)
		{

			q->pNext = p->pNext;
			if (p == l.pTail)//xoa dung nu't cuoi

				l.pTail = q;

			else //Nut xoa khong phai nut cuoi

				p->pNext->pPre = q;

			delete p;

		}
	}
	else
		DeleteFirst(l);

}
void DeleteBeforeQ(DList& l, DNode* q)
{
	DNode* p;
	if (q != NULL) //tuc ton tai node q
	{
		p = q->pPre;
		if (p != NULL)
		{

			q->pPre = p->pPre;
			if (p == l.pHead)//p la Node dau cua danh sach

				l.pHead = q;

			else //p khong phai la node dau
				p->pPre->pNext = q;

			delete p;

		}
	}
	else
		DeleteEnd(l);
}
int DeleteX(DList& l, int x)
{
	DNode* p;
	DNode* q;
	q = NULL;
	p = l.pHead;
	while (p != NULL)
	{
		if (p->Info == x)
			break;

		q = p;//q la Node co truong Info = x
		p = p->pNext;
	}
	if (p == NULL) return 0;//khong tim thay Node nao co truong Info =x
	if (q != NULL)
		DeleteLastQ(l, q);
	else
		DeleteFirst(l);
	return 1;
}
void Swap(int &x, int &y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}
void DoiChoTrucTiep(DList& l)
{
	DNode* p, * q;
	p = l.pHead;
	while (p != l.pTail)
	{
		q = p->pNext;
		while (q != NULL)
		{

			if (p->Info > q->Info)
				Swap(p->Info,q->Info);
			q = q->pNext;
		}
		p = p->pNext;
	}
}
void PrintList(DList l)
{
	DNode* p;
	p = l.pHead;
	while (p != NULL)
	{
		cout << "\t" << p->Info;
		p = p->pNext;
	}
}
DNode* Search(DList l, int x)
{
	DNode* p;
	p = l.pHead;
	while ((p != NULL) && (p->Info != x))
		p = p->pNext;
	return p;
}
void Menu()
{
	cout << "\nWhich method do you want to use?" << endl;
	cout << "1.Print list!" << endl;
	cout << "2.Add Head!" << endl;
	cout << "3.Add Tail!" << endl;
	cout << "4.Add after element Q!" << endl;
	cout << "5.Remove Head!" << endl;
	cout << "6.Remove element X:" << endl;
	cout << "7.Remove element after Q:" << endl;
	cout << "8.Searching Node has info equal X" << endl;
	cout << "9.delete end" << endl;
}
void main()
{
	DList l;
	DNode* tam,*q,*p;
	int *n,x,y,choice;
	CreateDList(l);
	do {
		cout << "Input :" << endl;
		cin >> x;
		if (x > 0)
		{
			p =CreateDnode(x);
			AddFirst(l, p);
		}

	} while (x > 0);
	cout << "List have already establish" << endl;
	PrintList(l);
	cout << "\n----------------------------------------------------------------" << endl;
	do
	{
		Menu();
		cout << "what is your choice?" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "List is :" << endl;
			PrintList(l);
		}
		break;
		case 2:
		{
			cout << "Input element which you want to add Head list!" << endl;
			cin >> x;
			p =CreateDnode(x);
			AddFirst(l, p);
			cout << "List after add Head:" << endl;
			PrintList(l);
		}
		break;
		case 3:
		{
			cout << "Input element which you want to add Tail list!" << endl;
			cin >> x;
			p = CreateDnode(x);
			AddEnd(l, p);
			cout << "List after add Tail:" << endl;
			PrintList(l);
		}
		break;
		case 4:
		{
			cout << "Input element which you want to add!" << endl;
			cin >> x;
			p = CreateDnode(x);
			cout << "input element Q: " << endl;
			cin >> y;
			q = Search(l, y);
			AddLastQ(l, p, q);
			cout << "List after Insert:" << endl;
			PrintList(l);
		}
		break;
		case 5:
		{
			DeleteFirst(l);
			cout << "List after Remove Head:" << endl;
			PrintList(l);
		}
		break;
		case 6:
		{
			cout << "Input element which do you want to remove:" << endl;
			cin >> x;
			p = CreateDnode(x);
			DeleteX(l, x);
			cout << "List after Remove X:" << endl;
			PrintList(l);
		}
		break;
		case 7:
		{
			cout << "Input element Q that you want to remove:" << endl;
			cin >> x;
			p = Search(l, x);
			DeleteLastQ(l, p);
			cout << "List after Remove after Q:" << endl;
			PrintList(l);
		}
		break;
		case 8:
		{
			cout << "Input Node has infor equal X:" << endl;
			cin >> x;
			p = Search(l, x);
			if (p == NULL)
			{
				cout << "not Found!" << endl;
			}
			else
			{
				cout << "X element is:" << x;
			}
		}
		break;
		case 9:
		{
			DeleteEnd(l);
			cout << "List after Remove Head:" << endl;
			PrintList(l);
		}
		break;
		default:
			cout << "Please try again!!!" << endl;
			break;
		}
	} while (choice != 0);
	system("pause");
}
