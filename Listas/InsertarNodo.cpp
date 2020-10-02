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
