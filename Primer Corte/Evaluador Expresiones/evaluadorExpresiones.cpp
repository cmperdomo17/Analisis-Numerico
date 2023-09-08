#include <iostream>
#include "Expression.h"

using namespace std;

/**
 * @brief Verifica si la funcion cumple el TVI en el intervalo dado
 * @param funcion Expresión de la función como cadena de texto
 * @param a Extremo inferior del intervalo
 * @param b Extremo superior del intervalo
 * @return Verdadero si se cumple tTVI en el intervalo [a,b]
 */
bool cumple_tvi(const string& funcion, double a, double b) {
    Expression f(funcion);
    return (f(a) * f(b) < 0.0);
}

int main(int argc, char *argv[]) {
    // Uso del evaluador de expresiones.
    Expression f("x^3 - 2*x^2 -x + 1"); // Crear la expresión

    double a = -1.0;
    double b = -0.5;

    cout << f(a) << " : " << f(b) << endl;

    return 0;
}
