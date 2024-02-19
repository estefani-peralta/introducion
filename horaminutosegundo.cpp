#include <iostream>
#include <cstdlib> // para la funci�n rand()
#include <ctime>   // para la funci�n time()
using namespace std;

// Definici�n de la estructura tiempo
typedef struct { 
	int hora, minuto, segundo; 
} tiempo;

// Funci�n para generar un n�mero aleatorio en el rango [0, 23] para la hora
int horaRand() {
	return rand() % 24; // Obtiene un n�mero aleatorio en el rango [0, 23]
}

// Funci�n para generar un n�mero aleatorio en el rango [0, 59] para los minutos y segundos
int msRand() {
	return rand() % 60; // Obtiene un n�mero aleatorio en el rango [0, 59]
}

// Funci�n para agregar valores aleatorios a los elementos del arreglo vt
void agregar(tiempo vt[], int tamanio) {
	for (int i = 0; i < tamanio; i++) {
		vt[i].hora = horaRand();
		vt[i].minuto = msRand();
		vt[i].segundo = msRand();
	}
}

// Funci�n para imprimir los elementos del arreglo vt
void imprimir(tiempo vt[], int tamanio) {
	for (int i = 0; i < tamanio; i++) {
		cout << "Hora " << i << ": " << vt[i].hora << "." << vt[i].minuto << "." << vt[i].segundo << endl;
	}
}

int main(int argc, char *argv[]) {
	const int TMA = 15;
	tiempo t1, vt[TMA];
	
	// Inicializa la semilla de generaci�n de n�meros aleatorios
	srand(time(0));
	
	// Agrega valores aleatorios a los elementos del arreglo vt
	agregar(vt, TMA);
	
	// Imprime los elementos del arreglo vt
	imprimir(vt, TMA);
	
	return 0;
}
