#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int** maketab(int l, int c){
	int** tablo ;
	int i ;
	tablo=malloc(l*sizeof(int*));
	for(i=0;i<l;i++){
		tablo[i]=malloc(c*sizeof(int));
	}
	return tablo ;
}

void remptab(int **tab, int ligne, int colonne){
	int l;
	int c;
	for(l=0;l<ligne;l++){
		for(c=0;c<colonne;c++){
			tab[l][c]=rand()%99;
		}
	}
}

void printtab(int **tab, int ligne, int colonne){
	int l;
	int c;
	for(l=0;l<ligne;l++){
		for(c=0;c<colonne;c++){
			printf("%d ",tab[l][c]);
		}
		printf("\n");
	}
}
		

int main (){
time_t t;
srand((unsigned) time(&t));
int li;
int col;

li=4;
col=3;
printf("\n");
int** tab;
tab = maketab(li,col);
remptab(tab,li,col);
printtab(tab,li,col);
printf("\n");
int** tab2;
tab2 = maketab(li,col);
remptab(tab2,li,col);
printtab(tab2,li,col);
printf("\n");
}

	

