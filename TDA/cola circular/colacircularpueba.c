#include<stdio.h>

#include"colacircular.h"

int main(){
	Circular q=formar(formar(formar(formar(formar(formar(formar(nuevac(),1),3),6),8),10),15),20);
	/*
	Circular q=formar(formar(formar(formar(formar(formar(formar(nuevac(),1),2),3),4),5),6),7);
	ImpColaC(q);
	printf("\n\n");
	int i;
	for(i=0;i<10;i++){
		ImpColaC(q);
		printf("\n");
		ImpELEMC(primero (q));
		printf("\n");
		q=rotar(q);
	}
	
	printf("-------------------------------------------\n");
	for(i=0;i<7;i++){
		ImpColaC(q);
		q=desformar(q);
		printf("\n");
	}   
	*/
	
	q=MeterEnCola(MeterEnCola(MeterEnCola(MeterEnCola(MeterEnCola(q,5),9),4),2),17);
	//ImpColaC(q);
	int i;
	for(i=0;i<10;i++){
		ImpColaC(q);
		printf("\n");
		ImpELEMC(primero (q));
		printf("\n");
		q=rotar(q);
	}
	return 0;
}

