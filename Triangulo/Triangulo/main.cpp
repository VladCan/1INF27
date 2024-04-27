/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 25 de marzo de 2024, 10:35 AM
 */

#include <iostream>

using namespace std;


void triangulo(int a,int b){
    
    if(a>b) return;
    
    for(int i=0;i<a;i++) cout <<" * ";
    cout << endl;
    triangulo(a+1,b);
    for(int i=0;i<a;i++) cout <<" * ";
    cout << endl;    
}

int main(int argc, char** argv) {

    triangulo(3,5);
    
    return 0;
}

