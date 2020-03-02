#include <stdio.h>

void factoriel (int fac){
	int res;
	int x;
	res=fac;
	for(x=1;x<fac;x++){
		res=res*x;   
		//printf("x=%d  res=%d\n",x,res);
	}
	printf("%d! = %d",fac,res);
}


int main (){
	int fac;
	printf("Entrez le chiffre en factorielle : \n");
	scanf("%d",&fac);
	printf("\n");

	factoriel(fac);
	printf("\n");
}