/*Matias Fontes - 248142*/
#include "Ejercicios.h"

void EnlistarAux(NodoABInt* a, ListaOrdInt& lista) {
	if (a != NULL) {
		EnlistarAux(a->der, lista);
		agregar(lista, a->dato);
		EnlistarAux(a->izq, lista);
	}
}

ListaOrdInt Enlistar(NodoABInt* a)
{
	ListaOrdInt res = crearListaOrdInt();

	EnlistarAux(a, res);
	return res;
}

ListaOrdInt UnionListaOrd(ListaOrdInt l1, ListaOrdInt l2)
{
	ListaOrdInt res = crearListaOrdInt();
	ListaOrdInt clonl1 = clon(l1);
	ListaOrdInt clonl2 = clon(l2);

	while (!esVacia(clonl1)) {
		agregar(res, minimo(clonl1));
		borrarMinimo(clonl1);
	}

	while (!esVacia(clonl2)) {
		agregar(res, minimo(clonl2));
		borrarMinimo(clonl2);
	}

	destruir(clonl1);
	destruir(clonl2);

	return res;
}

bool EstaContenida(PilaInt p1, PilaInt p2)
{
	bool ret = false;

	if (cantidadElementos(p2) >= cantidadElementos(p1)) {
		PilaInt clonP1 = clon(p1);
		PilaInt clonP2 = clon(p2);
		ListaOrdInt p1Lista = crearListaOrdInt();
		ListaOrdInt p2Lista = crearListaOrdInt();

		while (!esVacia(clonP1)) {
			agregar(p1Lista, top(clonP1));
			pop(clonP1);
		}

		while (!esVacia(clonP2)) {
			agregar(p2Lista, top(clonP2));
			pop(clonP2);
		}

		while (!esVacia(p2Lista) && !esVacia(p1Lista)) {
			if (existe(p2Lista, minimo(p1Lista))) {
				borrar(p2Lista, (minimo(p1Lista)));
				borrarMinimo(p1Lista);
			}
			else {
				borrarMinimo(p2Lista);
			}
		}
		ret = esVacia(p1Lista);

		destruir(clonP1);
		destruir(clonP2);
		destruir(p1Lista);
		destruir(p2Lista);
	}


	return ret;

}


ListaOrdInt ObtenerRepetidos(MultisetInt m) 
{
	ListaOrdInt retorno = crearListaOrdInt();
	MultisetInt clonM1 = clon(m);

	while (!esVacio(clonM1)) {
		if (!existe(retorno, elemento(clonM1))) {
			int elementoAgregar = elemento(clonM1);
			borrar(clonM1, elemento(clonM1));

			if (pertenece(clonM1, elementoAgregar)) {
				agregar(retorno, elementoAgregar);
			}

			while (pertenece(clonM1, elementoAgregar)) {
				borrar(clonM1, elementoAgregar);
			}
		}
	}
	destruir(clonM1);
	return retorno;
}

MultisetInt Xor(MultisetInt m1, MultisetInt m2)
{
	
	MultisetInt clonM1 = clon(m1);
	MultisetInt clonM2 = clon(m2);
	MultisetInt retorno = diferenciaConjuntos(clonM1, clonM2);
	MultisetInt diferenciaM2 = diferenciaConjuntos(clonM2, clonM1);

	while (!esVacio(diferenciaM2)) {
		int elem = elemento(diferenciaM2);
		agregar(retorno, elem, 1);
		borrar(diferenciaM2, elem);
	}

	destruir(clonM1);
	destruir(clonM2);
	destruir(diferenciaM2);

	return retorno;
}

ColaPrioridadInt MenorPrioridad(ColaPrioridadInt c) {
	ColaPrioridadInt retorno = crearColaPrioridadInt();
	if (!esVacia(c)) {
		ColaPrioridadInt clonC1 = clon(c);
		int menorPrio = principioPrioridad(clonC1);
		while (!esVacia(clonC1)) {
			menorPrio = principioPrioridad(clonC1);
			desencolar(clonC1);
		}
		destruir(clonC1);

		ColaPrioridadInt clonAux = clon(c);
		while (!esVacia(clonAux)) {
			if (principioPrioridad(clonAux) == menorPrio) {
				int e = principio(clonAux);
				encolar(retorno, e, menorPrio);
			}
			desencolar(clonAux);
		}
		destruir(clonAux);
	}
	return retorno;
}

