//Funcion auxiliar para saber el largo;
unsigned int largo(char* palabra) {
	int count = 0;
	for (int i = 0; palabra[i] != 0; i++) {
		count++;
	}
	return count;
}
