#include<iostream>
using namespace std;
const int Max = 100;
typedef struct tagstack
{
	int a[Max];
	int t;
}stack;
void CreateStack(stack& s)
{
	s.t = -1;
}
int IsEmpty(stack& s)
{
	if (s.t == -1)
		return 1;
	else
		return 0;
}
int IsFull(stack& s)
{
	if (s.t == Max)
		return 1;
	else
		return 0;
}
int Push(stack& s, int x)
{
	if (IsFull(s) == 0)
	{
		s.t++;
		s.a[s.t] = x;
		return 1;
	}
	else
		return 0;	
}
int Pop(stack& s, int& x)
{
	if (IsEmpty(s) == 0)
	{
		x = s.a[s.t];
		s.t--;
		return 1;
	}
	else
		return 0;
}
int main()
{
	stack s;
	int i,x, tv;
	CreateStack(s);
	for (i = 2; i <= 5; i++)
	{
		cout << i << " ";
		Push(s, i);
	}
	tv = Pop(s, x);
	if (tv == 1)
		cout << "\nThe value is taken from stack: " << x << endl;
}
