/*Matias Fontes - 248142*/
#include "PilaInt.h"

#ifdef PILA_INT_IMP

struct NodoPilaInt {
	int dato;
	NodoPilaInt* sig;
	NodoPilaInt() : dato(0), sig(NULL) {}
	NodoPilaInt(int d) : dato(d), sig(NULL) {}
};


struct _cabezalPilaInt {
	NodoPilaInt* top;
	unsigned int cantElementos;
};


PilaInt crearPilaInt(){
	PilaInt ret = new _cabezalPilaInt;
	ret->top = NULL;
	ret->cantElementos = 0;
	return ret;
}

void push(PilaInt& p, int e) {
	NodoPilaInt* nuevo = new NodoPilaInt;
	nuevo->dato = e;
	nuevo->sig = p->top;
	p->top = nuevo;
	p->cantElementos++;
}

int top(PilaInt p) {
	if (!esVacia(p)) {
		return p->top->dato;
	}
}

void pop(PilaInt& p) {
	if (!esVacia(p)) {
		NodoPilaInt* borrar = p->top;
		p->top = p->top->sig;
		delete borrar;
		p->cantElementos--;
	}
}

unsigned int cantidadElementos(PilaInt p) {
	return p->cantElementos;
}

bool esVacia(PilaInt p) {
	return p->cantElementos == 0;
}

PilaInt clon(PilaInt p) {
	PilaInt ret = crearPilaInt();
	PilaInt alReves = crearPilaInt();

	NodoPilaInt* temp = p->top;
	while (temp != NULL) {
		push(alReves, temp->dato);
		temp = temp->sig;
	}
	while (!esVacia(alReves)) {
		push(ret, top(alReves));
		pop(alReves);
	}
	destruir(alReves);
	return ret;
}

void destruir(PilaInt& p) {
	while (!esVacia(p)) {
		pop(p);
	}
	delete p;
}


#endif