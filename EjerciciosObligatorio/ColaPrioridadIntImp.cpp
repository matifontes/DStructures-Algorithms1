/*Matias Fontes - 248142*/
#include "ColaPrioridadInt.h"

#ifdef COLAPRIORIDAD_INT_IMP

struct NodoColaPrioInt {
	int dato;
	int prio;
	NodoColaPrioInt* sig;
	NodoColaPrioInt() : dato(0), prio(0), sig(NULL) {}
	NodoColaPrioInt(int d, int e) : dato(d), prio(e), sig(NULL) {}
};

struct _cabezalColaPrioridadInt {
	NodoColaPrioInt* ppio;
	NodoColaPrioInt* fin;
	int cantElementos;
};


ColaPrioridadInt crearColaPrioridadInt() {
	ColaPrioridadInt ret = new _cabezalColaPrioridadInt;
	ret->ppio = NULL;
	ret->fin = NULL;
	ret->cantElementos = 0;
	return ret;
}

void encolar(ColaPrioridadInt& c, int e, int p) {
	NodoColaPrioInt* nuevo = new NodoColaPrioInt();
	nuevo->dato = e;
	nuevo->prio = p;
	nuevo->sig = NULL;

	if (esVacia(c)) {
		c->ppio = nuevo;
		c->fin = nuevo;
		c->cantElementos++;
	}
	else {
		if (nuevo->prio > c->ppio->prio) {
			nuevo->sig = c->ppio;
			c->ppio = nuevo;
			c->cantElementos++;
		}
		else if (nuevo->prio <= c->fin->prio) {
			c->fin->sig = nuevo;
			c->fin = nuevo;
			c->cantElementos++;
		}
		else {
			NodoColaPrioInt* ant = NULL;
			NodoColaPrioInt* aux = c->ppio;
			while (nuevo->prio <= aux->prio) {
				ant = aux;
				aux = aux->sig;
			}
			ant->sig = nuevo;
			nuevo->sig = aux;
			c->cantElementos++;
		}
	}
}

int principio(ColaPrioridadInt c) {
	if (!esVacia(c)) {
		return c->ppio->dato;
	}
}

int principioPrioridad(ColaPrioridadInt c) {
	if (!esVacia(c)) {
		return c->ppio->prio;
	}
}

void desencolar(ColaPrioridadInt& c) {
	NodoColaPrioInt* borrar = c->ppio;
	c->ppio = c->ppio->sig;
	delete borrar;
	c->cantElementos--;
}

bool esVacia(ColaPrioridadInt c) {
	return c->cantElementos == 0;
}

unsigned int cantidadElementos(ColaPrioridadInt c) {
	return c->cantElementos;
}

ColaPrioridadInt clon(ColaPrioridadInt c) {
	ColaPrioridadInt ret = crearColaPrioridadInt();
	NodoColaPrioInt* temp = c->ppio;
	while (temp != NULL) {
		encolar(ret, temp->dato, temp->prio);
		temp = temp->sig;
	}
	return ret;
}

void destruir(ColaPrioridadInt& c) {
	while (!esVacia(c)) {
		desencolar(c);
	}
	delete c;
}

#endif