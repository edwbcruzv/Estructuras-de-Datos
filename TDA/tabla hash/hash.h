//////tda tabla hash/////
#include"lista.h"
int Primo(int n);
int EsPrimo(int n);
///TablaH en realidad es un doble apuntador a Lista
typedef Lista *TablaH;
///FUNCION HASH
int FHash(char* Ll,int n){
	int i=0,cont=0,tam=Primo(n);
	while(Ll[i]!='\0'){
		cont=cont+Ll[i++];
	}
	return cont%tam;
}
///SE CREA EL ARREGLO DE APUNTADORES A Lista
TablaH IniciaTablaH(int n){
	int i,tam=Primo(n);
	TablaH th=(TablaH)malloc(sizeof(Lista)*tam);
	Lista l=Vacia();
	for(i=0;i<tam;i++)
		th[i]=l;
	return th;
}
///REGRESA LA LLAVE DE ELEM
char* LlaveElem(Elem e){return e.Llave;}
///INSERTA UN ELEM EN LA LISTA DE LA TABLA HASH
void InsertEnTablaH(TablaH H,char* Ll,Elem e,int n){
	//Ll=LlaveElem(e);
	int h=FHash(Ll,n);
	H[h]=InsOrd(e,H[h]);
	//return H;
}
///IMPRIME ELEM 
void InfoTablaH(TablaH H,char* Ll,int n){
	int h=FHash(Ll,n);
	Lista Apx;
	Apx=H[h];
	while(!esvacia(Apx)){
		if(esigual(LlaveElem(cabeza(Apx)),Ll))
			ImpElem(cabeza(Apx));
		Apx=resto(Apx);
		
	}
}
///BUSCA UN ELEM EN LA TABLA HASH
int EstaEnTablaH(TablaH H,char* Ll,int n){
	int h=FHash(Ll,n);
	Lista Apx;
	Apx=H[h];
	while(!esvacia(Apx)){
		if(esigual(LlaveElem(cabeza(Apx)),Ll))
			return 1;
		Apx=resto(Apx);
		
	}
	return 0;
	
}
///IMPRIME TODOS LOS ELEMENTOS DE LA TABLA HASH
void ImpTablaH(TablaH H,int n){
	int i;
	for(i=0;i<Primo(n);i++){
		ImpLista(H[i]);
	}
}
///REGRESA EL NUMERO PRIMO MAS CERCANO Y MAS GRANDE DEL n RECIBIDO
int Primo(int n){
	while(!EsPrimo(n))
		n++;
	return n;
}
///VERIFICA SI UN NUMERO ES PRIMO O NO
int EsPrimo(int n){
	int i=2;
	for(i=2;i<n;i++){
		if((n%i)==0)
			return 0;
	}
	return 1;
}
