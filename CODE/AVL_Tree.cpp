#include <iostream>
using namespace std;
#define Left_HIGHER -1 
#define EQUAL_HEIGHT 0 
#define Right_HIGHER 1 
typedef struct tagAVLNode
{
	char balanceFactor;
	int Value;
	struct tagAVLNode* pLeft;
	struct tagAVLNode* pRight;
}AVLNode;
typedef AVLNode* AVLTree;
void CreateAVLTree(AVLTree& avlTREE)
{
	avlTREE = NULL;
}

AVLNode* CreateAVLNode(int x)
{
	AVLNode* p;
	p = new AVLNode;
	if (p == NULL)
		exit(1);
	else
	{
		p->Value = x;
		p->pLeft = NULL;
		p->pRight = NULL;
	}
	return p;
}

int InsertAVLNode(AVLTree& avlTREE, int X)
{
	if (avlTREE)
	{
		if (avlTREE->Value == X)
			return 0;
		if (avlTREE->Value > X)
			return InsertAVLNode(avlTREE->pLeft, X);
		else
			return InsertAVLNode(avlTREE->pRight, X);
	}
	avlTREE = new AVLNode;
	if (!avlTREE)
		return -1;
	avlTREE->Value = X;
	avlTREE->pLeft = avlTREE->pRight = NULL;
	return -1;
}

void Left_Left(AVLTree& avlTREE)
{
	AVLNode* avlTREE1 = avlTREE->pLeft;
	avlTREE->pLeft = avlTREE1->pRight;
	avlTREE1->pRight = avlTREE;
	switch (avlTREE1->balanceFactor)
	{
	case Left_HIGHER: avlTREE->balanceFactor = EQUAL_HEIGHT;
		avlTREE1->balanceFactor = EQUAL_HEIGHT;
		break;
	case EQUAL_HEIGHT: avlTREE->balanceFactor = Left_HIGHER;
		avlTREE1->balanceFactor = Right_HIGHER;
		break;
	}
	avlTREE = avlTREE1;
}

void Left_Right(AVLTree& avlTREE)
{
	AVLNode* avlTREE1 = avlTREE->pLeft;
	AVLNode* avlTREE2 = avlTREE1->pRight;
	avlTREE->pLeft = avlTREE2->pRight;
	avlTREE2->pRight = avlTREE;
	avlTREE1->pRight = avlTREE2->pLeft;
	avlTREE2->pLeft = avlTREE1;
	switch (avlTREE2->balanceFactor)
	{
	case Left_HIGHER: avlTREE->balanceFactor = Right_HIGHER;
		avlTREE1->balanceFactor = EQUAL_HEIGHT;
		break;
	case EQUAL_HEIGHT: avlTREE->balanceFactor = EQUAL_HEIGHT;
		avlTREE1->balanceFactor = EQUAL_HEIGHT;
		break;
	case Right_HIGHER: avlTREE->balanceFactor = EQUAL_HEIGHT;
		avlTREE1->balanceFactor = Left_HIGHER;
		break;
	}
	avlTREE2->balanceFactor = EQUAL_HEIGHT;
	avlTREE = avlTREE2;
}

void Right_Right(AVLTree& avlTREE)
{
	AVLNode* avlTREE1 = avlTREE->pRight;
	avlTREE->pRight = avlTREE1->pLeft;
	avlTREE1->pLeft = avlTREE;
	switch (avlTREE1->balanceFactor)
	{
	case Right_HIGHER: avlTREE->balanceFactor = EQUAL_HEIGHT;
		avlTREE->balanceFactor = EQUAL_HEIGHT;
		break;
	case EQUAL_HEIGHT: avlTREE->balanceFactor = Right_HIGHER;
		avlTREE1->balanceFactor = Left_HIGHER;
		break;
	}
	avlTREE = avlTREE1;
}

