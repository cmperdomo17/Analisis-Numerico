#ifndef SIMPSON13_H
#define SIMPSON13_H

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#include "expression.h"
#include "util.h"

using std::string;
using std::vector;

using util::crear_tabla;
using util::calcular_derivadas;

namespace integracion {
    /**
     * @brief Integracion mediante el metodo de Simpson 1 tercio
     */
    class simpson13 {
    public:
        /**
         * @brief Constructor de la clase
         * @param p_fn Funcion a integrar
         */
        explicit simpson13(string p_fn) : str_fn(p_fn) {}

        double calcular(double a, double b, int n) {
            if (n == 0 || n % 2 != 0) return NAN;
            if (a > b) std::swap(a, b);

            vector<double> x;
            vector<double> y;

            crear_tabla(x, y, a, b, n, str_fn);

            return calcular(x, y);
        }

        static double calcular(vector<double> &x, vector<double> &y) {
            size_t n = x.size() - 1;
            if (n <= 0 || n % 2 != 0) return NAN;

            double resultado = 0.0f;
            double h = (x[n] - x[0]) / (double)n;
            double sum_pares = 0.0f;
            double sum_impares = 0.0f;

            for (size_t i = 1; i < n; i++) {
                if (i % 2 != 0) {
                    // Suma Impares
                    sum_impares += fabs(y[i]);
                } else {
                    // Suma Pares
                    sum_pares += fabs(y[i]);
                }
            }

            resultado = (h / 3.0f) * (y[0] + 4.0f * sum_impares + 2.0f * sum_pares + y[n]);

            return resultado;
        }

        // ? Biblioteca: mathplusplus 

        // TODO Implementar metodos de errores de funciones Polinomicas y No Polinomicas
        // TODO Los metodos (polinomica y no polinomica) se implementan en cada respectiva clase (.h)
        // TODO Polinomica solo en Simpson 1/3

        // * Simpson 1/3 y 3/8: F4

        // * Simpson 1/3: Par

        double error_polinomico_s13 (vector<double> &x, vector<double> &y) {
            int orden = 4;
            calcular_derivadas(x, y, orden);
            double dy = *max_element(y.begin(), y.end()); 
            double h = (x.back() - x.front()) / (double)(x.size() - 1); 
            double error = (pow(h, 4) / 180) * dy;
            return error;
        }

    private:
        string str_fn;
    };
}

#endif