#include<iostream>
using namespace std;

/*3) Escriba un algoritmo que lea tres valores reales positivos y determine si pueden ser las
longitudes de los lados de un triángulo(considerar que la suma, al menos, de los cuadrados de
	dos de sus lados tiene que ser mayor igual al cuadrado del otro lado). */
bool auxSuma(unsigned int l1, unsigned int l2, unsigned int l3) {
	unsigned int l1Aux = l1 * l1;
	unsigned int l2Aux = l2 * l2;
	unsigned int l3Aux = l3 * l3;
	return l1Aux + l2Aux > l3;;
}

bool posibleTriangulo() {
	unsigned int l1 = 0;
	unsigned int l2 = 0;
	unsigned int l3 = 0;
	cout << "Ingrese lado1";
	cin >> l1;
	cout << "Ingrese lado2";
	cin >> l2;
	cout << "Ingrese lado3";
	cin >> l3;

	bool res = false;
	if (auxSuma(l1, l2, l3) || auxSuma(l1, l3, l2) || auxSuma(l3, l2, l1)) {
		return true;
	}
	else {
		return false;
	}
}

/* ----------------------------------------------------------------------------------- */

int strlen(char* p) {
	char* t = p;
	while (*t != '\0')
		t++;
	return t - p;
}




//PRE: Recibe un string o y un puntero d
//POS: Copia el string o al destino d que apunta a 
//		strlen(o)+1 caracteres reservados
void strcpy(char* d, char* o) {
	while (*d++ = *o++);
}


// EQUIVALENTES: *vec / vec[0]
//PRE:
//POS:  Si son iguales retorna 0
//		Si s < t retorna < 0; 
//		Si s > t retorna > 0; 
//		COMPARA CARACTERES SEGUN SU POSICION EN LA TABLA ASCII (AZ < Aa)
int strcmp(char* s, char* t) {
	int i;

	for (int i = 0; s[i] == t[i]; i++)
		if (s[i] == '\0')
			return 0;
	return s[i] - t[i];
}

// string: puntero al primer caracter de una serie de
// caracteres consecutivos en memoria terminados por 
// el caracter '\0


/* ----------------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------------- */

int main() {
	if (posibleTriangulo()) {
		cout << "true";
	}
	else {
		cout << "false";
	}
	return 0;
}
