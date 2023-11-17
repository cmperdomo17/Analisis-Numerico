#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "util.h"
#include "trapecio.h"
#include "simpson.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::setprecision;
using util::crear_tabla;

using integracion::trapecio;
using integracion::simpson13;
using integracion::simpson38;
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

/**
 * @brief Integración usando el método de Simpson 1/3
 * @param title Título del caso de prueba
 * @param str_fn Función a integrar
 * @param a Límite inferior del intervalo
 * @param b Límite superior del intervalo
 * @param n Número de subintervalos (segmentos)
*/
void calculo_simpson13(string title, string str_fn, double a, double b, int n);

/**
 * @brief Integración usando el método de Simpson 3/8
 * @param title Título del caso de prueba
 * @param str_fn Función a integrar
 * @param a Límite inferior del intervalo
 * @param b Límite superior del intervalo
 * @param n Número de subintervalos (segmentos)
*/
void calculo_simson38(string title, string str_fn, double a, double b, int n);

/** @brief Caso 1 - Método del Trapecio */
void caso_1_trapecio();

/** @brief Caso 1 - Metodo Simpson 1/3 */
void caso_1_simpson13();

/** @brief Caso 1 - Metodo Simpson 3/8 */
void caso_1_simpson38();

int main(){
    // Menu principal para pedir que caso usar
    int opcion;

    do{
        cout << "========================================" << endl;
        cout << "Integracion Numerica" << endl;
        cout << "========================================" << endl;
        cout << "1. Metodo del Trapecio" << endl;
        cout << "2. Metodo de Simpson 1/3" << endl;
        cout << "3. Metodo de Simpson 3/8" << endl;
        cout << "0. Salir" << endl;
        cout << "========================================" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch(opcion){
            case 1:
                caso_1_trapecio();
                break;
            case 2:
                caso_1_simpson13();
                break;
            case 3:
                caso_1_simpson38();
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
    } while(opcion != 0);

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
    crear_tabla(x,y,a,b,n,str_fn);
    // Imprimir la tabla de valores
    imprimir_tabla(x,y, "    x    ", "    y    ");
    // Calcular el valor de la integral
    double valor = t.calcular(x,y);
    // Mostrar el resultado
    cout << "Valor de la integral entre " << a << " y " << b << ": " << setprecision(8) << valor << "\n" << endl;
}

void caso_1_simpson13(){

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

    calculo_simpson13("Metodo de Simpson 1/3", str_fn, a, b, n);

}

void calculo_simpson13(string title, string str_fn, double a, double b, int n){
    cout << "========================================" << endl;
    cout << title << endl;
    cout << "========================================" << endl;
    cout << "Funcion: " << str_fn << endl;
    cout << "Limite inferior: " << a << endl;
    cout << "Limite superior: " << b << endl;
    cout << "Numero de subintervalos: " << n << endl;
    cout << "========================================" << endl;

    // Crear una instancia de Simpson
    simpson13 s(str_fn);

    vector <double> x;
    vector <double> y;
    // Crear la tabla de valores
    crear_tabla(x,y,a,b,n,str_fn);
    // Imprimir la tabla de valores
    imprimir_tabla(x,y, "    x    ", "    y    ");
    // Calcular el valor de la integral
    double valor = s.calcular(x,y);
    // Mostrar el resultado
    cout << "Valor de la integral entre " << a << " y " << b << ": " << setprecision(8) << valor << "\n" << endl;
}

void calculo_simson38(string title, string str_fn, double a, double b, int n){
    cout << "========================================" << endl;
    cout << title << endl;
    cout << "========================================" << endl;
    cout << "Funcion: " << str_fn << endl;
    cout << "Limite inferior: " << a << endl;
    cout << "Limite superior: " << b << endl;
    cout << "Numero de subintervalos: " << n << endl;
    cout << "========================================" << endl;

    // Crear una instancia de Simpson
    simpson38 s38(str_fn);

    vector <double> x;
    vector <double> y;
    // Crear la tabla de valores
    crear_tabla(x,y,a,b,n,str_fn);
    // Imprimir la tabla de valores
    imprimir_tabla(x,y, "    x    ", "    y    ");
    // Calcular el valor de la integral
    double valor = s38.calcular(x,y);
    // Mostrar el resultado
    cout << "Valor de la integral entre " << a << " y " << b << ": " << setprecision(8) << valor << "\n" << endl;
}

void caso_1_simpson38(){

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

    calculo_simson38("Metodo de Simpson 3/8", str_fn, a, b, n);

}