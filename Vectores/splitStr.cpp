char** splitStr(char* str, char separador, int &largoRet) {
	int lRet = 0;
	int lStr = largo(str);
	
	if (lStr > 0) {
		if (str[0] != separador && str[0] != '\n') {
			lRet++;
		}
	}

	for (int i = 0; i < lStr-1; i++) {
		if (str[i] == separador && str[i+1] != separador) {
			lRet++;
		}
	}

	largoRet = lRet;

	if (largoRet == 0) {
		return NULL;
	}
	else {

		char** res = new char* [largoRet];
		
		char* sep = new char[2];
		sep[0] = separador;
		sep[1] = '\0';

		char* auxStr = crearPalabra(str);
		char* subString;
		subString = strtok(auxStr, sep);
		res[0] = subString;

		for (int i=1; i < largoRet; i++) {
			subString = strtok(NULL, sep);
			res[i] = subString;
		}

		delete[] sep;
		return res;
	}
}
