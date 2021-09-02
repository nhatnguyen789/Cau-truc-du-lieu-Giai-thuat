/*
< Main >
- Tạo 1 cây rỗng.
- Tạo 1 nút có trường Key bằng X.
1. Thêm 1 nút vào cây nhị phân tìm kiếm.
2. Xoá 1 nút có Key bằng X trên cây.
3. Tìm 1 nút có khoá bằng X trên cây.
< Addition >
1. Số node lá (node bậc 0).
2. Số node có 1 nhánh con (node bậc 1).
3. Số node chỉ có 1 cây con phải.
4. Số node có 1 cây con trái.
5. Số node 2 cây con (node bậc 2).
6. Độ cao của cây.
7. Số node của cây.
8. Các node trên từng mức cây.
9. Độ dài đường đi từ gốc đến node X.
*/

#include <iostream>
using namespace std;

typedef struct tagTNode
{
	int Key;
	struct tagTNode* pLeft;
	struct tagTNode* pRight;
}TNode;

typedef TNode* TREE;

void CreateTree(TREE& T)
{
	T = NULL;
}

TNode* CreateTNode(int x)
{
	TNode* p;
	p = new TNode;
	if (p == NULL)
		exit(1);
	else
	{
		p->Key = x;
		p->pLeft = NULL;
		p->pRight = NULL;
	}
	return p;
}

int insertNode(TREE& T, int X)				//Case 1
{
	if (T)
	{
		if (T->Key == X)return 0;
		if (T->Key > X) return insertNode(T->pLeft, X);
		else
			return insertNode(T->pRight, X);
	}
	T = new TNode;
	if (T == NULL)
		return -1;
	T->Key = X;
	T->pLeft = T->pRight = NULL;
	return 1;
}

TNode* searchNode(TREE Root, int X)			//Case 3
{
	TNode* p = Root;
	while (p != NULL)
	{
		if (p->Key == X) return p;
		else
			if (X < p->Key)p = p->pLeft;
			else
				p = p->pRight;
	}
	return NULL;
}

TNode* SearchTNode(TREE T, int x)
{
	if (T != NULL)
	{
		if (T->Key == x)
			return T;
		else
			if (x > T->Key)
				return SearchTNode(T->pRight, x);
			else
				return SearchTNode(T->pLeft, x);
	}
	return NULL;
}

void Replace(TREE& p, TREE& T)
{
	if (T->pLeft != NULL)
		Replace(p, T->pLeft);
	else
	{
		p->Key = T->Key;
		p = T;
		T = T->pRight;
	}
}

void DeleteNodeX(TREE& T, int x)			//Case 2
{
	if (T != NULL)
	{
		if (T->Key < x)
			DeleteNodeX(T->pRight, x);
		else
		{
			if (T->Key > x)
				DeleteNodeX(T->pLeft, x);
			else
			{
				TNode* p;
				p = T;
				if (T->pLeft == NULL)T = T->pRight;
				else
				{
					if (T->pRight == NULL)T = T->pLeft;
					else
						Replace(p, T->pRight);
				}
				delete p;
			}
		}
	}
	else
		cout << "Not found! " << endl;
}

int CountLeafNode(TREE T)		//Case 4
{
	if (T)
	{
		if (T->pLeft == NULL && T->pRight == NULL)
			return 1;
		else
			return CountLeafNode(T->pLeft) + CountLeafNode(T->pRight);
	}
	else
		return 0;
}

int CountNodeOnOneBranch(TREE T)		//Case 5
{
	if (T)
	{
		if ((T->pLeft == NULL && T->pRight != NULL) || (T->pLeft != NULL && T->pRight == NULL))
			return (1 + CountNodeOnOneBranch(T->pLeft) + CountNodeOnOneBranch(T->pRight));
		return (CountNodeOnOneBranch(T->pLeft) + CountNodeOnOneBranch(T->pRight));
	}
	else
		return 0;
}

int  CountNodeOnLeftBranch(TREE T)		//Case 6
{
	if (T)
		if (T->pLeft != NULL && T->pRight == NULL)
			return 1;
		else
			return CountNodeOnLeftBranch(T->pLeft) + CountNodeOnLeftBranch(T->pRight);
	else
		return 0;
}

int  CountNodeOnRightBranch(TREE T)		//Case 7
{
	if (T)
		if (T->pLeft == NULL && T->pRight != NULL)
			return 1;
		else
			return CountNodeOnRightBranch(T->pLeft) + CountNodeOnRightBranch(T->pRight);
	else
		return 0;
}

int CountNodeOnTwoBranch(TREE T)		//Case 8
{
	if (T)
	{
		if (T->pLeft != NULL && T->pRight != NULL)
			return 1 + CountNodeOnTwoBranch(T->pLeft) + CountNodeOnTwoBranch(T->pRight);
		return CountNodeOnTwoBranch(T->pLeft) + CountNodeOnTwoBranch(T->pRight);
	}
	else
		return 0;
}

