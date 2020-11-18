nodoLista* posicion(nodoLista* L, int x) {
	if (L == NULL) return NULL;
	
	while(L){
		if(L->dato == x) return L;
		L = L->sig;
	}
	return NULL;
	
}

void eliminarPosiciones(nodoLista * & L, int desde, int hasta) {
		nodoLista* auxRecorrer = L;
		if (L!= NULL{
			count= desde;
			if(desde == 1){
				while (L && count<= hasta){
					nodoLista* borrar = L;
					L = L->sig;
					delete borrar;
					count++;
				}
			}else{
				countAux =1;
				while (L && countAux<desde-1){
					L= L->sig;
				}
				nodoLista* antDesde = L;
				
				while (L && countAux<=hasta){
					nodoLista* borrar = L;
					antDesde->sig = L->sig;
					L = L->sig;
					delete borrar;
					countAux++;
				}
			}
		}
}

int nivelDeElemento(ArbGen A, int x) {
	if(A==NULL) {
		return 0;
	}
	
	if(A->dato == x) return 1;
	int nivelSh = nivelDelElemetno(A->sh,x);
	if(nivelSh !=0) return nivelSh;
	int nivelPh=nivelDelElemento(a->ph,x);
	if(nivelPh!=0) return NivelPh+1;
	
	return 0;	
}

int auxFunc(int actual, int der){
		if(der== INT_MIN || actual>der){
			return actual;
		}
		return der;
}

int piso(ABB a, int x){
	if(a == NULL) return INT_MIN;
	
	if(a->dato == x) return x;
	
	if(a->dato > x){
		return piso(a->izq,x);
	}
	else {
		return auxFunc(a->dato, sucesor(a->der,x));
	}
	
	
}
