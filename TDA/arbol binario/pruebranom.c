#include<stdio.h>
#include"avl.h"

int main(int argc,char*argv[]){
	FILE *out=fopen(*(argv+1),"w");
	DiccBin a,b,c,d,e;
	e=InsOrdAR("Evelin",InsOrdAR("Fernanda",InsOrdAR("Rosalia",InsOrdAR("Alisson",InsOrdAR("Alicia",VacioA())))));
	d=InsOrdAR("Anastacia",InsOrdAR("Karen",InsOrdAR("Sofia",InsOrdAR("Yobana",InsOrdAR("Paola",e)))));
	c=InsOrdAR("Alondra",InsOrdAR("Kareli",InsOrdAR("Aline",InsOrdAR("Arantza",InsOrdAR("Paulina",d)))));
	b=InsOrdAR("Raquel",InsOrdAR("Jessica",InsOrdAR("Josselyn",InsOrdAR("Julieta",InsOrdAR("Zaira",c)))));
	a=InsOrdAR("Estefania",InsOrdAR("Carolina",InsOrdAR("Ana",InsOrdAR("Maria",InsOrdAR("Jaqueline",b)))));
	//ImpInOrder(a);
	ImpInOrderArch(a,out);
	return 0;
}