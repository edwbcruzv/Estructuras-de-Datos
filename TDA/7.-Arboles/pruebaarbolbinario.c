#include<stdio.h>
#include"avl.h"

int main(){
	ArBin A,a,b,c,d,e,f=VacioA(),g=VacioA();
	//f=ConsA(89,VacioA(),ConsA(5,VacioA(),VacioA()));
	g=ConsA(82,ConsA(78,f,VacioA()),VacioA());
	f=ConsA(89,VacioA(),ConsA(5,VacioA(),VacioA()));
	e=ConsA(27,VacioA(),ConsA(94,VacioA(),VacioA()));
	d=ConsA(43,ConsA(64,VacioA(),VacioA()),g);
	c=ConsA(27,f,ConsA(48,VacioA(),VacioA()));
	b=ConsA(47,d,e);
	a=ConsA(43,c,VacioA());
	A=ConsA(1,a,b);
	
	printf("\n----in order--------------------------\n");
	ImpInOrder(A);
	printf("\n-----preorder-------------------------\n");
	ImpPreOrder(A);
	printf("\n-----postorder------------------------\n");
	ImpPostOrder(A);
	printf("\n------raiz------------%d------------\n",RaizA(A));
	printf("\n-----izquierdo--------%d--------------\n",RaizA(Izquierdo(A)));
	printf("\n-----derecho---------%d-------------\n",RaizA(Derecho(A)));
	printf("\n----no. de elementos--------%d---------\n",NumElemA(A));
	printf("\n----no. de niveles--------%d---------\n",Niveles(A));
	printf("->%d",EsAVL(A));
	ImpAltura(A);
	
	return 0;
}
