#include <iostream>
using namespace std;

typedef struct {
	int hora, minuto, segundo;
} tiempo;

void imprimir(tiempo vt[], int tamanio) {
	for (int i = 0; i < tamanio; i++) {
		cout << "Hora " << i + 1 << ": " << vt[i].hora << "." << vt[i].minuto << "." << vt[i].segundo << endl;
	}
}

int main(int argc, char *argv[]) {
	const int TMA = 2;
	tiempo t1, vt[TMA];
	t1.hora = 12;
	t1.minuto = 0;
	t1.segundo = 0;
	
	// Registro array vt
	vt[0].hora = 13;
	vt[0].minuto = 30;
	vt[0].segundo = 10;
	
	// Registro array vt 2
	vt[1].hora = 23;
	vt[1].minuto = 0;
	vt[1].segundo = 10;
	
	imprimir(vt, TMA);
	
	cout << "Hora es: " << t1.hora << "." << t1.minuto << "." << t1.segundo << endl;
	
	return 0;
}
