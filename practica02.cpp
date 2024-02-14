#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	char cadena[] = "Hola mundo";
	char* pc = cadena;
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
	
	cout << "Cadena: " << cadena << endl;
	cout << "N�mero de vocales en min�scula: " << count << endl;
	
	return 0;
}
