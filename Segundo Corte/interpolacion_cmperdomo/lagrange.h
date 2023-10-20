/**
 * @file
 * @brief Interpolación mediante el método de Lagrange
 * @author Carlos Mario Perdomo Ramos <cmperdomo@unicauca.edu.co>
*/

#ifndef LAGRANGE_H
#define LAGRANGE_H

#include <vector>
#include <cmath>
#include <sstream>
#include <string>

using std::vector;
using std::string;
using std::ostringstream;

namespace interpolacion {

    class lagrange {
        /**
         * @brief Interpolacion mediante el metodo de Lagrange
        */
        public:
            /**
             * @brief Cronstuye una instancia del metodo de Lagrange
             * @param p_x Variable independiente, valores de x
             * @param p_y Variable dependiente, valores de y
            */
            lagrange( vector <double> p_x, vector <double> p_y): x(p_x), y(p_y){
            }   

            /**
             * @brief Interpola el valor de x_int utilizando todos los datos
             * @param x_int Valor de x a interpolar
             * @return Valor interpolado
            */
            double interpolar(double x_int){
                return interpolar(x_int, 0, x.size());
            }

            /**
             * @brief Interpola el valor de x_int utilizando un polinomio del grado especifico
             * @param x_int Valor de x a interpolar sobre el cual se calcula el polinomio p(x)
             * @param grado Grado del polinomio p(x)
             * @return Valor interpolado
            */
            double interpolar(double x_int, int grado){ 

                // TODO: Implementar la interpolacion con un grado menor que n
                // ? 0. Encontrar las posiciones de x_int dentro de los datos

                // ? 1. Si n_puntos es par (tomar un solo intervalo) 
                // ?    1.1. posInicial = ?? ?? ant ??? n_puntos / 2
                // ?    1.2. posFinal = ?? sig ?? n_puntos / 2
                // ? return interpolar(x_int, posInicial, posFinal)

                // ? 2. Si n_puntos es impar (tomar dos intervalos)
                // ?    2.1. yInt_1 = interpolar(x_int, posInicial, posFinal)
                // ?    2.2. error_int_1 = calcular_error_interpolacion(x_int, posInicial, posFinal)
                // ?    2.3. yInt_2 = interpolar(x_int, posInicial + 1, posFinal + 1)
                // ?    2.4. error_int_2 = calcular_error_interpolacion(x_int, posInicial + 1, posFinal + 1)
                // ?    2.5. Si abs(error_int_1) < abs(error_int_2) return yInt_1
                // ?    2.6. Si no return yInt_2

                int n_puntos = grado + 1;
                int pos_inicial = 0;
                int pos_final = 0;
                int i;

                for (i = 0; i < x.size(); i++) {
                    if (x[i] <= x_int) {
                        pos_inicial = i;
                    }
                    if (x[i] >= x_int) {
                        pos_final = i;
                        break;
                    }
                }

                return NAN;
            }

            /**
             * @brief Construye una nueva instancia del metodo de Lagrange
             * @param x_int Valor de x a interpolar
             * @return Valor interpolado
            */
            double interpolar(double x_int, int pos_inicial, int pos_final){
                double resultado = 0.0f;
                int j, k, n;
                n = x.size();

                if (pos_inicial < 0 || pos_final >= n) {return NAN;}

                for(j = pos_inicial; j < pos_final; j++){
                    double lj = 1.0f;
                    for(k = pos_inicial; k < pos_final; k++){
                        if(k != j){
                            lj *= (x_int - x[k]) / (x[j] - x[k]);
                        }
                    }
                    resultado += y[j] * lj;
                }
                return resultado;
            }
        private:
            vector <double> x; /*!< Variable independiente */
            vector <double> y; /*!< Variable dependiente */
    };
}

#endif