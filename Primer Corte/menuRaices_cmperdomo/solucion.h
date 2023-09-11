#ifndef SOLUCION_H
#define SOLUCION_H

#include <cfloat>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>

using std::cout;
using std::endl;
using std::setw;
using std::setprecision;
using std::vector;

namespace raices {
	
	/**
	* @brief Calcula el Error Relativo Porcentual entre dos aproximaciones
	* @param nueva Nueva aproximacion
	* @param anterior Aproximacion anterior
	*/
	double calcular_erp(double nueva, double anterior) {
		return fabs((nueva - anterior)/nueva) * 100.0f;
	}
	
	/**
	* @brief Verifica sie el valor dado puede considerarse cero
	* @param val Valor a verificar
	* @return Verdadero si el valor esta por debajo del limite de underflow
	*/
	bool es_cero(double val) {
		return (fabs(val) <= DBL_EPSILON);		
	}
	
	/**
	* @brief Aproximacion de una solucion
	*/
	struct aproximacion {
		double xAnt;/*!< Valor anterior */
		double xNueva;/*!< Valor anterior */
		double erp;/*!< Error relativo porcentual entre los dos valores */
	};
	
	/**
	* @brief Solucion a un metodo numerico para encontrar una raiz
	*/
	struct solucion {
		double raiz = NAN; /*!< Raiz encontrada, NAN si no se pudo hallar */
		vector<aproximacion> aproximaciones; /*!< Vector de aproximaciones */
		int iteraciones = 0; /*!< Cantidad de iteraciones realizadas */
		
		/**
		* @brief Adiciona una nueva aproximacion
		* @param a Aproximacion
		*/
		void adicionar(aproximacion a) {
			aproximaciones.push_back(a);
		}
		
		void imprimir() {
			if (std::isnan(raiz)) {
				cout << "\nNo se pudo obtener la raiz con los datos dados"<<endl;
			}else {
				cout << "\nLa raiz es: " << raiz <<endl;
				cout << "\nAproximaciones: \n"<< endl;
				cout << setw(20) << "Anterior" << setw(20) << "Nueva" << setw(20) << "Erp" << endl;
				cout << "\n";
				for (unsigned int i = 0; i< aproximaciones.size(); i++) {
					cout << setw(20)
						<< setprecision(10)
						<< aproximaciones[i].xAnt
						<< setw(20)
						<< setprecision(10)
						<< aproximaciones[i].xNueva
						<< setw(20)
						<< setprecision(10)
						<< aproximaciones[i].erp
						<<endl;
				}
				cout << "\nCantidad de iteraciones: " << iteraciones << endl;
			}
		}
	};
};

#endif
