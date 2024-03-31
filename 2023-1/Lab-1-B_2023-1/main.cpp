/* 
 * File:   main.cpp
 * Author: VLADYMIR
 *
 * Created on 30 de marzo de 2024, 21:25
 */


#define Niveles 5
#define cantRoborts 6

#include "funciones.hpp"
using namespace std;

int main(int argc, char** argv) {

    int piso[2][Niveles]={{100,90,95,85,105},{90,98,75,96,93}};
    int robots[cantRoborts]={77, 82, 81, 90, 92, 75};
    int catSoluciones=0;
    int noConciderados[cantRoborts];
    int cantNoC=0;
    solucion(piso,robots,catSoluciones);
    if(catSoluciones==0){
        cout<<"No se encontraron soluciones"<<endl;
        cout<<"===================================="<<endl;
        cout<<"Soluciones sin conciderar algunos robots"<<endl;
        if(noConciderar(piso,robots,noConciderados,cantNoC)){
            cout<<"No se concideraron los robots de peso: "<<endl;
            cout<<"===================================="<<endl;
            for(int i=0;i<cantNoC;i++){
                cout<<noConciderados[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}

