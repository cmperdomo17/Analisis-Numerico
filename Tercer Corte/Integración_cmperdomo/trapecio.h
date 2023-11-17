#ifndef TRAPECIO_H
#define TRAPECIO_H

#include <string>
#include <vector>

#include "expression.h" 
#include "util.h"

using std::string;
using std::vector;
using util::crear_tabla;

namespace integracion {
	/**
	* @brief Integracion mediante el Metodo del Trapecio.
	*/
	class trapecio {
	public:
		/**
		* @brief Crea una nueva instancia de Trapecio.
		* @param p_str_fn Texto de la funci�n.
		*/
		trapecio(string p_str_fn): str_fn(p_str_fn) {
		}
			
		/**
		* @brief Calcula el valor de la integral en el intervalo.
		* @param a Limite inferior del intervalo.
		* @param b Limite superior del intervalo.
		* @param n Cantidad de segmentos.
		* @return Valor aproximado de la integral.
		*/
		double calcular(double a, double b, int n) {
			if(n == 0) {
				return NAN;
			}
			
			//Intercambiar los limites si el limite inferior es mayor que el superior
			if(a > b) {
				std::swap(a, b);
			}
			
			vector<double> x;
			vector<double> y;
			
			//Crear la tabla de datos
			crear_tabla(x, y, a, b, n, str_fn);
			
			return calcular(x, y);
		}
		
		/**
		* @brief Calcula la integral de una tabla de datos.
		* @param x Valores de la variable independiente.
		* @param y Valores de la variables dependiente.
		* @return Valor aproximado de la integral.
		*/
		double calcular(vector<double> &x, vector<double> &y) {
			size_t n = x.size() - 1;
			if(n<=0) {
				return NAN;
			}
			
			double sum = 0.0f;
			
			for(size_t i=1; i<n; i++) {
				sum+=y[i];
			}
			
			double coef = y[0] + (2.0f*sum) +y[n];
			
			double a = x[0];
			double b = x[n];
			
			return (b-a)*(coef/(2.0f*n));
		}
		
	private:
		string str_fn;  /*!< Cadena de la funcion */
	};
};

#endif
