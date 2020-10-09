NodoLista* enNivel(NodoAB *a, int k) {
	NodoLista* res = NULL;
	NodoLista* auxRecorrer = NULL;
	if (a == NULL) {
		return res;
	}
	if (k == 1) {
		res = new NodoLista(a->dato);
		return res;
	}
	else if (k > 1) {
		res = enNivel(a->izq, k - 1);
		if (res != NULL) {
			auxRecorrer = res;
			while (auxRecorrer->sig != NULL) {
				auxRecorrer = auxRecorrer->sig;
			}
			auxRecorrer->sig = enNivel(a->der, k - 1);
		}
		else {
			res = enNivel(a->der, k - 1);
		}
		return res;
	}

}
