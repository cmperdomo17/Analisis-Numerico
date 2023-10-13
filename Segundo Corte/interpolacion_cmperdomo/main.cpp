#include <iostream>
#include <vector>

#include "newton.h"
#include "util.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

using interpolacion::newton;
using util::imprimir_tabla;

/** @brief Caso 1 Newton - Diapositivas */
void caso_1_newton();

int main(){
    caso_1_newton();
    return 0;
}

void caso_1_newton(){

    vector <double> x = {
        100.0f, 200.0f, 300.0f, 400.0f, 500.0f
    };

    vector <double> y = {
        -160.0f, -35.0f, -4.2f, 9.0f, 16.9f
    };

    // Instancia de Newton
    newton n(x, y);

    // Imprimir el polinomio
    cout << "Polinomio interpolante: " << n.polinomio() << endl;

    // Valor a interpolar
    double x_int;

    cout << "Interpolacion por diferencias divididas de Newton" << endl;

    // Imprimir la tabla
    imprimir_tabla(x, y, "Temperatura(K)", "B (cm3/mol)");
    // Solicitar el valor a interpolar
    do{
        cout << "Ingrese el valor a interpolar: ";
        cin >> x_int;
    } while(x_int < x[0] || x_int > x[x.size() - 1]);

    // Interpolar el valor ingresado por el usuario
    double y_int = n.interpolar(x_int);

    cout << "y = " << setprecision(7) << y_int << endl;
    
}