

#include <iostream>
using namespace std;

// dizideki max say�y� bulamaya yarayan blok
int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

// girilen say�lara g�re s�ralama algoritmas�n� sayma
void countSort(int arr[], int n, int exp)
{
	int output[n]; // ��k�� dizisi
	int i, count[10] = { 0 };

	// i�lem say�s�n� say�m say�s� olarak yapma
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// count[i] dizisini de�i�tirir �imdiki count[i] de�erei ger�ketir
	
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// ��k�� dizisini olu�turma
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// ��k�� sizisini arr[] kopyalar ge�erli basama�a g�re s�ralanm�� say�lar� i�erir
 	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

// radis sort s�ralamas� yap�l�r n b�y�kl���nde
void radixsort(int arr[], int n)
{
	// bildi�imiz say�lardan en b�y�g�n� bulur
	int m = getMax(arr, n);

	//her yeni indis i�in sayma i�lemi yap�l�r

	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}

// diziyi yazd�rma fonkisyonu
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}


int main()
{
	int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	//fonksyonlar� �a��r�r�z
	radixsort(arr, n);
	print(arr, n);
	return 0;
}

