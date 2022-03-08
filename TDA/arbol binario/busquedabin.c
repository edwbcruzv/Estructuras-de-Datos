#include<stdio.h>
#include"avl.h"

int main(){
	srand(time(NULL));
	AVL A,a,b,c=VacioA(),d,e,f,g;
	g=InsOrdAR(num(),InsOrdAR(num(),InsOrdAR(num(),InsOrdAR(num(),InsOrdAR(num(),VacioA())))));
	f=InsOrdAR(num(),InsOrdAR(num(),InsOrdAR(num(),g)));
	e=InsOrdAR(num(),InsOrdAR(num(),InsOrdAR(num(),f)));
	d=InsOrdAR(num(),InsOrdAR(num(),InsOrdAR(num(),e)));
	c=InsOrdAR(num(),InsOrdAR(num(),InsOrdAR(num(),d)));
	b=InsOrdAR(num(),InsOrdAR(num(),InsOrdAR(num(),c)));
	a=InsOrdAR(num(),InsOrdAR(num(),InsOrdAR(num(),b)));
	A=InsOrdAR(num(),InsOrdAR(num(),InsOrdAR(num(),InsOrdAR(num(),a))));
	printf("\n----in order--------------------------\n");
	ImpInOrder(A);
	printf("\n----no. de niveles--------%d---------\n",Niveles(A));
	printf("  %d",FactBal(A));
	A=RotarAVLIzq(A);
	//ImpInOrder(A);
	printf("  %d",FactBal(A));
	A=RotarAVLIzq(A);
	//ImpInOrder(A);
	printf("  %d",FactBal(A));
	/*A=RotarAVLDer(A);
	//ImpInOrder(A);
	printf("  %d",FactBal(A));
	A=RotarAVLDer(A);
	//ImpInOrder(A);
	printf("  %d",FactBal(A));
	RotarAVLDer(A);
	ImpInOrder(A);
	printf("  %d",FactBal(A));
	RotarAVLDer(A);
	ImpInOrder(A);
	printf("  %d",FactBal(A));*/
	return 0;
}
int num(){
	return rand()%1000;
}
