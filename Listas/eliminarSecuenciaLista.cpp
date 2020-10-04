void eliminarSecuencia(NodoLista* &l, NodoLista* secuencia) 
{
	bool encontroCoincidencia = false;

	if (coincideSecuencia(l, secuencia)) {
		while (secuencia) {
			NodoLista* auxBorrar = l;
			l = l->sig;
			delete auxBorrar;
			secuencia = secuencia->sig;
		}
		encontroCoincidencia = true;
	}

	if (!encontroCoincidencia) {
		NodoLista* auxRecorrer = l;
		while (auxRecorrer != NULL && auxRecorrer->sig != NULL) {
			if (coincideSecuencia(auxRecorrer->sig, secuencia)) {
				while (secuencia) {
					NodoLista* auxBorrar = auxRecorrer->sig;
					auxRecorrer->sig = auxRecorrer->sig->sig;
					delete auxBorrar;
					secuencia = secuencia->sig;
				}
			}
			auxRecorrer = auxRecorrer->sig;
		}
	}
		
}
