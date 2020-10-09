NodoLista* camino(NodoAB *arbol, int x) {
	NodoLista* res = NULL;

	res = new NodoLista(arbol->dato);

	if (arbol->dato < x) {
		res->sig = camino(arbol->der, x);
	}
	else if(arbol->dato > x) {
		res->sig = camino(arbol->izq, x);
	}

	return res;
}
