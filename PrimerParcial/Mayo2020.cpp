void diferencia (lista& l1, lista l2) {
	lista ant = NULL;
	lista recorrer = l1;
	lista ppio = l1;
	
	if(l1 == NULL) {
		return NULL;
	}
	if(l2 == NULL){
		return l1;
	} 
	
	while (recorrer && l2){
		if(recorrer->dato < l2->dato){
			ant = recorrer;
			recorrer = recorrer->sig;
		}
		else if(recorrer->dato == l2){
				if(ant == NULL){
					lista borrar = recorrer;
					recorrer = recorrer->sig;
					l1 = recorrer;
					delete borrar;
					l2 = l2->sig;
				}else{
					lista borrar = recorrer;
					ant->sig = recorrer->sig;
					recorrer = recorrer->sig;
					delete borrar;
					l2 = l2->sig;
				}
		}
		else if(recorrer->dato > l2->dato){
			l2 = l2->sig;
		}	
	} 
} 


ABB copiaEnRango (ABB a, int inf, int sup){
	if (a == NULL)
		return NULL;
	
	if(a->dato > inf && a->dato < sup){
		ABB res = new ABB(a->dato);
		res->izq = copiaEnRango(a->izq, inf, supp);
		res->der = copiaEnRango(a->der, inf, supp);
	} 
	
	if(a->dato <= inf)
		return copiaEnRango(a->der, inf, sup);
	if(a->dato>=sup)
		return copiaEnRango(a->izq, inf,sup);
	

} 



AG padre(AG a, int x){
	if(a == NULL) return NULL;
	
	if(a->dato == x) return NULL;
	
	AG hijo = a->ph;
	
	while(hijo != NULL && hijo->dato != x){
		hijo = hijo->sh;
	}
	if(aux != NULL) return a;
	AG ptrPH = padre(a->ph, x);
	if(ptrPH != NULL) return ptrPh;
	return padre(a->sh, x);

} 



Lista comunes(Lista l1, Lista l2){
	if(l1 == NULL || l2 == NULl){
		return NULL;
	}
	else {
		Lista res = NULL;
		while (l1 && l2){
			if(l1->dato == l2->dato){
				Lista nuevo = new Lista;
				nuevo->dato = l1->dato;
				nuevo->sig = res;
				res = nuevo;
				l1=l1->sig;
				l2=l2->sig;
			}
			else if(l1->dato < l2->dato {
				l1 = l1->sig;
			}
			else if(l1->dato > l2->dato {
				l2 = l2->sig;
			}
		}
		return res;
	}
	
}
