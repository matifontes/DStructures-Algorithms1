int menor(int numero1, int numero2) {
	int res = 0;
	if (numero1 < numero2) {
		res = numero1;
	}
	else {
		res = numero2;
	}

	return res;
}

bool stringMenorIgual(char* vecVerificar, char* vecOriginal) {  ///T
	bool res = true;
	int lVecVerificar = largo(vecVerificar);
	int lVecOriginal = largo(vecOriginal);
	int menorLargo = menor(lVecVerificar, lVecOriginal);
	for (int i = 0; i < menorLargo; i++) {
		if (vecVerificar[i] < vecOriginal[i]) {
			return true;
		}
		else if (vecVerificar[i] > vecOriginal[i]) {
			return false;
		}
	}
	return lVecVerificar <= lVecOriginal;
}

void inicializarVector(bool* vecAux, int largoVec) {
	for (int i = 0; i < largoVec; i++) {
		vecAux[i] = false;
	}
}


char* crearPalabra(char* palabra) {
	int lPalabra = largo(palabra);
	char* nuevo = new char[lPalabra + 1];
	for (int i = 0; i < lPalabra; i++) {
		nuevo[i] = palabra[i];
	}
	nuevo[lPalabra] = '\0';
	return nuevo;
}

char* maxString(char** vecStr, int largoVecStr) {
	char* max = vecStr[0];
	for (int i = 0; i < largoVecStr; i++) {
		if (stringMenorIgual(max, vecStr[i])) {
			max = vecStr[i];
		}
	}
	return max;
}

char **ordenarVecStrings(char **vecStr, int largoVecStr) {
	bool* vecAux = new bool[largoVecStr];
	inicializarVector(vecAux, largoVecStr);
	char** vecRes = new char*[largoVecStr+1];
	int minIndex = 0;

	char* max = maxString(vecStr, largoVecStr);

	for (int i = 0; i < largoVecStr; i++) {
		char* min = max;
		for (int j = 0; j < largoVecStr; j++) {
			if(!vecAux[j]){
				if (stringMenorIgual(vecStr[j], min)) {
					minIndex = j;
					min = vecStr[j];
				}
			}
		}
		vecAux[minIndex] = true;
		char* nuevo = crearPalabra(min);
		vecRes[i] = nuevo;
	}

	delete[] vecAux;
	return vecRes;
}
