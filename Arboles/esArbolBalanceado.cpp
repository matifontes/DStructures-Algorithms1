bool esArbolBalanceado(NodoAB *raiz) {
	if (raiz == NULL) {
		return true;
	}
	int diff = altura(raiz->izq) - altura(raiz->der);

	if (diff < -1 || diff > 1) {
		return false;
	}
	else {
		return esArbolBalanceado(raiz->izq) && esArbolBalanceado(raiz->der);
	}
	
}
