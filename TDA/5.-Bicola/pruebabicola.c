#include<stdio.h>
#include"bicola.h"
int num();


int main(){
	srand(time(NULL));
	BiCola bq;
	bq=LeeBiCola();
	ImpBiCola(bq);
	return 0;
}

int num(){return rand()%1000;}



BiCola LeeBiCola(){
	BiCola h=NuevaBC();
	int i;
	puts("No. de elementos derecho?");
	scanf("%d",&i);
	while(i--)
		k=Formar(k,num());
	puts("No. de elementos izquierdo?");
	scanf("%d",&i);
	while(i--)
		k=Formar(num(),k);
	return k;
}