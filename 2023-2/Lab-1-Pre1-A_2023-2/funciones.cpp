#include "funciones.hpp"

using namespace std;

void solucionOptima(int pesos[N][N], int valores[N][N]) {
    int pesosResul[N][N] = {}, valoresResul[N][N] = {};
    int valorMax = 0, valor;
    int posibilidades = pow(2, N * N) - 1;
    int solucion[N * N] = {};
    int mejorSolucion;
    for (int i = 0; i < posibilidades; i++) {
        cargaBase(solucion, i, 2);
        valor = validarSolucion(solucion, pesos, valores);
        if (valor > valorMax) {
            valorMax=valor;
            mejorSolucion = i;
        }

    }
    cargaBase(solucion,mejorSolucion,2);    
     int x, y;
            for (int i = 0; i < N * N; i++) {
                if(solucion[i]==1){
                x = i / N;
                y = i % N;
                pesosResul[x][y] = pesos[x][y];
                valoresResul[x][y] = valores[x][y];
                }
            }
     cout<<"Pesos"<<endl;
     mostrarSolucion(pesosResul);
     cout<<"Valores"<<endl;
     mostrarSolucion(valoresResul);
}

void cargaBase(int *arr, int num, int base) {
    int i = 0;
    int digito;
    while (num > 0) {
        digito = num % base;
        arr[i] = digito;
        num /= base;
        i++;
    }

}

int validarSolucion(int *solucion, int pesos[N][N], int valores[N][N]) {
    int x, y;

    int peso = 0, valor = 0;
    for (int i = 0; i < N * N; i++) {
        if (solucion[i] == 1) {
            x = i / N;
            y = i % N;
            peso += pesos[x][y];
            valor += valores[x][y];
            if (peso > P) {
                return 0;
            }

        }

    }

    return valor;
}
void mostrarSolucion(int pesosResul[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<setw(5)<<pesosResul[i][j]<<" ";
        }
        cout<<endl;
    }


}