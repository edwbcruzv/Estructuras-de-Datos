///////************TDA DE AVL*********//////////
#include"diccarbin.h"
///RECIBE UN DiccBin
///SE DEFINE QUE UN AVL ES UN DICCIONARIO DE BUSQUEDA BINARIA BALANCEADA-------------
typedef DiccBin AVL;
///ROTA ARBOL A LA DERECHA-----------------------------------------------------------
AVL RotarAVLDer(AVL a){
	AVL n=ConsA(RaizA(Izquierdo(a)),Izquierdo(Izquierdo(a)),ConsA(RaizA(a),Derecho(Izquierdo(a)),Derecho(a)));
	return n;
}
///ROTA ARBOL A LA IZQUIERDA---------------------------------------------------------
AVL RotarAVLIzq(AVL a){
	AVL n=ConsA(RaizA(Derecho(a)),ConsA(RaizA(a),Izquierdo(a),Izquierdo(Derecho(a))),Derecho(Derecho(a)));
	return n;
}
///ROTA EL SUBARBOL IZQUIERDO A LA IZQUIERDA Y DESPUES EL ARBOL A LA DERECHA---------
AVL RotaDerIzq(AVL a){ ///raiz - derecho +    raiz derecha   subderecho izquierda
	return RotarAVLDer(ConsA(RaizA(a),RotarAVLIzq(Izquierdo(a)),Derecho(a)));
}
///ROTA EL SUBARBOL DERECHO A LA DERECHA Y DESPUES EL ARBOL A LA IZQUIERDA-----------
AVL RotaIzqDer(AVL a){//                          subderecho->derecho
	return RotarAVLIzq(ConsA(RaizA(a),Izquierdo(a),RotarAVLDer(Derecho(a))));
}
///FUNCION DE VALOR ABSOLUTO--------------------------------------------------------
int absoluto(int n){
	   if(-n) return -n;
       else return n;	   
}
///VERIFICA SI UN ARBOL ESTA BALANCEADO---------------------------------------------
int EsAVL(AVL a){
	if(EsVacioA(a))
	     return 1;//regresa verdadero
	else if(((absoluto(Niveles(Izquierdo(a))-Niveles(Derecho(a))))<=1) && EsAVL(Izquierdo(a)) && EsAVL(Derecho(a)))
			return 1;//regresa verdadero
         else return 0;//regresa falso
}
///REGRESA EL FACTOR DE BALANCEO--------------------------------------------------
int FactBal(AVL a){
	if(EsHojaA(a))
		 return 0;
	else return Niveles(Izquierdo(a))-Niveles(Derecho(a));
} 
///FUNCION COMPLEMENTARIA DE HacerAVL (CASOS)--------------------------------------
AVL Rota(AVL A){
						///raiz +, izq +
	if((FactBal(A)>0)&&(FactBal(Izquierdo(A))>0))
		A=RotarAVLDer(A);
						     ///raiz + izq -
	else if((FactBal(A)>0)&&(FactBal(Izquierdo(A))<0))
	   A=RotaDerIzq(A);
				               ///raiz - derecho -
		else if((FactBal(A)<0)&&(FactBal(Derecho(A))<0))
				     A=RotarAVLIzq(A);
					        ///raiz - derecho +
	        else if((FactBal(A)<0) && FactBal(Derecho(A))>0)
				    A=RotaIzqDer(A);			            
	return A;
}
///BALANCEA UN ARBOL QUE DEJO DE SER AVL AL MOMENTO DE INSERTAR UN ELEMENTO---------
AVL HacerAVL(AVL A){
	if(EsAVL(A)) return A;
	else if(!EsAVL(Izquierdo(A)))
		return ConsA(RaizA(A),HacerAVL(Izquierdo(A)),Derecho(A));
		else if(!EsAVL(Derecho(A)))
			return ConsA(RaizA(A),Izquierdo(A),HacerAVL(Derecho(A)));
			else return Rota(A);
}
///LA FUNCION VA A IR CONSTRUYENDO EL ARBOL BALANCEADAMENTE-------------------------
AVL InsOrdAVL(ElemA e,AVL A){
	A=InsOrdAR(e,A);
	if(EsAVL(A)) 
		return A;
	else return HacerAVL(A);
}
///ELIMINAR UN ELEMENTO DE UN AVL---------------------------------------------------
AVL EliminarElemAVL(ElemA e,AVL A){
	return HacerAVL(BorraElemA(e,A));
}
