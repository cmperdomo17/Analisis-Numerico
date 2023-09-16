#include <cmath>
#include <iostream>
#include "solucion.h"
#include "biseccion.h"
#include "reglafalsa.h"
#include "newton_raphson.h"
#include "newton_generalizado.h"
#include "muller.h"
#include "secante.h"
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::isnan;
using std::make_pair;
using std::pair;
using std::string;
using std::to_string;

using raices::aproximacion;
using raices::biseccion;
using raices::muller;
using raices::newton_generalizado;
using raices::newton_raphson;
using raices::reglafalsa;
using raices::secante;
using raices::solucion;

void ejercicio_2();
void ejercicio_1();
void imprimir_aproximaciones(vector<pair<string, solucion>> soluciones, string funcstr);
void metodo_biseccion(string fstr);
void metodo_reglaFalsa(string fstr);
void metodo_secante(string fstr);

int main()
{
    int opcion;
    do
    {
        cout << "\n==============================================================\n" << endl;
        cout << "Ingrese que ejercicio desea evaluar: \n\n";
        cout << "\n[1]. Ejercicio 1 \n";
        cout << "\n[2]. Ejercicio 2 \n";
        cout << "\n[3]. Salir \n";
        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            ejercicio_1();
            break;
        case 2:
            ejercicio_2();
            break;
        case 3:
            cout << "\nSaliendo..." << endl;
            exit(0);
            break;
        default:
            cout << "\nOpcion invalida" << endl;
        }

    } while (opcion != 3);

    return 0;
}

void ejercicio_1()
{
    int metodo;
    
    std::string fstr = "q = (1 / n) * sqrt(i) * (pow(h * (b + m * h), 5.0 / 3.0) / pow(b + 2 * h * sqrt(1 + m * m), 2.0 / 3.0))";

    cout << "\n1. Ejercicio 1" << endl;
    cout << "\nFuncion: " << fstr << endl;
    cout << "\nIngrese por que metodo desea hallar la raiz: \n\n";
    cout << "[1]. Metodo de Biseccion \n";
    cout << "[2]. Metodo de Regla Falsa \n";
    cout << "[3]. Metodo de la Secante \n";
    cout << "[4]. Regresar al menu principal \n";

    cout << "\nIngrese una opcion: ";
    cin >> metodo;

    switch (metodo)
    {
    case 1:
        metodo_biseccion(fstr);
        break;
    case 2:
        metodo_reglaFalsa(fstr);
        break;
    case 3:
        metodo_secante(fstr);
        break;
    case 4:
        // Regresar al menú principal
        return;
    default:
        cout << "\nOpcion invalida" << endl;
    }
}

