//PRE: Recibe un nodo
//POS: Crea una copia de ese nodo y la devuelve sin compartir memoria
NodoLista* copiaNodo(NodoLista* l) {
	NodoLista* res = new NodoLista;
	res->sig = NULL;
	res->dato = l->dato;
	return res;
}


//PRE: Recibe un nodo nuevo, y dos listas simplemente enlazadas.
//POS: Se debe agregar el nodo nuevo a la lista res y en caso que sea el primer nodo de la lista res actualizar aux (que apunte a res)
void insertarNodo(NodoLista* nuevo, NodoLista*& res, NodoLista*& aux) {
	if (res == NULL) {
		nuevo->sig = res;
		res = nuevo;
		aux = res;
	}
	else {
		res->sig = nuevo;
		res = res->sig;
	}
}

NodoLista* intercalarIter(NodoLista* l1, NodoLista* l2)
{

	NodoLista* res = NULL;
	NodoLista* aux = res;

	if (l1 != NULL && l2 != NULL) {
		while (l1 != NULL && l2 != NULL) {
			if (l1->dato <= l2->dato) {
				NodoLista* nuevo = copiaNodo(l1);
				insertarNodo(nuevo, res, aux);
				l1 = l1->sig;
			} else {
				NodoLista* nuevo = copiaNodo(l2);
				insertarNodo(nuevo, res, aux);
				l2 = l2->sig;
			}
		}
	}
	

	if (l1 == NULL) {
		while (l2 != NULL) {
			NodoLista* nuevo = copiaNodo(l2);
			insertarNodo(nuevo, res, aux);
			l2 = l2->sig;
		}
	}
	else {
		while (l1 != NULL) {
			NodoLista* nuevo = copiaNodo(l1);
			insertarNodo(nuevo, res, aux);
			l1 = l1->sig;
		}
	}

	return aux;
}
