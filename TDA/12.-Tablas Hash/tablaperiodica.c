#include<stdio.h>
#include"hash.h"
#define tam 120

void LeePeriodica(TablaH TP,FILE* ent);
Elem NewElem(char* ll,char* s,char* g,int per,int na,int nm,int p,int n,int e,char* tip);
void menu(TablaH TP,int n);
int main(){
	TablaH TP=IniciaTablaH(tam);
	FILE* ent=fopen("tablasp.txt","r");
	LeePeriodica(TP,ent);
	int n;
	do{
		printf("\tMenu:\n\t1-Imprimir elemento.\n\t2-Buscar elemento.\n\t3-Imprimir toda la tabla.\n\t");
		scanf("%i",&n);
		menu(TP,n);
	}while((n<1)&&(n>3));
	main();
	return 0;
}
void menu(TablaH TP,int n){
	char j[20];
	switch(n){
		case 1:	printf("Digite el nombre del elemento: ");
				scanf("%s",j);
				//system("cls");
				InfoTablaH(TP,j,tam);
			break;
		case 2:	printf("Digite el nombre del elemento a buscar: ");
				scanf("%s",j);
				EstaEnTablaH(TP,j,tam)?printf("Si Existe  \n"):printf("No Existe  \n");
			break;
		case 3: ImpTablaH(TP,tam);
			break;
	}
}
/*Todas las operaciones que realiza esta funcion son por referencia
recibe el apuntador a la tabla hash y al archivo.txt el cual va a leer toda la informacion de la tabla
periodica y los va a ir metiendo en la tabla hash, cada elemento que va leyendo le creara memoria dinamica 
uno por uno hasta llegar al final del archivo
*/
void LeePeriodica(TablaH TP,FILE* ent){
	int per,na,nm,p,n,e;
	char ll[15],s[5],g[5],tip[25];
	char *a,*b,*c,*d;
	
	while(!feof(ent)){
		fscanf(ent,"%s %s %s %d %d %d %d %d %d %s",ll,s,g,&per,&na,&nm,&p,&n,&e,tip);
		//fprintf(stdout,"%s %s %s %d %d %d %d %d %d %s\n",ll,s,g,per,na,nm,p,n,e,tip);
		a=(char*)malloc(15);
		b=(char*)malloc(5);
		c=(char*)malloc(5);
		d=(char*)malloc(25);
		strcpy(a,ll);
		strcpy(b,s);
		strcpy(c,g);
		strcpy(d,tip);
		InsertEnTablaH(TP,a,NewElem(a,b,c,per,na,nm,p,n,e,d),tam);
	}
	
}


/*la funcion revibe todas las caracteristicas del elemento y este los va a asignar a su respectivo
lugar de la estructura Elem y regresara elem para que la funcion Leeperiodica() la guarde en la celda de la tabla hash 
que corresponda 
*/
Elem NewElem(char* ll,char* s,char* g,int per,int na,int nm,int p,int n,int e,char* tip){
	Elem t;
	t.Llave=ll;//nombre del elemento
	t.simbolo=s; 
	t.grupo=g;
	t.periodo=per;
	t.noatomico=na;
	t.nomasa=nm;
	t.protones=p;
	t.neutrones=n;
	t.electrones=e;
	t.tipoelem=tip;
	return t;
}
