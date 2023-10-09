#include <iostream>
#include "regresion.h"
#include <vector>

using std::cout;
using std::endl;
using std::vector; 

using regresion::lineal_simple;
using regresion::exponencial;
using regresion::potencia;
using regresion::cuadratica;

using regresion::solucion_lineal;
using regresion::solucion_potencia;
using regresion::solucion_exponencial;
using regresion::solucion_cuadratica;

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
 * @brief Caso 1 - Regresion linealizada mediante la funcion potencia
*/
void caso_1_potencia();

/**
 * @brief Caso 1 - Regresion linealizada mediante la funcion exponencial
*/
void caso_1_exponencial();


/**
 * @brief Caso 1 - Regresion cuadratica
*/
void caso_1_cuadratica();



/**
 * @brief Ejecuta un caso de regresion lineal
 * @param x Vector de la variable independiente
 * @param y Vector de la variable dependiente
 * @param titulo Titulo de la regresion
 * @param x_label Etiqueta de la variable independiente
 * @param y_label Etiqueta de la variable dependiente
*/
void caso_regresion_lineal(vector <double> x, vector <double> y, string title, string x_label = "", string y_label = "");

/**
 * @brief Ejecuta un caso de regresion Linealizada mediante la funcion potencia
 * @param x Vector de la variable independiente
 * @param y Vector de la variable dependiente
 * @param titulo Titulo de la regresion
 * @param x_label Etiqueta de la variable independiente
 * @param y_label Etiqueta de la variable dependiente
 * 
*/
void caso_regresion_potencia(vector <double> x, vector <double> y, string title, string x_label = "", string y_label = "");

/**
 * @brief Ejecuta un caso de regresion Linealizada mediante la funcion exponencial
 * @param x Vector de la variable independiente
 * @param y Vector de la variable dependiente
 * @param titulo Titulo de la regresion
 * @param x_label Etiqueta de la variable independiente
 * @param y_label Etiqueta de la variable dependiente
 * 
*/
void caso_regresion_exponencial(vector <double> x, vector <double> y, string title, string x_label = "", string y_label = "");

/**
 * @brief Ejecuta un caso de regresion cuadratica
 * @param x Vector de la variable independiente
 * @param y Vector de la variable dependiente
 * @param titulo Titulo de la regresion
 * @param x_label Etiqueta de la variable independiente
 * @param y_label Etiqueta de la variable dependiente
*/
void caso_regresion_cuadratica(vector <double> x, vector <double> y, string title, string x_label = "", string y_label = "");


/**
 * @brief Ejercicio 1
*/
void ejercicio_1_lineal();

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
    while(opcion != 10){
        cout << "\n---------------- Menu principal ----------------\n" << endl;
        cout << "1. Caso 1." << endl;
        cout << "2. Caso 1. Snatch damas." << endl;
        cout << "3. Caso 1. Clean & Jerk hombres." << endl;
        cout << "4. Ejercicio 1: Gastos y Ventas." << endl;
        cout << "5. Ejercicio 2: Trigo y Harina." << endl;
        cout << "6. Ejercicio 3: Errores en Software." << endl;
        cout << "7. Caso 1. Potencia." << endl;
        cout << "8. Caso 1. Exponencial." << endl;
        cout << "9. Caso 1. Cuadratica." << endl;
        cout << "10. Salir." << endl;
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
                ejercicio_1_lineal();
                break;
            case 5:
                ejercicio_2();
                break;
            case 6:
                ejercicio_3();
                break;
            case 7:
                caso_1_potencia();
                break;
            case 8:
                caso_1_exponencial();
                break;
            case 9:
                caso_1_cuadratica();
                break;
            case 10:
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

    caso_regresion_lineal(x, y, "\nCaso 1");
}

void caso_snatch_damas(){
    
    vector <double> x = {48.0f, 53.0f, 58.0f, 63.0f, 69.0f, 75.0f, 90.0f};
    vector <double> y = {98.0f, 103.0f, 112.0f, 117.0f, 123.0f, 135.0f, 130.0f};

    caso_regresion_lineal(x, y, "\nCaso 1. Snatch damas", "Peso corporal (kg)", "Peso levantado (kg)");
}

void caso_clean_and_jerk(){
 
    vector <double> x = {56.0f, 62.0f, 69.0f, 77.0f, 85.0f, 94.0f, 105.0f};
    vector <double> y = {171.0f, 183.0f, 198.0f, 214.0f, 220.0f, 233.0f, 246.0f};

    caso_regresion_lineal(x, y, "\nCaso 1. Clean & Jerk hombres", "Peso corporal (kg)", "Peso levantado (kg)");

}

