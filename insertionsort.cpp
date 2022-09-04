

#include <bits/stdc++.h>
using namespace std;


void insertionSort(int arr[], int n)
{
	int i, key, j;
	int c = 0;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
		c++;
	}
	cout<<"calisma sayisi = "<<c;
	cout<<"\n";
}


void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}


int main()
{
	int arr[] = { 2, 3, 4, 5, 6, 7, 8, 9, 15 };
	int N = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, N);
	printArray(arr, N);

	return 0;
}


