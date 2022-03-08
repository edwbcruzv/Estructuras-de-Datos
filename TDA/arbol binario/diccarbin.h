////******TDA DICCIONARIO DE BUSQUEDA BINARIA****
#include"arbolbinario.h"
///UN DICCIONARIO: UN ARBOL DE BUSQUEDA BINARIA------------------------------------------------------
typedef ArBin DiccBin;
///CONSTRUYE UN ARBOL BINARIO ORDENADO EN IN-ORDER---------------------------------------------------
DiccBin InsOrdAR(ElemA v,DiccBin db){
	if(EsVacioA(db)){
		return ConsA(v,VacioA(),VacioA());
	}
	else if(EsMoIA(v,RaizA(db))){///si la raiz es mayor el elemento la mete en el sub arbol izquierdo
		return ConsA(RaizA(db),InsOrdAR(v,Izquierdo(db)),Derecho(db));
		}///si el elemento es mayor que la raiz la manda al sub arbol derecho
		else return ConsA(RaizA(db),Izquierdo(db),InsOrdAR(v,Derecho(db)));	
}

///BUSCA EL ELEMENTO DADO----------------------------------------------------------------------------
int BuscarElemA(ElemA e,DiccBin db){
	if(!EsVacioA(db)){
		if(EsMenor(e,RaizA(db)))
			return BuscarElemA(e,Izquierdo(db));
		else if(EsMenor(RaizA(db),e))
			return BuscarElemA(e,Derecho(db));
			else if(e==RaizA(db))
				return 1;
	}
	else return 0;
}

///BORRAR UN ELEMENTO DE UN DICCBIN USANDO EL MAXIMO------------------
DiccBin BorraElemA(ElemA e,DiccBin db){
	if(EsVacioA(db)){
		return db;
	}	
	if(e==RaizA(db)){
		if(EsHojaA(db)){
			return VacioA();
		}
		else if(EsVacioA(Derecho(db))){
				return Izquierdo(db);
			}
			else if(EsVacioA(Izquierdo(db))){
					return Derecho(db);
				}
				else{//return ConsA(Maximo(Izquierdo(db)),BorraElemA(Maximo(Izquierdo(db)),Izquierdo(db)),Derecho(db));
					return ConsA(Minimo(Derecho(db)),Izquierdo(db),BorraElemA(Minimo(Derecho(db)),Derecho(db)));
					}
	}
	else if(e<RaizA(db))
		 return ConsA(RaizA(db),BorraElemA(e,Izquierdo(db)),Derecho(db));
		else ConsA(RaizA(db),Izquierdo(db),BorraElemA(e,Derecho(db)));
}

ElemA Maximo(DiccBin db){
	if(EsHojaA(db))
		return RaizA(db);
	else if(EsVacioA(Derecho(db)))
			return RaizA(db);
		else return Maximo(Derecho(db));
}

ElemA Minimo(DiccBin db){
	if(EsHojaA(db))
		return RaizA(db);
	else if(EsVacioA(Izquierdo(db)))
			return RaizA(db);
		else return Minimo(Izquierdo(db));
}

///ELIMINAR UN ELEMENTO DE LA LISTA------------------------------------------------------------------
//prototipos de las funciones del lado izquierdo
DiccBin RecorreIzq(DiccBin db);
DiccBin RecDer(DiccBin db);
ElemA RemplazoIzq(DiccBin db);
ElemA RemDer(DiccBin db);
//prototipos de las funciones del lado derecho
DiccBin RecorreDer(DiccBin db);
DiccBin RecIzq(DiccBin db);
ElemA RemplazoDer(DiccBin db);
ElemA RemIzq(DiccBin db);
//////////////////////FUNCION MAESTRA////////////////////////////
DiccBin EliminarElemA(ElemA e,DiccBin db){
	if(!EsVacioA(db)){
		if(EsMenor(e,RaizA(db)))
			return db=ConsA(RaizA(db),EliminarElemA(e,Izquierdo(db)),Derecho(db));
		else if(EsMenor(RaizA(db),e))
			return db=ConsA(RaizA(db),Izquierdo(db),EliminarElemA(e,Derecho(db)));
			else if(e==RaizA(db)){
					if(EsHojaA(db)){
					return db=VacioA();
					}
					else if(!(EsVacioA(Izquierdo(db)))){
								e=RemplazoIzq(Izquierdo(db));
							return db=ConsA(e,RecorreIzq(Izquierdo(db)),Derecho(db));
						}
						else if(!(EsVacioA(Derecho(db)))){
								e=RemplazoDer(Derecho(db));
							return db=ConsA(e,Izquierdo(db),RecorreDer(Derecho(db)));
						}
			}
	}
	else return db;
}
///FUNCION BUSCA EL NODO EN EL SUBARBOL IZQUIERDO QUE SE VA A ELIMINAR-------------------------------
DiccBin RecorreIzq(DiccBin db){
	if(EsHojaA(db))//caso
		return VacioA();
	else if(!(EsVacioA(Derecho(db))))//caso
			return RecDer(db);
		else if(!(EsVacioA(Izquierdo(Izquierdo(db)))))//caso
			return db=ConsA(RaizA(db),Izquierdo(Izquierdo(db)),Derecho(db));
			else if(EsVacioA(Izquierdo(Izquierdo(db))))//caso
				return db=ConsA(RaizA(Izquierdo(db)),VacioA(),VacioA());
}
DiccBin RecDer(DiccBin db){
	if(EsHojaA(Derecho(db)))//caso
		return db=ConsA(RaizA(db),Izquierdo(db),VacioA());
	else if((!(EsVacioA(Izquierdo(Derecho(db)))))&&(EsVacioA(Derecho(Derecho(db)))))//caso
			return db=ConsA(RaizA(db),Izquierdo(db),Izquierdo(Derecho(db)));
		 else return db=ConsA(RaizA(db),Izquierdo(db),RecDer(Derecho(db)));
}

