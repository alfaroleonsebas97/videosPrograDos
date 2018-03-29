/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: b60210
 *
 * Created on 15 de marzo de 2018, 10:10 AM
 */

#include <iostream>
using namespace std;

#include "CnjOrdInt.h"
/*
 * 
 */
int main(int argc, char** argv) {
    CnjOrdInt a,b; // a = ( 1, 2, 3 ) y b =( 10, 11, 13 )
    a.insertarOrd(1);
    a.insertarOrd(2);
    a.insertarOrd(3);
    cout << a.aHil() << endl;
    b.insertarOrd(10);
    b.insertarOrd(11);
    b.insertarOrd(13);
    cout << b.aHil() << endl;
    //CnjOrdInt c = a + b; // une a con b igual a ( 1, 2, 3, 10 , 11, 13 )
    //CnjOrdInt d = a / b; // construye la diferencia simétrica entre a y b.
    //c.insertarOrd(5);
    CnjOrdInt* e = new CnjOrdInt();
    e->insertarOrd(12);
    e->insertarOrd(9);
    e->insertarOrd(6);
    delete e;
    return 0;
}

