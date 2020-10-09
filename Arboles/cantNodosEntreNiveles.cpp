
int cantNodosEntreNiveles(NodoAB* a, int desde, int hasta) {
	int res = 0;
	if (a != NULL && desde <= hasta && hasta >= 1) {
		if (desde <= 1) {
			res++;
		}
		res = res + cantNodosEntreNiveles(a->izq, desde - 1, hasta - 1);
		res = res + cantNodosEntreNiveles(a->der, desde - 1, hasta - 1);
	}
	return res;
}
