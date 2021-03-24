#pragma once

// Elegir la implementacion a usar (solo 1 a la vez):
#define LISTA_ORD_INT_IMP
//#define LISTA_ORD_INT_IMP_2

#if defined(LISTA_ORD_INT_IMP)
	#include "ListaOrdIntImp.h"
#elif defined(LISTA_ORD_INT_IMP_2)
	#include "ListaOrdIntImp2.h"
#endif

// PRE: -
// POS: retorna una nueva lista vacia
ListaOrdInt crearListaOrdInt();

// PRE: -
// POS: agrega el elemento e en la lista ordenada de menor a mayor
void agregar(ListaOrdInt& l, int e);

// PRE: -
// POS: borra el menor elemento de la lista. Si no hay elementos no tiene efecto
void borrarMinimo(ListaOrdInt& l);

// PRE: -
// POS: borra el mayor elemento de la lista. Si no hay elementos no tiene efecto
void borrarMaximo(ListaOrdInt& l);

// PRE: -
// POS: borra el primer elemento que sea igual a e
//        Si no encuentra no tiene efecto
void borrar(ListaOrdInt& l, int e);

// PRE: !esVacia()
// POS: retorna el menor elemento
int minimo(ListaOrdInt l);

// PRE: !esVacia()
// POS: retorna el mayor elemento     
int maximo(ListaOrdInt l);

// PRE: -
// POS: retorna true sii existe al menos un elemento que sea igual a e
bool existe(ListaOrdInt l, int e);

// PRE: -
// POS: retorna true si la lista esta vacia
bool esVacia(ListaOrdInt l);

// PRE: -
// POS: retorna la cantidad de elementos presentes en la lista
unsigned int cantidadElementos(ListaOrdInt l);

// PRE: -
// POS: retorna una copia de la lista l sin compartir memoria
ListaOrdInt clon(ListaOrdInt l);

// PRE: -
// POS: libera la memoria de la lista
void destruir(ListaOrdInt& l);


