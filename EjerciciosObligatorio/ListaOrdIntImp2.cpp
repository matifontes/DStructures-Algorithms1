/*Matias Fontes - 248142*/
#include "ListaOrdInt.h"

#ifdef LISTA_ORD_INT_IMP_2

struct NodoABB {
	int dato;
	unsigned int auxiliar; //para saber si hay repetidos y cantidad.
	NodoABB* izq;
	NodoABB* der;
	NodoABB() {}
	NodoABB(int d) : dato(d), izq(NULL), der(NULL), auxiliar(0) {}
};

struct _cabezalListaOrdInt {
	NodoABB* raiz;
	int cantElementos;
};

/*AUX*/
NodoABB* maximoAux(NodoABB* raiz) {
	if (raiz != NULL) {
		if (raiz->der != NULL) {
			maximoAux(raiz->der);
		}
		else {
			return raiz;
		}
	}
}

NodoABB* minimoAux(NodoABB* raiz) {
	if (raiz != NULL) {
		if (raiz->izq != NULL) {
			minimoAux(raiz->izq);
		}
		else {
			return raiz;
		}
	}
	
}


void agregarAux(NodoABB*& raiz, int e) {
	if (raiz == NULL) {
		NodoABB* nuevo = new NodoABB;
		nuevo->dato = e;
		nuevo->auxiliar = 0;
		nuevo->izq = NULL;
		nuevo->der = NULL;
		raiz = nuevo;
	}
	else if (e < raiz->dato) {
		agregarAux(raiz->izq, e);
	}
	else if (e > raiz->dato) {
		agregarAux(raiz->der, e);
	}
	else {
		raiz->auxiliar++;
	}
}


bool borrarMinimoAux(NodoABB*& raiz) {
	if (raiz != NULL) {
		if (raiz->izq != NULL) {
			return borrarMinimoAux(raiz->izq);
		}
		else {
			if (raiz->auxiliar > 0) {
				raiz->auxiliar--;
				return true;
			}
			else {
				NodoABB* borrar = raiz;
				raiz = raiz->der;
				delete borrar;
				return true;
			}
		}
	}
	return false;
}


bool borrarMaximoAux(NodoABB*& raiz) {
	if (raiz != NULL) {
		if (raiz->der != NULL) {
			return borrarMaximoAux(raiz->der);
		}
		else {
			if (raiz->auxiliar > 0) {
				raiz->auxiliar--;
				return true;
			}
			else {
				NodoABB* borrar = raiz;
				raiz = raiz->izq;
				delete borrar;
				return true;
			}
		}
	}
	return false;
}


bool borrarAux(NodoABB*& raiz, int e) {
	if (raiz != NULL) {
		if (e < raiz->dato){
			return borrarAux(raiz->izq, e);
		}
		else if (e > raiz->dato) {
			return borrarAux(raiz->der, e);
		}
		else {
			if (raiz->auxiliar > 0){
				raiz->auxiliar--;
				return true;
			}
			else if (raiz->izq == NULL) {
				NodoABB* borrar = raiz;
				raiz = raiz->der;
				delete borrar;
				return true;
			}
			else if (raiz->der == NULL) {
				NodoABB* borrar = raiz;
				raiz = raiz->izq;
				delete borrar;
				return true;
			}
			else {
				NodoABB* minimo = minimoAux(raiz->der);
				raiz->dato = minimo->dato;
				raiz->auxiliar = minimo->auxiliar;
				minimo->auxiliar = 0;
				borrarMinimoAux(raiz->der);
				return true;
			}
		}
	}
	return false;
}


bool existeAux(int e, NodoABB* raiz) {
	if (raiz == NULL) {
		return false;
	}
	else if (raiz->dato == e) {
		return true;
	}
	else if (e > raiz->dato) {
		return existeAux(e, raiz->der);
	}
	else if (e < raiz->dato) {
		return existeAux(e, raiz->izq);
	}
}

void agregarClon(ListaOrdInt& l, int e, int aux) {
	while (aux >= 0) {
		agregarAux(l->raiz, e);
		l->cantElementos++;
		aux--;
	}
}

void clonAux(NodoABB* raiz, ListaOrdInt& nuevo) {
	if (raiz != NULL) {
		clonAux(raiz->izq, nuevo);
		agregarClon(nuevo, raiz->dato, raiz->auxiliar);
		clonAux(raiz->der, nuevo);
	}
}


void borrarABB(NodoABB*& raiz) {
	if (raiz == NULL) {
		return;
	}
	borrarABB(raiz->izq);
	borrarABB(raiz->der);
	delete raiz;
}

ListaOrdInt crearListaOrdInt() {
	ListaOrdInt nueva = new _cabezalListaOrdInt;
	nueva->raiz = NULL;
	nueva->cantElementos = 0;
	return nueva;
}

void agregar(ListaOrdInt& l, int e) {
	agregarAux(l->raiz, e);
	l->cantElementos++;
}

void borrarMinimo(ListaOrdInt& l) {
	if (l->cantElementos > 0) {
		bool b = borrarMinimoAux(l->raiz);
		if (b) {
			l->cantElementos--;
		}
	}
}

void borrarMaximo(ListaOrdInt& l) {
	if (l->cantElementos > 0) {
		bool b = borrarMaximoAux(l->raiz);
		if (b) {
			l->cantElementos--;
		}
	}
}

void borrar(ListaOrdInt& l, int e) {
	if (l->cantElementos > 0) {
		bool b = borrarAux(l->raiz, e);
		if (b) {
			l->cantElementos--;
		}
	}
}

int minimo(ListaOrdInt l) {
	NodoABB* minimo = minimoAux(l->raiz);
	return minimo->dato; 
}

int maximo(ListaOrdInt l) {
	NodoABB* maximo = maximoAux(l->raiz);
	return maximo->dato;
}

bool existe(ListaOrdInt l, int e) {
	return existeAux(e, l->raiz);
}

bool esVacia(ListaOrdInt l) {
	return l->cantElementos == 0;
}

unsigned int cantidadElementos(ListaOrdInt l) {
	return l->cantElementos;
}

ListaOrdInt clon(ListaOrdInt l) {
	ListaOrdInt retorno = crearListaOrdInt();
	clonAux(l->raiz, retorno);
	return retorno;
}

void destruir(ListaOrdInt& l) {
	borrarABB(l->raiz);
	delete l;
}



#endif