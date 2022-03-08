#include"elempila.h"
typedef Elem Tipo;

typedef struct stack{
	Tipo dato;
	struct stack* sig;
}*Pila;

Pila empty(){return NULL;}   //indica que la pila esta vacia

Pila push(Tipo e,Pila p){
	Pila s=(Pila)malloc(sizeof(struct stack));
	s->dato=e;
	s->sig=p;
	return s;
}                                // mete un elemento a la pila
int isempty(Pila p){return p==NULL;}    //es para saber si la pila esta vacia int para regresar un booleano
Tipo tope(Pila p){return p->dato;}     //tope de la pila (primer elemento)
Pila pop(Pila p){return p->sig;}    // devuelve el resto de la pila----se usa despues de sacar un elemento de la pila 
 //se interpreta como sacar el primer elemento de la pila
