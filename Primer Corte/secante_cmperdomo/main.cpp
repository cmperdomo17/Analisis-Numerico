#include<iostream>
#include <string>

#include "biseccion.h"
#include "expression.h"
#include "reglafalsa.h"
#include "secante.h"
#include "newton_raphson.h"

using raices::biseccion;
using raices::reglafalsa;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using raices::secante;
using raices::newton_raphson;


/**
* @brief Menu de opciones
*/
void menu();

/**
* @brief Metodo 1.
* @param str_f String de la funcion
*/

void metodo_biseccion(string str_f);

/**
* @brief Metodo 2.
* @param str_f String de la funcion
*/

void metodo_reglaFalsa(string str_f);

void metodo_secante(string str_f);

void metodo_newton_raphson(string str_f1, string str_f2);

int main () {
	menu();
	return 0;
}

void menu(){
	int metodo /*!< Opcion menu de metodos*/;
	int funcion; /*!< Opcion menu de funciones*/
	string str_f1 = "(e^(~(x^2)))-x";
	string str_f2 = "x^3 + 4*(x^2)-10";
	
	do{
		cout << "\n==============================================================\n" << endl;
		cout << "1. Metodo de Biseccion " << endl;
		cout << "2. Regla Falsa" << endl;
		cout << "3. Newton - Raphson" << endl;
		cout << "4. Metodo de la Secante" << endl;
		cout << "3. Salir" << endl;
		cout << "Ingrese una opcion: ";
		cin >> metodo;
		
		switch(metodo){
		case 1:
			cout << "Seleccione la funcion a evaluar: " << endl;
			cout << "1. " << str_f1 << endl;
			cout << "2. " << str_f2 << endl;
			cout << "Ingrese una opcion: ";
			cin >> funcion;
			switch(funcion){
			case 1:
				metodo_biseccion(str_f1);
				break;
			case 2:
				metodo_biseccion(str_f2);
				break;
			}			
			break;
			
		case 2:
			cout << "Seleccione la funcion a evaluar: " << endl;
			cout << "1. " << str_f1 << endl;
			cout << "2. " << str_f2 << endl;
			cout << "Ingrese una opcion: ";
			cin >> funcion;
			switch(funcion){
			case 1:
				metodo_reglaFalsa(str_f1);
				break;
			case 2:
				metodo_reglaFalsa(str_f2);
				break;
			}			
			break;
			
		case 3: 	
			metodo_newton_raphson(str_f1, str_f2);
			break;
		case 4:
			cout << "Seleccione la funcion a evaluar: " << endl;
			cout << "1. " << str_f1 << endl;
			cout << "2. " << str_f2 << endl;
			cout << "Ingrese una opcion: ";
			cin >> funcion;
			switch(funcion){
			case 1:
				metodo_secante(str_f1);
				break;
			case 2:
				metodo_secante(str_f2);
				break;
			}			
			break;
		case 5: 
			cout << "Saliendo..." << endl;
			exit(0);	
			break;
		default:
			cout << "Opcion invalida" << endl;
		}
		
	}while(metodo != 4);
}

void metodo_biseccion(string str_f) {
	
	double xa, xb, tol;
	int n;
	
	cout << "Metodo de biseccion" << endl;
	cout << "Funcion a evaluar: " << str_f << endl;
	cout << "Ingrese el valor inferior del intervalo: ";
	cin >> xa;
	cout << "Ingrese el valor superior del intervalo: ";
	cin >> xb;
	cout << "Ingrese la tolerancia (en porcentaje): ";
	cin >> tol;
	cout << "Ingrese el maximo numero de iteraciones: ";
	cin >> n;
	//Crear una instancia de biseccion pasando 
	//la funcion como parametro
	
	biseccion bis(str_f);
	
	solucion sol = bis.calcular(xa, xb, tol, n);
	
	sol.imprimir();
}

void metodo_reglaFalsa(string str_f) {
	
	double xi, xs, tol;
	int n;
	
	cout << "Metodo de regla Falsa" << endl;
	cout << "Funcion a evaluar: " << str_f << endl;
	cout << "Ingrese el valor inferior del intervalo: ";
	cin >> xi;
	cout << "Ingrese el valor superior del intervalo: ";
	cin >> xs;
	cout << "Ingrese la tolerancia (en porcentaje): ";
	cin >> tol;
	cout << "Ingrese el maximo numero de iteraciones: ";
	cin >> n;
	//Crear una instancia de regla falsa pasando 
	//la funcion como parametro
	
	reglafalsa rf(str_f);
	
	solucion sol = rf.calcular(xi,xs,tol,n);
	
	sol.imprimir();
	
}

void metodo_secante(string str_f){
	double x0, x1, tol;
	int n;
	cout << "Metodo de la secante" << endl;
	cout << "Ingrese el valor de x0: ";
	cin >> x0;
	cout << "Ingrese el valor de x1: ";
	cin >> x1;
	cout << "Ingrese la tolerancia (en porcentaje): ";
	cin >> tol;
	cout << "Ingrese el maximo numero de iteraciones: ";
	cin >> n;
	//Crear una instancia de secante pasando 
	//la funcion como parametro
	
	secante sec(str_f);
	
	solucion sol = sec.calcular(x0,x1,tol,n);
	
	sol.imprimir();
}

void metodo_newton_raphson(string str_f1, string str_f2){
	
	double x0, tol;
	int n;
	
	cout << "Metodo de Newton - Raphson" << endl;
	cout << "Funcion a evaluar: " << str_f1 << endl;
	cout << "Ingrese el valor inicial: ";
	cin >> x0;
	cout << "Ingrese la tolerancia (en porcentaje): ";
	cin >> tol;
	cout << "Ingrese el maximo numero de iteraciones: ";
	cin >> n;
	//Crear una instancia de regla falsa pasando 
	//la funcion como parametro
	
	newton_raphson nr(str_f1, str_f2);
	
	solucion sol = nr.calcular(x0,tol,n);
	
	sol.imprimir();
}