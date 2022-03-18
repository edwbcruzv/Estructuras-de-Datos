#include<stdio.h>
#include<stdlib.h>
#include"heap.h"
#include"lista.h"

int main(){
	Heap A=VacioA();
	Lista L=Vacia();
	int n,i;
	printf("No de elementos a meter a la lista: ");
	scanf("%d",&n);
	while(n--){
		printf("Dato?: ");
		scanf("%d",&i);
		L=ConsL(i,L);
	}
	ImpLista(L);
	/
	while(L!=Vacia()){
		A=HazCompletoA(cabeza(L),A);
		L=resto(L);
	}
	A=ConsHeap(A);
	ImpInOrder(A);
	return 0;
}
