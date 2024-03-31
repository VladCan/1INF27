#include "funciones.hpp"

using namespace std;


void mejorSolucion(int camiones[M],int paquetes[N]){
    int menoriferencia=1000,diferencia;
    int mayorCarga=0;
    int opciones=pow(N,N)-1;
    int solucion[N]={};
    int optimos[opciones][2]={};
    for(int i=0;i<opciones;i++){
        cargaBase(solucion,i,M+1);
        diferencia = calcularDiferencia(solucion,camiones,paquetes,optimos[i]);
        if(optimos[i][1]!=0){
               if(diferencia<menoriferencia) 
                   menoriferencia=diferencia;
               if(optimos[i][1]>mayorCarga)
                   mayorCarga=optimos[i][1];
        }
        
    }
    for(int i=0;i<opciones;i++){
        if(optimos[i][0]==menoriferencia and optimos[i][1]==mayorCarga){
            cargaBase(solucion,i,M+1);
            escribirSolucion(solucion);
        }
    
    }
    

}

void cargaBase(int *arr,int num,int base){
    int digito;
    int i=0;
    while(num>0){
        digito=num%base;
        arr[i]=digito;
        num/=base;
        i++;      
    }

}

int calcularDiferencia(int *arr,int camiones[M],int paquetes[N],int *optimo){
    //i numero del paquete
    //arr[i]-1 numero del camion
    int camionAux[M];
    for(int i=0;i<M;i++)
        camionAux[i]=camiones[i];
    int carga=0;
    int mayor=0;
    int menor=100000;
    for(int i=0;i<N;i++){
        if(arr[i]>0){
            camionAux[arr[i]-1]-=paquetes[i];
//            if(camionAux[arr[i]-1]-paquetes[i]<-1){
//                return 10000;
//            }
            carga+=paquetes[i];
        }
        
         
        
    }
   
    for(int i=0;i<M;i++){
        if(camionAux[i]>mayor)
            mayor=camionAux[i];
        if(camionAux[i]<menor)
            menor=camionAux[i];
    }
    optimo[0]=mayor-menor;
    optimo[1]=carga;
    return mayor-menor;
}

void escribirSolucion(int *arr){
    for(int i=0;i<N;i++){
            cout<<"Paquete "<<i+1<<" en el camion "<<arr[i]<<endl;
            }
    cout<<endl;
    
}

