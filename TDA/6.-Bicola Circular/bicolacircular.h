///////TDA DE BICOLA CIRCULAR------
#include"elembicolacircular.h"
///SE CREA EL NODO DE LA BICOLA------------------------------------------------------------------------------
typedef struct NodoBCC{
	ELEMBCC dato;
	struct NodoBCC*sig;
	struct NodoBCC*ant;
}*BiColaC;
///CUANDO SE CONSTRUYA UNA COLA SE LE DEBE DE DEFINIR PRIMERALEMTE ES ES NULL---------------------------------
BiColaC NuevaBCC(){return NULL;}
///PARA SABER SI UNA COLA ES NUEVA----------------------------------------------------------------------------
int EsNuevaBCC(BiColaC bcc){return bcc==NuevaBCC();}
///CONSTRUTE LA NUEVA BICOLA Y LAS CONECTA CIRCULARMENTE------------------------------------------------------
BiColaC FormarBCC(BiColaC bcc,ELEMBCC e){
	BiColaC bc=(BiColaC)malloc(sizeof(struct NodoBCC));
	bc->dato=e;
	if(EsNuevaBCC(bcc)){
		bc->sig=bc->ant=bc;
		bcc=bc;
	} 
	else{
		bcc->sig->ant=bc;
		bc->sig=bcc->sig;
		bc->ant=bcc;
		bcc->sig=bc;
		bcc=bc;
	}
	return bcc;
}
///PARA SACAR UN NODO DE LA BICOLA------------------------------------------------------------------------------
BiColaC DesformarBCCI(BiColaC bcc){
	bcc->sig->ant=bcc->ant;
	bcc->ant->sig=bcc->sig;
	bcc=bcc->ant;
	return bcc;
}

ELEMBCC PrimerELEMBCC(BiColaC bcc){return bcc->sig->dato;}
///ROTAR APUNTADOR BCC A LA IZQUIERDA---------------------------------------------------------------------------
BiColaC RotarBCCIzq(BiColaC bcc){return bcc=bcc->ant;}
///ROTAR APUNTADOR BCC A LA DERECHA-----------------------------------------------------------------------------
BiColaC RotarBCCDer(BiColaC bcc){return bcc=bcc->sig;}
///PARA IMPRIMIR LA BICOLA CIRCULAR-----------------------------------------------------------------------------
void ImpBiColaC(BiColaC bcc){
	BiColaC cent=bcc->sig;
	do{
		ImpELEMBiColaC(cent->dato);
		cent=cent->sig;
	}while(cent!=bcc->sig);
}