#include<stdio.h>
#include"conjunto.h"

Conjunto leeconj1(){
	Conjunto c=VacioCJ();
	int g=10;
	while(g){
		c=InsertaCJ(g--,c);
	}
	return c;
}
Conjunto leeconj2(){
	Conjunto c=VacioCJ();
	int g=20;
	while(g){
		c=InsertaCJ(g--,c);
	}
	return c;
}

int main(){
	Conjunto c1,c2,cu,ci,cd;
	c1=leeconj1();
	c2=leeconj2();
	printf("conjunto1---------\n");
	ImpConj(c1);
	printf("conjunto2---------\n");
	ImpConj(c2);
	printf("union---------\n");
	cu=Union(c1,c2);
	ImpConj(cu);
	printf("interseccion---------\n");
	ci=Interseccion(c1,c2);
	ImpConj(ci);
	printf("diferencia---------\n");
	cd=Diferencia(c1,c2);
	ImpConj(cd);
	return 0;
}
