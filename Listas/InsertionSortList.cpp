//PRE: Recibe un nodo
//POS: Crea una copia de ese nodo y la devuelve sin compartir memoria
NodoLista* copiaNodo(NodoLista* l) {
	NodoLista* res = new NodoLista;
	res->sig = NULL;
	res->dato = l->dato;
	return res;
}

NodoLista* listaOrdenadaInsertionSort(NodoLista* l) 
{
	NodoLista* res = NULL;
	while (l != NULL) {
		NodoLista* nuevo = copiaNodo(l);
		if (res == NULL) {
			res = nuevo;
		}
		else if (nuevo->dato <= res->dato) {
			nuevo->sig = res;
			res = nuevo;
		}
		else if (nuevo->dato > res->dato) {
			NodoLista* aux = NULL;
			NodoLista* auxRecorrer = res;
			while (nuevo->dato > auxRecorrer->dato && auxRecorrer->sig != NULL) {
				aux = auxRecorrer;
				auxRecorrer = auxRecorrer->sig;
			}
			if (nuevo->dato <= auxRecorrer->dato) {
				nuevo->sig = auxRecorrer;
				aux->sig = nuevo;
			}
			else if (auxRecorrer->sig == NULL) {
				auxRecorrer->sig = nuevo;
			}
		}
		l = l->sig;
	}

	return res;
}
