/*Matias Fontes - 248142*/
#include "ColaInt.h"

#ifdef COLA_INT_IMP

struct NodoColaInt {
	int dato;
	NodoColaInt* sig;
	NodoColaInt() : dato(0), sig(NULL) {}
	NodoColaInt(int d) : dato(d), sig(NULL) {}
};

struct _cabezalColaInt {
	NodoColaInt* ppio;
	NodoColaInt* fin;
	int cantElementos;
};

ColaInt crearColaInt() {
	ColaInt ret = new _cabezalColaInt;
	ret->ppio = NULL;
	ret->fin = NULL;
	ret->cantElementos = 0;
	return ret;
}

void encolar(ColaInt& c, int e) {
	NodoColaInt* nuevo = new NodoColaInt;
	nuevo->dato = e;
	nuevo->sig = NULL;

	if (esVacia(c)) {
		c->ppio = nuevo;
		c->fin = nuevo;
	}
	else {
		c->fin->sig = nuevo;
		c->fin = nuevo;
	}
	c->cantElementos++;
}

int principio(ColaInt c) {
	return c->ppio->dato;
}

void desencolar(ColaInt& c) {
	NodoColaInt* borrar = c->ppio;
	c->ppio = c->ppio->sig;
	delete borrar;
	c->cantElementos--;
}

bool esVacia(ColaInt c) {
	return c->cantElementos == 0;
}

unsigned int cantidadElementos(ColaInt c) {
	return c->cantElementos;
}

ColaInt clon(ColaInt c) {
	ColaInt ret = crearColaInt();
	NodoColaInt* temp = c->ppio;
	while (temp != NULL) {
		encolar(ret, temp->dato);
		temp = temp->sig;
	}
	return ret;
}

void destruir(ColaInt& c) {
	while (!esVacia(c)) {
		desencolar(c);
	}
	delete c;
}

#endif