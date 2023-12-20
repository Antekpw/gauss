#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    /**
  	 * Tutaj należy umieścić właściwą implemntację.
		 */
int eliminate(Matrix *mat, Matrix *b){
    /**
  	 * Tutaj należy umieścić właściwą implemntację.
		 */
	double wsp;
	for(int i=0; i<mat->r-1; i++)
	{
		for(int j=i+1; j<mat->r; j++)
		{
		if(mat->data[i][i]==0) return 1;       
			wsp = mat->data[j][i] / mat->data[i][i];
		for(int k=i; k<mat->c; k++)
		mat->data[j][k] -=wsp * mat->data[i][k]; 
		b->data[j][0] -= wsp * b->data[i][0]; 
		}
	
		}

		return 0;
}

