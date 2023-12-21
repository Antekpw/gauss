#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){


    	/**
  	 * Tutaj należy umieścić właściwą implemntację.
		 */
	double wsp;
/*		for(int i=0; i<mat->r; i++){
		printf("\n");
			for(int j=0; j<mat->r; j++){
		printf("%g->",mat->data[i][j]);
		}}
		printf("\nmaciez b\n");
		for(int i=0; i< b->r; i++)printf("%g\n", b->data[i][0]);
		
*/		double max;
		int maxid;
		
			double *pol = malloc(sizeof(*pol)*mat->r);
			double polb;
		for(int i=0; i<mat->r-1; i++)
		{	max = mat->data[i][i];
			maxid = i;
			for(int k =i+1; k<mat->r; k++)
			{
				if(mat->data[k][i]>max)
				{max = mat->data[k][i];
					maxid = k; 
				}
			}
			if(maxid!=i)
			{ polb = b->data[i][0];
				b->data[i][0] = b->data[maxid][0];
				b->data[maxid][0] = polb;
			pol = mat->data[i];
			mat->data[i] = mat->data[maxid];
			mat->data[maxid] = pol;
			
			}for(int j=i+1; j<mat->r; j++)
		{
		if(mat->data[i][i]==0) return 1;       
			wsp = mat->data[j][i] / mat->data[i][i];
		for(int k=i; k<mat->c; k++)
		mat->data[j][k] -=wsp * mat->data[i][k]; 
		b->data[j][0] -= wsp * b->data[i][0]; 
		}
		
		}
		
/*	printf("PO GAUSSSSIEEEEEE");	
		for(int i=0; i<mat->r; i++){
		printf("\n");
			for(int j=0; j<mat->r; j++){
		printf("%g->",mat->data[i][j]);
		}}
		printf("\nmaciez b\n");
		for(int i=0;i<b->r; i++)printf("%g\n", b->data[i][0]);
	*/	
	return 0;
}

