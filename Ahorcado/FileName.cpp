#include <iostream>
#include <string.h>

using namespace std;

//Inicializar un array cualquiera
void InicializarArray(char array[], int dim) {

	for (int i = 0; i < dim; i++) {
		array[i] = '_';
	}

}

//Función para comprobar si letra pertenece a array
int	ComprobarLetra(char array[], int dim, char letra) {

	int ret = -1;

	for (int i = 0;i < dim;i++) {

		if (array[i] == letra) {

			ret = 1;

		}

	}

	return ret;

}

//Función para comprobar si un array esta lleno
int ComprobarDim(char array[], int dim) {

	int i = 0;
	bool lleno = true;
	while (i < dim && lleno == true) {

		if (array[i] == '_') {

			lleno = false;

		}

		i++;

	}

	return lleno;

}

//Funcion para escribir una letra de un array en otro
void CambiarPorLetra(char array1[], char array2[], char letra, int dim) {

	for (int i=0;i<dim;i++) {

		if (array1[i] == letra) {

			array2[i] = array1[i];

		}

	}

}
//Mostrar array por pantalla
void MostrarArray(char array[], int dim) {

	for (int i = 0;i < dim;i++) {

		cout << array[i];

	}

}

const int DIM = 20;
const int OP = 10;
int main() {

	int dimpalabra = 0, contador = 0, letrapertenece;
	char palabra[DIM], palabranum[DIM], letra;
	bool lleno = false;

	cout << "===== AHORCADO =====" << endl;
	cout << "Usuario 1, escoge una palabra (maximo 20 letras): ";
	cin >> palabra;

	system("cls");

	dimpalabra = strlen(palabra);

	InicializarArray(palabranum, dimpalabra);

	do {

		cout << "Usuario 2, escoge una letra: ";
		cin >> letra;

		letrapertenece = ComprobarLetra(palabra, dimpalabra, letra);

		if (letrapertenece == 1) {

			CambiarPorLetra(palabra, palabranum, letra, dimpalabra);

			cout << "Palabra: ";
			MostrarArray(palabranum, dimpalabra);
			cout << endl << endl;

			lleno = ComprobarDim(palabranum, dimpalabra);

		}
		else {

			contador++;
			cout << "Letra incorrecta, oportunidades restantes: " << OP - contador << endl << endl;

		}

	} while (contador < OP && lleno == 0);

	if (contador == OP) {

		cout << "Has perdido :(" << endl;
		cout << "La palabra correcta era: ";
		MostrarArray(palabra, dimpalabra);
		cout << endl << endl;

	}
	else {

		cout << "Has ganado!!! La palabra correcta era: "; 
		MostrarArray(palabra, dimpalabra);
		cout << endl << endl;

	}

}