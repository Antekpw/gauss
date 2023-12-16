#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - bĹ‚Ä…d dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - bĹ‚Ä…d nieprawidĹ‚owych rozmiarĂłw macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
				/**
				 * Tutaj naleĹĽy umieĹ›ciÄ‡ wĹ‚aĹ›ciwÄ… implemntacjÄ™.
				 */

				/* To ponizej jest przepisaniem b do x. Nalezy to poprawic! */
				if(mat->r != mat->c) return 2;
				if(mat->c != b->r)return 2;
				if(b->c != 1) return 2;
				

				//if(mat->r != b->r) return 2;
			//	if(mat->r == mat->c){
				for(int i=mat->r-1; i>=0; i--)
				{
					x->data[i][0] = b->data[i][0];
				for(int j=mat->c-1; j>i; j--)
				       x->data[i][0] -=x->data[j][0]*mat->data[i][j];
			if(mat->data[i][i]==0) return 1;	
				x->data[i][0] /= mat->data[i][i];
				}
				
				
				
				
			//	int i;
			//	for (i =0; i < x->r; i++) {
			//					x->data[i][0] = b->data[i][0];
			//	}

				return 0;
}


