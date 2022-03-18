//***********elementos del TDA de la cola********
#include"elemcola.h"
///DE DECLARA LA ESTRUCTURA NODO SEMEJANTE A LA LISTA----------------------------------------
typedef struct Nodo{    ///se esta creando el/los nodo(s) dentro de una cola (lista)
	ElemC dato;        //area donde se mete el dato de tipo ElemC
	struct Nodo*sig;  //area el cual apunta a otro nodo
}*ApNodo;
///SE DECLARA LA COLA EN LA CUAL VAN ENTRANDO LOS NODOS UNO TRAS OTRO------------------------
typedef struct CNodo{  ///se esta creando la cola la cual esta formada por dos nodos el cual apunta a dos nodos..
	ApNodo prim;       ///el primer nodo
	ApNodo ult;        ///el ultimo nodo
}*Cola;
///SE INICIALIZA LA COLA---------------------------------------------------------------------
Cola Nueva(){             
	Cola t=(Cola)malloc(sizeof(struct CNodo)); ///se reserva memoria para los n nodos que se vallan a crear
	t->prim=t->ult=NULL;    //con esto se define que la cola esta vacia
	return t;   //retorna la nueva cola
}
///APUNTADOR AL DATO DEL PRIMER NODO DE LA COLA----------------------------------------------
ElemC PrimElemC(Cola q){return q->prim->dato;} ///(no necesariamente el primer nodo)
//PARA SABER SI LA COLA ESTA VACIA-----------------------------------------------------------
int EsNueva(Cola q){return((q->prim==NULL)&&(q->ult==NULL));}  //es int por que devuelve un buleano
//SE LE METE UN NODO TIPO ElemC--------------------------------------------------------------
Cola Formar(Cola q,ElemC e){    //recibe una cola y un elemento que se va a meter a un nodo
	ApNodo t=(ApNodo)malloc(sizeof(struct Nodo));//se crea el nodo
	t->dato=e;           //al crear el nodo se le mete el elemento ElemC
	if(EsNueva(q)){         // se pregunta si la cola esta apuntando a null
		q->prim=q->ult=t;  //con esto se define que un nodo es el primero y ultimo al mismo tiempo
		t->sig=NULL;       //como es un solo nodo se le apunta a NULL
	} else {
		q->ult->sig=t;     //el nodo que antes era el ultimo apunta al nuevo nodo
		q->ult=t;           //la cola  apunta al nuevo nodo el cual ahora es el ultimo
		t->sig=NULL;       //el sig del ultimo nodo apunta a NULL
}
	return q;			
}
////SACA EL PRIMER NODO DEL CONJUNTO----------------------------------------------------------
Cola Desformar(Cola q){         
	if(q->prim==q->ult){      ///se pregunta si la cola apunta a un nodo al mismo tiempo
	   q->prim=q->ult=NULL;   ///si es asi se elimina el unico nodo que hay y se deja en vacio
	}
	else q->prim=q->prim->sig; ///si hay mas nodos entonces prim apunta al que esta detras del primero
	return q;
}

///IMPRIME LA COLA CON WHILE------------------------------------------------------------------
void ImpCola(Cola q){     
	ApNodo c=q->prim;       ///c es un contador que va nodo por nodo(while se encarga de hacer eso)
	while(c){               ///imprime elemento a elemento haSta que encuentro un NULL
		ImpElemC(c->dato);  ///imprime el dato del n nodo
		c=c->sig;           ///el contador se le apunta al siguiente nodo y regresa al inicio del while
	}putchar('\n');
}

///IMPRIME LA COLA DE FORMA RECURSIVA---------------------------------------------------------
void ImpColaR(Cola q){
	Cola t=(Cola)malloc(sizeof(struct CNodo));// se necisita reservas espacio en memoria para leer la cola
	t->prim=q->prim;
	t->ult=q->ult;
	if(!EsNueva(t)){       
	ImpElemC(PrimElemC(t));    ///se le manda el dato del nodo para imprimirlo
	ImpColaR(Desformar(t));    ///
	}
	//putchar('\n');
}

