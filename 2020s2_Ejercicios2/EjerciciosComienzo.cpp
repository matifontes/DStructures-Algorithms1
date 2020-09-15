#include "EjerciciosComienzo.h"
#include <stdlib.h>

int suma(int a, int b) {
    return a+b;
}

void tablaDel(unsigned int tablaDel, unsigned int desde, unsigned int hasta) {
	int res = 0;
	for (int i = desde; i <= hasta; i++) {
		res=i*tablaDel;
		cout << i << "*" << tablaDel << "=" << res;
		if (i < hasta) {
			cout << ";";
		}
	}
}

void simplificar(int n, int d) {
	if (n == 0 || d == 1) {
		cout << n << "/" << d;
	}else{
		bool esMax = false;
		int max = abs(n);
		while (max > 1 && !esMax) {
			if (n % max == 0 && d % max == 0) {
				n = n / max;
				d = d / max;
				esMax = true;
			}
			max--;
		}

		if (d < 0 && n>0) {
			n = -n;
			d = abs(d);
		}else if (d < 0 && n < 0) {
			n = abs(n);
			d = abs(d);
		}
		cout << n << "/" << d;
	}
}

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


//Funcion auxiliar para saber el largo;
unsigned int largo(char* palabra) {
	int count = 0;
	for (int i = 0; palabra[i] != 0; i++) {
		count++;
	}
	return count;
}

char* invertirCase(char* palabra){
	// IMPLEMENTAR SOLUCION
	//A + (a-A) = a;

	char* nueva = new char[largo(palabra)+1];
	
	int i = 0;
	while (palabra[i]!=0){
		if (palabra[i] <= 'Z' && palabra[i] >= 'A') {
			nueva[i] = (palabra[i] + ('a' - 'A'));
		}
		else if (palabra[i] <= 'z' && palabra[i] >= 'a') {
			nueva[i] = (palabra[i] - ('a'- 'A'));
		}
		else {
			nueva[i] = palabra[i];
		}
		++i;
	}
	nueva[i] = '\0';
	return nueva;
}

int islas(char** mapa, int col, int fil){
	// IMPLEMENTAR SOLUCION
    return 0;
}

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

char **ordenarVecStrings(char **vecStr, int largoVecStr)
{
	// IMPLEMENTAR SOLUCION
    return NULL;
}

int* intercalarVector(int* v1, int* v2, int l1, int l2){
	// IMPLEMENTAR SOLUCION
	return NULL;
}

bool subconjuntoVector(int* v1, int* v2, int l1, int l2)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

char** splitStr(char* str, char separador, int &largoRet)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void ordenarVecIntMergeSort(int* vector, int largo) 
{
	// IMPLEMENTAR SOLUCION
}
