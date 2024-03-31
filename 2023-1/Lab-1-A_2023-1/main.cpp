/* 
 * File:   main.cpp
 * Author: VLADYMIR
 *
 * Created on 30 de marzo de 2024, 19:41
 */

#include "funciones.hpp"
#define M 4
#define N 5
using namespace std;


int main(int argc, char** argv) {
    
    int camiones[M]={25,50,100,100};
    int paquetes[N]={50,20,30,50,20};
    
    
    mejorSolucion(camiones,paquetes);
    
    
    return 0;
}

