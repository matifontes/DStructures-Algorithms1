NodoLista* intercalarRec(NodoLista* l1, NodoLista* l2)
{
	NodoLista* res = NULL;
	if (l1 == NULL && l2 == NULL)
		return res;


	if (l1 != NULL && l2 != NULL) {
		if (l1->dato > l2->dato) {
			res = copiaNodo(l2);
			res->sig = intercalarRec(l1, l2->sig);
		}
		else {
			res = copiaNodo(l1);
			res->sig = intercalarRec(l1->sig, l2);
		}
	}
	else {
		if (l1 == NULL) {
			res = copiaNodo(l2);
			res->sig = intercalarRec(l1, l2->sig);
		}
		else if (l2 == NULL) {
			res = copiaNodo(l1);
			res->sig = intercalarRec(l1->sig, l2);
		}
	}
	return res;
}
