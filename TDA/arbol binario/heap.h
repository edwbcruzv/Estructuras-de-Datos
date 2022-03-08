#include"arbolbinario.h"
typedef ArBin Heap;

Heap HazHeap(ElemA e,Heap I,Heap D){
	if(EsVacioA(I)&&EsVacioA(D))
		return ConsA(e,I,D);
	else if(EsVacioA(D))
			if(EsMAoIA(e,RaizA(I)))
				return ConsA(e,I,D);
			else return ConsA(RaizA(I),ConsA(e,VacioA(),VacioA()),VacioA());
		else if(EsMayor(e,RaizA(I))&&EsMayor(e,RaizA(D)))
				return ConsA(e,I,D);
			else if(EsMAoIA(RaizA(I),RaizA(D)))
				return ConsA(RaizA(I),HazHeap(e,Izquierdo(I),Derecho(I)),D);
				else return ConsA(RaizA(D),I,HazHeap(e,Izquierdo(D),Derecho(D)));
}
//precondicion: el arbin debe de ser completo
Heap ConsHeap(ArBin A){
	if(EsVacioA(A))
		return A;
	else if((Niveles(Izquierdo(A))-Niveles(Derecho(A)))<=1)
		return HazHeap(RaizA(A),ConsHeap(Izquierdo(A)),ConsHeap(Derecho(A)));
}
