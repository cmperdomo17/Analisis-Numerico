#ifndef DERIVACION_H
#define DERIVACION_H

#include <iostream>
#include <string>

#include "expression.h"

using std::string;

namespace derivacion {
    class derivada {
        public:
            derivada(string p_str_fn) : f(p_str_fn) {}
            
            double primera(double xi, double paso, int diferencias, int direccion){
                // Primera diferencia hacia adelante
                if (diferencias == 1 && direccion == 0) {
                    double yi = f(xi);
                    double yip1 = f(xi + paso);
                    return (yip1 - yi) / paso;
                }
                // Segunda diferencia hacia adelante
                else if (diferencias == 2 && direccion == 0) {
                    double yi = f(xi);
                    double yip1 = f(xi + paso);
                    double yip2 = f(xi + 2.0f * paso);
                    return (-3.0f * yi + 4.0f * yip1 - yip2) / (2.0f * paso);
                }
                // Primera diferencia hacia atras
                else if (diferencias == 1 && direccion == 1) {
                    double yi = f(xi);
                    double yim1 = f(xi - paso);
                    return (yi - yim1) / paso;
                }
                // Segunda diferencia hacia atras
                else if (diferencias == 2 && direccion == 1) {
                    double yi = f(xi);
                    double yim1 = f(xi - paso);
                    double yim2 = f(xi - 2.0f * paso);
                    return (3.0f * yi - 4.0f * yim1 + yim2) / (2.0f * paso);
                }
                // Primera diferencia centrada
                else if (diferencias == 1 && direccion == 2) {
                    double yip1 = f(xi + paso);
                    double yim1 = f(xi - paso);
                    return (yip1 - yim1) / (2.0f * paso);
                }
            }

            double segunda(double xi, double paso, int diferencias, int direccion){
                // Primera diferencia hacia adelante
                if (diferencias == 1 && direccion == 0) {
                    double yi = f(xi);
                    double yip1 = f(xi + paso);
                    return (yip1 - yi) / paso;
                }
                // Segunda diferencia hacia adelante
                else if (diferencias == 2 && direccion == 0) {
                    double yi = f(xi);
                    double yip1 = f(xi + paso);
                    double yip2 = f(xi + 2.0f * paso);
                    return (-3.0f * yi + 4.0f * yip1 - yip2) / (2.0f * paso);
                }
                // Primera diferencia hacia atras
                else if (diferencias == 1 && direccion == 1) {
                    double yi = f(xi);
                    double yim1 = f(xi - paso);
                    return (yi - yim1) / paso;
                }
                // Segunda diferencia hacia atras
                else if (diferencias == 2 && direccion == 1) {
                    double yi = f(xi);
                    double yim1 = f(xi - paso);
                    double yim2 = f(xi - 2.0f * paso);
                    return (3.0f * yi - 4.0f * yim1 + yim2) / (2.0f * paso);
                }
                // Primera diferencia centrada
                else if (diferencias == 1 && direccion == 2) {
                    double yip1 = f(xi + paso);
                    double yim1 = f(xi - paso);
                    return (yip1 - yim1) / (2.0f * paso);
                }
            }

        private:
            Expression f;
    };
}


#endif