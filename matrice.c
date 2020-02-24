#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int** makematrix(int l, int c){
	int** tablo ;
	int i ;
	tablo=malloc(l*sizeof(int*));
	for(i=0;i<l;i++){
		tablo[i]=malloc(c*sizeof(int));
	}
	return tablo ;
}

void freematrix(int **matrix, int ligne){
	for(int i=0;i<ligne;i++){
		free(matrix[i]);
	}
	free(matrix);
}

void rempmatrix(int **matrix, int ligne, int colonne){
	int l;
	int c;
	for(l=0;l<ligne;l++){
		for(c=0;c<colonne;c++){
			matrix[l][c]=rand()%99;
		}
	}
}

void printmatrix(int **matrix, int ligne, int colonne){
	int l;
	int c;
	for(l=0;l<ligne;l++){
		for(c=0;c<colonne;c++){
			printf("%d ",matrix[l][c]);
		}
		printf("\n");
	}
}

void addmatrix(int **matrix, int ligne, int colonne, int **matrix2, int ligne2, int colonne2, int **matrixadd){
	if(ligne==ligne2){
		if(colonne==colonne2){
			int l;
			int c;
			for(l=0;l<ligne;l++){
                		for(c=0;c<colonne;c++){
               				matrixadd[l][c]=matrix[l][c]+matrix2[l][c];
				}
			}
		}
		else{
			printf("Les colonnes ne sont pas égales\n");
		}
	}
	else{
		printf("Les lignes ne sont pas égales\n");
        }
}

void mulmatrix(int **matrix, int ligne, int colonne, int **matrix2, int ligne2, int colonne2, int **matrixmul){
	if(colonne==ligne2){
		int l;
		int c;
		int x;
		int somme;
		somme=0;

		for(l=0;l<ligne;l++){
                	for(c=0;c<colonne2;c++){
				somme=0;
               			for(x=0;x<colonne;x++){
					//printf("On va multiplier %d et ",matrix[l][x]);
					//printf("%d\n",matrix2[x][c]);		
					somme=matrix[l][x]*matrix2[x][c]+somme;
				}
				matrixmul[l][c]=somme;
			}
		}
	}
	else{
		printf("Les matrices ne sont pas multipliables\n");
	}
}

		

int main (){
srand((unsigned) time(NULL));

int li;
int col;
int li2;
int col2;
int limul;
int colmul;
printf("Entrez le nombre de lignes de la première matrice \n");
scanf("%d",&li);
printf("Entrez le nombre de colonnes de la première matrice \n");
scanf("%d",&col);
printf("Entrez le nombre de lignes de la seconde matrice \n");
scanf("%d",&li2);
printf("Entrez le nombre de colonnes de la seconde matrice \n");
scanf("%d",&col2);


printf("\n");
int** matrix;
matrix = makematrix(li,col);
rempmatrix(matrix,li,col);
printmatrix(matrix,li,col);
printf("\n");

int** matrix2;
matrix2 = makematrix(li2,col2);
rempmatrix(matrix2,li2,col2);
printmatrix(matrix2,li2,col2);
printf("\n");

int** matrixadd;
matrixadd = makematrix(li,col);
addmatrix(matrix,li,col,matrix2,li2,col2,matrixadd);
printmatrix(matrixadd,li,col);
printf("\n");

limul=li;
colmul=col2;
int** matrixmul;
matrixmul = makematrix(limul,colmul);
mulmatrix(matrix,li,col,matrix2,li2,col2,matrixmul);
printmatrix(matrixmul,limul,colmul);
printf("\n");

freematrix(matrixmul,limul);
freematrix(matrixadd,li);
freematrix(matrix2,li2);
freematrix(matrix,li);
}

	

