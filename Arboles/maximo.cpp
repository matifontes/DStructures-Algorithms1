//PRE: Recibe un arbol binario de busqueda A, no vacio.
//POS: Devuelve el nodo con mayor valor (A->dato);
int maximo(NodoAB* A) {
	if (A->der == NULL) {
		return A->dato;
	}
	return maximo(A->der);

}
