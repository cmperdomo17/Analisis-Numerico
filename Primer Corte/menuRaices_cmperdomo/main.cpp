#include<iostream>
#include <string>

#include "biseccion.h"
#include "expression.h"
#include "muller.h"
#include "newton_generalizado.h"
#include "newton_raphson.h"
#include "reglafalsa.h"
#include "secante.h"

using raices::biseccion;
using raices::muller;
using raices::newton_generalizado;
using raices::newton_raphson;
using raices::reglafalsa;
using raices::secante;
using std::cin;
using std::cout;
using std::endl;
using std::string;

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

void metodo_newton_raphson(string str_f, string str_f2);

void metodo_raices_multiples(string str_f, string strd_f1, string strd2_f1);

void metodo_muller(string str_f);

int main () {
	menu();
	return 0;
}

void menu(){
	int metodo /*!< Opcion menu de metodos*/;
	int funcion; /*!< Opcion menu de funciones*/
	string str_f = "e^(~x) - ln(x)"; 
	string strd_f1 = "3*(x^2)-(10*x)+7";
	string strd2_f1 = "6*x-10";
	//string str_f = "(e^(~(x^2)))-x";
	string str_f2 = "x^3 + 4*(x^2)-10";
	
	do{
		cout << "\n==============================================================\n" << endl;
		cout << "--------- Menu de metodos para encontrar raices ---------\n" << endl;
		cout << "[1]. Metodo de Biseccion " << endl;
		cout << "[2]. Regla Falsa" << endl;
		cout << "[3]. Newton - Raphson" << endl;
		cout << "[4]. Metodo de la Secante" << endl;
		cout << "[5]. Newton - Raphson para raices multiples" << endl;
		cout << "[6]. Metodo de Muller" << endl;
		cout << "[7]. Salir" << endl;
		cout << "\nIngrese una opcion: ";
		cin >> metodo;
		cout << "\n";

		switch(metodo){
		case 1:

			cout << "\n**************** Metodo de biseccion **************** \n" << endl;
			cout << "Seleccione la funcion a evaluar: " << endl;
			cout << "\n1. " << str_f << endl;
			cout << "\n2. " << str_f2 << endl;
			cout << "\nIngrese una opcion: ";
			cin >> funcion;
			switch(funcion){
			case 1:
				metodo_biseccion(str_f);
				break;
			case 2:
				metodo_biseccion(str_f2);
				break;
			}			
			break;
			
		case 2:

			cout << "\n**************** Metodo de regla Falsa ****************\n" << endl;
			cout << "Seleccione la funcion a evaluar: " << endl;
			cout << "\n1. " << str_f << endl;
			cout << "\n2. " << str_f2 << endl;
			cout << "\nIngrese una opcion: ";
			cin >> funcion;
			switch(funcion){
			case 1:
				metodo_reglaFalsa(str_f);
				break;
			case 2:
				metodo_reglaFalsa(str_f2);
				break;
			}			
			break;
			
		case 3: 	
			cout << "\n**************** Metodo de la secante ****************\n" << endl;
			metodo_newton_raphson(str_f, strd_f1);
			break;
		case 4:
			cout << "\n**************** Metodo de Newton - Raphson ****************\n" << endl;
			cout << "Seleccione la funcion a evaluar: " << endl;
			cout << "1. " << str_f << endl;
			cout << "2. " << str_f2 << endl;
			cout << "\nIngrese una opcion: ";
			cin >> funcion;
			switch(funcion){
			case 1:
				metodo_secante(str_f);
				break;
			case 2:
				metodo_secante(str_f2);
				break;
			}			
			break;
		case 5: 		
			cout << "\n**************** Metodo de Newton - Raphson para raices multiples ****************\n" << endl;
			metodo_raices_multiples(str_f, strd_f1, strd2_f1);
			break;
		case 6: 
			cout << "\n**************** Metodo de Muller ****************\n" << endl;
			metodo_muller(str_f);
			break;
		case 7: 
			cout << "\nSaliendo..." << endl;
			exit(0);	
			break;
		default:
			cout << "\nOpcion invalida" << endl;
		}
		
	}while(metodo != 7);
}

