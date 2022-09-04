

#include <iostream>
using namespace std;

// dizideki max sayýyý bulamaya yarayan blok
int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

// girilen sayýlara göre sýralama algoritmasýný sayma
void countSort(int arr[], int n, int exp)
{
	int output[n]; // çýkýþ dizisi
	int i, count[10] = { 0 };

	// iþlem sayýsýný sayým sayýsý olarak yapma
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// count[i] dizisini deðiþtirir þimdiki count[i] deðerei gerçketir
	
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// çýkýþ dizisini oluþturma
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// çýkýþ sizisini arr[] kopyalar geçerli basamaða göre sýralanmýþ sayýlarý içerir
 	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

// radis sort sýralamasý yapýlýr n büyüklüðünde
void radixsort(int arr[], int n)
{
	// bildiðimiz sayýlardan en büyügünü bulur
	int m = getMax(arr, n);

	//her yeni indis için sayma iþlemi yapýlýr

	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}

// diziyi yazdýrma fonkisyonu
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}


int main()
{
	int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	//fonksyonlarý çaðýrýrýz
	radixsort(arr, n);
	print(arr, n);
	return 0;
}

