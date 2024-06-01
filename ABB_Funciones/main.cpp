/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: VLADYMIR
 * 
 * Created on 31 de mayo de 2024, 18:44
 */

#include "ArbolBinario.h"
#include "ArbolBinarioBusqueda.h"
#include "funcionesArbolesBinarios.h"
#include "funcionesABB.h"
#include "funciones.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ArbolBinarioBusqueda ABB;
    construir(ABB);
    int arr[25]={3, 1, 5, 2, 4, 8, 13, 18, 0};
    for(int i=0;arr[i]!=0;i++)
        insertar(ABB,arr[i]);
    
    dibujar(obtenerRaiz(ABB),0);
    cout<<endl;
    cout<<alturaRecursivo(obtenerRaiz(ABB))<<endl;
    balanceo(ABB);
    dibujar(obtenerRaiz(ABB),0);
    cout<<endl;
    cout<<alturaRecursivo(obtenerRaiz(ABB))<<endl;
    balanceoArreglo(ABB);
    dibujar(obtenerRaiz(ABB),0);
    cout<<endl;
    recorrerPostOrden(ABB.arbolBinario);
    cout<<endl;
    postOrdenR(ABB);
    cout<<endl;
    recorrerEnOrden(ABB.arbolBinario);
    cout<<endl;
    enOrdenR(ABB);
    cout<<endl;
    recorrerPreOrden(ABB.arbolBinario);
    cout<<endl;
    enPreOrden(obtenerRaiz(ABB));        
    cout<<endl;
    return 0;
}

