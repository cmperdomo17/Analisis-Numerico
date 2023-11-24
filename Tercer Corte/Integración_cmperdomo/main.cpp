#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "romberg.h"
#include "simpson.h"
#include "trapecio.h"
#include "util.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::setprecision;
using util::crear_tabla;
using util::imprimir_tabla;
using integracion::simpson;
using integracion::simpson13;
using integracion::simpson38;
using integracion::trapecio;
using integracion::romberg;
using integracion::resultado_romberg;

// ? Biblioteca: mathplusplus 

// TODO Implementar metodos de errores de funciones Polinomicas y No Polinomicas
// TODO Los metodos (polinomica y no polinomica) se implementan en cada respectiva clase (.h)
// TODO Polinomica solo en Simpson 1/3

// * Trapecio: F2
// * Simpson 1/3 y 3/8: F4

// * Simpson 1/3: Par
// * Simpson 3/8: Impar y multiplo de 3

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

/**
 * @brief Integración usando el método de Romberg
 * @param title Título del caso de prueba
 * @param str_fn Función a integrar
 * @param a Límite inferior del intervalo
 * @param b Límite superior del intervalo
 * @param k Número de aproximaciones
*/
void calculo_romberg(string title, string str_fn, double a, double b, int k);

/**
 * @brief Integración usando el método de Simpson
 * @param title Título del caso de prueba
 * @param x Vector de valores de x
 * @param y Vector de valores de y
*/
void caso_simpson(string title, vector<double> &x, vector<double> &y);

/** @brief Caso 1 - Método del Trapecio */
void caso_1_trapecio();

/** @brief Caso 1 - Metodo Simpson 1/3 */
void caso_1_simpson13();

/** @brief Caso 1 - Metodo Simpson 3/8 */
void caso_1_simpson38();

/** @brief Caso 1 - Metodo Simpson */
void caso_1_simpson();

/** @brief Caso 1 - Metodo Romberg */
void caso_1_romberg();

int main(){
    // Menu principal para pedir que caso usar
    int opcion;

    do{
        cout << "\n========================================" << endl;
        cout << "Integracion Numerica" << endl;
        cout << "========================================" << endl;
        cout << "1. Metodo del Trapecio" << endl;
        cout << "2. Metodo de Simpson 1/3" << endl;
        cout << "3. Metodo de Simpson 3/8" << endl;
        cout << "4. Metodo de Simpson: Tablas de Datos" << endl;
        cout << "5. Metodo de Romberg (sin(x))^2 " << endl;
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
            case 4:
                caso_1_simpson();
                break;
            case 5:
                caso_1_romberg();
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
    // Calcular el error
    double error = s.error_polinomico_s13(x,y);
    // Mostrar el resultado
    cout << "Valor de la integral entre " << a << " y " << b << ": " << setprecision(8) << valor << endl;
    // Mostar el error
    cout << "Error: " << setprecision(8) << error << endl;
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
    cout << "Valor de la integral entre " << a << " y " << b << ": " << setprecision(8) << valor << endl;
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

void caso_simpson(string title, vector<double> &x, vector<double> &y) {
    cout << title << ":" << " por el metodo de Simpson." << endl;

    simpson s;

    imprimir_tabla(x, y, "   X   ", "    Y    ");

    double valor = s.calcular(x, y);

    cout << "Valor del area de la tabla de datos: "
         << valor << endl;
}

void caso_1_simpson(){
    vector<double> x = {0.00000, 0.04706, 0.09412, 0.14118, 0.18824, 0.23529, 0.28235, 0.32941, 0.37647, 0.42353, 0.47059, 0.51765, 0.56471, 0.61176, 0.65882, 0.70588, 0.75294, 0.80000};
    vector<double> y = {0.20000, 0.99959, 1.27640, 1.30746, 1.28600, 1.33258, 1.50611, 1.81498, 2.22811, 2.68604, 3.11198, 3.42294, 3.54075, 3.40317, 2.97498, 2.25901, 1.30727, 0.23200};
    caso_simpson("\nCaso 1: Tabla de datos",
                  x,
                  y);
}

void caso_1_romberg(){

    // Declarar las variables
    string str_fn;
    double a;
    double b;
    int k;

    // Pedir los datos al usuario
    cout << "Ingrese la funcion a integrar: ";
    cin >> str_fn;
    cout << "Ingrese el limite inferior: ";
    cin >> a;
    cout << "Ingrese el limite superior: ";
    cin >> b;
    cout << "Ingrese el numero de aproximaciones: ";
    cin >> k;

    calculo_romberg("Metodo de Romberg", str_fn, a, b, k);

}

void calculo_romberg(string title, string str_fn, double a, double b, int k){
    cout << "========================================" << endl;
    cout << title << endl;
    cout << "========================================" << endl;
    cout << "Funcion: " << str_fn << endl;
    cout << "Limite inferior: " << a << endl;
    cout << "Limite superior: " << b << endl;
    cout << "Numero de aproximaciones: " << k << endl;
    cout << "========================================" << endl;

    // Crear una instancia de Romberg
    romberg r(str_fn);

    resultado_romberg res = r.calcular(a,b,k);

    // Calcular el valor de la integral
    double valor = res.valor;
    // Calcular el error
    double error = res.error;
    // Mostrar el resultado y el error
    cout << "\nValor de la integral entre " << a << " y " << b << ": \n" << setprecision(8) << valor << "\n" << endl;
    cout << "Error: \n" << setprecision(8) << error << endl;
}