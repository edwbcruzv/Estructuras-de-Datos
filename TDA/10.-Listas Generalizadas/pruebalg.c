#include<stdio.h>
#include"listagen.h"
ListaG LeeListaG();

int main(){
	ListaG lg1=VaciaLG(),lg2,lg3,lg4,lg5;
	int i,n,h;
	for(i=0;i<=3;i++){
		printf("Elemento %d?",i+1);
		scanf("%d",&h);
		lg1=ConsAtomico(h,lg1);
	}
	lg1=ConsLG(LeeListaG(),lg1);
	ImprimeListaG(lg1);
	return 0;
}

ListaG LeeListaG(){
	ListaG t=VaciaLG();
	int i,n,h;
	printf("Numero de elementos a insertar: ");
	scanf("%d",&n);
	
	for(i=0;i<=n;i++){
		printf("Elemento %d?",i+1);
		scanf("%d",&h);
		t=ConsAtomico(h,t);
	}
	return t;
}

