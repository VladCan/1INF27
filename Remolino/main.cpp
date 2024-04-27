/* 
 * File:   main.cpp
 * Author: VLADYMIR
 *
 * Created on 12 de abril de 2024, 21:34
 */
#include <iomanip>
#include <iostream>
#define N 5
#define M 5

using namespace std;

void remolino(int tablero[N][M], int n, int m, int x, int y) {
    if (y > m) {
        return;
    }
 
   

}




int main(int argc, char** argv) {

    int tablero[N][M];
    int n = N - 1, m = M, valor = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tablero[i][j] = valor++;
            cout << setw(3) << tablero[i][j];
        }
        cout << endl;
    }
 //   remolino(tablero, n, m, 0, 0);
    return 0;
}

