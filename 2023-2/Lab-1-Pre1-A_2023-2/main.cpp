/* 
 * File:   main.cpp
 * Author: VLADYMIR
 *
 * Created on 30 de marzo de 2024, 23:52
 */
#include "funciones.hpp"

using namespace std;

int main(int argc, char** argv) {

    int pesos[N][N] = {
        {20, 20, 20, 20},
        {10, 30, 10, 30},
        {10, 10, 10, 10},
        {15, 15, 15, 15}
    };
    int valores[N][N] = {
        {10, 10, 10, 50},
        {80, 10, 10, 20},
        {20, 20, 20, 20},
        {50, 50, 50, 50}
    };

    solucionOptima(pesos,valores);

    return 0;
}

