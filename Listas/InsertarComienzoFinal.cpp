void agregarAlInicio(NodoLista* nuevo, NodoLista*& res, NodoLista*& aux) {
	if (res == NULL) {
		nuevo->sig = res;
		res = nuevo;
		aux = res;
	}
	else {
		nuevo->sig = res;
		res = nuevo;
	}
}

NodoLista* insComFin(NodoLista* l, int x)
{
	NodoLista* res = NULL;
	NodoLista* ultimo = NULL;
	while (l) {
		NodoLista* nuevo = copiaNodo(l);
		agregarAlInicio(nuevo, res, ultimo);
		l = l->sig;
	}

	NodoLista* primerElem = new NodoLista(x);
	NodoLista* ultimoElem = new NodoLista(x);
	agregarAlInicio(primerElem, res, ultimo);
	
	if (ultimo != NULL) {
		ultimo->sig = ultimoElem;
	}
	else {
		agregarAlInicio(ultimoElem, res, ultimo);
	}

	return res;
}