void Right_Left(AVLTree& avlTREE)
{
	AVLNode* avlTREE1 = avlTREE->pRight;
	AVLNode* avlTREE2 = avlTREE1->pLeft;
	avlTREE->pRight = avlTREE2->pLeft;
	avlTREE2->pLeft = avlTREE;
	avlTREE1->pLeft = avlTREE2->pRight;
	avlTREE2->pRight = avlTREE1;
	switch (avlTREE2->balanceFactor)
	{
	case Right_HIGHER: avlTREE->balanceFactor = Left_HIGHER;
		avlTREE1->balanceFactor = EQUAL_HEIGHT;
		break;
	case EQUAL_HEIGHT: avlTREE->balanceFactor = EQUAL_HEIGHT;
		avlTREE1->balanceFactor = EQUAL_HEIGHT;
		break;
	case Left_HIGHER: avlTREE->balanceFactor = EQUAL_HEIGHT;
		avlTREE1->balanceFactor = Right_HIGHER;
		break;
	}
	avlTREE2->balanceFactor = EQUAL_HEIGHT;
	avlTREE = avlTREE2;
}

int balanceLeft(AVLTree& avlTREE)
{
	AVLNode* avlTREE1 = avlTREE->pLeft;
	switch (avlTREE1->balanceFactor)
	{
	case Left_HIGHER:
		Left_Left(avlTREE);
		return 2;
	case EQUAL_HEIGHT:
		Left_Left(avlTREE);
		return 1;
	case Right_HIGHER:
		Left_Left(avlTREE);
		return 2;
	}
	return 0;
}

int balanceRight(AVLTree& avlTREE)
{
	AVLNode* avlTREE1 = avlTREE->pRight;
	switch (avlTREE->balanceFactor)
	{
	case Left_HIGHER:
		Right_Left(avlTREE);
		return 2;
	case EQUAL_HEIGHT:
		Right_Right(avlTREE);
		return 1;
	case Right_HIGHER:
		Right_Right(avlTREE);
		return 2;
	}
	return 0;
}

int insert(AVLTree& avlTREE, int X)
{
	int i;
	if (avlTREE)
	{
		if (avlTREE->Value == X)
			return 0;
		if (avlTREE->Value > X)
		{
			i = insert(avlTREE->pLeft, X);
			if (i < 2)
				return i;
			switch (avlTREE->balanceFactor)
			{
			case Right_HIGHER:
				avlTREE->balanceFactor = EQUAL_HEIGHT;
				return 1;
			case EQUAL_HEIGHT:
				avlTREE->balanceFactor = Left_HIGHER;
				return 2;
			case Left_HIGHER:
				balanceLeft(avlTREE);
				return 1;
			}
		}
		else
		{
			i = insert(avlTREE->pRight, X);
			if (i < 2)
				return i;
			switch (avlTREE->balanceFactor)
			{
			case Left_HIGHER:
				avlTREE->balanceFactor = EQUAL_HEIGHT;
				return 1;
			case EQUAL_HEIGHT:
				avlTREE->balanceFactor = Right_HIGHER;
				return 2;
			case Right_HIGHER:
				balanceRight(avlTREE);
				return 1;
			}

		}
	}
	avlTREE = new AVLNode;
	if (!avlTREE)
		return -1;
	avlTREE->Value = X;
	avlTREE->pLeft = avlTREE->pRight = NULL;
	return 2;
}

int functionTable()
{
	int choice;
	cout << "1. Add a node." << endl;
	cout << "2. Left_Left. " << endl;
	cout << "3. Left_Right. " << endl;
	cout << "4. Right_Right. " << endl;
	cout << "5. Left_Right. " << endl;
	cout << "___________________" << endl;
	cout << "0. Cancle. " << endl;
	cout << "Your choice: ";
	do
	{
		cin >> choice;
		if (choice < 0 || choice>5)
		{
			cout << "Wrong chosen! Please choose again! " << endl;
			cout << "Your choice: ";
		}
	} while (choice < 0 || choice > 5);
	return choice;
}

int main()
{
	AVLTree avltree;
	int choice;
	CreateAVLTree(avltree);
	do
	{
		cout << endl;
		choice = functionTable();
		switch (choice)
		{
		case 1:
			int p;
			cout << "Enter value of node: ";
			cin >> p;
			InsertAVLNode(avltree, p);
			break;
		case 2:
			cout << "Left_Left - Done!" << endl;
			Left_Left(avltree);
			break;
		case 3:
			cout << "Left_Right - Done!" << endl;
			Left_Right(avltree);
			break;
		case 4:
			cout << "Right_Right - Done!" << endl;
			Right_Right(avltree);
			break;
		case 5:
			cout << "Right_Left - Done!" << endl;
			Right_Left(avltree);
			break;
		case 0:
			exit(0);
		}
	} while (choice != 0);
}