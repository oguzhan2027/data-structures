

#include <bits/stdc++.h>
#define N 8
using namespace std;


void printSolution(int board[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << " " << board[i][j] << " ";
		printf("\n");
	}
}

/*bu fonksiyon vezirin tahtaya yerleþip yerleþmediðini
 kontrol eder eðer önceden yerleþmisse sadece sol 
 tarafý kontrol ederiz */

bool isSafe(int board[N][N], int row, int col)
{
	int i, j;

	/* satýrýn 
	 tarafýný kontroleder */
	//
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

	/* diyagonal üst  kontrol eder */
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	/*  diyagonal alt kontrol eder */
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}

/* recursive fonksiyon problemi çözmeye yarar */
bool solveNQUtil(int board[N][N], int col)
{
	/*tüm vezirler yerleþmisse true döner */
	if (col >= N)
		return true;

	/* veziri sýra sýra yerleþtirmeye çalýþýr*/
	for (int i = 0; i < N; i++) {
		/* vezirin yerleþitðini kontrol eder[i][col] */
		if (isSafe(board, i, col)) {
			/* vezirin tahtadaki yeri [i][col] */
			board[i][col] = 1;

			/* diðer vezirleri yerleþtirmek için tekrarlanýr */
			if (solveNQUtil(board, col + 1))
				return true;

			/* veziri yerleþtirmek bir çözüme yol açmaz */
			board[i][col] = 0; // BACKTRACK
		}
	}

	/* eger vezir yerleþmezse false döner*/
	return false;
}

/* n vezir probelmini çözen fonksiyon solvenqutil ile probelmi
 çözmeye çalýþýrfalse dönerse vezir yerleþmemiþ demektir diðer
  durumlarda true döner ve yeri iþaretlerbþrden çok yerleþim
   olabilir bu onlardan biri*/

bool solveNQ()
{
	int board[N][N] = { { 0, 0, 0, 0,0, 0, 0, 0 },
						{ 0, 0, 0, 0,0, 0, 0, 0 },
						{ 0, 0, 0, 0,0, 0, 0, 0 },
						{ 0, 0, 0, 0,0, 0, 0, 0 },
						{ 0, 0, 0, 0,0, 0, 0, 0 },
						{ 0, 0, 0, 0,0, 0, 0, 0 },
						{ 0, 0, 0, 0,0, 0, 0, 0 },
						{ 0, 0, 0, 0,0, 0, 0, 0 } };

	if (solveNQUtil(board, 0) == false) {
		cout << "cozumm yok";
		return false;
	}

	printSolution(board);
	return true;
}

// 
int main()
{
	solveNQ();
	return 0;
}



