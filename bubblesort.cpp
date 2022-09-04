
#include <bits/stdc++.h>
using namespace std;


void bubbleSort(int arr[], int n)
{
	int i, j;
	int c = 0;
	for (i = 0; i < n - 1; i++){
	
		for (j = 0; j < n - i - 1; j++){
				if (arr[j] > arr[j + 1])
					swap(arr[j], arr[j + 1]);
		}
		c++;	
	}
	cout<<"calisma sayisi = "<<c;
	cout<<"\n";
	
}


void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}


int main()
{
	int arr[] = { 2, 3, 4, 5, 6, 7, 8, 9, 15 };
	int N = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, N);
	printArray(arr, N);
	return 0;
}


