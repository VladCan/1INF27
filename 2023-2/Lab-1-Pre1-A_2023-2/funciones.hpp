/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.hpp
 * Author: VLADYMIR
 *
 * Created on 30 de marzo de 2024, 23:53
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <iostream>
#include <iomanip>
#include <cmath>
#define P 100
#define N 4

void solucionOptima(int pesos[N][N],int valores[N][N]);
void cargaBase(int *arr,int num,int base);
int validarSolucion(int *solucion, int pesos[N][N], int valores[N][N]); 
void mostrarSolucion(int pesosResul[N][N]);
#endif /* FUNCIONES_HPP */

