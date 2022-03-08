///////*****TDA Listas generalizadas******///////
#include"elemlistag.h"
///ESPECIFICACION DE LA ESTRUCTURA LA CUAL APUNTARA A OTRA LISTA GENERALIZADA O A UN ELEM LISTA
typedef union LoE{
	ElemAtomico DatoAtom;            //dato atomico
	struct NodoG *NuevaLista;      //apuntador a la nueva lista generalizada
}ElemLG;
///ESPECIFICAION DEL NODO DE LA LISTA GENERALIZADA (SIMILAR A LA DE LISTA NORMAL)
typedef struct NodoG{
	int tipo;
	ElemLG DatoLG;         //union de la nueva lista o el dato atomico
	struct NodoG *sig;     //apuntador al siguiente nodo
}*ListaG;
///INICIALIZACION DE UNA LISTA GENERALIZADA
ListaG VaciaLG(){return NULL;}
///OBSERVADORA QUE RECIBE UNA LISTA GENERALIZADA Y VE SI ES VACIA O NO
int EsVaciaLG(ListaG lg){return lg==NULL;}
///REGRESA EL RESTO DE LA LISTA GENERALIZADA(ELIMINA EL PRIMER NODO)
ListaG RestoLG(ListaG lg){return lg->sig;}
///CONSTRUCTORA LA CUAL EL DATO SERA DE TIPO DatoAtom
ListaG ConsAtomico(ElemAtomico e,ListaG lg){
	ListaG t=(ListaG)malloc(sizeof(struct NodoG));
	t->tipo=1;                 //si es un Nodo atomico el tipo es 1
	t->DatoLG.DatoAtom=e;
	if(EsVaciaLG(lg))
		t->sig=NULL;
	else{
		t->sig=lg;
	}
	return t;
}
///CONSTRUCTORA LA CUAL EL DATO SERA UNA NUEVA ListaG
ListaG ConsLG(ListaG lgnva,ListaG lg){
	ListaG t=(ListaG)malloc(sizeof(struct NodoG));
	t->tipo=0;                  //si el nodo es un apuntador a lista es 0
	t->DatoLG.NuevaLista=lgnva;
	if(EsVaciaLG(lg))
		t->sig=NULL;
	else{
		t->sig=lg;
	}
	return t;
}
///VERIFICA SI LA CABEZA DE LA LISTA GENERALIZADA ES ATOMICO(QUE NO SEA UN APUNTADOR A OTRA LISTA GENERALIZADA)
int EsAtomico(ListaG lg){return lg->tipo;}///DUDAA--------------------------------------------------------
///REGRESA UN ElemAtomico DE UN NODO DE LA LISTA GENERALIZADA(EN CASO DE QUE APUNTE A ElemAtomico)
ElemAtomico CabezaAtomico(ListaG lg){
	if(EsAtomico(lg))
		return lg->DatoLG.DatoAtom;
	return 0;
}
///REGRESA UNA ListaG DE UN NODO DE UNA LISTA GENERALIZADA (EN CASO DE QUE APUNTE A UNA ListaG)
ListaG CabezaLG(ListaG lg){
	if(!EsAtomico(lg))
		return lg->DatoLG.NuevaLista;
	return 0;
}

//IMPRIME UNA LISTA GENERALIZADA
void ImprimeListaG(ListaG lg){
	if(!EsVaciaLG(lg)){
		if(EsAtomico(lg)){
			ImpElemLG(CabezaAtomico(lg));
			ImprimeListaG(RestoLG(lg));
		}	
		else{
			ImprimeListaG(CabezaLG(lg));
			ImprimeListaG(RestoLG(lg));
		}
	}
}
