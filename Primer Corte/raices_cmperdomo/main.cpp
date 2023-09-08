#include<iostream>
#include <string>

#include "biseccion.h"
#include "expression.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using raices::biseccion;

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