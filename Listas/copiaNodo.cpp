//PRE: Recibe un nodo
//POS: Crea una copia de ese nodo y la devuelve sin compartir memoria
NodoLista* copiaNodo(NodoLista* l) {
	NodoLista* res = new NodoLista;
	res->sig = NULL;
	res->dato = l->dato;
	return res;
}
