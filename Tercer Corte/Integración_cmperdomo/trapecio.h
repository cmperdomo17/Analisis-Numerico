#ifndef TRAPECIO_H
#define TRAPECIO_H

#include <string>   
#include <vector>

#include "expression.h"

using std::string;
using std::vector;

namespace integracion {
    /**
     * @brief Integracion mediante el método del trapecio
    */
    class trapecio {
        public:
            /**
             * @brief Crea una nueva instancia de la clase trapecio
             * @param str_fn Función a integrar
            */
            trapecio(string str_fn): f(str_fn){
                
            }

            void crear_tabla(vector<double> &x, // Paso de parámetros por referencia
                             vector<double> &y,
                             double a,
                             double b,
                             int n){
                             //Expression f){ // Por si lo necesito en el futuro para llamarlo desde otro lado
                                
                // Reservar espacio para la cantidad requerida de segmentos
                x.resize(n+1);
                y.resize(n+1);

                // Calcular el paso
                double h = (b-a)/(double)n;    
                double xi = a;

                for (int i = 0; i <= n; i++){    
                    x[i] = xi;
                    y[i] = f(xi);
                    xi += h;
                }
            }
            /**
             * @brief Calcula el valor de la integral
             * @param a Límite inferior del intervalo
             * @param b Límite superior del intervalo
             * @param n Número de subintervalos (segmentos)
             * @return Valor aproximado de la integral
            */
            double calcular(double a, double b, int n){
                // Si el numero de segmentos es 0, retornar NaN
                if (n == 0){
                    return NAN;
                }
                // Intercambiar los limites si el limite inferior es mayor que el superior
                if (a > b){
                    std::swap(a,b);
                }
                
                // Crear la tabla de valores
                vector <double> x;
                vector <double> y;

                crear_tabla(x,y,a,b,n);

                return calcular(x,y);
            }
            /**
             * Calcula la integral de una tabla de datos
             * @param x Valores de la variable independiente
             * @param y Valores de la variable dependiente
             * @return Valor aproximado de la integral
            */
            double calcular(vector<double> &x, vector<double> &y){
                size_t n = x.size() - 1;
                if (n <= 0) {return NAN;}
                double sum = 0.0f;
                for (size_t i = 1; i < n; i++){
                    sum += y[i];
                }

                double a = x[0];
                double b = x[n];

                double coef = y[0] + 2.0f*sum + y[n];
                return (b - a) * (coef / (2.0f*n)); 
            }
        private:
            Expression f; /*!< Evaluador de la funcion */
    };
};
#endif