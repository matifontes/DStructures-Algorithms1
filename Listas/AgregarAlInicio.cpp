//PRE: Recibe una lista res, una lista aux y un nodo nuevo
//POS: agrega nodo nuevo al principio de la lista res y en caso de que sea el primer nodo de res aux apunta a ese nodo.
void agregarAlInicio(NodoLista* nuevo, NodoLista*& res, NodoLista*& aux) {
	if (res == NULL) {
		nuevo->sig = res;
		res = nuevo;
		aux = res;
	}
	else {
		nuevo->sig = res;
		res = nuevo;
	}
}




