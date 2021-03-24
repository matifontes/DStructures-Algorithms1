/*Matias Fontes - 248142*/

#include "ListaPosInt.h"

#ifdef LISTA_POS_INT_IMP

#define AGRANDO_EN 10

struct _cabezalListaPosInt {
	int* vec;
	unsigned int tamVec;
	unsigned int cantElementos;
	
};

ListaPosInt crearListaPosInt()
{
	ListaPosInt ret = new _cabezalListaPosInt;
	ret->cantElementos = 0;
	ret->tamVec = AGRANDO_EN;
	ret->vec = new int[AGRANDO_EN];
	return ret;
}


/*Auxiliares*/
void expandir(ListaPosInt& l) {
	if (l->cantElementos == l->tamVec) {
		int* nuevo = new int[l->tamVec + AGRANDO_EN];
		for (int i = 0; i < l->cantElementos; i++) {
			nuevo[i] = l->vec[i];
		}
		l->tamVec = l->tamVec + AGRANDO_EN;
		delete[] l->vec;
		l->vec = nuevo;
	}
}

void correrHaciaAdelante(ListaPosInt& l, int desde) {
	if (desde < l->tamVec) {
		for (int i = l->cantElementos - 1; i >= desde; i--) {
			l->vec[i + 1] = l->vec[i];
		}
	}

}

void correrHaciaAtras(ListaPosInt& l, int hasta) {
	for (int i = hasta; i < l->cantElementos; i++) {
		l->vec[i] = l->vec[i + 1];
	}
}

/*FUNCIONES */

void agregar(ListaPosInt& l, int e, unsigned int pos)
{
	int posNueva = pos;
	if (pos >= l->cantElementos) {
		posNueva = l->cantElementos;
	}
	expandir(l);
	correrHaciaAdelante(l, posNueva);
	l->vec[posNueva] = e;
	l->cantElementos++;
}

void borrar(ListaPosInt& l, unsigned int pos)
{
	if (pos < l->cantElementos) {
		correrHaciaAtras(l, pos);
		l->cantElementos--;
	}
}

int elemento(ListaPosInt l, unsigned int pos)
{
	return l->vec[pos];
}

bool esVacia(ListaPosInt l)
{
	return l->cantElementos == 0;
}

unsigned int cantidadElementos(ListaPosInt l)
{
	return l->cantElementos;
}

ListaPosInt clon(ListaPosInt l)
{
	ListaPosInt ret = crearListaPosInt();
	ret->tamVec = l->tamVec;
	for (int i = 0; i < l->cantElementos; i++) {
		agregar(ret, l->vec[i], i);
	}
	return ret;
}

void destruir(ListaPosInt& l)
{
	delete[] l->vec;
	delete l;
}


#endif