void metodo_biseccion(string str_f) {
	
	double xa, xb, tol;
	int n;
	
	cout << "\nFuncion a evaluar: " << str_f << endl;
	cout << "\nIngrese el valor inferior del intervalo: ";
	cin >> xa;
	cout << "\nIngrese el valor superior del intervalo: ";
	cin >> xb;
	cout << "\nIngrese la tolerancia (en porcentaje): ";
	cin >> tol;
	cout << "\nIngrese el maximo numero de iteraciones: ";
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
	
	cout << "\nFuncion a evaluar: " << str_f << endl;
	cout << "\nIngrese el valor inferior del intervalo: ";
	cin >> xi;
	cout << "\nIngrese el valor superior del intervalo: ";
	cin >> xs;
	cout << "\nIngrese la tolerancia (en porcentaje): ";
	cin >> tol;
	cout << "\nIngrese el maximo numero de iteraciones: ";
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

	cout << "\nIngrese el valor de x0: ";
	cin >> x0;
	cout << "\nIngrese el valor de x1: ";
	cin >> x1;
	cout << "\nIngrese la tolerancia (en porcentaje): ";
	cin >> tol;
	cout << "\nIngrese el maximo numero de iteraciones: ";
	cin >> n;
	//Crear una instancia de secante pasando 
	//la funcion como parametro
	
	secante sec(str_f);
	
	solucion sol = sec.calcular(x0,x1,tol,n);
	
	sol.imprimir();
}

void metodo_newton_raphson(string str_f, string strd_f1){
	
	double x0, tol;
	int n;
	
	cout << "\nFuncion a evaluar: " << str_f << endl;
	cout << "\nIngrese el valor inicial: ";
	cin >> x0;
	cout << "\nIngrese la tolerancia (en porcentaje): ";
	cin >> tol;
	cout << "\nIngrese el maximo numero de iteraciones: ";
	cin >> n;
	//Crear una instancia de regla falsa pasando 
	//la funcion como parametro
	
	newton_raphson nr(str_f, strd_f1);
	
	solucion sol = nr.calcular(x0,tol,n);
	
	sol.imprimir();
}

void metodo_raices_multiples(string str_f, string strd_f1, string strd2_f1){
	
	double x0, tol;
	int n;
	
	cout << "\nFuncion a evaluar: " << str_f << endl;
	cout << "\nPrimera derivada: " << strd_f1 << endl;
	cout << "\nSegunda derivada: " << strd2_f1 << endl;
	cout << "\nIngrese el valor inicial: ";
	cin >> x0;
	cout << "\nIngrese la tolerancia (en porcentaje): ";
	cin >> tol;
	cout << "\nIngrese el maximo numero de iteraciones: ";
	cin >> n;
	//Crear una instancia de regla falsa pasando 
	//la funcion como parametro

	newton_generalizado nr(str_f, strd_f1, strd2_f1);
	
	solucion sol = nr.calcular(x0,tol,n);
	
	sol.imprimir();
}

void metodo_muller(string str_f){
	double x0,x1,x2,tol;
	int n;

	cout << "\nFuncion a evaluar: " << str_f << endl;
	cout << "\nIngrese la primera aproximacion x0: ";
	cin >> x0;
	cout << "\nIngrese la segunda aproximacion x1: ";
	cin >> x1;
	cout << "\nIngrese la tercera aproximacion x2: ";
	cin >> x2;
	cout << "\nIngrese la tolerancia (en porcentaje): ";
	cin >> tol;
	cout << "\nIngrese el maximo numero de iteraciones: ";
	cin >> n;
	//Crear una instancia de muller pasando 
	//la funcion como parametro
	
	muller mull(str_f);
	
	//Calcular la solucion
	solucion sol = mull.calcular(x0,x1,x2,tol,n);
	//Imprimir
	sol.imprimir();
}