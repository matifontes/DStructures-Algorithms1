
void borrarNodoRaiz(NodoAB * & A) {

	if (A->der == NULL && A->izq == NULL) {
		delete A;
		A = NULL;
	}
	else if (A->der != NULL & A->izq == NULL) {
		NodoAB* borrar = A;
		A = A->der;
		delete borrar;
	}
	else if (A->der == NULL && A->izq != NULL) {
		NodoAB* borrar = A;
		A = A->izq;
		delete borrar;
	}
	else {
		A->dato = maximo(A->izq);
		borrarMaximo(A->izq);
	}
