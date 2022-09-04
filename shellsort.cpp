
#include <iostream>
using namespace std;


int shellSort(int arr[], int n)
{
	
	for (int gap = n/2; gap > 0; gap /= 2)
	{
	
		
		for (int i = gap; i < n; i += 1)
		{
		
			int temp = arr[i];

			
			int j;			
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];
			
			
			arr[j] = temp;
		}
	}
	return 0;
}

void printArray(int arr[], int n)
{
	for (int i=0; i<n; i++)
		cout << arr[i] << " ";
}

int main()
{
	int arr[] = {7, 3, 5, 8, 2, 9, 4, 15, 6}, i;
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << "Siralanmadan onceki hali: \n";
	printArray(arr, n);

	shellSort(arr, n);

	cout << "\nSiralandiktan sonraki hali: \n";
	printArray(arr, n);

	return 0;
}

