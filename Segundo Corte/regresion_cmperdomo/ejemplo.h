#ifndef REGRESION_H
#define REGRESION_H
#include <vector>
#include <cmath>
#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

namespace regresion
{

    /**
     * @brief Solucion de una regresion lineal
     */
    struct solucion_lineal
    {
        double b0 = 0.0f;  /*!<Termino constante de la recta de regresion*/
        double b1 = 0.0f;  /*!<Coeficiente de la recta de regresion*/
        double st = 0.0f;  /*!<Sumatoria de la diferencia cuadratica de yi y el promedio*/
        double sr = 0.0f;  /*!<Sumatoria de la diferencia cuadratica de yi y la estimacion*/
        double sy = 0.0f;  /*!<Desviacion estandar*/
        double syx = 0.0f; /*!<Error estandar de aproximacion*/
        double r2 = 0.0f;  /*!<Coeficiente de determinacion*/

        /**
         * @brief Impresion de la regresion lineal
         *
         */
        void imprimir()
        {
            cout << "Recta de regresion" << endl
                 << "y= " << b1 << " *x"
                 << ((b0 > 0) ? " + " : " - ")
                 << fabs(b0)
                 << endl;
            cout << "Desv. estandar: " << sy << endl;
            cout << "Desv. estandar de aprox: " << syx << endl;
            cout << "Coeficiente de determinacion: " << r2 << endl;
        }
    };

    /**
     * @brief Solucion potencia
     *
     */
    struct solucion_lineal_potencia
    {
        double c = 0.0f;        /*!<Coeficiente de la potencia*/
        double a = 0.0f;        /*!<Exponente de la potencia*/
        solucion_lineal lineal; /*!<Regresion lineal de los datos transformados*/
        double r2 = 0.0f;       /*!<Coeficiente de determinacion*/
        /**
         * @brief Impresion de la regresion de potencia
         *
         */
        void imprimir()
        {
            cout << "Recta de regresion" << endl
                 << "y= " << c << " *x^"
                 << a
                 << endl;
            cout << "Coeficiente de determinacion: " << r2 << endl;
        }
    };
    /**
     * @brief Solucion exponencial
     *
     */
    struct solucion_lineal_exponencial
    {
        double c = 0.0f;        /*!<Coeficiente de la potencia*/
        double a = 0.0f;        /*!<Exponente de la potencia*/
        solucion_lineal lineal; /*!<Regresion lineal de los datos transformados*/
        double r2 = 0.0f;       /*!<Coeficiente de determinacion*/
		vector<double> Y;		/*!<Retorno Del Ln(Y) Transformado*/
        /**
         * @brief Impresion de la regresion exponencial
         *
         */
        void imprimir()
        {
            cout << "Recta de regresion" << endl
                 << "y= " << c << " *e^"
                 << a << "*x"
                 << endl;
            cout << "Coeficiente de determinacion: " << r2 << endl;
        }
    };

    /**
     * @brief Solucion cuadratica
     *
     */
    struct solucion_cuadratica
    {
        double a0;         /*!<Coeficiente independiente del polinomio*/
        double a1;         /*!<Coeficiente de x del polinomio*/
        double a2;         /*!<Coeficiente de x^2 del polinomio*/
        double st = 0.0f;  /*!<Sumatoria de la diferencia cuadratica de yi y el promedio*/
        double sr = 0.0f;  /*!<Sumatoria de la diferencia cuadratica de yi y la estimacion*/
        double sy = 0.0f;  /*!<Desviacion estandar*/
        double syx = 0.0f; /*!<Error estandar de aproximacion*/
        double r2 = 0.0f;  /*!<Coeficiente de determinacion*/

        /**
         * @brief Impresion de la regresion cuadratica
         *
         */
        void imprimir()
        {
            cout << "Regresion cuadratica" << endl;
            cout << "Ecuacion: "
                 << "y ="
                 << a0
                 << ((a1 > 0) ? " + " : " - ") << fabs(a1) << "*x"
                 << ((a2 > 0) ? " + " : " - ") << fabs(a2) << "*x^2"<<endl;
            cout << "Desv. estandar: " << sy << endl;
            cout << "Desv. estandar de aprox: " << syx << endl;
            cout << "Coeficiente de determinacion: " << r2 << endl;
        }
    };

    /**
     * @brief Regresion lineal
     *
     */

