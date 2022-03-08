#include<stdio.h>
#include"avl.h"
void AVLprueva();
int Num();

int main(){
	srand(time(NULL));
	AVLprueva();
	
	return 0;
}
///insertando elementos del 1 hasta n-----------------------------------------------------
void AVLprueva(){
	AVL A=VacioA();
	int e,n,j,i=1;
	scanf("%d",&n);
	getchar();getchar();
	while(i!=n+1){
		printf(" %d\t",i);
		A=InsOrdAVL(i++,A);
		EsAVL(A)?printf("Es AVL\n"):printf("No es AVL\n");
	}
	while(!EsVacioA(A)){
		printf("Eliminar Elemento: ");
		scanf("%d",&e);
		A=EliminarElemAVL(e,A);
		ImpInOrder(A);
		//ImpAltura(A);
		/*
		//do{
		printf("Que elemento desea buscar: ");
		scanf("%d",&j);
		BuscarElemA(j,A)?printf("Elemento %d encontrado \n",j):printf("Elemento no existe en el arbol\n");
		//}while(j!=0);*/
	}
	printf("El Arbol Esta Vacio");
}
int Num(){
	return rand()%10000;
}
