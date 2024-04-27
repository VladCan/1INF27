/* 
 * File:   main.cpp
 * Author: VLADYMIR
 *
 * Created on 25 de abril de 2024, 15:19
 */

#include "funciones.hpp"

using namespace std;
void encolarPrioridad(Cola &cola,Cliente cliente){
    struct Nodo *nuevoNodo = crearNodo(cliente,nullptr);
    if(esColaVacia(cola)){
            cola.lista.cabeza=nuevoNodo;
            cola.lista.cola=nuevoNodo;
            if(cliente.prioridad==1)
                cola.lista.colaVip=nuevoNodo;  
    }else{
        if(cliente.prioridad==1){
            
            if(cola.lista.colaVip!=nullptr){
            if(cola.lista.colaVip->siguiente==nullptr)
                cola.lista.cola=nuevoNodo;
            nuevoNodo->siguiente=cola.lista.colaVip->siguiente;
            cola.lista.colaVip->siguiente=nuevoNodo;
            cola.lista.colaVip=nuevoNodo;      
        }else{
            cola.lista.colaVip=nuevoNodo;
            nuevoNodo->siguiente=cola.lista.cabeza;
            cola.lista.cabeza=nuevoNodo;
        }
    }
    else{
        cola.lista.cola->siguiente=nuevoNodo;
        cola.lista.cola=nuevoNodo;
    }
    
}
    cola.lista.longitud++;
}

int main(int argc, char** argv) {
    
    Cola cola;
    construir(cola);
    Cliente clientes[10];
    strcpy(clientes[0].dni,"15267805");
    clientes[0].prioridad=1;
    strcpy(clientes[1].dni,"841515");
    clientes[1].prioridad=2;
    strcpy(clientes[2].dni,"185155");
    clientes[2].prioridad=1;
    strcpy(clientes[3].dni,"29161561");
    clientes[3].prioridad=2;
    strcpy(clientes[4].dni,"16161");
    clientes[4].prioridad=1;
    for(int i=0;i<5;i++){
    encolarPrioridad(cola,clientes[i]);
    }
    
    imprime(cola);
    return 0;
}