    class regresion_lineal
    {
    public:
        /**
         * @brief Halla la recta de regresion lineal para los datos dados
         *
         * @param x Valores de la variable independiente (x)
         * @param y Valores d ela variable dependiente y
         * @return solucion_lineal recta solucion de regresion lineal
         */
        solucion_lineal calcular(vector<double> x, vector<double> y)
        {
            solucion_lineal s;

            double n = x.size();
            // Validar que los dos vectores tengan el mismo tamaÃƒÂ±o
            if (x.size() != y.size())
            {
                return s;
            }
            if (n == 0)
            {
                return s;
            }

            double sum_x, sum_y, sum_x2, sum_xy;
            sum_x = sum_y = sum_x2 = sum_xy = 0.0f;
            for (size_t i = 0; i < n; i++)
            {
                sum_x += x[i];
                sum_y += y[i];
                sum_x2 += pow(x[i], 2.0f);
                sum_xy += x[i] * y[i];
            }

            double x_prom = sum_x / n;
            double y_prom = sum_y / n;

            s.b1 = (sum_xy - (y_prom * sum_x)) / (sum_x2 - (x_prom * sum_x));
            s.b0 = y_prom - s.b1 * x_prom;

            s.st = 0.0f;

            for (size_t i = 0; i < n; i++)
            {
                s.st += pow(y[i] - y_prom, 2.0f);
            }
            s.sy = sqrt(s.st / (double)(n - 1));
            s.sr = 0.0f;
            for (size_t i = 0; i < n; i++)
            {
                s.sr += pow(y[i] - (s.b1 * x[i] + s.b0), 2.0f);
            }
            s.syx = sqrt(s.sr / (double)(n - 2));
            s.r2 = (s.st - s.sr) / s.st;
            return s;
        }
    };

    class regresion_lineal_potencia
    {
    public:
        /**
         * @brief Halla la recta de regresion lineal potencial para los datos dados
         *
         * @param x Valores de la variable independiente (x)
         * @param y Valores d ela variable dependiente (y)
         * @return solucion_lineal_potencia recta solucion de regresion lineal potencia
         */
        solucion_lineal_potencia calcular(vector<double> x, vector<double> y)
        {
            solucion_lineal_potencia solucion;
            // Asignar los datos originales (Sin transformar)
            vector<double> X = x;
            vector<double> Y = y;
            regresion_lineal rl;
            double n = x.size();
            // Validar que los dos vectores tengan el mismo tamaÃƒÂ±o
            if (x.size() != y.size())
            {
                return solucion;
            }
            if (n == 0)
            {
                return solucion;
            }

            // POST: Los arreglos tienen el mismo tamaÃƒÂ±o
            //  Transformar datos originales
            for (size_t i = 0; i < x.size(); i++)
            {
                X[i] = log10(x[i]);
                Y[i] = log10(y[i]);
            }
            // Calcular la regresion lineal sobre los datos transformados
            solucion.lineal = rl.calcular(X, Y);
            // Obtener r2 de la regresion con los datos transformados ( De los datos transformados, para comparar sacar de los datos no transformados)
            solucion.r2 = solucion.lineal.r2;
            // Calcular c
            solucion.c = pow(10.0f, solucion.lineal.b0);
            // Calcular a
            solucion.a = solucion.lineal.b1;
			
            return solucion;
        }
    };
    class regresion_lineal_exponencial
    {
    public:
        /**
         * @brief Halla la recta de regresion lineal potencial para los datos dados
         *
         * @param x Valores de la variable independiente (x)
         * @param y Valores d ela variable dependiente (y)
         * @return solucion_lineal_potencia recta solucion de regresion lineal potencia
         */
        solucion_lineal_exponencial calcular(vector<double> x, vector<double> y)
        {
            solucion_lineal_exponencial solucion;
            // Asignar los datos originales (Sin transformar)
            vector<double> Y = y;
            regresion_lineal rl;
            double n = x.size();
            // Validar que los dos vectores tengan el mismo tamaÃƒÂ±o
            if (x.size() != y.size())
            {
                return solucion;
            }
            if (n == 0)
            {
                return solucion;
            }

            // POST: Los arreglos tienen el mismo tamaÃƒÂ±o
            //  Transformar datos originales
            for (size_t i = 0; i < x.size(); i++)
            {
                Y[i] = log(y[i]);
            }
            // Calcular la regresion lineal sobre los datos transformados
            solucion.lineal = rl.calcular(x, Y);
            // Obtener r2 de la regresion con los datos transformados ( De los datos transformados, para comparar sacar de los datos no transformados)
            solucion.r2 = solucion.lineal.r2;
            // Calcular c
            solucion.c = exp(solucion.lineal.b0);
            // Calcular a
            solucion.a = solucion.lineal.b1;
			solucion.Y = Y;
            return solucion;
        }
    };
    /**
     * @brief Regresion cuadratica
     *
     */
}
#endif
