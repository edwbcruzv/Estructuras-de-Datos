#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"cola.h"
int num();
Cola LeeCola();
void DeformarCola(Cola k);

int main(){
	srand(time(NULL));
	Cola q;
	q=LeeCola();
	printf("\n---cola-----------------------------------------\n");
	ImpCola(q);
	ImpColaR(q);
	printf("\n---deforma cola-----------------------------------------\n");
	DeformarCola(q);
	return 0;
}
int num(){return rand()%1000;}

Cola LeeCola(){
	Cola k=Nueva();
	int i;
	puts("No. de elementos?");
	scanf("%d",&i);
	while(i--)
		k=Formar(k,num());
	return k;
}

void DeformarCola(Cola k){
	if(!EsNueva(k)){
	ImpCola(k);
	DeformarCola(k=Desformar(k));
	}
}
