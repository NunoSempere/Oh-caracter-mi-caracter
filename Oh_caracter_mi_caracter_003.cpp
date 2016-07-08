#include <iostream>
#include <fstream>

using namespace std;
	
int main() {
	
	ifstream fin;
	fin.open("celestina.txt", ios::in);
	
	char mi_caracter;
	
	int contador_puntos = 0; // Si el anterior caracter era un punto y el siguiente también lo es, el segundo no se cuenta como final de una frase.
	int numero_de_oraciones = 0;
	int numero_de_palabras = 0;
	int numero_de_espacios = 0;
	
	long double	palabras_por_oracion = 0;

	while (!fin.eof() ) {
	
		fin.get(mi_caracter);
	
		// contar el número de oraciones		
		if (mi_caracter == '.'){ // Una frase puede o bien terminar en ".".	
		
			if (contador_puntos == 0){ // Una frase puede o bien terminar en ".".	
				++numero_de_oraciones;
			}
			contador_puntos = 1;
		}
	
		if (mi_caracter == '?'){ // o bien terminar terminar en "?", al ser una pregunta.
			++numero_de_oraciones;
		}
	
		if (mi_caracter == '!'){ // o bien terminar en "!", al ser una exclamación.
			++numero_de_oraciones;
		}
	
		if (mi_caracter != '.'){ // El segundo punto no puede ser precedido de un caracter que no es un punto.
			contador_puntos = 0;
		}
	
		// contar el numero de espacios. El numero de palabras sera el numero de espacios +1
		if (mi_caracter == ' '){ 
			++numero_de_espacios;
		}
	
	
	}
	
	// obtener el número de palabras y la proporcion palabras por oracion
	numero_de_palabras = numero_de_espacios +1;
	palabras_por_oracion = numero_de_palabras / numero_de_oraciones;

	// Mensaje final
	cout << "Numero de palabras por oracion = " << palabras_por_oracion << endl;
	cout << "Numero de oraciones = " << numero_de_oraciones << endl;
	cout << "Numero de palabras = " << numero_de_palabras << endl;
	
	// Advertencia en cuanto a formato
	cout << "TEN EN CUENTA QUE EL FICHERO DEBE" << endl;
	cout << "ESTAR CODIFICADO EN FORMATO .TXT - ANSI" << endl;
		
}
