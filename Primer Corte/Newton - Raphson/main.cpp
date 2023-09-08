/*
Metodo de Newton - Raphson
Implica generar la suceción Pn definida por:
Fórmula: Pn = Pn-1 - (f(Pn-1)/f'(Pn-1)
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include "solucion.h"
#include "Expression.h"
#include "newton_raphson.h"
#include "biseccion.h"
#include "reglafalsa.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using raices::biseccion;
using raices::newton_raphson;
using raices::reglafalsa;

/**
* @brief Caso 1. e^~x - ln(x)
*/

/**
 * @brief Caso 2. x^3 + 4*(x^2) - 10
*/

/**
 * @brief Caso 3. e^(~x) + x^2 - 2
*/

void caso_1_newton_raphson() {
	
	/**
	 * @brief Función a la que se le aplicará el método de Newton - Raphson
	 * @param P0 aproximación inicial
	 * @param tol tolerancia
	 * @param n número máximo de iteraciones
	 * @return Solución aproximada p o mensaje de error
	*/
	double p0, tol;
	int n;
	
	string str_f = "e^~x - ln(x)";
    string str_df = "~(e^~x) - (1/x)";
	
	cout << "Metodo de Newton-Raphson" << endl;
	cout << "Funcion a evaluar: " << str_f << endl;
	cout << "Ingrese el valor inicial de x: ";
	cin >> p0;
	cout << "Ingrese la tolerancia (en porcentaje): ";
	cin >> tol;
	cout << "Ingrese el maximo numero de iteraciones: ";
	cin >> n;
	//Crear una instancia de newton-raphson pasando 
	//la formula y su derivada como parametro
	
    
	newton_raphson nr(str_f, str_df); // Crear una instancia de newton_raphson
    
	solucion sol = nr.calcular(p0, tol, n); // Calcular la solucion
    
    sol.imprimir(); // Imprimir la solucion
}

void caso_2_newton_raphson(){

	/**
	 * @brief Función a la que se le aplicará el método de Newton - Raphson
	 * @param P0 aproximación inicial
	 * @param tol tolerancia
	 * @param n número máximo de iteraciones
	 * @return Solución aproximada p o mensaje de error
	*/
	double p0, tol;
	int n;
	
	string str_f = "x^3 + 4*(x^2) - 10";
    string str_df = "3*(x^2) + 8*x";
	
	cout << "Metodo de Newton-Raphson" << endl;
	cout << "Funcion a evaluar: " << str_f << endl;
	cout << "Ingrese el valor inicial de x: ";
	cin >> p0;
	cout << "Ingrese la tolerancia (en porcentaje): ";
	cin >> tol;
	cout << "Ingrese el maximo numero de iteraciones: ";
	cin >> n;
	//Crear una instancia de newton-raphson pasando 
	//la formula y su derivada como parametro
	
    
	newton_raphson nr(str_f, str_df); // Crear una instancia de newton_raphson
    
	solucion sol = nr.calcular(p0, tol, n); // Calcular la solucion
    
    sol.imprimir(); // Imprimir la solucion
}

void caso_3_newton_raphson(){

	/**
	 * @brief Función a la que se le aplicará el método de Newton - Raphson
	 * @param P0 aproximación inicial
	 * @param tol tolerancia
	 * @param n número máximo de iteraciones
	 * @return Solución aproximada p o mensaje de error
	*/
	double p0, tol;
	int n;
	
	string str_f = "e^(~x) + x^2 - 2";
    string str_df = "~(e^(~x)) + 2*x";
	
	cout << "Metodo de Newton-Raphson" << endl;
	cout << "Funcion a evaluar: " << str_f << endl;
	cout << "Ingrese el valor inicial de x: ";
	cin >> p0;
	cout << "Ingrese la tolerancia (en porcentaje): ";
	cin >> tol;
	cout << "Ingrese el maximo numero de iteraciones: ";
	cin >> n;
	//Crear una instancia de newton-raphson pasando 
	//la formula y su derivada como parametro
	
    
	newton_raphson nr(str_f, str_df); // Crear una instancia de newton_raphson
    
	solucion sol = nr.calcular(p0, tol, n); // Calcular la solucion
    
    sol.imprimir(); // Imprimir la solucion
}

