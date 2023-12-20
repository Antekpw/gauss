#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
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
		if(mat->data[i][i]==0) {
			return 1;
		}
		int max = i;
		if(mat->data[j][i] > mat->data[max][i]){
			max = j;
		}
		if(max!=i){
			double *temp = mat->data[i];
			mat->data[i] = mat->data[max];
			mat->data[max] = temp;
			double b2 = b->data[max][0];
			b->data[max][0] = b->data[i][0];
			b->data[i][0] = b2;
		}	
			wsp = mat->data[j][i] / mat->data[i][i];
		for(int k=i; k<mat->c; k++)
		mat->data[j][k] -=wsp * mat->data[i][k]; 
		b->data[j][0] -= wsp * b->data[i][0]; 
		}
	
		}

		return 0;
}

