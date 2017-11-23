#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
string store[5000009];

void QuickSort(string *list, int left, int right)
{
	if (left < right)
	{
		int i = left;
		int j = right + 1;
		string pivot = list[left];
		do{
			do i++; while (list[i] < pivot && i < right);
			do j--; while (list[j] > pivot);
			if (i < j) swap(list[i], list[j]);
		} while (i < j);
			swap(list[left], list[j]);

			QuickSort(list, left, j - 1);
			QuickSort(list, j + 1, right);
	}
}
int main(void)
{
	string getS;
	string *temp;
//	string store[5000009];
	int i = 0;
	while (1)
	{
		if(cin.eof())
			break;
		getline(cin, store[i]);
		i++;
	}

	QuickSort(store, 0, i-2);
	for (int j = 0; j < i-1; j++)
	{
		cout << store[j] << endl;
	}
    
	return 0;
}
