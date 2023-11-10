#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "util.h"
#include "trapecio.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::setprecision;

using integracion::trapecio;
using util::imprimir_tabla;

/**
 * @brief Integración usando el método del Trapecio
 * @param title Título del caso de prueba
 * @param str_fn Función a integrar
 * @param a Límite inferior del intervalo
 * @param b Límite superior del intervalo
 * @param n Número de subintervalos (segmentos)
*/
void calculo_trapecio(string title, string str_fn, double a, double b, int n);

/** @brief Caso 1 - Método del Trapecio */
void caso_1_trapecio();

int main(){
    caso_1_trapecio();
    return 0;
}

void caso_1_trapecio(){

    // Declarar las variables
    string str_fn;
    double a;
    double b;
    int n;

    // Pedir los datos al usuario
    cout << "Ingrese la funcion a integrar: ";
    cin >> str_fn;
    cout << "Ingrese el limite inferior: ";
    cin >> a;
    cout << "Ingrese el limite superior: ";
    cin >> b;
    cout << "Ingrese el numero de segmentos: ";
    cin >> n;

    calculo_trapecio("Metodo del Trapecio", str_fn, a, b, n);

}

void calculo_trapecio(string title, string str_fn, double a, double b, int n){
    cout << "========================================" << endl;
    cout << title << endl;
    cout << "========================================" << endl;
    cout << "Funcion: " << str_fn << endl;
    cout << "Limite inferior: " << a << endl;
    cout << "Limite superior: " << b << endl;
    cout << "Numero de subintervalos: " << n << endl;
    cout << "========================================" << endl;

    // Crear una instancia de Trapecio
    trapecio t(str_fn);

    vector <double> x;
    vector <double> y;
    // Crear la tabla de valores
    t.crear_tabla(x,y,a,b,n);
    // Imprimir la tabla de valores
    imprimir_tabla(x,y, "    x    ", "    y    ");
    // Calcular el valor de la integral
    double valor = t.calcular(x,y);
    // Mostrar el resultado
    cout << "Valor de la integral entre " << a << " y " << b << ": " << setprecision(8) << valor << endl;
}