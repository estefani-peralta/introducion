#include <iostream>
using namespace std;

int contarVocalesMinusculas(char* pc) {
	int count = 0;  // Variable para contar las vocales en min�scula
	
	while (*pc != '\0') {  // Iterar hasta el final de la cadena ('\0')
		switch (*pc) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			count++;  // Incrementar el contador de vocales en min�scula
			break;
		default:
			break;
		}
		pc++;  // Mover el puntero al siguiente car�cter en la cadena
	}
	
	return count;  // Retornar el n�mero de vocales en min�scula
}

int main(int argc, char* argv[]) {
	char cadena[] = "Hola mundo";
	char* pc = cadena;  // Declarar el puntero en el main y asignarlo a la direcci�n de la cadena
	
	cout << "Cadena: " << cadena << endl;  // Imprimir la cadena original
	
	int numVocales = contarVocalesMinusculas(pc);  // Llamar a la funci�n para contar las vocales en min�scula y obtener el resultado
	
	cout << "N�mero de vocales en min�scula: " << numVocales << endl;  // Imprimir el n�mero de vocales en min�scula
	
	return 0;
}
