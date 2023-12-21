#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
	int res;
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;

	if (A == NULL) return -1;
	if (b == NULL) return -2;
	printToScreen(A);
	printToScreen(b);

	res = eliminate(A,b);
// res = 1 macierz osobliwa - dzielenie przez 0
	if(res == 1)
	{
	fprintf(stderr,"Blad, macierz osobliwa - dzielenie przez 0\n");
	return 1;
	}

	x = createMatrix(b->r, 1);
	if (x != NULL) {


/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - bĹ‚Ä…d dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - bĹ‚Ä…d nieprawidĹ‚owych rozmiarĂłw macierzy
 */
		res = backsubst(x,A,b);
if(res == 1)
{
	fprintf(stderr,"BLAD! dzielenie przez zero\n");
	return 1;
}
if(res == 2)
{
	fprintf(stderr,"BLAD! nieprawidlowy rozmiar macierzy\n");
	return 1;
}
		printToScreen(x);
	  freeMatrix(x);
	} else {
					fprintf(stderr,"Blad! Nie moglem utworzyc wektora wynikowego x.\n");
	}

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
