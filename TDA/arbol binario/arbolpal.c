#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"avl.h"


int main(int argc,char *argv[]){
	//printf("%d %s %s %s",argc,argv[0],argv[1],argv[2]);

	FILE *in=fopen(*(argv+1),"r");
	FILE *out=fopen(*(argv+2),"w");
	char arr[100],*x;
	DiccBin ent=VacioA();
	
	while(fscanf(in,"%s",arr)!=EOF){
		x=(char*)malloc(100);
		strcpy(x,arr);
		ent=InsOrdAR(x,ent);
	}
	
	ImpInOrderArch(ent,out);
	EsAVL(ent);
	EsPerfAVL(ent);
	return 0;
}