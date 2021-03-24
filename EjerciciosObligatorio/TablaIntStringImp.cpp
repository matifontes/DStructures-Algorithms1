/*Matias Fontes - 248142*/
#include "TablaIntString.h"

#ifdef TABLA_INT_STRING_IMP

struct NodoTabla {
	int dominio;
	char* rango;
	NodoTabla* sig;
	NodoTabla() : dominio(0), rango(NULL), sig(NULL) {}
	NodoTabla(int d, char* r) : dominio(d),rango(r), sig(NULL) {}
};



struct _cabezalTablaIntString {
	NodoTabla** tabla;
	int esperados;
	int cantidad;
};

/* AUXILIARES*/
unsigned int largoString(const char* palabra) {
	int count = 0;
	for (int i = 0; palabra[i] != 0; i++) {
		count++;
	}
	return count;
}

char* crearPalabra(const char* palabra) {
	int lPalabra = largoString(palabra);
	char* nuevo = new char[lPalabra + 1];
	for (int i = 0; i < lPalabra; i++) {
		nuevo[i] = palabra[i];
	}
	nuevo[lPalabra] = '\0';
	return nuevo;
}

void actualizarImagen(TablaIntString& t, int d, const char* r) {
	int hash = abs(d) % t->esperados;
	NodoTabla* aux = t->tabla[hash];
	while (aux->dominio != d) {
		aux = aux->sig;
	}
	aux->rango = crearPalabra(r);
}


/*FUNCIONES*/

TablaIntString crearTablaIntString(unsigned int esperados) {
	TablaIntString retorno = new _cabezalTablaIntString();
	retorno->tabla = new NodoTabla * [esperados];
	retorno->cantidad = 0;
	retorno->esperados = esperados;
	for (int i = 0; i < esperados; i++) {
		retorno->tabla[i] = NULL;
	}
	return retorno;
}


void agregar(TablaIntString& t, int d, const char* r) {
	if (!estaDefinida(t, d)) {
			int hash = abs(d) % t->esperados;
			NodoTabla* nuevo = new NodoTabla();
			nuevo->dominio = d;
			nuevo->rango = crearPalabra(r);
			nuevo->sig = t->tabla[hash];
			t->tabla[hash] = nuevo;
			t->cantidad++;
	}
	else {
		actualizarImagen(t, d, r);
	}
}

bool estaDefinida(TablaIntString t, int d) {
	if (!esVacia(t)) {
		int hash = abs(d) % t->esperados;
		NodoTabla* aux = t->tabla[hash];
		while (aux != NULL) {
			if (aux->dominio == d) {
				return true;
			}
			aux = aux->sig;
		}
		return false;
	}
	return false;
}

char* recuperar(TablaIntString t, int d) {
	int hash = abs(d) % t->esperados;
	NodoTabla* aux = t->tabla[hash];
	while (aux != NULL && aux->dominio != d) {
		aux = aux->sig;
	}
	char* ret = crearPalabra(aux->rango);
	return ret;

}

void borrar(TablaIntString& t, int d) {
	int hash = abs(d) % t->esperados;
	if (t->tabla[hash] != NULL) {
		if (t->tabla[hash]->dominio == d) {
			NodoTabla* borrar = t->tabla[hash];
			t->tabla[hash] = t->tabla[hash]->sig;
			delete[] borrar->rango;
			delete borrar;
			t->cantidad--;
		}
		else {
			NodoTabla* aux = t->tabla[hash];
			while (aux->sig != NULL && aux->sig->dominio != d) {
				aux = aux->sig;
			}
			if (aux->sig != NULL && aux->sig->dominio == d) {
				NodoTabla* borrar = aux->sig;
				aux->sig = aux->sig->sig;
				delete[] aux->rango;
				delete borrar;
				t->cantidad--;
			}
		}
	}
}

int elemento(TablaIntString t) {
	if (!esVacia(t)) {
		for (int i = 0; i < t->esperados; i++) {
			if (t->tabla[i] != NULL) {
				return t->tabla[i]->dominio;
			}
		}
	}
}

bool esVacia(TablaIntString t) {
	return t->cantidad == 0;
}

unsigned int cantidadElementos(TablaIntString t) {
	return t->cantidad;
}

void destruir(TablaIntString& t) {
	for (int i = 0; i < t->esperados; i++) {
		while (t->tabla[i] != NULL) {
			NodoTabla* borrar = t->tabla[i];
			t->tabla[i] = t->tabla[i]->sig;
			delete[] borrar->rango;
			delete borrar;
		}
	}
	delete[] t->tabla;
	delete t;
}

TablaIntString clon(TablaIntString t) {
	TablaIntString ret = crearTablaIntString(t->esperados);
	ret->cantidad = t->cantidad;
	for (int i = 0; i < t->esperados; i++) {
		if (t->tabla[i] != NULL) {
			NodoTabla* aux = t->tabla[i];
			while (aux != NULL) {
				NodoTabla* nuevo = new NodoTabla();
				nuevo->dominio = aux->dominio;
				nuevo->rango = crearPalabra(aux->rango);
				NodoTabla* fin = ret->tabla[i];
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

#endif