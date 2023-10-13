/**
 * @file
 * @brief Interpolacion
 */
#ifndef NEWTON_H
#define NEWTON_H

#include <vector>
#include <cmath>
using std::vector;

namespace interpolacion
{
	/**
	 * @brief interpolacion de newton
	 */
	class newton
	{
	public:
		/**
		 * @brief Calcula los coeficientes del polinomio interpolante
		 * @param p_x variable independiente (X)
		 * @param p_y variable dependiente (Y)
		 */
		newton(vector<double> p_x, vector<double> p_y) : x(p_x), y(p_y)
		{
			calcular_coeficientes(x, y);
		}
		/**
		 * @brief interpola el valor de p(xInt)
		 * @param xInt  valor a interpolar
		 * @return Valor de p(xInt)
		 * @note El valor de xint debe estar dentro del intervalo de los valores de x.
		 */
		double interpolar(double xInt)
		{
			double resultado = NAN;

			if (!b.size())
			{
				return resultado;
			}

			double p = 0;
			size_t n = x.size();
			for (size_t i = 0; i < n; i++)
			{
				double prod = 1.0f;
				// Calcular la productoria 1, (x-x0),(x-x1)(x-x0)...
				for (size_t j = 0; j < i; j++)
				{
					prod *= (xInt - x[j]);
				}
				p += b[i] * prod;
			}

			return p;
		}
		vector<double> coeficientes(){
			return b;
		}
	private:
		vector<double> b;
		vector<double> x;
		vector<double> y;

		void calcular_coeficientes(vector<double> x, vector<double> y)
		{
			if (x.size() != y.size())
			{
				return;
			}

			if (!x.size())
			{
				return;
			}

			size_t n = x.size();
			vector<vector<double>> F(n);
			// La fila 0 tiene n elementos, lafila 1 tiene n-1, ...
			// la ultima fila tiene un elemento
			for (size_t i = 0; i < n; i++)
			{
				F[i].resize(n - i);
			}

			// Llenar la primera columna
			for (size_t i = 0; i < n; i++)
			{
				F[i][0] = y[i];
			}
			// Calcular las diferencias divididas para f[x1,x0]....f[Xn....x0]
			for (size_t j = 1; j < n; j++)
			{
				for (size_t i = 0; i < n - j; i++)
				{
					F[i][j] = (F[i + 1][j - 1] - F[i][j - 1]) / (x[i + j] - x[i]);
				}
			}

			// Tomar los coeficientes de la primera fila de la matriz
			b = F[0];
		}
	};
};
#endif
