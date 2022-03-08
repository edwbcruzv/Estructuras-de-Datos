/**** funciones del TDA Lista *////
#include"elemlista.h"
///SE CREA EL NODO DE LA LISTA------------------------------------------------------------------------------
typedef struct nodo{    
	Elem dato;
	struct nodo*sig;
}*Lista;

///SOLO SE RETORNA EL VALOR NULL-----------------------------------------------------------------------------
Lista Vacia(){return NULL;}
///SE UTILIZA PARA CONSTRUIR LA LISTA------------------------------------------------------------------------
Lista ConsL(Elem e,Lista l){        
	Lista t=(Lista)malloc(sizeof(struct nodo)); //se le reserva espacio de memoria a cada nodo que se crea
	t->dato=e;   ///en el nuevo nodo se inserta el elem 
	if(esvacia(l))
		t->sig=NULL;
	else
	t->sig=l;    //el sig de nuevo nodo se apunta a la lista ya existente
	return t;
}
///PARA SABER SI UNA LISTA ES VACIA-------------------------------------------------------------------------
int esvacia(Lista l){return l==Vacia();}
///REGRESA EL DATO DEL PRIMER ELEMENTO DE UNA LISTA---------------------------------------------------------
Elem cabeza(Lista l){return l->dato;}
///REGRESA EL RESTO DE LA LISTA-----------------------------------------------------------------------------
Lista resto(Lista l){return l->sig;}
///CUENTA EL NUMERO DE NODOS EN LA LISTA--------------------------------------------------------------------
int numero(Lista l){  
    if(esvacia(l))
        return 0;
    else
        return 1+numero(resto(l)); //llamada recursiva
}
///ELIMINA EL ELEMENTO n DE UNA LISTA----------------------------------------------------------------------
Lista ElimNodo(Lista l,int n){//no probado
	Lista cent1,cent2; 
	int o,u;
	cent1=l;
	cent2=l->sig->sig;
	for(o=1;o<=n-2;o++){
		cent1=resto(cent1);
		cent2=resto(cent2);
	}
	cent1->sig=cent2;
	return l;
}
///IMPRIME UNA LISTA----------------------------------------------------------------------------------------
void ImpLista(Lista l){  
	if(!esvacia(l)){
	     ImpElem(cabeza(l));   //este imprime la cabeza--la funcion se encuentra en elemlista.h
	     ImpLista(resto(l));    //este imprime el resto llamando recursivamente a esta funcion
	}
}
///ELIMINA EL PRIMER ELEMENTO DE UNA LISTA------------------------------------------------------------------
Lista ElimPrimer(Lista l){return resto(l);}
///INSERTA EL ELEMENTO EN EL LUGAR QUE LE CORRESPONDE-------------------------------------------------------
Lista InsOrd(Elem e,Lista l){   //en elemento que se va a insertar lo va a poner en el orden que le corresponde
		if(esvacia(l))
   	     return ConsL(e,l);  //Se va a construir la lista con solo un elemento
	else if(esmenor(e,cabeza(l))) //esta funcion esta en elemlista.h
	         return ConsL(e,l);
	     else 
		     return ConsL(cabeza(l),InsOrd(e,resto(l)));     //la lista en el que se va a insertar el elemento debe de estar ordenada
}
///ORDENA LA LISTA------------------------------------------------------------------------------------------
Lista OrdLista(Lista l){  //incompleta
	if(esvacia(l))
	       return l;
	else           
	       return InsOrd(cabeza(l),OrdLista(resto(l)));

}  
///PEGA DOS LISTAS SEGUIDA DE LA OTRA (CONTATENAR)------------------------------------------------------------------------
Lista ConCat(Lista l1,Lista l2){
	if (esvacia(l1)) return l2;
	 else return ConsL(cabeza(l1),ConCat(resto(l1),l2));  //primero cons pega la cabeza de l1 y 
}
///INVIERTE UNA LISTA----------------------------------------------------------------------------------------
Lista Invierte(Lista l){  
	if(esvacia(l)) return Vacia();  //si la lista esta vacia devuelve la misma lista
	else return ConCat(Invierte(resto(l)),ConsL(cabeza(l),Vacia()));
}


////archivos-------------------------------------------------------------------------------------------------
void ImpListaArch(Lista l, FILE *out){        //recibe la lista u el archivo de salida
	if(!esvacia(l)){
	     ImpElemArch(cabeza(l),out);   //este imprime la cabeza
	     ImpListaArch(resto(l),out);    //este imprime el resto
	}
}     

