NodoAB* invertirHastak(NodoAB* a, int k) {
	if (k == 0 || a == NULL) {
		return NULL;
	}
	
	NodoAB* res = new NodoAB(a->dato);
	res->izq = invertirHastak(a->der, k - 1);
	res->der = invertirHastak(a->izq, k - 1);

	return res;

}
