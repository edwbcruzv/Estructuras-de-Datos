////colas con prioridades
///------------------------------------------------------------------------------///////
#include"elemcircular.h"
///SE DEFINE UN NODO PARA FORMAR LA ESTRUCTURA DE UNA COLA CIRCULAR------------------------------------
typedef struct NodoC{
	ELEM dato;
	struct NodoC*sig;
}*Circular;
///SE DEFINE LA FUNCION NULL---------------------------------------------------------------------------
Circular nuevac(){return NULL;}
///SE DEFINA UNA COLA VACIA----------------------------------------------------------------------------
int esnueva(Circular q){ return q==NULL;} /// 
///FORMA LA COLA NODO POR NODO-------------------------------------------------------------------------
Circular formar(Circular q,ELEM e){    //la q siempre va apuntar al ultimo nodo------------------------
	Circular t=(Circular)malloc(sizeof(struct NodoC)); ///se les reserva memoria a los nuevos nodos
	t->dato=e; ///al nuevo nodo se le asigna el nuevo dato
	if(esnueva(q)){  ///se verifica si la cola es vacia
		q=t;            ///el nuevo y unico nodo va a ser unica
		q->sig=t;      ///el sig del nodo apunta asi mismo
	}////////en el caso de que no este vacia la cola
	else{ 
		t->sig=q->sig; // el nuevo nodo va a apuntar al primer nodo de la cola
		q->sig=t;	//el ultimo nodo va apuntar al nuevo nodo
		q=t;
	}
	return t;
}
///ROTAR LA COLA---------------------------------------------------------------------------------------
Circular rotar(Circular q){
	return q->sig; ///regresa el el nodo adelante de l nodo que apunta q
/*	if(esnueva(q)) return q;
	else return formar(desformar(q),primero(q));   */
}
///LA FUNCION REGRESA DATO DEL PRIMER NODO DE LA COLA---------------------------------------------------
ELEM primero(Circular q){return q->sig->dato;}
ELEM DatoNodo(Circular q){return q->dato;}
///DESFORMA (ELIMINA)EL PRIMER NODO DE LA COLA---------------------------------------------------------
Circular desformar(Circular q){   //la cola siempre va apuntar al ultimo elemento
	Circular t=q->sig;   /// t apunta al primer nodo por medio del ultimo elemento
	if(q==q->sig){        ///se verifica si la cola tiene solo un nodo  
		free(t); //se libera el espacio en memoria
		return nuevac();  ///se elimina espacio en memoria y se regresa que la cola es nueva
	}
	else{ 
		q->sig=q->sig->sig; ///el ultimo nodo apunta al segundo nodo y asi el primero se elimina
		free(t); //se libera el espacio en memoria        
	}
	return q;              ///retorna la cola ya modificada
}
///IMPRIME LA COLA CIRCULAR (recursivamente)-----------------------------------------------------------
Circular ImpColaC(Circular q){ //q apunta al ultimo de la cola
	Circular t=q; //t=q->sig;   //centinela se inicializa por el primero de la cola
	do{
		t=rotar(t);
		ImpELEMC(DatoNodo(t));
	
	}while(t!=q);
}
///METE UN ELEM A UN NUEVO NODO EL CUAL SE VA A INSERTAR EN EL ORDEN QUE LE CORRESPONDA---COLA CON PRIORIDADES---------
Circular MeterEnCola(Circular q,ELEM e){
	Circular cent;
	cent=q;
	q=rotar(q);
	while(!EsMayor(q->sig->dato,e)){
			q=rotar(q);
			}
	q=formar(q,e);
	q=cent;
	return q;
}
