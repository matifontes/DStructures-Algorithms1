/*Matias Fontes - 248142*/
#include "DiccionarioInt.h"

#ifdef DICCIONARIO_INT_IMP

struct NodoDiccionarioInt {
	int dato;
	NodoDiccionarioInt* sig;
	NodoDiccionarioInt() : dato(0), sig(NULL) {}
	NodoDiccionarioInt(int d) : dato(d), sig(NULL) {}
};

struct _cabezalDiccionarioInt {
	NodoDiccionarioInt** tabla;
	int cantidad;
	int esperados;
};


DiccionarioInt crearDiccionarioInt(unsigned int esperados) {
	DiccionarioInt retorno = new _cabezalDiccionarioInt();
	retorno->tabla = new NodoDiccionarioInt * [esperados];
	retorno->cantidad = 0;
	retorno->esperados = esperados;
	for (int i = 0; i < esperados; i++) {
		retorno->tabla[i] = NULL;
	}
	return retorno;
}

void agregar(DiccionarioInt& d, int e) {
	if (!pertenece(d, e)) {
		NodoDiccionarioInt* nuevo = new NodoDiccionarioInt(e);
		int hash = abs(e) % d->esperados;
		nuevo->sig = d->tabla[hash];
		d->tabla[hash] = nuevo;
		d->cantidad++;
	}
}

void borrar(DiccionarioInt& d, int e) {
	int hash = abs(e) % d->esperados;
	if (d->tabla[hash] != NULL) {
		if (d->tabla[hash]->dato == e) {
			NodoDiccionarioInt* borrar = d->tabla[hash];
			d->tabla[hash] = d->tabla[hash]->sig;
			delete borrar;
			d->cantidad--;
		}
		else {
			NodoDiccionarioInt* aux = d->tabla[hash];
			while (aux->sig != NULL && aux->sig->dato != e) {
				aux = aux->sig;
			}
			if (aux->sig != NULL && aux->sig->dato == e) {
				NodoDiccionarioInt* borrar = aux->sig;
				aux->sig = aux->sig->sig;
				delete borrar;
				d->cantidad--;
			}
		}
	}
}

bool pertenece(DiccionarioInt d, int e) {
	int hash = abs(e) % d->esperados;
	NodoDiccionarioInt* aux = d->tabla[hash];
	if (aux == NULL) {
		return false;
	}else if (aux->dato == e) {
		return true;
	}
	else {
		while (aux != NULL) {
			if (aux->dato == e) {
				return true;
			}
			aux = aux->sig;
		}
		return false;
	}
}

int elemento(DiccionarioInt d) {
	if (!esVacio(d)) {
		for (int i = 0; i < d->esperados; i++) {
			if (d->tabla[i] != NULL) {
				return d->tabla[i]->dato;
			}
		}
	}
}

bool esVacio(DiccionarioInt d) {
	return d->cantidad == 0;
}

unsigned int cantidadElementos(DiccionarioInt d) {
	return d->cantidad;
}

DiccionarioInt clon(DiccionarioInt d) {
	DiccionarioInt ret = crearDiccionarioInt(d->esperados);
	ret->cantidad = d->cantidad;
	for (int i = 0; i < d->esperados; i++) {
		if (d->tabla[i] != NULL) {
			NodoDiccionarioInt* aux = d->tabla[i];
			while (aux != NULL) {
				NodoDiccionarioInt* nuevo = new NodoDiccionarioInt(aux->dato);
				NodoDiccionarioInt* fin = ret->tabla[i];
				if (fin == NULL) {
					ret->tabla[i] = nuevo;
				}
				else {
					while (fin->sig != NULL) {
						fin = fin->sig;
					}
					fin->sig = nuevo;
				}
				aux = aux->sig;
			}
		}
	}
	return ret;
}

void destruir(DiccionarioInt& d) {
	for(int i=0; i<d->esperados; i++) {
		while (d->tabla[i] != NULL) {
			NodoDiccionarioInt* borrar = d->tabla[i];
			d->tabla[i] = d->tabla[i]->sig;
			delete borrar;
		}
	}
	delete[] d->tabla;
	delete d;
}


#endif