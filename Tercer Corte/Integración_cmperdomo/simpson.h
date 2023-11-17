#ifndef SIMSONTERCIO_H
#define SIMSONTERCIO_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "Expression.h"
#include "util.h"

using std::string;
using std::vector;

using util::crear_tabla;

namespace integracion{

	/**
	 * @brief Integracion mediante el metodo de Simpson general  	 
	*/
	class simpson{ //TODO Implementar metodo Simpson con 1/3 y 3/8 fusionados y validados los segmentos
		public:
		private:
	};

    /**
     * @brief Integracion mediante el metodo de Simpson 1 tercio
     */
    class simpson13{
    public:
        /**
         * @brief Constructor de la clase
         * @param p_fn Funcion a integrar
         */
        explicit simpson13(string p_fn):str_fn(p_fn){}

        double calcular(double a, double b, int n){
            if (n == 0 || n % 2 != 0) return NAN;
            if(a > b) std::swap(a , b);

            vector<double> x;
            vector<double> y;

            crear_tabla(x, y, a, b, n, str_fn);

            return calcular(x, y);
        }

        double calcular(vector<double> &x,
                        vector<double> &y){
            size_t n = x.size() - 1;
            if(n <= 0 || n % 2 != 0) return NAN;

			double resultado = 0.0f;
			double h = (x[n] - x[0]) / (double)n;
			double sum_pares = 0.0f;
			double sum_impares = 0.0f;

            for(size_t i = 1; i < n; i++){
                if(i % 2 != 0){
					// Suma Impares
                    sum_impares += fabs(y[i]);
                } else {
					// Suma Pares
                    sum_pares += fabs(y[i]);
                }
            }

			resultado = (h / 3.0f) * (fabs(y[0]) + (4.0f * sum_impares) + (2.0f * sum_pares) + fabs(y[n]));

			return resultado;
        }
    private:
        string str_fn;
    };

	/**
	 * @brief Integracion mediante el metodo de Simpson 3 octavos
	 */
	class simpson38 {
		public:
			/**
			 * @brief Constructor de la clase
			 * @param p_fn Funcion a integrar
			 */
			explicit simpson38(string p_fn): str_fn(p_fn) {}
			
			/**
			 * @brief Calcula el valor de la integral en el intervalo.
			 * @param a Limite inferior del intervalo.
			 * @param b Limite superior del intervalo.
			 * @param n Cantidad de segmentos.
			 * @return Valor aproximado de la integral.
			 */
			double calcular(double a, double b, int n) {
				
				if( n == 0 || n % 2 == 0 || n % 3 != 0 ) {
					return NAN;
				}
				
				if(a > b) {
					std::swap(a, b);
				}
				
				vector<double> x;
				vector<double> y;
				
				crear_tabla(x, y, a, b, n, str_fn);
				
				return calcular(x, y);
			}
			
			double calcular(vector<double> &x, vector<double> &y) {
				size_t n = x.size() - 1;
				if (n <= 0 || n % 2 == 0 || n % 3 != 0) {
					return NAN;
				}

				double h = (x[n] - x[0]) / (double)n;

				double sum_1 = 0.0f;
				double sum_2 = 0.0f;
				double sum_3 = 0.0f;

				for (size_t i = 1; i < n; i += 3) {
					sum_1 += fabs(y[i]);
				}

				for (size_t i = 2; i < n; i += 3) {
					sum_2 += fabs(y[i]);
				}

				for (size_t i = 3; i < n; i += 3) {
					sum_3 += fabs(y[i]);
				}

				double resultado = ((3.0f * h) / 8.0f) * (fabs(y[0]) + (3.0f * sum_1) + (3.0f * sum_2) + (2.0f * sum_3) + fabs(y[n]));

				return resultado;
			}
		private:
			string str_fn;
	};
}

#endif