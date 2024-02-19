#include <iostream>
#include <cstdlib> // para la funci�n rand()
#include <ctime>   // para la funci�n time()
using namespace std;

// Definici�n de la estructura Libro
struct Libro {
	string title;
	string author;
	int ISBN;
	int publicationYear;
};

// Definici�n de la estructura Usuario
struct Usuario {
	int userID;
	string name;
	string lastname;
	string email;
};

// Definici�n de la estructura Bibliotecario
struct Bibliotecario {
	int employeeID;
	string name;
	string lastname;
	string email;
};

// Nombres y apellidos fijos para autores
string nombres_autores[] = {"Alejandro", "Emiliano", "Francisco", "Antonieta", "Cristobal ", "Valentina", "Magdalena", "Antonella"};
string apellidos_autores[] = {"Guti�rrez", "Dominguez", "Mart�nez", "Hern�ndez", "Pausinis", "Fern�ndez", "Carrasco", "Rodr�guez"};

// Nombres y apellidos fijos para usuarios y bibliotecarios
string nombres[] = {"Gabriela", "Isabella", "Valentina", "Fernando", "Benjamin","jhonatan","Leonardo","Salvador"};
string apellidos[] = {"Gonz�lez", "Montanese", "Mart�nez", "Pausinis", "Rodr�guez","Villegas","Fernandez","Clemente"};



// Funci�n para generar un nombre aleatorio
string generarNombreAleatorio(string nombres[], int tamano) {
	return nombres[rand() % tamano];
}

// Funci�n para generar un apellido aleatorio
string generarApellidoAleatorio(string apellidos[], int tamano) {
	return apellidos[rand() % tamano];
}



// Funci�n para combinar nombre y apellido en un email
string generarEmail(string nombre, string apellido) {
	return nombre + apellido + "@gmail.com";
}

// Funci�n para inicializar los libros aleatoriamente  
void inicializarLibros(Libro *vt, int cantidad) {
	string titulos[] = {"El viejo y el mar", "Rebeli�n en la granja", "La isla del tesoro", "El corazon de la luz", "Aprende programacion","Inteligencia Artificial","Ciberseguridad Esencial","JavaScript Moderno","Arduino Proyectos" };
	int numTitulos = sizeof(titulos) / sizeof(titulos[0]); // Obtener la cantidad de t�tulos en el arreglo
	
	for (int i = 0; i < cantidad; ++i) {
		vt[i].title = titulos[rand() % numTitulos];  // Obtener un t�tulo c�clicamente
		string nombreAutor = generarNombreAleatorio(nombres_autores, sizeof(nombres_autores) / sizeof(nombres_autores[0]));
		string apellidoAutor = generarApellidoAleatorio(apellidos_autores, sizeof(apellidos_autores) / sizeof(apellidos_autores[0]));
		vt[i].author = nombreAutor + " " + apellidoAutor;
		vt[i].ISBN = i + 1; // Asignar ISBN secuencial
		vt[i].publicationYear = rand() % 35 + 1990; // A�o entre 1990 y 2024
	}
}

// Funci�n para inicializar los usuarios aleatoriamente
void inicializarUsuarios(Usuario *vt, int cantidad) {
	for (int i = 0; i < cantidad; ++i) {
		vt[i].userID = i + 1;
		vt[i].name = generarNombreAleatorio(nombres, sizeof(nombres) / sizeof(nombres[0]));
		vt[i].lastname = generarApellidoAleatorio(apellidos, sizeof(apellidos) / sizeof(apellidos[0]));
		vt[i].email = generarEmail(vt[i].name, vt[i].lastname);
	}
}

// Funci�n para inicializar los bibliotecarios aleatoriamente
void inicializarBibliotecarios(Bibliotecario *vt, int cantidad) {
	for (int i = 0; i < cantidad; ++i) {
		vt[i].employeeID = i + 1;
		vt[i].name = generarNombreAleatorio(nombres, sizeof(nombres) / sizeof(nombres[0]));
		vt[i].lastname = generarApellidoAleatorio(apellidos, sizeof(apellidos) / sizeof(apellidos[0]));
		vt[i].email = generarEmail(vt[i].name, vt[i].lastname);
	}
}

// Funci�n para imprimir los libros
void imprimirLibros(Libro *vt, int cantidad) {
	cout << "Imprimiendo datos de libros:" << endl;
	cout << "T�tulo\t\t\t\tAutor\t\t\t\tISBN\t\tA�o de Publicaci�n" << endl;
	for (int i = 0; i < cantidad; ++i) {
		cout << vt[i].title << "\t\t" << vt[i].author << "\t\t" << vt[i].ISBN << "\t\t\t" << vt[i].publicationYear << endl;
	}
}

// Funci�n para imprimir los usuarios
void imprimirUsuarios(Usuario *vt, int cantidad) {
	cout << "Imprimiendo datos de usuarios:" << endl;
	cout << "ID\tNombre\t\tApellido\tEmail" << endl;
	for (int i = 0; i < cantidad; ++i) {
		cout << vt[i].userID << "\t" << vt[i].name << "\t" << vt[i].lastname << "\t" << vt[i].email << endl;
	}
}

// Funci�n para imprimir los bibliotecarios
void imprimirBibliotecarios(Bibliotecario *vt , int cantidad) {
	cout << "Imprimiendo datos de bibliotecarios:" << endl;
	cout << "ID Emp\tNombre\t\tApellido\tEmail" << endl;
	for (int i = 0; i < cantidad; ++i) {
		cout << vt[i].employeeID << "\t" << vt[i].name << "\t" << vt[i].lastname << "\t" << vt[i].email << endl;
	}
}

int main() {
	const int CANTIDAD = 7;
	
	// Semilla de generaci�n de n�meros aleatorios
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

