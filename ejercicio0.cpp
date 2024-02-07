#include <iostream>

int main() {
	// Declarar variables para almacenar los tres números
	double num1, num2, num3;
	
	// Solicitar al usuario que ingrese los tres números
	std::cout << "Ingrese el primer numero: ";
	std::cin >> num1;
	
	std::cout << "Ingrese el segundo numero: ";
	std::cin >> num2;
	
	std::cout << "Ingrese el tercer numero: ";
	std::cin >> num3;
	
	// Determinar el mayor de los tres números
	double mayor = num1;
	
	if (num2 > mayor) {
		mayor = num2;
	}
	
	if (num3 > mayor) {
		mayor = num3;
	}
	
	// Mostrar el resultado
	std::cout << "El mayor numero es: " << mayor << std::endl;
	
	return 0;
}
