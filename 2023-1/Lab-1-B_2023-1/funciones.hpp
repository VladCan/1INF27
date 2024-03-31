/* 
 * File:   funciones.hpp
 * Author: VLADYMIR
 *
 * Created on 30 de marzo de 2024, 21:43
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <iostream>
#include <cmath>
#define Niveles 5
#define cantRoborts 6

int  solucion(int piso[2][Niveles],int robots[cantRoborts],int &catSoluciones);
void cargaBase(int *arr,int num,int base);
bool validarSolucion(int *arr,int piso[2][Niveles],int robots[cantRoborts]);
void escribirSolucion(int *solucion);
bool noConciderar(int piso[2][Niveles],int robots[cantRoborts],int noConciderados[cantRoborts],int &cantNoC);
#endif /* FUNCIONES_HPP */