///BUSCA EL REMPLAZO EN EL SUBARBOL IZQUIERDO ANTES DE ELIMINAR SU NODO-----------------------------
ElemA RemplazoIzq(DiccBin db){
	if(EsHojaA(db))//caso
		return RaizA(db);
	else if(!(EsVacioA(Derecho(db))))//caso
		return RemDer(db);
	else if(!(EsVacioA(Izquierdo(Izquierdo(db)))))//caso
		return RaizA(Izquierdo(db));
		else if(EsVacioA(Izquierdo(Izquierdo(db))))
			return RaizA(db);
}
ElemA RemDer(DiccBin db){
	if(EsHojaA(Derecho(db)))//caso
		return RaizA(Derecho(db));
	else if((!(EsVacioA(Izquierdo(Derecho(db)))))&&(EsVacioA(Derecho(Derecho(db)))))//caso
		return RaizA(Derecho(db));
		else return RemDer(Derecho(db));
}
//----------------------------------------------------------------------------------------------------------
///FUNCION BUSCA EL NODO EN EL SUBARBOL DERECHO QUE SE VA A ELIMINAR-------------------------------
DiccBin RecorreDer(DiccBin db){
	if(EsHojaA(db))//caso
		return VacioA();
	else if(!(EsVacioA(Izquierdo(db))))//caso
			return RecIzq(db);
		else if(!(EsVacioA(Derecho(Derecho(db)))))//caso
			return db=ConsA(RaizA(db),Izquierdo(db),Derecho(Derecho(db)));
			else if(EsVacioA(Derecho(Derecho(db))))
				return db=ConsA(RaizA(Derecho(db)),VacioA(),VacioA());
}
DiccBin RecIzq(DiccBin db){
	if(EsHojaA(Izquierdo(db)))//caso
		return db=ConsA(RaizA(db),VacioA(),Derecho(db));
	else if((EsVacioA(Izquierdo(Izquierdo(db))))&&(!(EsVacioA(Derecho(Izquierdo(db))))))//caso
			return db=ConsA(RaizA(db),Derecho(Izquierdo(db)),Derecho(db));
		 else return db=ConsA(RaizA(db),RecIzq(Izquierdo(db)),Derecho(db));
}
///BUSCA EL REMPLAZO EN EL SUBARBOL DERECHO ANTES DE ELIMINAR SU NODO-----------------------------
ElemA RemplazoDer(DiccBin db){
	if(EsHojaA(db))//caso
		return RaizA(db);
	else if(!(EsVacioA(Izquierdo(db))))//caso
		return RemIzq(db);
	else if(!(EsVacioA(Derecho(Derecho(db)))))//caso
		return RaizA(Derecho(db));
		else if(EsVacioA(Derecho(Derecho(db))))
			return RaizA(db);
}
ElemA RemIzq(DiccBin db){
	if(EsHojaA(Izquierdo(db)))//caso
		return RaizA(Izquierdo(db));
	else if((EsVacioA(Izquierdo(Izquierdo(db))))&&(!(EsVacioA(Derecho(Izquierdo(db))))))//caso
		return RaizA(Izquierdo(db));
		else return RemIzq(Izquierdo(db));
}