void caso_1_biseccion() {
	
	double xa, xb, tol;
	int n;
	
	string str_f = "e^~x - ln(x)";
	
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
	
	if (std::isnan(sol.raiz)) {
		cout << "No se pudo obtener la raiz con los datos dados"<<endl;
	}else {
		cout << "La raiz es: " << sol.raiz <<endl;
		cout << "Aproximaciones: "<< endl;
		for (unsigned int i = 0; i< sol.aproximaciones.size(); i++) {
			cout << setw(15)
				<< setprecision(10)
				<< sol.aproximaciones[i].xAnt
				<< setw(15)
				<< setprecision(10)
				<< sol.aproximaciones[i].xNueva
				<< setw(15)
				<<setprecision(10)
				<< sol.aproximaciones[i].erp
				<<endl;
		}
	}
}

void caso_2_biseccion() {
	
	double xa, xb, tol;
	int n;
	
	string str_f = "x^3 + 4*(x^2) - 10";
	
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
	
	if (std::isnan(sol.raiz)) {
		cout << "No se pudo obtener la raiz con los datos dados"<<endl;
	}else {
		cout << "La raiz es: " << sol.raiz <<endl;
		cout << "Aproximaciones: "<< endl;
		for (unsigned int i = 0; i< sol.aproximaciones.size(); i++) {
			cout << setw(15)
				<< setprecision(10)
				<< sol.aproximaciones[i].xAnt
				<< setw(15)
				<< setprecision(10)
				<< sol.aproximaciones[i].xNueva
				<< setw(15)
				<<setprecision(10)
				<< sol.aproximaciones[i].erp
				<<endl;
		}
	}
}

void caso_3_biseccion() {
	
	double xa, xb, tol;
	int n;
	
	string str_f = "e^(~x) + x^2 - 2";
	
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
	
	if (std::isnan(sol.raiz)) {
		cout << "No se pudo obtener la raiz con los datos dados"<<endl;
	}else {
		cout << "La raiz es: " << sol.raiz <<endl;
		cout << "Aproximaciones: "<< endl;
		for (unsigned int i = 0; i< sol.aproximaciones.size(); i++) {
			cout << setw(15)
				<< setprecision(10)
				<< sol.aproximaciones[i].xAnt
				<< setw(15)
				<< setprecision(10)
				<< sol.aproximaciones[i].xNueva
				<< setw(15)
				<<setprecision(10)
				<< sol.aproximaciones[i].erp
				<<endl;
		}
	}
}

void caso_1_reglaFalsa() {
	
	double xi, xs, tol;
	int n;
	
	string str_f = "e^~x - ln(x)";
	
	cout << "Metodo de biseccion" << endl;
	cout << "Funcion a evaluar: " << str_f << endl;
	cout << "Ingrese el valor inferior del intervalo: ";
	cin >> xi;
	cout << "Ingrese el valor superior del intervalo: ";
	cin >> xs;
	cout << "Ingrese la tolerancia (en porcentaje): ";
	cin >> tol;
	cout << "Ingrese el maximo numero de iteraciones: ";
	cin >> n;
	//Crear una instancia de biseccion pasando 
	//la funcion como parametro
	
	reglafalsa rf(str_f);
	
	solucion sol = rf.calcular(xi, xs, tol, n);

    sol.imprimir();
}

