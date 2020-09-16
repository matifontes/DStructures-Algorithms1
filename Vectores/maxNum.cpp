int maximoNumero(unsigned int n) {
	int entrada = 0;
	int largo = (int)n;
	int max = INT_MIN;
	
	for (int i = 0; i < largo; i++) {
		cout << "Ingrese numero " << i+1 << ": ";
		cin >> entrada;
		if (entrada > max) {
			max = entrada;
		}
	}

	return max;
}
