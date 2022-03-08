///////******ARBOL BINARIO******///////////////
#include"elemarbolbinario.h"
#include<stdlib.h>
///SE DEFINE LA ESTRUCTURA DE CADA VERTICE DE NUESTRO ARBO BINARIO-------------------------
typedef struct NodoAR{
	ElemA dato;
	struct NodoAR*izq;
	struct NodoAR*der;
}*ArBin;
///SE ENCARGA DE CONSTRUIR EL ARBOL--------------------------------------------------------
ArBin ConsA(ElemA e,ArBin Izq, ArBin Der){
	ArBin A=(ArBin)malloc(sizeof(struct NodoAR));
	A->dato=e;
	A->izq=Izq;
	A->der=Der;
	return A;
}
///SE DECLARA EL QUE PARTE VA SER VACIO EL ARBOL-------------------------------------------
ArBin VacioA(){return NULL;}
///PARA PREGUNTAR SI EL ARBOL EL VACIO(VER NumElemA())-------------------------------------
int EsVacioA(ArBin A){return A==VacioA();}
///REGRESA EL VALOR DE LA RAIZ DEL ARBOS QUE SE LE MANDA-----------------------------------
ElemA RaizA(ArBin A){return A->dato;}
///REGRESA EL ARBOL QUE APUNTA LA RAIZ DEL LADO IZQUIERDO----------------------------------
ArBin Izquierdo(ArBin A){return A->izq;}
///REGRESA EL ARBOL QUE APUNTA LA RAIZ DEL LADO DERECHO------------------------------------
ArBin Derecho(ArBin A){return A->der;}
///SE COMPRUEBA SI UN ARBOL ES HOJA--------------------------------------------------------
int EsHojaA(ArBin A){return (EsVacioA(Izquierdo(A)) && EsVacioA(Derecho(A)));}
///CUENTA CUANTOS ELEMENTOS TIENE EL ARBOL-------------------------------------------------
int NumElemA(ArBin A){
	if(EsVacioA(A)){return 0;}
	else return 1+NumElemA(Izquierdo(A))+NumElemA(Derecho(A));
}
///CUENTA CUANTOS NIVELES HAY EN EL ARBOL--------------------------------------------------
int Niveles(ArBin A){
	if(EsVacioA(A)) return 0;
	else return 1+NivelMayor(Niveles(Izquierdo(A)),Niveles(Derecho(A)));
}
///COMPLEMENTO DE LA FUNCION Niveles------------------------------------------------------
int NivelMayor(int A1,int A2){
	if(A1<=A2) return A2;
	else return A1;
}
///IMPRIME EL ARBOL EN IN-ORDER  IZQUIERDO-RAIZ-DERECHO ----------------------------------
void ImpInOrder(ArBin A){
	if(!EsVacioA(A)){
		ImpInOrder(Izquierdo(A));
	    ImpElemA(RaizA(A));
		ImpInOrder(Derecho(A));
	}
}
///IMPRIME EL ARBOL EN PRE-ORDER  RAIZ-IZQUIERDO-DERECHO -----------------------------------
void ImpPreOrder(ArBin A){
	if(!EsVacioA(A)){
		ImpElemA(RaizA(A));
		ImpPreOrder(Izquierdo(A));
		ImpPreOrder(Derecho(A));
	}
}
///IMPRIME EL ARBOL EN POST-ORDER  IZQUIERDO-DERECHO-RAIZ ----------------------------------
void ImpPostOrder(ArBin A){
	if(!EsVacioA(A)){
		ImpPostOrder(Izquierdo(A));
		ImpPostOrder(Derecho(A));
		ImpElemA(RaizA(A));
	}
}
///IMPRIMIR EN IN-ORDER EN UN ARCHIVO-------------------------------------------------------
void ImpInOrderArch(ArBin A,FILE *out){
	if(!EsVacioA(A)){
		ImpInOrderArch(Izquierdo(A),out);
	    ImpElemAArch(RaizA(A),out);
		ImpInOrderArch(Derecho(A),out);
	}
}

///IMPRIMIR POR ALTURURA 1-N----------------------------------------------------------------
void ImprimeXAltura(ArBin A,int a){
	if(!EsVacioA(A)){
		if(Niveles(A)==a) 
			ImpElemA(RaizA(A));
		ImprimeXAltura(Izquierdo(A),a);
		ImprimeXAltura(Derecho(A),a);
	}
}

void ImpAltura(ArBin A){
	int a=Niveles(A);
	while(a)
		ImprimeXAltura(A,a--);
}

///////////////////////////////////////////ARBOL HEAP\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Un arbol binario es completo si tiene una altura "h" y esta lleno hasta el nivel "h-1" con el nivel "h" llenado de 
//izquierda y derecha
//en todos sus nodos tienen 0 o 2 nodo
//completo!=lleno
//CHECA SI UN ARBOL ESTA COMPLETO---------------------------------------------------------------------------
//                 *
//				  / \
//			     /   \
//			    /     \
//			   /       \
//			  /         \
//           *           *
//          / \         / \
//         /   \       /   \
//		  *     *     *     *	 
//		 / \   / \   
//	    *   * *   * 
int EsCompletoA(ArBin A){
	if(EsVacioA(A))
		return 1;
	else if(absoluto(Niveles(Izquierdo(A))-Niveles(Derecho(A)))<=1&&(Niveles(Izquierdo(A))>=Niveles(Derecho(A)))&&(EsCompletoA(Izquierdo(A)))&&(EsCompletoA(Derecho(A))))
		return 1;
		else return 0;			
}

//CHECA SI UN ARBOL ES LLENO---------------------------------------------------------------------------------
//                 *
//				  / \
//			     /   \
//			    /     \
//			   /       \
//			  /         \
//           *           *
//          / \         / \
//	       /   \       /   \
//		  *     *     *     *	 
//		 / \   / \   / \   / \
//	    *   * *   * *   * *   *
			 
int EsLlenoA(ArBin A){
	if(EsVacioA(A))
		return 1;
	else if((Niveles(Izquierdo(A))==Niveles(Derecho(A)))&&(EsLlenoA(Izquierdo(A)))&&(Niveles(Izquierdo(A))==Niveles(Derecho(A)))&&(!(EsLlenoA(Derecho(A)))))
		return 1;
		else return 0;
}

ArBin HazCompletoA(ElemA e,ArBin A){
	if(EsVacioA(A))
		return ConsA(e,VacioA(),VacioA());
	else if((Niveles(Izquierdo(A))==Niveles(Derecho(A))+1)&&(EsLlenoA(A))||(Niveles(Derecho(A))))
		return ConsA(RaizA(A),Izquierdo(A),HazCompletoA(e,Derecho(A)));
		else ConsA(RaizA(A),HazCompletoA(e,Izquierdo(A)),Derecho(A));
}
