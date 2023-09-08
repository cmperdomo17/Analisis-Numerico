#include<iostream>
#include <string>

#include "biseccion.h"
#include "reglafalsa.h"
#include "expression.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using raices::biseccion;
using raices::reglafalsa;


/**
* @brief Caso 1. e^~x - ln(x)
*/

void caso_1_biseccion();

/**
* @brief Caso 2. e^~x - ln(x)
*/

void caso_1_reglaFalsa();

int main () {
	//caso_1_biseccion(); //Caso 1	
	caso_1_reglaFalsa();
	return 0;
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