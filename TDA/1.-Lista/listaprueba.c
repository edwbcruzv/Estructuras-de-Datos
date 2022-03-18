#include<stdio.h>
#include<stdlib.h>
#include"lista.h"

/** Funciones que manipulan a la lista usando las funciones del TDA **/
Lista LeeLista();
int main(){  
	srand(time(NULL));
	Lista l1,l2,I;
	l1=LeeLista();
	l2=LeeLista();
    printf("---lista 1-----------------------------------------\n");
    ImpLista(l1);
	printf("---lista 2-----------------------------------------\n");
    ImpLista(l2);
    printf("-----invierte la lista 1--------------------------------------\n");
	I=Invierte(l1);ImpLista(I);
	printf("-----invierte la lista 2--------------------------------------\n");
	I=Invierte(l2);ImpLista(I);	
    printf("------ordena una lista 1--------------------------------------\n");
    l1=OrdLista(l1);ImpLista(l1);
	printf("------ordena una lista 1--------------------------------------\n");
    l2=OrdLista(l2);ImpLista(l2);
    printf("------concatena dos listas--------------------------------------\n");
    I=ConCat(l1,l2);ImpLista(I);
	return 0;
}

int num(){return rand()%1000;}

Lista LeeLista(){
	Lista l=Vacia();
	int i;
	puts("No. de elementos?");
	scanf("%d",&i);
	while(i--)
		l=ConsL(num(),l);
	return l;
}
