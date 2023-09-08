#ifndef BISECCION_H
#define BISECCION_H
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

// using namespace std; es una mala practica 

#include "Expression.h"
#include "solucion.h"

using std::cout;
using std::string;
using std::endl;
using std::setprecision;
using std::setw;
using raices::solucion;
using raices::calcular_erp;


namespace raices {
	
	/**
	* @brief Metodo de biseccion
	*/
	class biseccion {
	public:
		/**
		* @brief Crea una nueva instancia del metodo de biseccion
		* @param strFunc Texto de la funcion a evaluar
		*/
		biseccion(string strFunc):f(strFunc) {
			
		}
		
		/**
		* @brief Calcula la raiz de la funcion en el intervalo dado
		* @param xa Valor inferior del intervalo
		* @param xb Valor superior del intervalo
		* @param tol Tolerancia (error relativo porcentual)
		* @param n Numero maximo de iteraciones
		* @return Solucion encontrada. La raiz es NAN si no se encuentra la solucion.
		*/
		solucion calcular(
						double xa, 
						double xb, 
						double tol, 
						int n
						) {
			
			solucion sol;
			//Paso 1
			int i = 1;
			//Paso 2
			double xAnt = (xa + xb)/2.0f;
			
			if (f(xa) * f(xAnt) > 0.0f) {
				xa = xAnt;
			}else {
				xb = xAnt;
			}
			//Paso 3
			while (i <= n) {
				//Paso 4
				double xNueva = (xa + xb)/2.0f;
				//Calcular el error relativo porcentual
				double erp = calcular_erp(xNueva, xAnt);
				//Adicionar la aproximacion
				sol.adicionar({xAnt, xNueva, erp});
				//Paso 5
				if ( fabs(f(xNueva)) <= DBL_EPSILON  ||
					erp < tol) {
					//Guardar la raiz
					sol.raiz = xNueva;
					return sol;
				}
				//Paso 6
				i++;
				//Paso 7
				if (f(xa) * f(xNueva) > 0.0f) {
					xa = xNueva;
				}else {
					xb = xNueva;
				}
				xAnt = xNueva;
			}
			
			return sol;
		}
	private:
		Expression f; /*!< Evaluador de la funcion */
	};
};

#endif
