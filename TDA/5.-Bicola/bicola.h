////BICOLA- ENTRAN Y SALEN POR LOS DOS EXTREMOS--------
#include"elembicola.h"
typedef struct Nodo{
	ELEMB dato;
	struct Nodo*sig;
	struct Nodo*ant;
}*ApNodoB;

typedef struct BNodo{
	ApNodoB izq;
	ApNodoB der;
}*BiCola;
///SE INICIALIZA LA NUEVA BICOLA-----------------------------------------
BiCola NuevaBC(){
	BiCola bq=(BiCola)malloc(sizeof(struct BNodo));
	bq->izq=bq->der=NULL; //los dos nodos apuntado deve de iniciar el NULL
	return bq; //debe de retornar el la nueva bicola
}
///PARA PREGUNTAS SI LA BICOLA ES NUEVA(IGUAL A NULL)-------------------------------
int EsNuevaB(BiCola bq){return (bq->izq==NULL)&&(bq->der==NULL);} ///si la cola es nueva
///METERA NODOS POR EL LADO IZQUIERDO-----------------------------------------------
BiCola FormarI(ELEMB e,BiCola bq){
	ApNodoB t=(ApNodoB)malloc(sizeof(struct Nodo));
	t->dato=e;
	if(EsNuevaB(bq)){///si es nuvo el nodo acemos que se apunte asi mismo en ambas direcciones
		bq->der=bq->izq=t;
		t->sig=t->ant=NULL;
	} 
	else{
		bq->izq->ant=t;
		t->sig=bq->izq;
		bq->izq=t;
		t->ant=NULL;
	}
	return bq;
}
///METERA NODOS POR EL LADO DERECHO-------------------------------------------------
BiCola FormarD(BiCola bq,ELEMB e){
	ApNodoB t=(ApNodoB)malloc(sizeof(struct Nodo));
	t->dato=e;
	if(EsNuevaB(bq)){///si es nuvo el nodo acemos que se apunte asi mismo en ambas direcciones
		bq->der=bq->izq=t;
		t->sig=t->ant=NULL;
	} 
	else{
		bq->der->sig=t;
		t->ant=bq->der;
		bq->der=t;
		t->sig=NULL;
	}
	return bq;
}
///PARA PEDIR EL ELEMENTO DEL NODO DE LADO IZQUIERDO-----------------------------
ELEMB ElemI(BiCola bq){return bq->izq->dato;}
///PARA PEDIR EL ELEMENTO DEL NODO DEL LADO DERECHO------------------------------
ELEMB ElemD(BiCola bq){return bq->der->dato;}
///PARA SACAR EL NODO DEL LADO IZQUIERDO--------------------------------------------
BiCola DesformarI(BiCola bq){
	bq->izq=bq->izq->sig;
	bq->izq->ant=NULL;
	return bq;
}
///PARA SACAR EL NODO DEL LADO DERECHO----------------------------------------------
BiCola DesformarD(BiCola bq){
	bq->der=bq->der->ant;
	bq->der->sig=NULL;
	return bq;
}

void ImpBiCola(BiCola bq){
	ApNodoB cent=bq->izq;
	do{
		ImpELEMB(cent->dato);
		cent=cent->sig;
	}while(cent);
}

