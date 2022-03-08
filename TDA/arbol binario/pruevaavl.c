#include<stdio.h>
#include"avl.h"
/// 100 50 200 25 75 60 90 150 300     ag 65
int main(){
	AVL A,B;
	B=InsOrdAR(60,InsOrdAR(90,InsOrdAR(150,InsOrdAR(300,InsOrdAR(65,VacioA())))));
	A=InsOrdAR(100,InsOrdAR(50,InsOrdAR(200,InsOrdAR(25,InsOrdAR(75,B)))));
	ImpInOrder(A);
	printf("valor de balanceo: %d",FactBal(A));
	A=RotarAVLIzq(A);
	printf("valor de balanceo: %d",FactBal(A));
	/*A=RotarAVLIzq(A);
	printf("valor de balanceo: %d",FactBal(A));
	A=RotarAVLIzq(A);
	printf("valor de balanceo: %d",FactBal(A));*/
	return 0;
}
