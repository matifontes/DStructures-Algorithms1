void listaOrdenadaSelectionSort(NodoLista*& l)
{
	if (l != NULL) {
		NodoLista* auxActual = l;
		while (auxActual->sig != NULL) {
			NodoLista* auxRecorrer = auxActual->sig;
			NodoLista* min = auxActual;
			while (auxRecorrer != NULL) {
				if (auxRecorrer->dato <= min->dato) {
					min = auxRecorrer;
				}
				auxRecorrer = auxRecorrer->sig;
			}
			if (auxActual->dato > min->dato) {
				int datoAux = min->dato;
				min->dato = auxActual->dato;
				auxActual->dato = datoAux;
			}


			auxActual = auxActual->sig;
		}
	}
}
