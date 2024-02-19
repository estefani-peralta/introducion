#include <iostream>
#include <cstdlib> // para la función rand()
#include <ctime>   // para la función time()
using namespace std;

// Definición de la estructura Libro
struct Libro {
	string title;
	string author;
	int ISBN;
	int publicationYear;
};

// Definición de la estructura Usuario
struct Usuario {
	int userID;
	string name;
	string lastname;
	string email;
};

// Definición de la estructura Bibliotecario
struct Bibliotecario {
	int employeeID;
	string name;
	string lastname;
	string email;
};

// Nombres y apellidos fijos para autores
string nombres_autores[] = {"Alejandro", "Emiliano", "Francisco", "Antonieta", "Cristobal ", "Valentina", "Magdalena", "Antonella"};
string apellidos_autores[] = {"Gutiérrez", "Dominguez", "Martínez", "Hernández", "Pausinis", "Fernández", "Carrasco", "Rodríguez"};

// Nombres y apellidos fijos para usuarios y bibliotecarios
string nombres[] = {"Gabriela", "Isabella", "Valentina", "Fernando", "Benjamin","jhonatan","Leonardo","Salvador"};
string apellidos[] = {"González", "Montanese", "Martínez", "Pausinis", "Rodríguez","Villegas","Fernandez","Clemente"};



// Función para generar un nombre aleatorio
string generarNombreAleatorio(string nombres[], int tamano) {
	return nombres[rand() % tamano];
}

// Función para generar un apellido aleatorio
string generarApellidoAleatorio(string apellidos[], int tamano) {
	return apellidos[rand() % tamano];
}



// Función para combinar nombre y apellido en un email
string generarEmail(string nombre, string apellido) {
	return nombre + apellido + "@gmail.com";
}

// Función para inicializar los libros aleatoriamente  
void inicializarLibros(Libro *vt, int cantidad) {
	string titulos[] = {"El viejo y el mar", "Rebelión en la granja", "La isla del tesoro", "El corazon de la luz", "Aprende programacion","Inteligencia Artificial","Ciberseguridad Esencial","JavaScript Moderno","Arduino Proyectos" };
	int numTitulos = sizeof(titulos) / sizeof(titulos[0]); // Obtener la cantidad de títulos en el arreglo
	
	for (int i = 0; i < cantidad; ++i) {
		vt[i].title = titulos[rand() % numTitulos];  // Obtener un título cíclicamente
		string nombreAutor = generarNombreAleatorio(nombres_autores, sizeof(nombres_autores) / sizeof(nombres_autores[0]));
		string apellidoAutor = generarApellidoAleatorio(apellidos_autores, sizeof(apellidos_autores) / sizeof(apellidos_autores[0]));
		vt[i].author = nombreAutor + " " + apellidoAutor;
		vt[i].ISBN = i + 1; // Asignar ISBN secuencial
		vt[i].publicationYear = rand() % 35 + 1990; // Año entre 1990 y 2024
	}
}

// Función para inicializar los usuarios aleatoriamente
void inicializarUsuarios(Usuario *vt, int cantidad) {
	for (int i = 0; i < cantidad; ++i) {
		vt[i].userID = i + 1;
		vt[i].name = generarNombreAleatorio(nombres, sizeof(nombres) / sizeof(nombres[0]));
		vt[i].lastname = generarApellidoAleatorio(apellidos, sizeof(apellidos) / sizeof(apellidos[0]));
		vt[i].email = generarEmail(vt[i].name, vt[i].lastname);
	}
}

// Función para inicializar los bibliotecarios aleatoriamente
void inicializarBibliotecarios(Bibliotecario *vt, int cantidad) {
	for (int i = 0; i < cantidad; ++i) {
		vt[i].employeeID = i + 1;
		vt[i].name = generarNombreAleatorio(nombres, sizeof(nombres) / sizeof(nombres[0]));
		vt[i].lastname = generarApellidoAleatorio(apellidos, sizeof(apellidos) / sizeof(apellidos[0]));
		vt[i].email = generarEmail(vt[i].name, vt[i].lastname);
	}
}

// Función para imprimir los libros
void imprimirLibros(Libro *vt, int cantidad) {
	cout << "Imprimiendo datos de libros:" << endl;
	cout << "Título\t\t\t\tAutor\t\t\t\tISBN\t\tAño de Publicación" << endl;
	for (int i = 0; i < cantidad; ++i) {
		cout << vt[i].title << "\t\t" << vt[i].author << "\t\t" << vt[i].ISBN << "\t\t\t" << vt[i].publicationYear << endl;
	}
}

// Función para imprimir los usuarios
void imprimirUsuarios(Usuario *vt, int cantidad) {
	cout << "Imprimiendo datos de usuarios:" << endl;
	cout << "ID\tNombre\t\tApellido\tEmail" << endl;
	for (int i = 0; i < cantidad; ++i) {
		cout << vt[i].userID << "\t" << vt[i].name << "\t" << vt[i].lastname << "\t" << vt[i].email << endl;
	}
}

// Función para imprimir los bibliotecarios
void imprimirBibliotecarios(Bibliotecario *vt , int cantidad) {
	cout << "Imprimiendo datos de bibliotecarios:" << endl;
	cout << "ID Emp\tNombre\t\tApellido\tEmail" << endl;
	for (int i = 0; i < cantidad; ++i) {
		cout << vt[i].employeeID << "\t" << vt[i].name << "\t" << vt[i].lastname << "\t" << vt[i].email << endl;
	}
}

int main() {
	const int CANTIDAD = 7;
	
	// Semilla de generación de números aleatorios
	srand(time(0));
	
	// Inicializar estructuras
	Libro libros[CANTIDAD]; //Array de estructuras Libro
	Usuario usuarios[CANTIDAD];
	Bibliotecario bibliotecarios[CANTIDAD];
	
	// Inicializar libros, usuarios y bibliotecarios aleatoriamente
	inicializarLibros(libros, CANTIDAD); // Llenar el array de libros con datos aleatorios
	inicializarUsuarios(usuarios, CANTIDAD);
	inicializarBibliotecarios(bibliotecarios, CANTIDAD);
	
	// Imprimir los libros, usuarios y bibliotecarios
	imprimirLibros(libros, CANTIDAD);
	imprimirUsuarios(usuarios, CANTIDAD);
	imprimirBibliotecarios(bibliotecarios, CANTIDAD);
	
	return 0;
}

