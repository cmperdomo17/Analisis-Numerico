#include <iostream>
#include "regresion.h"
#include <vector>

using std::cout;
using std::endl;
using std::vector; 

using regresion::solucion_lineal;
using regresion::lineal_simple;

/**
 * @brief Caso 1
*/
void caso_1();

/**
 * @brief Caso 1 - Snatch damas
*/
void caso_1_snatch_damas();

int main(){
    // Caso 1 diapositivas
    caso_1();
    return 0;
}

void caso_1(){
    cout << "\nCaso 1." << endl;
    vector <double> x = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f};
    vector <double> y = {0.5f, 2.5f, 2.0f, 4.0f, 3.5f, 6.0f, 5.5f};
    // imprimir_tabla(x,y); TODO: Implementar
    lineal_simple ls(x,y); 
    solucion_lineal sol = ls.calcular();

    sol.imprimir();
}

void caso_1_snatch_damas(){
    // TODO: Implementar
}