bool esPrefijo(NodoAG *a, NodoLista *l)
{
	if (l == NULL) {
		return true;
	}
	else if (a != NULL) {
		if (a->dato == l->dato) {
			return esPrefijo(a->ph, l->sig) || esPrefijo(a->sh, l);
		}
		else {
			return esPrefijo(a->sh, l);
		}

	}
	return false;
}
