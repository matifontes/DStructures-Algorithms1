//PRE recibe un vector de largo n y un numero k
//POS devuelve la posicion en el vector donde se enecuntra k, en caso de no existir retorna n-1;

int posicion(int vector[], int n, int k) {
	if (n < 0) {
		return -1;
	}
	else {
		if (vector[n - 1] == k) {
			return n - 1;
		}
		else {
			return posicion(vector, n-1, k)
		}
	}
}