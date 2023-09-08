#ifndef NEWTON_RAPHSON_H
#define NEWTON_RAPHSON_H
# include <string>


#include "Expression.h"
#include "solucion.h"

namespace raices {
    /**
     * @brief Implementación del método de Newton - Raphson
    */
    class newton_raphson {
    public: 
        /**
         * @brief Construye una nueva instancia de newton_raphson
         * @param strFunc Texto de la función a evaluar
         * @param strdFunc Texto de la derivada de la función a evaluar
        */
        newton_raphson(string strFunc, string strdFunc): f(strFunc), df(strdFunc) {
        }

        /**
         * @brief Calcula la raiz de la función a partir de p0
         * @param p0 Aproximación inicial
         * @param tol Tolerancia (error relativo porcentual)
         * @param n Número máximo de iteraciones
         * @return Solución encontrada. La raiz es NAN si no se encuentra
        */
        solucion calcular(double p0, double tol, int n){
            solucion sol;

            // Paso 1

            int i = 1;
            // Validar si el usuario especificó una raiz
            if (fabs(f(p0)) <= DBL_EPSILON) {
                sol.raiz = p0;
                // TO DO sol.iteraciones = i;
                return sol;
            };

            // Paso 2
            while (i <= n) {
                // Paso 3
                double p = p0 - (f(p0)/df(p0));
                // Paso 4
                double erp = calcular_erp(p, p0);
                // Adicionar la aproximación
                sol.adicionar({p0, p, erp});
                if ( erp < tol ){
                    sol.raiz = p;
                    // TO DO sol.iteraciones = i;
                    return sol;
                }            
                // Paso 5
                i++;
                // Paso 6
                p0 = p;
            }
            return sol;
        }
    private:
        Expression f; /*!< Evaluador de la funcion */
        Expression df; /*!< Evaluador de la derivada de la funcion */
    };
};
#endif