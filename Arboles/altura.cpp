int max(int a, int b) {
	if (a < b) {
		return b;
	}
	else {
		return a;
	}
}
int altura(NodoAB* raiz){
	// IMPLEMENTAR SOLUCION
	if (raiz == NULL) {
		return 0;
	}
	else {
		return 1 + max(altura(raiz->der), altura(raiz->izq));
	}
}
