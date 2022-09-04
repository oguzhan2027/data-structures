

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

/*bu fonksiyon vezirin tahtaya yerle�ip yerle�medi�ini
 kontrol eder e�er �nceden yerle�misse sadece sol 
 taraf� kontrol ederiz */

bool isSafe(int board[N][N], int row, int col)
{
	int i, j;

	/* sat�r�n 
	 taraf�n� kontroleder */
	//
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

	/* diyagonal �st  kontrol eder */
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	/*  diyagonal alt kontrol eder */
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}

/* recursive fonksiyon problemi ��zmeye yarar */
bool solveNQUtil(int board[N][N], int col)
{
	/*t�m vezirler yerle�misse true d�ner */
	if (col >= N)
		return true;

	/* veziri s�ra s�ra yerle�tirmeye �al���r*/
	for (int i = 0; i < N; i++) {
		/* vezirin yerle�it�ini kontrol eder[i][col] */
		if (isSafe(board, i, col)) {
			/* vezirin tahtadaki yeri [i][col] */
			board[i][col] = 1;

			/* di�er vezirleri yerle�tirmek i�in tekrarlan�r */
			if (solveNQUtil(board, col + 1))
				return true;

			/* veziri yerle�tirmek bir ��z�me yol a�maz */
			board[i][col] = 0; // BACKTRACK
		}
	}

	/* eger vezir yerle�mezse false d�ner*/
	return false;
}

/* n vezir probelmini ��zen fonksiyon solvenqutil ile probelmi
 ��zmeye �al���rfalse d�nerse vezir yerle�memi� demektir di�er
  durumlarda true d�ner ve yeri i�aretlerb�rden �ok yerle�im
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



