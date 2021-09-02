#include<iostream>
#include<queue>
#include<stack>
#include<string>
using namespace std;

int main()
{
	queue<char> Queue;
	stack<char> Stack;
	string S;
	int i, j = 0,count,choice;
	cout << "Input string that you want to check Palindrome:" << endl;
	getline(cin, S);
	count = S.length();
	cout << "choose the way to check:" << endl;
	cout << "1.using Queue" << endl;
	cout << "2.using Stack" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		for (i = count - 1; i >= (count / 2); i--)
			Queue.push(S[i]);
			for (i = 0; i < (count / 2); i++)
			{
				if (S[i] != Queue.front())
					break;
			Queue.pop();
		    }
		break;
	}
	case 2:
	{
		for (i = (count / 2); i < count; i++)
			Stack.push(S[i]);
		for (i = 0; i < (count / 2); i++)
		{
			if (S[i] != Stack.top())
				break;
			Stack.pop();
		}
		break;
	}
	default:
	{
		break;
	}
	}
	if (i == (count / 2))
		cout << "S is Palindrome String:" << endl;
	else
		cout << "Not a Polindrome String:" << endl;
	system("pause");
	return 0;
}
