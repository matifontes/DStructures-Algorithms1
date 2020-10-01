void eliminarNesimoDesdeElFinal(NodoLista*& lista, int &n) 
{
	{
		if (lista != NULL) {
			eliminarNesimoDesdeElFinal(lista->sig, n);
			if (n == 1) {
				NodoLista* aux = lista;
				lista = lista->sig;
				delete aux;
			}
			n--;
		}
	}
}