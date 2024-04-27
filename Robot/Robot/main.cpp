
/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 25 de marzo de 2024, 11:04 AM
 */

#include <iostream>
#define M 3

using namespace std;

int robot(int x,int y,int n,int m,int tablero[][3]){
    int der=-999999,aba=-999999;
    
    if(x==n-1 && y==m-1)return tablero[x][y]; 
    
    if(y+1<m) der = robot(x,y+1,n,m,tablero);
    if(x+1<n)aba = robot(x+1,y,n,m,tablero);
    
    if(der>aba)
        return der + tablero[x][y];
    return aba + tablero[x][y];
    
}


int main(int argc, char** argv) {
    int n=3,m=3;
    int tablero[][M]={  {3,8,6},
                        {3,100,2},
                        {0,9,1}};
    cout << "El resultado es:"<<robot(0,0,n,m,tablero) << endl;

    return 0;
}

