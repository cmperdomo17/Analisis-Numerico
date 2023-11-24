#ifndef ROMBERG_H
#define ROMBERG_H

#include <string>
#include <vector>

#include "trapecio.h"

using integracion::trapecio;

using std::string;
using std::vector;
using std::cout;

namespace integracion {
    /**
     * @brief Resultado de la integracion por Romberg
    */
    struct resultado_romberg {
        double valor = NAN; /*!< Valor de la integral */
        double error = NAN; /*!< Error de la integral */
    };

    /**
     * @brief Integracion mediante el metodo de Romberg
    */
    class romberg {
    public:
        /**
         * @brief Crea una nueva instancia de Romberg
         * @param p_str_fn Funcion a integrar
        */
        romberg(string p_str_fn) : str_fn(p_str_fn) {};
        
        /**
         * @brief Calcula la integral en el intervalo [a, b] con k aproximaciones
         * @param a Limite inferior
         * @param b Limite superior
         * @param k Numero de aproximaciones
         * @return Valor de la integral aproximada
        */
        resultado_romberg calcular(double a, double b, int k){
            int i, j;
            resultado_romberg res;
            vector<vector<double>> m(k);
            if (k <= 1) return res;
            int n = 1;
            for (i = 0; i < k; i++) {
                m[i].resize(k - i);
                // Calcular los valores de la primera columna
                trapecio t(str_fn);
                m[i][0] = t.calcular(a, b, n);
                cout << n << " Segmentos = " << m[i][0] << endl;
                n *= 2;
            }

            // Calcular las aproximaciones

            double pot = 4.0f;

            for (j = 1; j < k; j++) {
                for (i = 0; i < k - j; i++) {
                    m[i][j] = (pot/(pot - 1.0f)) *
                            m[i + 1][j - 1] -
                            (1.0f/(pot - 1.0f)) *
                            m[i][j - 1];
                }
                pot *= 4.0f;
            }

            res.valor = m[0][k - 1];
            res.error = fabs(m[0][k-1] - m[0][k-2]) / m[0][k-1] * 100.0f;
            return res;
        }

    private:
        string str_fn; /*!< Funcion a integrar */
    };
}

#endif