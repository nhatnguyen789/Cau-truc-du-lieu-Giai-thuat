#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
void Input(int arrArrayA[], int &n);
void Output(int arrArrayA[], int n);
int LinearSearch(int arrArrayA[], int n, int x);
int LinearSearch2(int arrArrayA[], int n, int x);
int BinarySearch(int arrArrayA[], int n, int x);
void InterchangeSort(int arrArrayA[], int n);
void SelectSort(int arrArrayA[], int n);
void BubbleSort(int arrArrayA[], int n);
void InsertionSort(int arrArrayA[], int n);
void ShellSort(int arrArrayA[], int n, int h[], int k);
void QuickSort(int arrArrayA[], int left, int right);
void Shift(int arrArrayA[], int l, int r);
void CreateHeap(int arrArrayA[], int n);
void HeapSort(int arrArrayA[], int n);

int main()
{
	int arrArrayA[100],h[50],n,x,k;
	int choice,choice2,result,left,right;
	cout << "\nhow manny element: ";
	cin  >> n;
	Input(arrArrayA, n);
	Output(arrArrayA, n);
	cout << "\nwhat element do you want to find?";
	cin >> x;
	cout << "\nWhich method do you want to use?\n";
	cout << "1.Linear Search " <<  endl;
	cout << "2.Linear Search 2" << endl;
	cout << "3.Binary Search" <<   endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		result = LinearSearch(arrArrayA, n, x);
		if (result == -1)
			cout << "\nNot found!";
		else
			cout << "\nits location is:" << result << endl;
	}
	break;
	case 2:
	{
		result = LinearSearch2(arrArrayA, n, x);
		if (result == -1)
			cout << "\nNot Found!";
		else
			cout << "\n its location is:" << result << endl;
	}
	break;
	case 3:
	{
		result = BinarySearch(arrArrayA, n, x);
		if (result == -1)
			cout << "\nNot Found!";
		else
			cout << "\n its location is:" << result << endl;
	}
	break;
	}
	cout << "\nwhat kind of sort do you want to do?" << endl;
	cout << "1.InterchangeSort" << endl;
	cout << "2.SelectSort " << endl;
	cout << "3.BubbleSort " << endl;
	cout << "4.InsertionSort" << endl;
	cout << "5.ShellSort" << endl;
	cout << "6.QuickSort" << endl;
	cout << "7.HeapSort" << endl;
	cin >> choice2;
	switch (choice2)
	{
	case 1:
	{
		InterchangeSort(arrArrayA, n);
		Output(arrArrayA, n);
	}
	break;
	case 2:
	{
		SelectSort(arrArrayA, n);
		Output(arrArrayA, n);
	}
	break;
	case 3:
	{
		BubbleSort(arrArrayA, n);
		Output(arrArrayA, n);
	}
	break;
	case 4:
	{
		InsertionSort(arrArrayA, n);
		Output(arrArrayA, n);
	}
	break;
	case 5:
	{
		k = 3;
		int h[] = { 5,3,1 };
     	ShellSort(arrArrayA, n, h, k);
		Output(arrArrayA, n);
	}
	break;
	case 6:
	{
		left = 0; right = n - 1;
		QuickSort(arrArrayA, left, right);
		Output(arrArrayA, n);
	}
	break;
	case 7:
	{
		HeapSort(arrArrayA, n);
		//Output(arrArrayA, n);
	}
	break;
	}
	system("pause");
}
void Input(int arrArrayA[], int &n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\n\ta[" << i << "]=";
		cin >> arrArrayA[i];
	}
}
void Output(int arrArrayA[], int n)
{
	cout << "\narray is:\n";
	for (int i = 0; i < n; i++)
	{
		cout << "\t";
		cout << arrArrayA[i];
	}
}
int LinearSearch(int arrArrayA[], int n, int x)
{
	int i = 0;
	while ((i < n) && (arrArrayA[i] != x))
		i++;
	if (i == n)
		return -1;
	else
		return i;
}
int LinearSearch2(int arrArrayA[], int n, int x)
{
	int i = 0;
	arrArrayA[n] = x;
	while (arrArrayA[i] != x)
		i++;
	if (i == n)
		return -1;
	else
		return i;
}
int BinarySearch(int arrArrayA[], int n, int x)
{
	int left = 0, right = n - 1;
	int mid;
	do {
		mid = (left + right) / 2;
		if (x == arrArrayA[mid])
			return mid;
		else if (x < arrArrayA[mid])
			right = mid - 1;
		else
			left = mid + 1;
	} while (left <= right);
	return -1;
}
void Swap(int &a,int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void InterchangeSort(int arrArrayA[], int n)
{
	int i, j;
	for (i = 0; i < n-1; i++)
		for (j = i+1; j < n; j++)
			if (arrArrayA[j] < arrArrayA[i])
				Swap(arrArrayA[i], arrArrayA[j]);
}
void SelectSort(int arrArrayA[], int n)
{
	int min, i, j;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if(arrArrayA[j] < arrArrayA[min])
			min = j;
		}
					   Swap(arrArrayA[min], arrArrayA[i]);
	}
}
void BubbleSort(int arrArrayA[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = n - 1; j > i; j--)
			if (arrArrayA[j] < arrArrayA[j - 1])
				Swap(arrArrayA[j], arrArrayA[j - 1]);
}
void InsertionSort(int arrArrayA[], int n)
{
	int pos, i;
	int x;
	for (i = 1; i < n; i++)
	{
		x = arrArrayA[i]; pos = i - 1;//tìm vị trí chèn x
		while ((pos>=0)&&(arrArrayA[pos]>x))//kết hợp dời chỗ các phần tử sẽ đứng sau x trong dãy mới
		{
			arrArrayA[pos + 1] = arrArrayA[pos];
			pos--;
		}
		arrArrayA[pos + 1] = x;//chèn x vào dãy
	}
}
void ShellSort(int arrArrayA[], int n, int h[], int k)
{
	int step, i, j, x, len;
	for (step = 0; step < k; step++)
	{
		len = h[step];
		for (i = len; i < n; i++)
		{
			x = arrArrayA[i];
			j= i - len;
			while ((x < arrArrayA[j]) && (j >= 0))
			{
				arrArrayA[j + len] = arrArrayA[j];
				j = j - len;
			}
			arrArrayA[j + len] = x;
		}
	}
}

