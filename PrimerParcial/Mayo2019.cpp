bool parecidas(Lista l1, Lista l2) {
	int cantElementos = 0;
	int cantIguales = 0;
	if(!l1)
		return false;
	
	while(l1 != NULL) {
		if (l1->dato == l2->dato){
			cantIguales++;
		} 
		cantElementos++;
		l1=l1->sig;
		l2=l2->sig;
	}
	
	cantElementos = cantElementos/2;
	return cantIguales >= cantElementos;
	
 } 
 
 ABB dual(ABB a){
	 ABB res = 
	if (!ABB){
		return NULL;
	}
	ABB res = new ABB(a->dato);
	res->der = dual(a->izq);
	res->izq = dual(a->der);
} 

//Peor caso: O(n) siendo n la cantidad de elemetnos de a, porque tiene que recorrer todo el arbol a para crear el arbol dual;
 
 
 
 void impDesdeNivel(AG a, int k){
	if(a == NULL) return NULL;
	
	if(a != NULL){
		if(k==0){
			cout << a->dato;
		impDesdeNivel(a->sh, k);
		if(k>0){
			impDesdeNivel(a->ph, k-1);
		} else {
			impDesdeNivel(a->ph, k);
		} 
	}  
} 