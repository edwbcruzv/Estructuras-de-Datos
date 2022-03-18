///////TDA Conjunto////////////////
#include"lista.h"
typedef Lista Conjunto;
typedef Elem ElemCJ;

Conjunto VacioCJ(){return NULL;}

int EsVacioCJ(Conjunto s){return s==NULL;}

Conjunto InsertaCJ(ElemCJ e,Conjunto s){return ConsL(e,s);}

int Contiene(ElemCJ e,Conjunto s){return BuscaElemL(e,s);}

Conjunto Elimina(ElemCJ e,Conjunto s){return ElimNodo(e,s);}

void ImpConj(Conjunto s){ImpLista(s);}

Conjunto Union(Conjunto s1,Conjunto s2){
	return ConCat(s1,s2);
}

Conjunto Interseccion(Conjunto s1,Conjunto s2){
	Conjunto ban,s=VacioCJ();
	while(!EsVacioCJ(s1)){
		ban=s2;
		while(!EsVacioCJ(ban)){
			if(cabeza(s1)==cabeza(ban))
				s=ConsL(cabeza(s1),s);
			ban=resto(ban);
		}
		s1=resto(s1);
	}
	return s;
}
Conjunto Diferencia(Conjunto s1,Conjunto s2){
	Conjunto s=s1;
	while(!EsVacioCJ(s2)){
		s=Elimina(cabeza(s2),s);
		s2=resto(s2);
	}
	return s;
}

int Tamano(Conjunto s){return numero(s);}
