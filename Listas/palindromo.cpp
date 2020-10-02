bool palindromo(NodoLista* l)
{
	NodoLista* aux = NULL;
	NodoLista* recorrerAux = l;
	
	while (recorrerAux) {
		NodoLista* nuevo = copiaNodo(recorrerAux);
		if (aux == NULL) {
			nuevo->sig = aux;
			aux = nuevo;
		}
		else {
			nuevo->sig = aux;
			aux = nuevo;
		}
		recorrerAux = recorrerAux->sig;
	}

	bool res = true;

	while (l && aux && res) {
		if (aux->dato != l->dato) {
			res = false;
		}
		l = l->sig;
		aux = aux->sig;
	}

	return res;
}
