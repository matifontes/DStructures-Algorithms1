//PRE: Recibe una lista
//POS: Devuelve el largo de la lista.
int largoLista(NodoLista* l) {
	int res = 0;
	while (l) {
		res++;
		l = l->sig;
	}
	return res;
}

//PRE: Recibe una lista simplemente encadenada no vacia y la posicion de un elemento 
//POS: Retorna el puntero de la lista en esa posicion. Las posiciones de la lista serán numeradas a partir del 1.
NodoLista* buscarPos(NodoLista* l, int posicion) {
	int count = 1;
	NodoLista* res = l;
	while (res && count != posicion) {
		res = res->sig;
		count++;
	}
	return res;
}

void moverNodo(NodoLista* &lista, unsigned int inicial, unsigned int final)
{
	if (lista != NULL) {
		int largo = largoLista(lista);
		if (inicial > 0 && final > 0 && inicial <= largo && final <= largo) {
			NodoLista* aux1 = NULL;
			NodoLista* aux2 = NULL;
			if (inicial == 1 && final != 1) {
				aux1 = lista;
				aux2 = buscarPos(lista, final);
				lista = lista->sig;
				aux1->sig = aux2->sig;
				aux2->sig = aux1;
			}
			else if (inicial != 1 && final == 1) {
				aux2 = buscarPos(lista, inicial-1);
				aux1 = aux2->sig;
				aux2->sig = aux1->sig;
				aux1->sig = lista;
				lista = aux1;
			}
			else if (inicial !=1 && final != 1) {
				aux1 = buscarPos(lista, inicial - 1);
				aux2 = aux1->sig;
				aux1->sig = aux2->sig;
				aux1 = buscarPos(lista, final - 1);
				aux2->sig = aux1->sig;
				aux1->sig = aux2;
			}
		}
	}
}
