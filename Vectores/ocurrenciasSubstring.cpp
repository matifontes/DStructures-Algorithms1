bool verificarOcurrencia(char* original, char* buscada, int index, int lBuscada) {
	for (int i = 0; i < lBuscada; i++) {
		if (original[index + i] != buscada[i]) {
			return false;
		}
	}
	return true;
}

bool auxOcurrencias(char* original, char* buscada) {
	bool aux = true;
	int lOriginal = largo(original);
	int lBuscada = largo(buscada);
	bool res = false;
	for (int i = 0; i <= lOriginal - lBuscada && !res; i++) {
		if (original[i] == buscada[0]) {
			res = verificarOcurrencia(original, buscada, i, lBuscada);
		}
	}
	return res;
}

unsigned int ocurrenciasSubstring(char **vecStr, int largoVecStr, char *substr)
{
	unsigned int res = 0;
	for (int i = 0; i < largoVecStr; i++) {
		if (largo(vecStr[i]) >= largo(substr)) {
			if (auxOcurrencias(vecStr[i], substr)) {
				res++;
			}
		}
	}
    return res;
}
