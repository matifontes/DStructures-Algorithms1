//PRE recibe un vector ordenado de largo n y un numero k
//POS devuelve la posicion en el vector donde se enecuntra k, en caso de no existir retorna n-1;

int bipart(int vec[], int izq, int der, int k) {
	if (n < 0) {
		return -1;
	}
	else {
		int medio = (izq + der) / 2;
		if (vec[medio] == k) {
			return medio;
		}
		if (vec[medio] > k){
			return Bipart(vec, izq, medio - 1, k);
		}
		else {
			return Bipart(vec, izq, medio+1, k);
		}
	}
}