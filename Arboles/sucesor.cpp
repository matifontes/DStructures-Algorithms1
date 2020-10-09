int minSucesorAux(int actual, int izq) {
	if (izq == -1 || actual < izq) {
		return actual;
	}
	return izq;

}

int sucesor(NodoAB* a, int n) {

	if (a != NULL) {
		if (a->dato <= n) {
			return sucesor(a->der, n);
		}
		else {
			return minSucesorAux(a->dato, sucesor(a->izq, n));
		}
	}
	return -1;
}
