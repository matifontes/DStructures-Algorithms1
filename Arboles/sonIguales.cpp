bool sonIguales(NodoAB* p, NodoAB* q) 
{
	if (p == NULL && q == NULL) {
		return true;
	}
	else if (p == NULL && q != NULL) {
		return false;
	}
	else if (p != NULL && q == NULL) {
			return false;
	}

	if (p->dato != q->dato) {
		return false;
	}

	return sonIguales((p->der), (q->der)) && sonIguales((p->izq), (q->izq));
}
