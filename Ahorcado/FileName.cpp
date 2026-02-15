#include <iostream>
#include <string.h>

using namespace std;

//Inicializar un array cualquiera
void inicializarArray(char array[], int dim) {

	for (int i = 0; i < dim; i++)
	{
		array[i] = '_';
	}

}

//Función para comprobar si letra pertenece a array
int	comprobarLetra(char array[], int dim, char letra) {

	int ret = -1;

	for (int i = 0;i < dim;i++)
	{

		if (array[i] == letra)
		{

			ret = 1;

		}

	}

	return ret;

}

//Función para comprobar si un array esta lleno
int comprobarDim(char array[], int dim) {

	int i = 0;
	bool lleno = true;
	while (i < dim && lleno == true) {

		if (array[i] == '_')
		{

			lleno = false;

		}

		i++;

	}

	return lleno;

}

//Funcion para escribir una letra de un array en otro
void cambiarPorLetra(char array1[], char array2[], char letra, int dim) {

	for (int i = 0;i < dim;i++)
	{

		if (array1[i] == letra)
		{

			array2[i] = array1[i];

		}

	}

}

//Mostrar array por pantalla
void mostrarArray(char array[], int dim)
{

	for (int i = 0;i < dim;i++)
	{

		cout << array[i];

	}

}

//Mostrar letras por pantalla
void mostrarLetras(char letras[], int dim)
{

	for (int i = 0;i < dim;i++)
	{

		if (i != 0 && i != dim)
		{

			cout << ", ";

		}

		cout << letras[i];

	}

}

//Cambiar todas las letras a mayuscula
void transformaMayusculas(char palabras[], int dim)
{

	for (int i = 0; i < dim; i++)
	{

		if (palabras[i] >= 'a' && palabras[i] <= 'z')
		{

			palabras[i] = palabras[i] - 32;

		}

	}

}

const int DIM = 20;
const int OPORTUNITATS = 10;
int main() {

	int dimPalabra = 0, contador = 0, letraPertenece, indiceLetras = 0, existeLetra = -1;
	char palabra[DIM], palabraNum[DIM], letras[DIM], letra;
	bool lleno = false;

	cout << "===== AHORCADO =====" << endl;
	cout << "Usuario 1, escoge una palabra (maximo 20 letras): ";
	cin >> palabra;

	transformaMayusculas(palabra, DIM);

	system("cls");

	dimPalabra = strlen(palabra);

	inicializarArray(palabraNum, dimPalabra);

	do
	{

		cout << "Usuario 2, escoge una letra: ";
		cin >> letra;

		if (letra >= 'a' && letra <= 'z')
		{

			letra = letra - 32;

		}

		letraPertenece = comprobarLetra(palabra, dimPalabra, letra);

		if (letraPertenece == 1)
		{

			cambiarPorLetra(palabra, palabraNum, letra, dimPalabra);

			cout << "Letra correcta, palabra: --> ";
			mostrarArray(palabraNum, dimPalabra);
			cout << " <--" << endl;

			lleno = comprobarDim(palabraNum, dimPalabra);

		}
		else 
		{

			existeLetra = comprobarLetra(letras, DIM, letra);

			if (existeLetra == -1)
			{

				letras[indiceLetras] = letra;
				indiceLetras++;

			}

			contador++;
			cout << "Letra incorrecta, oportunidades restantes: " << OPORTUNITATS - contador << endl;
			cout << "- Letras utilizadas e incorrectas: ";
			mostrarLetras(letras, indiceLetras);
			cout << endl;

		}

		cout << endl;

	} while (contador < OPORTUNITATS && lleno == 0);

	if (contador == OPORTUNITATS)
	{

		cout << "Has perdido :(" << endl;
		cout << "La palabra correcta era: ";
		mostrarArray(palabra, dimPalabra);
		cout << endl << endl;

	}
	else
	{

		cout << "Has ganado!!! La palabra correcta era: "; 
		mostrarArray(palabra, dimPalabra);
		cout << endl << endl;

	}

}