void QuickSort(int arrArrayA[], int left, int right)
{
	int i, j, x;
	x= arrArrayA[(left + right) / 2];
	i = left; j = right;
	do
	{
		while (arrArrayA[i] < x) i++;
		while (arrArrayA[j] > x) j--;
		if (i <= j)
		{
			Swap(arrArrayA[i], arrArrayA[j]);
			i++; j--;
		}
	}while (i <= j);

		if (left < j)
			QuickSort(arrArrayA, left, j);
		if (i < right)
			QuickSort(arrArrayA, i, right);
	
}
void Shift(int arrArrayA[], int l, int r)
{
	int x, i, j;
	i = l;
	j = 2 * i + 1;
	x = arrArrayA[i];
	while (j <= r)
	{
		if (j < r)
			if (arrArrayA[j] < arrArrayA[j + 1])
				j++;
		if (arrArrayA[j] <= x) return;
		else
		{
			arrArrayA[i] = arrArrayA[j];
			arrArrayA[j] = x;
			i = j;
			j = 2 * i + 1;
			x = arrArrayA[i];
		}
	}
}
void CreateHeap(int arrArrayA[], int n)
{
	int l;
	l = (n / 2) - 1;
	while (l >= 0);
	{
		Shift(arrArrayA, l, n - 1);
		l = l - 1;
	}
}
void HeapSort(int arrArrayA[], int n)
{
	int r;
	CreateHeap(arrArrayA, n);
	r = n - 1;
	while (r > 0)
	{
		Swap(arrArrayA[0], arrArrayA[r]);
		r--;
		if (r > 0)
			Shift(arrArrayA, 0, r);
		Output(arrArrayA, n);
	}
}