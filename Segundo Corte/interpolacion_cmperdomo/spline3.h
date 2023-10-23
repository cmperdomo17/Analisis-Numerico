#ifndef SPLINE3_H
#define SPLINE3_H

#include "util.h"

#include <cmath>
#include <vector>

using std::vector;
using util::gauss;

namespace interpolacion {
    class spline3 {
        public: 
            spline3(vector <double> p_x,
                    vector <double> p_y): x(p_x), y(p_y){
                // Calcular las segundas derivadas
                f2 = calcular_f2(); 
            }

            double interpolar(double x_int){
                // TODO: Determinar el intervalo i en donde se encuentra x_int
                // TODO 2: Evaluar el polinomio del trazador en x_int (18.36)
                // TODO 3: Retornar el valor interpolado
                return NAN;
            }
        private:
            vector <double> x;
            vector <double> y;
            vector <double> f2;
            vector <double> calcular_f2(){
                vector <double> resultado;

                size_t n = x.size();
                size_t intervalos = n - 1;
                size_t i;

                // TODO 1: Construir la matriz de coeficientes (M)
                // * M es una matriz de banda, en donde:
                // * En los puntos interiores se tienen tres coeficientes
                // * En el primer punto se tienen dos coeficientes
                // * En el ultimo punto se tienen dos coeficientes
                // * m . f2 = c 
                // * donde c = Terminos a la derecha del igual en (18.37)

                vector <vector <double>> m(intervalos - 1);
                for (i = 0; i < intervalos - 1; i++){
                    m[i].resize(n);
                }

                for ( i = 1; i < intervalos; i++ ){

                    size_t fila = i - 1;

                    // * Primer coeficiente
                    if (i > 1) {
                        // Los puntos interiores tienen f''(xi-1)
                        m[fila][i - 1] = (x[i] - x[i - 1]);
                    };
                    
                    // * Segundo coeficiente
                    m[fila][i] = 2.0f * (x[i + 1] - x[i - 1]);

                    // * Tercer coeficiente
                    if (i < intervalos - 2){
                        // Los puntos interiores tienen f''(xi+1)
                        m[fila][i + 1] = (x[i + 1] - x[i]);
                    };
                    
                    double ci_1 = (6/(x[i + 1] - x[i])) * (y[i + 1] - y[i]);
                    double ci_2 = (6/(x[i] - x[i - 1])) * (y[i - 1] - y[i]);
                    double ci = ci_1 + ci_2;
                    m[fila][intervalos] = ci;
                    
                }

                resultado = gauss(m);

                vector <double> c;
     
                // TODO 2: Calcular F2
                // * Calcular F2: F2 = gauss(M)
                // * Insertar 0 al inicioy al final de F2
                // * (f2 en los extremos vale 0)
                return resultado;
            };
    };
}


#endif