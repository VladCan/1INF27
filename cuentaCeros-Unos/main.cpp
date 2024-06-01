

/* 
 * File:   main.cpp
 * Author: VLADYMIR
 *
 * Created on 2 de mayo de 2024, 17:32
 */

#include <iostream>

using namespace std;

int cuentaUnos(int *arr, int ini, int fin, int cont) {
    if (ini > fin) return cont;
    int med = (ini + fin) / 2;
    if (arr[med] == 0) {
        return cuentaUnos(arr, med + 1, fin, cont);
    } else
        return cuentaUnos(arr, ini, med-1, cont+fin-med+1);


}

int main(int argc, char** argv) {
    
    int arr[]={0,0,0,0,0,00,000,0,0,0,1,1,1,1,1,1,1,1,1,1};
    int n=sizeof (arr)/(sizeof(int));
    cout<<n<<endl;
    cout<<cuentaUnos(arr,0,n-1,0);
    return 0;
}

