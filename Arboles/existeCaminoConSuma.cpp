bool existeCaminoConSuma(NodoAB* raiz, int sum) {
	bool res = false;
	if (raiz == NULL){
		return true;
	}
	else {
		int diff = sum - raiz->dato;
		if (diff != 0 && esHoja(raiz)) {
			return false;
		}

		if (diff == 0 && esHoja(raiz)) {
			return true;
		}

		if (raiz->izq != NULL) {
			res = existeCaminoConSuma(raiz->izq, diff);
		}

		if (raiz->der != NULL) {
			res = res || existeCaminoConSuma(raiz->der, diff);
		}

		return res;
	}
}
