#ifndef SOLUCION_H
#define SOLUCION_H
#include <cfloat>
#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>

using std::vector;
using std::setw;
using std::setprecision;
using std::endl;
using std::cout;

namespace raices { // Agrupa diferentes definiciones de clases, funciones y variables
	
	/**
	 * @brief Calcula el error relativo porcentual entre dos aproximaciones
	 * @param nueva Nueva aproximacion
	 * @param anterior Aproximacion anterior
	 * @return Error relativo porcentual
	*/
	double calcular_erp(double nueva, double anterior){ 
		return fabs((nueva - anterior) / nueva) * 100.0f;
	};
	
	/**
	* @brief Aproximacion de una solucion
	*/
	struct aproximacion { // Clase donde sus atributos son publicos por defecto
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
		
		/**
		* @brief Adiciona una nueva aproximacion
		* @param a Aproximacion
		*/
		void adicionar(aproximacion a) {
			aproximaciones.push_back(a); // Adiciona una nueva a
		}

        void imprimir(){
            if (std::isnan(raiz)) {
                cout << "No se pudo obtener la raiz con los datos dados"<<endl;
            }else {
                cout << "La raiz es: " << raiz <<endl;
                cout << "Aproximaciones: "<< endl;
                for (unsigned int i = 0; i< aproximaciones.size(); i++) {
                    cout << setw(15)
                        << setprecision(10)
                        << aproximaciones[i].xAnt
                        << setw(15)
                        << setprecision(10)
                        << aproximaciones[i].xNueva
                        << setw(15)
                        <<setprecision(10)
                        << aproximaciones[i].erp
                        <<endl;
                }
            }
        }
	};
};



#endif
