#include <stdio.h>

int factoriel(int fac){
	if(fac==0){
		return 1;
	}
	return fac * factoriel(fac - 1);
}

int main(){
	int fac;
	printf("Entrez le chiffre en factorielle : \n");
	scanf("%d",&fac);
	printf("\n");

	printf("%d! = %d",fac,factoriel(fac));
	printf("\n");
}