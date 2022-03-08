///////////////TDA Bolsa/////////////////no acepta elementos repetidos
#include"lista.h"
typedef Lista Bolsa
typedef Elem ElemB;

Bolsa VaciaB(){return NULL;}

int EsVaciaB(Bolsa b){return b==VaciaB();}

int ContieneB(ElemB e,Bolsa b){return BuscaElemL(e,b);}

Bolsa Elimina(ElemB e,Bolsa b){return ElimNodo(e,b);}

Bolsa UnionB(Bolsa b1,Bolsa b2){
	return ElimRep(ConCat(b1,b2));
}

Bolsa InterseccionB(Bolsa b1,Bolsa b2){
	Conjunto ban,b=VaciaB();
	while(!EsVaciaB(b1)){
		ban=b2;
		while(!EsVaciaB(ban)){
			if(cabeza(b1)==cabeza(ban))
				b=ConsL(cabeza(b1),b);
			ban=resto(ban);
		}
		b1=resto(b1);
	}
	return ElimRep(b);
}

Bolsa DiferenciaB(Bolsa b1,Bolsa b2){
	Bolsa b=b1;
	while(!EsVaciaB(s2)){
		b=Elimina(cabeza(b2),b);
		b2=resto(b2);
	}
	return b;
}

Bolsa TamañoB(Bolsa b){return numero(b);}