void caso_regresion_lineal(vector <double> x, vector <double> y, string title, string x_label, string y_label){
    // Imprime el titulo del caso
    cout << title << endl;

    // Imprimir la tabla
    imprimir_tabla(x, y, x_label, y_label);
    lineal_simple ls(x,y);
    solucion_lineal sol = ls.calcular();

    sol.imprimir();
}

void caso_regresion_potencia(vector <double> x, vector <double> y, string title, string x_label, string y_label){
    // Imprime el titulo del caso
    cout << title << endl;

    // Imprimir la tabla
    imprimir_tabla(x, y, x_label, y_label);
    potencia reg_pot(x,y);
    solucion_potencia sol = reg_pot.calcular();

    sol.imprimir();
}

void caso_regresion_exponencial(vector <double> x, vector <double> y, string title, string x_label, string y_label){
    // Imprime el titulo del caso
    cout << title << endl;

    // Imprimir la tabla
    imprimir_tabla(x, y, x_label, y_label);
    exponencial reg_exp(x,y);
    solucion_exponencial sol = reg_exp.calcular();

    sol.imprimir();
}

void caso_regresion_cuadratica(vector <double> x, vector <double> y, string title, string x_label, string y_label){
    // Imprime el titulo del caso
    cout << title << endl;

    // Imprimir la tabla
    imprimir_tabla(x, y, x_label, y_label);
    cuadratica reg_cua(x,y);
    solucion_cuadratica sol = reg_cua.calcular();

    sol.imprimir();
}

// Ejemplos sobre regresion Lineal

void ejercicio_1_lineal(){

    vector <double> x = {14.22, 13.93, 15.50, 16.31, 17.49, 19.89, 21.48, 20.40, 22.68, 20.97, 23.35, 26.10, 29.11, 27.24, 23.01, 27.61, 32.11, 36.18, 37.57, 33.51, 36.61, 31.16, 32.78, 41.19, 39.97, 39.69, 40.30, 40.95}; // Gastos en publicidad (millones de pesos)
    vector <double> y = {95.07, 97.28, 103.16, 107.61, 113.86, 121.15, 129.10, 132.34, 142.86, 143.12, 147.93, 155.96, 164.95, 163.92, 163.43, 172.49, 180.52, 190.51, 196.50, 196.02, 200.83, 196.77, 205.34, 220.23, 228.70, 236.50, 244.56, 254.77}; // Volumen de ventas (millones de pesos)

    caso_regresion_lineal(x, y, "\nEjercicio 1", "Gastos en Publicidad", "Volumen de Ventas");
}

void ejercicio_2(){
    vector <double> x = {30, 28, 32, 25, 27, 26, 23, 24, 35, 40};  // Producción de trigo (miles de toneladas)
    vector <double> y = {25, 30, 27, 40, 42, 40, 50, 45, 30, 25};  // Precio del kilo de harina de trigo (en pesos)

    caso_regresion_lineal(x, y, "\nEjercicio 2", "Produccion de trigo", "Precio del kilo de harina de trigo");
}

void ejercicio_3(){
    vector <double> x = {235, 276, 373, 412, 506, 598, 642, 703, 773, 844, 968, 1164};  // Tamaño de módulo en LDC
    vector <double> y = {6, 7, 11, 21, 19, 15, 27, 26, 36, 34, 44, 49};                // Cantidad de errores detectados

    caso_regresion_lineal(x, y, "\nEjercicio 3", "Tamanio de modulo en LDC", "Cantidad de errores detectados");
}

void caso_1_potencia(){
    vector <double> x = {10.0f, 20.0f, 30.0f, 40.0f, 50.0f, 60.0f, 70.0f, 80.0f};
    vector <double> y = {1.06f, 1.33f, 1.52f, 1.68f, 1.81f, 1.91f, 2.01f, 2.11f};

    caso_regresion_potencia(x, y, "\nCaso 1. Potencia", "X", "Y");
}

void caso_1_exponencial(){
    vector<double> x = {12.0f, 41.0f, 93.0f, 147.0f, 204.0f, 264.0f, 373.0f, 509.0f, 773.0f};
    vector<double> y = {930.0f, 815.0f, 632.0f, 487.0f, 370.0f, 265.0f, 147.0f, 76.0f, 17.0f};  

    caso_regresion_exponencial(x, y, "\nCaso 1. Exponencial", "X", "Y");
}

void caso_1_cuadratica(){
    vector<double> x = {0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0};
    vector<double> y = {2.1f, 7.7f, 13.6f, 27.2f, 40.9f, 61.1f};

    caso_regresion_cuadratica(x, y, "\nCaso 1. Cuadratica", "X", "Y");
}