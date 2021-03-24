/*Matias Fontes - 248142*/
#include "MultisetInt.h"

#ifdef MULTISET_INT_IMP


struct NodoMultiSet {
	int dato;
	int ocurrencias;
	NodoMultiSet* sig;
	NodoMultiSet() : dato(0), ocurrencias(0), sig(NULL) {}
	NodoMultiSet(int d, int o) : dato(d), ocurrencias(o), sig(NULL) {}
};

struct _cabezalMultisetInt {
	NodoMultiSet* ppio;
	unsigned int cantElementos;
};

MultisetInt crearMultisetInt() {
	MultisetInt retorno = new _cabezalMultisetInt;
	retorno->ppio = NULL;
	retorno->cantElementos = 0;
	return retorno;
}


void agregar(MultisetInt& s, int e, unsigned int ocurrencias){
	if (pertenece(s, e)) {
		NodoMultiSet* aux = s->ppio;
		while (aux->dato != e) {
			aux = aux->sig;
		}
		aux->ocurrencias = aux->ocurrencias + ocurrencias;
		s->cantElementos = s->cantElementos + ocurrencias;
	}
	else {
		NodoMultiSet* nuevo = new NodoMultiSet;
		nuevo->dato = e;
		nuevo->ocurrencias = ocurrencias;
		nuevo->sig = s->ppio;
		s->ppio = nuevo;
		s->cantElementos = s->cantElementos + ocurrencias;
	}
}

void borrar(MultisetInt& s, int e) {
	NodoMultiSet* auxRecorrer = s->ppio;
		
	while (auxRecorrer != NULL && auxRecorrer->dato != e ) {
		auxRecorrer = auxRecorrer->sig;
	}
	if (auxRecorrer != NULL) {
		if (auxRecorrer->ocurrencias > 1) {
			auxRecorrer->ocurrencias--;
			s->cantElementos--;
		}
		else {
			if (auxRecorrer->dato == s->ppio->dato) {
				s->ppio = s->ppio->sig;
				delete auxRecorrer;
				s->cantElementos--;
			}
			else {
				NodoMultiSet* ant = s->ppio;
				while (ant->sig != NULL && ant->sig->dato != e) {
					ant = ant->sig;
				}
				ant->sig = auxRecorrer->sig;
				auxRecorrer->sig = NULL;
				delete auxRecorrer;
				s->cantElementos--;
			}
		}
	}
}

bool pertenece(MultisetInt s, int e) {
	if (!esVacio(s)) {
		NodoMultiSet* aux = s->ppio;
		while (aux != NULL) {
			if (aux->dato == e) {
				return true;
			}
			aux = aux->sig;
		}
		return false;
	}
	else {
		return false;
	}
}

MultisetInt unionConjuntos(MultisetInt s1, MultisetInt s2) {
	MultisetInt retorno = crearMultisetInt();
	
	NodoMultiSet* auxS1 = s1->ppio;
	while (auxS1 != NULL) {
		agregar(retorno, auxS1->dato, auxS1->ocurrencias);
		auxS1 = auxS1->sig;
	}

	NodoMultiSet* auxS2 = s2->ppio;
	while (auxS2 != NULL) {
		if (pertenece(retorno, auxS2->dato)) {
			NodoMultiSet* aux = retorno->ppio;
			while (aux->dato != auxS2->dato) {
				aux = aux->sig;
			}
			if (aux->ocurrencias < auxS2->ocurrencias) {
				int auxCant = auxS2->ocurrencias - aux->ocurrencias;
				aux->ocurrencias = auxS2->ocurrencias;
				retorno->cantElementos = retorno->cantElementos + auxCant;
			}
		}
		else {
			agregar(retorno, auxS2->dato, auxS2->ocurrencias);
		}
		auxS2 = auxS2->sig;
	}
	return retorno;
}

MultisetInt interseccionConjuntos(MultisetInt s1, MultisetInt s2) {
	MultisetInt retorno = crearMultisetInt();


	NodoMultiSet* auxS1 = s1->ppio;
	while (auxS1 != NULL) {
		if (pertenece(s2, auxS1->dato)) {
			NodoMultiSet* auxS2 = s2->ppio;
			while (auxS2->dato != auxS1->dato) {
				auxS2 = auxS2->sig;
			}

			if (auxS2->ocurrencias < auxS1->ocurrencias) {
				agregar(retorno, auxS1->dato, auxS2->ocurrencias);
			}
			else {
				agregar(retorno, auxS1->dato, auxS1->ocurrencias);
			}
		}
		auxS1 = auxS1->sig;
	}
	return retorno;
}

MultisetInt diferenciaConjuntos(MultisetInt s1, MultisetInt s2) {
	MultisetInt retorno = crearMultisetInt();


	NodoMultiSet* auxS1 = s1->ppio;
	while (auxS1 != NULL) {
		if (!pertenece(s2, auxS1->dato)) {
			agregar(retorno, auxS1->dato, auxS1->ocurrencias);
		}
		else {
			NodoMultiSet* auxS2 = s2->ppio;
			while (auxS1->dato != auxS2->dato) {
				auxS2 = auxS2->sig;
			}
			if (auxS1->ocurrencias > auxS2->ocurrencias) {
				int auxOcurrencias = auxS1->ocurrencias - auxS2->ocurrencias;
				agregar(retorno, auxS1->dato, auxOcurrencias);
			}
		}
		auxS1 = auxS1->sig;
	}

	return retorno;
}


bool contenidoEn(MultisetInt s1, MultisetInt s2) {
	bool ret = true;
	NodoMultiSet* auxS1 = s1->ppio;
	while (auxS1 != NULL) {
		if (!pertenece(s2, auxS1->dato)) {
			return false;
		}
		else {
			NodoMultiSet* auxS2 = s2->ppio;
			while (auxS1->dato != auxS2->dato) {
				auxS2 = auxS2->sig;
			}
			if (auxS1->ocurrencias > auxS2->ocurrencias) {
				return false;
			}
		}
		auxS1 = auxS1->sig;
	}
	return ret;
}

int elemento(MultisetInt s) {
	return s->ppio->dato;
}

bool esVacio(MultisetInt s) {
	return s->cantElementos == 0;
}

unsigned int cantidadElementos(MultisetInt s) {
	return s->cantElementos;
}

void destruir(MultisetInt& s) {
	while (s->ppio != NULL) {
		NodoMultiSet* aux = s->ppio;
		s->ppio = s->ppio->sig;
		delete aux;
	}
	delete s;
}

MultisetInt clon(MultisetInt s) {
	MultisetInt ret = crearMultisetInt();
	NodoMultiSet* aux = s->ppio;
	while (aux != NULL) {
		agregar(ret, aux->dato, aux->ocurrencias);
		aux = aux->sig;
	}
	return ret;
}

#endif