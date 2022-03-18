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
}*/