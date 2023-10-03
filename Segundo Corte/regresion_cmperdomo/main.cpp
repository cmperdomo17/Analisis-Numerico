#include <iostream>
#include "regresion.h"
#include <vector>

using std::cout;
using std::endl;
using std::vector; 

using regresion::solucion_lineal;
using regresion::lineal_simple;
using regresion::imprimir_tabla;

/**
 * @brief Caso 1
*/
void caso_1();

/**
 * @brief Caso 1 - Snatch damas
*/
void caso_snatch_damas();

/**
 * @brief Caso 1 - Clean & Jerk hombres
*/
void caso_clean_and_jerk();

/**
 * @brief Ejecuta un caso de regresion lineal
 * @param x Vector de la variable independiente
 * @param y Vector de la variable dependiente
 * @param titulo Titulo de la regresion
 * @param x_label Etiqueta de la variable independiente
 * @param y_label Etiqueta de la variable dependiente
*/
void caso_regresion(vector <double> x, vector <double> y, string title, string x_label = "", string y_label = "");

/**
 * @brief Ejercicio 1
*/
void ejercicio_1();

/**
 * @brief Ejercicio 2
*/
void ejercicio_2();

/**
 * @brief Ejercicio 3
*/
void ejercicio_3();

/**
 * @brief Funcion principal
*/
int main();

int main(){
    // Menú principal:
    int opcion = 0;
    while(opcion != 4){
        cout << "\n---------------- Menu principal ----------------\n" << endl;
        cout << "1. Caso 1." << endl;
        cout << "2. Caso 1. Snatch damas." << endl;
        cout << "3. Caso 1. Clean & Jerk hombres." << endl;
        cout << "4. Ejercicio 1: Gastos y Ventas." << endl;
        cout << "5. Ejercicio 2: Trigo y Harina." << endl;
        cout << "6. Ejercicio 3: Errores en Software." << endl;
        cout << "7. Salir." << endl;
        cout << "\nIngrese una opcion: ";
        std::cin >> opcion;

        switch(opcion){
            case 1:
                caso_1();
                break;
            case 2:
                caso_snatch_damas();
                break;
            case 3:
                caso_clean_and_jerk();
                break;
            case 4:
                ejercicio_1();
                break;
            case 5:
                ejercicio_2();
                break;
            case 6:
                //ejercicio_3();
            case 7:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
    }
    return 0;
}

void caso_1(){

    vector <double> x = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f};
    vector <double> y = {0.5f, 2.5f, 2.0f, 4.0f, 3.5f, 6.0f, 5.5f};

    caso_regresion(x, y, "\nCaso 1");
}

void caso_snatch_damas(){
    
    vector <double> x = {48.0f, 53.0f, 58.0f, 63.0f, 69.0f, 75.0f, 90.0f};
    vector <double> y = {98.0f, 103.0f, 112.0f, 117.0f, 123.0f, 135.0f, 130.0f};

    caso_regresion(x, y, "\nCaso 1. Snatch damas", "Peso corporal (kg)", "Peso levantado (kg)");
}

void caso_clean_and_jerk(){
 
    vector <double> x = {56.0f, 62.0f, 69.0f, 77.0f, 85.0f, 94.0f, 105.0f};
    vector <double> y = {171.0f, 183.0f, 198.0f, 214.0f, 220.0f, 233.0f, 246.0f};

    caso_regresion(x, y, "\nCaso 1. Clean & Jerk hombres", "Peso corporal (kg)", "Peso levantado (kg)");

}

void caso_regresion(vector <double> x, vector <double> y, string title, string x_label, string y_label){
    // Imprime el titulo del caso
    cout << title << endl;

    // Imprimir la tabla
    imprimir_tabla(x, y, x_label, y_label);
    lineal_simple ls(x,y);
    solucion_lineal sol = ls.calcular();

    sol.imprimir();
}

// Ejemplos sobre regresionLineal

void ejercicio_1(){

    vector <double> x = {14.22, 13.93, 15.50, 16.31, 17.49, 19.89, 21.48, 20.40, 22.68, 20.97, 23.35, 26.10, 29.11, 27.24, 23.01, 27.61, 32.11, 36.18, 37.57, 33.51, 36.61, 31.16, 32.78, 41.19, 39.97, 39.69, 40.30, 40.95}; // Gastos en publicidad (millones de pesos)
    vector <double> y = {95.07, 97.28, 103.16, 107.61, 113.86, 121.15, 129.10, 132.34, 142.86, 143.12, 147.93, 155.96, 164.95, 163.92, 163.43, 172.49, 180.52, 190.51, 196.50, 196.02, 200.83, 196.77, 205.34, 220.23, 228.70, 236.50, 244.56, 254.77}; // Volumen de ventas (millones de pesos)

    caso_regresion(x, y, "\nEjercicio 1", "Gastos en Publicidad", "Volumen de Ventas");
}

void ejercicio_2(){
    vector <double> x = {30, 28, 32, 25, 27, 26, 23, 24, 35, 40};  // Producción de trigo (miles de toneladas)
    vector <double> y = {25, 30, 27, 40, 42, 40, 50, 45, 30, 25};  // Precio del kilo de harina de trigo (en pesos)

    caso_regresion(x, y, "\nEjercicio 2", "Produccion de trigo", "Precio del kilo de harina de trigo");
}