int HeighOfTree(TREE T)				//Case 9
{
	int HoLeft, HoRight;
	if (T == NULL)
		return 0;
	else
	{
		HoLeft = HeighOfTree(T->pLeft);
		HoRight = HeighOfTree(T->pRight);
		if (HoRight > HoLeft)
			return HoRight + 1;
		else
			return HoLeft + 1;
	}
}

int CountNodeOnTree(TREE T)			//Case 10
{
	if (T)
		return (CountLeafNode(T) + CountNodeOnOneBranch(T) + CountNodeOnTwoBranch(T));
	else
		return 0;
}

int CountNodeOnEachLevel(TREE T, int Level, int Temp)		//Case 11
{
	if (!T)
		return 0;
	if (Temp == Level)
		return 1;
	return CountNodeOnEachLevel(T->pLeft, Temp + 1, Level) + CountNodeOnEachLevel(T->pRight, Temp + 1, Level);
}

int LengthROOTtoX(TREE T, int X)		//Case 12
{
	int length = 0;
	TNode* p = T;
	while (p != NULL) {
		if (p->Key == X)
			return length - 1;
		else
			if (X < p->Key)
			{
				p = p->pLeft;
				length += 1;
			}
			else
			{
				p = p->pRight;
				length += 1;
			}

	}
	return NULL;
}

int functionTable()
{
	int choice;
	cout << "_____________ BINARY SEARCH TREE _____________" << endl;
	cout << "1. Add 1 node into BST. " << endl;
	cout << "2. Remove 1 node from BST. " << endl;
	cout << "3. Find 1 node on BST. " << endl;
	cout << "4. Count leaf node. " << endl;
	cout << "5. Count node has 1 branch. " << endl;
	cout << "6. Count node has 1 branch (on the right). " << endl;
	cout << "7. Count node has 1 branch (on the left). " << endl;
	cout << "8. Count node has 2 branch. " << endl;
	cout << "9. Heigh of Tree. " << endl;
	cout << "10. Count node on Tree." << endl;
	cout << "11. Show node on each level of Tree. " << endl;
	cout << "12. Length of way from ROOT to node X." << endl;
	cout << "_________________________________________________" << endl;
	cout << "0. Close." << endl;
	cout << "\nYour choice: ";
	do
	{
		cin >> choice;
		if (choice > 12 || choice < 0)
		{
			cout << "Wrong chosen! Please choose again!";
			cout << "\nYour choice:";
		}
	} while (choice > 12 || choice < 0);
	return choice;
}

int main()
{
	TREE BST;
	CreateTree(BST);
	int choice, Value;

	do {
		choice = functionTable();
		switch (choice)
		{
		case 1:
		{
			cout << "Input value: ";
			cin >> Value;
			insertNode(BST, Value);
			break;
		}
		case 2:
		{
			cout << "Input value's node that you want to remove: ";
			cin >> Value;
			DeleteNodeX(BST, Value);
			break;
		}
		case 3:
		{
			cout << "Input value's node that you want to find: ";
			cin >> Value;
			if (searchNode(BST, Value))
				cout << "Found!" << endl;
			else
				cout << "Not found!" << endl;
			break;
		}
		case 4:
		{
			cout << "Number of leaf node on BST: " << CountLeafNode(BST) << endl;
			break;
		}
		case 5:
		{
			cout << "Number of node has ONE branch: " << CountNodeOnOneBranch(BST) << endl;
			break;
		}
		case 6:
		{
			cout << "Number of node has ONE branch ON THE RIGHT: " << CountNodeOnRightBranch(BST) << endl;
			break;
		}
		case 7:
		{
			cout << "Number of node has ONE branch ON THE LEFT: " << CountNodeOnLeftBranch(BST) << endl;
			break;
		}
		case 8:
		{
			cout << "Number of node has TWO branches: " << CountNodeOnTwoBranch(BST) << endl;
			break;
		}
		case 9:
		{
			cout << "Height of BST: " << HeighOfTree(BST) << endl;
			break;
		}
		case 10:
		{
			cout << "Number of node on BST: " << CountNodeOnTree(BST);
			break;
		}
		case 11:
		{
			int i;
			for (i = 0; i < HeighOfTree(BST); i++)
				cout << "Level " << i << " has " << CountNodeOnEachLevel(BST, 0, i) << " node(s)." << endl;
			break;
		}
		case 12:
		{
			cout << "Input value of node X: ";
			cin >> Value;
			cout << "From ROOT, the way to X are: " << LengthROOTtoX(BST, Value) << " node(s)." << endl;
			break;
		}
		}
		cout << endl;
	} while (choice != 0);
}