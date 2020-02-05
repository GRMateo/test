#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include <time.h>

//---------------------------------------------------- TRI PAR SELECTION --------------------------------------------------------------
void swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}


void TriSelection(int *tab, int tabsize) {
	for (int l = 0; l < tabsize-1; l++) {
		for (int i = l+1; i < tabsize; i++) {
			if (*(tab+l)   > *(tab+i)) {
				swap(tab + l, tab + i );
			}
		}
	}
}

int main() {
	int tabsize = 20;
	int tab[20];
	srand(time(NULL));
	for (int i = 0; i < tabsize; i++) {
		tab[i] = rand() % (20 + 1);
	}
	TriSelection(tab, 20);
	for (int i = 0; i < tabsize; i++) {
		printf("%d / ", tab[i]);
	}
	printf("\n");
	system("pause");
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------
														TRI PAR INSERTION SEQUENTIEL
---------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*void TriInsertionSequentiel(int *tab, int tabsize) {
	int i, j, valeur;
	for (i = 1; i < tabsize; i++) {
		valeur = *(tab+i);
		for (j = i; j > 0 && *(tab + j - 1) > valeur; j--) {
			*(tab+j) = *(tab+j-1);
		}
		*(tab+j) = valeur;
	}
	
}

int main() {
	int tabsize = 20;
	int tab[20];
	srand(time(NULL));
	for (int i = 0; i < tabsize; i++) {
		tab[i] = rand() % (20 + 1);
	}
	TriInsertionSequentiel(tab, 20);
	for (int i = 0; i < tabsize; i++) {
		printf("%d / ", tab[i]);
	}
	printf("\n");
	system("pause");
}*/

//------------------------------------------------- TRI PAR INSERTION DICHOTOMIQUE ----------------------------------------------------------------------------
int rang(int *tab, int indmin, int indmax, int valeur) {
	int milieu;
	if (indmin = indmax) {
		return indmin;
	}
	else {
		milieu = (indmin + indmax) / 2;
		if (valeur < *(tab + milieu)) {
			return(rang(*tab, indmin, milieu, valeur));
		}
		else {
			return(rang(*tab, milieu + 1, indmax, valeur));
		}
	}
}

void TriInsertionDichotomique(int *tab, int tabsize) {
	int i, j, k, valeur;
	for (i = 1; i < tabsize; i++) {
		if (*(tab + i - 1) > *(tab + i)) {
			k = rang(*tab, 0, i, *(tab + i));
			valeur = *(tab + i);
			for (j = (i - 1); j > k; j--) {
				*(tab + j + 1) = *(tab + j);
			}
			*(tab + k) = valeur;
		}
	}
}

int main() {
	int tabsize = 20;
	int tab[20];
	srand(time(NULL));
	for (int i = 0; i < tabsize; i++) {
		tab[i] = rand() % (20 + 1);
	}
	TriInsertionDichotomique(tab, 20);
	for (int i = 0; i < tabsize; i++) {
		printf("%d / ", tab[i]);
	}
	printf("\n\n");
	printf("Il y a 20 valeurs triées\n");

	system("pause");
}








