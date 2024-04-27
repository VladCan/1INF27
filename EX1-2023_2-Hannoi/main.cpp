
/* 
 * File:   main.cpp
 * Author: VLADYMIR
 *
 * Created on 25 de abril de 2024, 11:09
 */


#include "funciones.hpp"

using namespace std;

void hanoi(int n, Pila &desde, Pila &auxiliar, Pila &hacia) {
    int elem;
    if (n == 1) {
        elem = desapilar(desde);
        apilar(hacia, elem);
        return;
    }
    hanoi(n - 1, desde, hacia, auxiliar);
    elem = desapilar(desde);
    apilar(hacia, elem);
    hanoi(n - 1, auxiliar, desde, hacia);

}

void robotApilador(Pila &principal, Cola &cola) {
    Pila A, B;
    int elem = 0, l;
    bool valida = true;
    l = longitud(cola);
    construir(A);
    construir(B);
    int m = longitud(principal);
    for (int i = 0; i < l; i++) {
        elem = desencolar(cola);
        if (esPilaVacia(principal)) {
            apilar(principal, elem);
        } else {
            for (int k = 0; k <= m; k++) {
                if (elem > cima(principal)) {
                    hanoi(k + 1, principal, A, B);
                } else if (elem <= cima(principal)) {
                    valida = false;
                    break;
                }
                valida = true;
                int p=1;
                while (true) {
                    if (cima(principal) != -1) {
                        if (elem > cima(principal)) {
                            hanoi(p, B, A, principal);
                            hanoi(p+1, principal, A, B);
                            p++;
                        } else break;
                    } else break;           
                }
                break;
            }
            apilar(principal, elem);
            if (valida) {
                hanoi(longitud(B), B, A, principal);
                valida = true;
            }
        }
    }
}

void robotApiladorMejorado(struct Pila &principal, Cola &cola) {
    Pila A, B;
    int elem = 0, l= longitud(cola);
    construir(A);
    construir(B);
    int cont=0;
    for (int i = 0; i < l; i++) {
        int m=longitud(principal);
        cont=0;
        elem = desencolar(cola);
        if (esPilaVacia(principal)) {
            apilar(principal, elem);
        } else {
            for(int k=0; k<m+1; k++){
                if(elem>cima(principal) and cima(principal)!=-1){
                    if(cont>0){
                        hanoi(cont, B, A, principal);
                    }
                    hanoi(cont+1, principal, A, B);
                    cont++;
                }
                else{
                    apilar(principal, elem);
                    break;
                }
            }
            if(cont!=0){
                hanoi(cont, B, A, principal);
            }
        }
    }
}

int main(int argc, char** argv) {
    Cola cola;
    Pila principal;
    construir(cola);
    construir(principal);
    encolar(cola, 2);
    encolar(cola, 7);
    encolar(cola, 8);
    encolar(cola, 3);
    encolar(cola, 1);
    encolar(cola, 10);
    encolar(cola, 8);
    encolar(cola, 5);
    encolar(cola, 11);
    encolar(cola, -48181881);
    encolar(cola,1234567890);
    encolar(cola, 2);
    encolar(cola, 119);
    encolar(cola, 7022);
    encolar(cola, 9);
    encolar(cola, 0);
    imprime(cola);
    robotApiladorMejorado(principal, cola);
    imprimir(principal);
    return 0;
}

