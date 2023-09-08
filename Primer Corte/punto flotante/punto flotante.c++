#include <bitset>
#include <cmath>
#include <iostream>
#include <string>

using std::bitset;
using std::string;
using std::cin;
using std::cout;
using std::endl;

/**
* @brief Retorna la representación en binario de un numero real de 32 bits
* @param val Valor real de 32 bits
* @return Cadena de caracteres con la representación en binario
*/
string binary_string32(float val);

int main(int argc, char *argv[]){
    float x;
    cout <<"Representacion de numeros de punto flotante"<<endl;
    cout <<"Ingrese un numero real: ";
    cin>>x;
    cout<<"La representación de " <<x
        << " en punto flotante es " << binary_string32(x)
        <<endl;
    return 0;
}

string binary_string32(float val){
    //Entero de 32 bits
    unsigned int x;

    //Obtener los 32 bits de 
    //la representacion del valor en punto flotante
    x = *(unsigned int*)&val;
    //Convertir a string
    return bitset<32>(x).to_string();
}


