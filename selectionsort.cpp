
#include <bits/stdc++.h>
using namespace std;


void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;
	int c = 0;


	for (i = 0; i < n-1; i++)
	{
	
	
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_idx])
			min_idx = j;

		
		if(min_idx!=i)
			swap(&arr[min_idx], &arr[i]);
		c++;
	}
	cout<<"calisma sayisi = "<<c;
	cout<<"\n";
}


void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}


int main()
{
	int arr[] = { 2, 3, 4, 5, 6, 7, 8, 9, 15 };
	int n = sizeof(arr)/sizeof(arr[0]);
	selectionSort(arr, n);
	
	printArray(arr, n);
	return 0;
}
// This is code is contributed by rathbhupendra

