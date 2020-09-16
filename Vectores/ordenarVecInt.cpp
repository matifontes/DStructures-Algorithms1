void ordenarVecInt(int *vec, int largoVec) {
	int aux = 0;
	for (int i = 0; i < largoVec-1; i++) {
		for (int j = i+1; j < largoVec; j++) {
			if (vec[i] > vec[j]) {
				aux = vec[i];
				vec[i] = vec[j];
				vec[j] = aux;
			}
		}
	}
}
