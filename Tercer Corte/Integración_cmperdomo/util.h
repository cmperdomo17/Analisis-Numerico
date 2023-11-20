/**
 * @file
 * @brief Biblioteca de utilidades
 * @author Carlos Mario Perdomo Ramos <cmperdomo@unicauca.edu.co>
*/

#ifndef UTIL_H
#define UTIL_H

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "expression.h"

using std::setprecision;
using std::setw;
using std::left;
using std::right;
using std::endl;
using std::string;
using std::vector;
using std::to_string;
using std::cout;

namespace util {
    /**
     * @brief Repite una cadena de caracteres
     * @param s Cadena a repetir
     * @param n Cantidad de repeticiones
     * @return Concatenación de s n veces
     */
    string str_repeat(string s, int n) {
        string ret = "";
        for (int i = 0; i < n; i++) {
            ret += s;
        }
        return ret;
    }

    int getCenteredWidth(size_t label_length, int value) {
        size_t value_length = to_string(value).length();
        return (label_length - value_length) / 2 + value_length;
    }

    /**
     * Imprime una tabla de datos
     * @param X variable independiente
     * @param y variable dependiente
     * @param x_label Etiqueta de la variable independiente
     * @param y_label Etiqueta de la variable dependiente
     */
    void imprimir_tabla(vector<double> x, vector<double> y, string x_label = "", string y_label = "") {

        if (x_label.empty()) {
            x_label = "X";
        }

        if (y_label.empty()) {
            y_label = "Y";
        }

        size_t x_width = x_label.length() + 4;
        size_t y_width = y_label.length() + 4;

        cout << "\n";
        cout << str_repeat("=", x_width + y_width + 2) << endl;

        cout << "  " << setw(x_width) << left << x_label << setw(y_width / 4) << right << y_label << endl;

        cout << str_repeat("=", x_width + y_width + 2) << endl;

        for (size_t i = 0; i < x.size(); i++) {
            int x_space = getCenteredWidth(x_width, x[i]);
            int y_space = getCenteredWidth(y_width, y[i]);

            cout << setw(x_space) << right << x[i] << setw(x_width - x_space + y_space) << right << y[i] << endl;
        }
        cout << str_repeat("=", x_width + y_width + 2) << endl;
        cout << "\n";
    }

    /**
     * @brief Eliminacion de Gauss para una matriz de reales
     * @param m Matriz de reales
     * @return vector<double> Vector de coeficientes
     */
    vector<double> gauss(vector<vector<double>> m) {
        int i, j, k;
        int n = m.size();
        vector<double> resultado(n);

        // Pivoteo: Para cada fila i, buscar en la columna i el valor mayor
        // e intercambiar la fila i por la que contenga el valor mayor.
        for (i = 0; i < n - 1; i++) {
            for (j = i + 1; j < n; j++) {
                if (m[i][j] > m[i][i]) {
                    std::swap(m[i], m[j]);
                }
            }
        }

        // Eliminación gaussiana
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                double v = m[j][i] / m[i][i]; // Valor que anula el elemento en la columna

                // Hacer la operación fila[j] = fila[j] - v * fila[i]
                for (k = 0; k <= n; k++) {
                    m[j][k] -= v * m[i][k];
                }
            }
        }

        // Despejar las variables
        for (i = n - 1; i >= 0; i--) {
            resultado[i] = m[i][n];

            // Reemplazar las variables ya halladas
            for (j = i + 1; j < n; j++) {
                if (i != j) { // Reemplazar las variables, menos el coeficiente
                    resultado[i] = resultado[i] - m[i][j] * resultado[j];
                }
            }

            resultado[i] = resultado[i] / m[i][i];
        }

        return resultado;
    }

    /**
     * @brief Construye una tabla de datos espaciados uniformemente.
     * @param x Referencia al vector donde se almacenarán los valores de x.
     * @param y Referencia al vector donde se almacenarán los valores de y.
     * @param a Limite inferior.
     * @param b Limite superior.
     * @param n Cantidad de segmentos.
     * @param str_fn Texto de la función a evaluar.
     */
    void crear_tabla(vector<double> &x, vector<double> &y, double a, double b, int n, string str_fn) {
        // Crear el evaluador
        Expression f(str_fn);

        // Reservar espacio para la cantidad requerida de segmentos
        x.resize(n + 1);
        y.resize(n + 1);

        // Calcular el paso
        double h = (b - a) / (double)n;

        double xi = a;

        for (int i = 0; i <= n; i++) {
            x[i] = xi;
            y[i] = f(xi);
            xi += h;
        }
    }
}

#endif

