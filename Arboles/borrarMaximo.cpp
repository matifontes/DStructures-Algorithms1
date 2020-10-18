//PRE: REcibe un arbol binario de busqueda A
//POS: Eliminar el elemento màs grande
void borrarMaximo(NodoAB* & A) {
	if (A != NULL) {
		if (A->der == NULL) {
			NodoAB* borrar = A;
			A = A->izq;
			delete borrar;
		}
		else {
			borrarMaximo(A->der);
		}
	}
}
