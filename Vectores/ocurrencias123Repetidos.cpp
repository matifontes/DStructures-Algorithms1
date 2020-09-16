int ocurrencias123Repetidos(int* vector, int largo) {
	int count = 0;
	int res = 0;

	for (int i = 0; i < largo; i++) {
		if (count == 0) {
			if (vector[i] == 1) {
				count++;
			}
		}
		else if (count == 1){
			if (vector[i] == 2) {
				count++;
			}else if(vector[i]!=1){
				count = 0;
			}
		}
		else if (count == 2) {
			if (vector[i] == 3) {
				count++;
			}
			else if (vector[i] != 2) {
				count = 0;
			}
		}
		
		if (count == 3) {
			res++;
			count = 0;
		}
	}

	return res;
}
