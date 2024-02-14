#include <iostream>
using namespace std;

int contarVocalesMinusculas(char* pc) {
	int count = 0;  // Variable para contar las vocales en minúscula
	
	while (*pc != '\0') {  // Iterar hasta el final de la cadena ('\0')
		switch (*pc) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			count++;  // Incrementar el contador de vocales en minúscula
			break;
		default:
			break;
		}
		pc++;  // Mover el puntero al siguiente carácter en la cadena
	}
	
	return count;  // Retornar el número de vocales en minúscula
}

int main(int argc, char* argv[]) {
	char cadena[] = "Hola mundo";
	char* pc = cadena;  // Declarar el puntero en el main y asignarlo a la dirección de la cadena
	
	cout << "Cadena: " << cadena << endl;  // Imprimir la cadena original
	
	int numVocales = contarVocalesMinusculas(pc);  // Llamar a la función para contar las vocales en minúscula y obtener el resultado
	
	cout << "Número de vocales en minúscula: " << numVocales << endl;  // Imprimir el número de vocales en minúscula
	
	return 0;
}