void ejercicio_2()
{
	// erp
	string fstr("~x^3*(0.85*x^4+0.75*x^3-0.25*x^2+0.5*x-5.5)");
	string dfstr("~5.95*x^6-4.5*x^5+1.25*x^4-2*x^3+16.5*x^2");
	string d2fstr("~35.7*x^5-22.5*x^4+5*x^3-6*x^2+33*x");
	double erp = 1e-8f;
	double n = 20;
	// Regla falsa

	// Raiz 1
	double xInf = -2.1f;
	double xSup = -1.9f;
	// Raiz 2 (Falla)
	double xInf2 = -0.2f;
	double xSup2 = 0.4;
	// Raiz 3
	double xInf3 = 1.3f;
	double xSup3 = 1.5f;

	// Newton
	// Raiz 1
	double p0 = -2.1f;
	// Raiz 2 (Falla)
	double p01 = 0.1f;
	// Raiz 3
	double p02 = 1.5f;

	// Newton generalizado

	// Raiz 1
	double p0ng = -2.1f;
	// Raiz 2 (No falla)
	double p0ng1 = 0.5f;
	// Raiz 3
	double p0ng2 = 1.5f;
	// Muller

	// Raiz 1
	double x2 = -2.2;
	double x1 = -2.1;
	double x0 = -2.0f;

	// Raiz 2 (falla)
	double x2_1 = 0.8f;
	double x1_1 = 1.0f;
	double x0_1 = 1.3f;

	// Raiz 3
	double x2_2 = 1.28f;
	double x1_2 = 1.29f;
	double x0_2 = 1.3f;

	vector<pair<string, solucion>> soluciones = {
		{make_pair("Regla falsa (raiz 1) en el intervalo [" + to_string(xInf) + "," + to_string(xSup) + "]", reglafalsa(fstr).calcular(xInf, xSup, erp, n))},
		{make_pair("Regla falsa (raiz 2) en el intervalo [" + to_string(xInf2) + "," + to_string(xSup2) + "]", reglafalsa(fstr).calcular(xInf2, xSup2, erp, n))},
		{make_pair("Regla falsa (raiz 3) en el intervalo [" + to_string(xInf3) + "," + to_string(xSup3) + "]", reglafalsa(fstr).calcular(xInf3, xSup3, erp, n))},

		{make_pair("Newton-Raphson desde p0=" + to_string(p0), newton_raphson(fstr, dfstr).calcular(p0, erp, n))},
		{make_pair("Newton-Raphson desde p0=" + to_string(p01), newton_raphson(fstr, dfstr).calcular(p01, erp, n))},
		{make_pair("Newton-Raphson desde p0=" + to_string(p02), newton_raphson(fstr, dfstr).calcular(p02, erp, n))},

		{make_pair("Newton-Raphson generalizado desde p0=" + to_string(p0ng), newton_generalizado(fstr, dfstr, d2fstr).calcular(p0ng, erp, n))},
		{make_pair("Newton-Raphson generalizado desde p0=" + to_string(p0ng1), newton_generalizado(fstr, dfstr, d2fstr).calcular(p0ng1, erp, n))},
		{make_pair("Newton-Raphson generalizado desde p0=" + to_string(p0ng2), newton_generalizado(fstr, dfstr, d2fstr).calcular(p0ng2, erp, n))},

		{make_pair("Muller con x0=" + to_string(x0) + ", x1=" + to_string(x1) + ", x2=" + to_string(x2), muller(fstr).calcular(x0, x1, x2, erp, n))},
		{make_pair("Muller con x0=" + to_string(x0_1) + ", x1=" + to_string(x1_1) + ", x2=" + to_string(x2_1), muller(fstr).calcular(x0_1, x1_1, x2_1, erp, n))},
		{make_pair("Muller con x0=" + to_string(x0_2) + ", x1=" + to_string(x1_2) + ", x2=" + to_string(x2_2), muller(fstr).calcular(x0_2, x1_2, x2_2, erp, n))},
	};
	imprimir_aproximaciones(soluciones, fstr);
}

void imprimir_aproximaciones(vector<pair<string, solucion>> soluciones, string funcstr)
{
	cout << "\nAproximaciones para:" << funcstr << endl;

	for (auto &sol : soluciones)
	{
		cout << "Raiz de " << funcstr << " Usando el metodo de " << sol.first << endl;
		sol.second.imprimir();
		// sol.second.imprimir();

		cout << "\n=================================================================" << endl;
	}
}

void metodo_biseccion(string fstr) {
	
	double xa, xb, tol;
	int n;
	
	cout << "\nFuncion a evaluar: " << fstr << endl;
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
	
	biseccion bis(fstr);
	
	solucion sol = bis.calcular(xa, xb, tol, n);
	
	sol.imprimir();
}


void metodo_reglaFalsa(string fstr) {
	
	double xi, xs, tol;
	int n;
	
	cout << "\nFuncion a evaluar: " << fstr << endl;
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
	
	reglafalsa rf(fstr);
	
	solucion sol = rf.calcular(xi,xs,tol,n);
	
	sol.imprimir();
	
}

void metodo_secante(string fstr){
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
	
	secante sec(fstr);
	
	solucion sol = sec.calcular(x0,x1,tol,n);
	
	sol.imprimir();
}
