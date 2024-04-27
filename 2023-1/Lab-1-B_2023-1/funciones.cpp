#include "funciones.hpp"

using namespace std;

int solucion(int piso[2][Niveles], int robots[cantRoborts], int &catSoluciones) {
    int posibilidades = pow(2, Niveles);
    int solucion[5] = {};
    for (int i = 0; i < posibilidades; i++) {
        cargaBase(solucion, i, 2);
        if (validarSolucion(solucion, piso, robots)) {
            escribirSolucion(solucion);
            catSoluciones++;
        }
    }


}

void escribirSolucion(int *solucion) {
    for (int i = 0; i < Niveles; i++) {
        if (solucion[i] == 0)
            cout << "Izquierda ";
        if (solucion[i] == 1)
            cout << "Derecha ";
    }
    cout << endl;
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

bool validarSolucion(int *arr, int piso[2][Niveles], int robots[cantRoborts]) {
    int resiste;

    for (int j = 0; j < cantRoborts; j++) {
        for (int k = 0; k < Niveles; k++) {
            resiste = piso[arr[k]][k] - robots[j];
            if (resiste < 0)
                return false;
        }
    }
    return true;
}

bool noConciderar(int piso[2][Niveles], int robots[cantRoborts], int noConciderados[cantRoborts], int &cantNoC) {
    int mayor = 0, posMayor,cantSoluciones;
    if (cantNoC == cantRoborts) {
        return false;
    }
    for (int i = 0; i < cantRoborts; i++) {
        if (robots[i] > mayor) {
            mayor = robots[i];
            posMayor = i;
        }
    }
    noConciderados[cantNoC]=mayor;
    robots[posMayor]=0;
    cantNoC++;
    solucion(piso,robots,cantSoluciones);
    if(cantSoluciones!=0){
        return true;
    }else{
        return noConciderar(piso,robots,noConciderados,cantNoC);
    }
}
