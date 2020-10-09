int sumaPorNiveles(NodoAG* raiz){
	if (raiz == NULL) {
		return 0;
	}
	else {
		return (-1 * raiz->dato + -1 * sumaPorNiveles(raiz->ph) + sumaPorNiveles(raiz->sh));
	}

}