void caso_2_reglaFalsa() {
	
	double xi, xs, tol;
	int n;
	
	string str_f = "x^3 + 4*(x^2) - 10";
	
	cout << "Metodo de biseccion" << endl;
	cout << "Funcion a evaluar: " << str_f << endl;
	cout << "Ingrese el valor inferior del intervalo: ";
	cin >> xi;
	cout << "Ingrese el valor superior del intervalo: ";
	cin >> xs;
	cout << "Ingrese la tolerancia (en porcentaje): ";
	cin >> tol;
	cout << "Ingrese el maximo numero de iteraciones: ";
	cin >> n;
	//Crear una instancia de biseccion pasando 
	//la funcion como parametro
	
	reglafalsa rf(str_f);
	
	solucion sol = rf.calcular(xi, xs, tol, n);

    sol.imprimir();
}

void caso_3_reglaFalsa() {
	
	double xi, xs, tol;
	int n;
	
	string str_f = "e^(~x) + x^2 - 2";
	
	cout << "Metodo de biseccion" << endl;
	cout << "Funcion a evaluar: " << str_f << endl;
	cout << "Ingrese el valor inferior del intervalo: ";
	cin >> xi;
	cout << "Ingrese el valor superior del intervalo: ";
	cin >> xs;
	cout << "Ingrese la tolerancia (en porcentaje): ";
	cin >> tol;
	cout << "Ingrese el maximo numero de iteraciones: ";
	cin >> n;
	//Crear una instancia de biseccion pasando 
	//la funcion como parametro
	
	reglafalsa rf(str_f);
	
	solucion sol = rf.calcular(xi, xs, tol, n);

    sol.imprimir();
}

void menu(){
	int opcion;
	do{
		cout << "1. Metodo de Newton-Raphson" << endl;
		cout << "2. Metodo de Biseccion" << endl;
		cout << "3. Regla Falsa" << endl;
		cout << "4. Salir" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		switch(opcion){
			case 1:
				cout << "Seleccione el caso a evaluar: " << endl;
				cout << "1. e^~x - ln(x)" << endl;
				cout << "2. x^3 + 4*(x^2) - 10" << endl;
				cout << "3. e^(~x) + x^2 - 2" << endl;
				cout << "Ingrese una opcion: ";
				cin >> opcion;
				switch(opcion){
					case 1:
						caso_1_newton_raphson();
						break;
					case 2:
						caso_2_newton_raphson();
						break;
					case 3:
						caso_3_newton_raphson();
						break;
					default:
						cout << "Opcion invalida" << endl;
				}
				break;
			case 2:
				cout << "Seleccione el caso a evaluar: " << endl;
				cout << "1. e^~x - ln(x)" << endl;
				cout << "2. x^3 + 4*(x^2) - 10" << endl;
				cout << "3. e^(~x) + x^2 - 2" << endl;
				cout << "Ingrese una opcion: ";
				cin >> opcion;
				switch(opcion){
					case 1:
						caso_1_biseccion();
						break;
					case 2:
						caso_2_biseccion();
						break;
					case 3:
						caso_3_biseccion();
						break;
					default:
						cout << "Opcion invalida" << endl;
				}
				break;
			case 3:
				cout << "Seleccione el caso a evaluar: " << endl;
				cout << "1. e^~x - ln(x)" << endl;
				cout << "2. x^3 + 4*(x^2) - 10" << endl;
				cout << "3. e^(~x) + x^2 - 2" << endl;
				cout << "Ingrese una opcion: ";
				cin >> opcion;
				switch(opcion){
					case 1:
						caso_1_reglaFalsa();
						break;
					case 2:
						caso_2_reglaFalsa();
						break;
					case 3:
						caso_3_reglaFalsa();
						break;
					default:
						cout << "Opcion invalida" << endl;
				}
				break;
			case 4:
				cout << "Saliendo..." << endl;
				exit(0);	
				break;
			default:
				cout << "Opcion invalida" << endl;
		}
	}while(opcion != 4);
}

int main () {
	//caso_1_biseccion(); 
	//caso_1_newton_raphson();
	menu();
	return 0;
}






