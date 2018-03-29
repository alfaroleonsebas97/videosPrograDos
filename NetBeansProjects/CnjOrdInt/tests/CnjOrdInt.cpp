/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PrbCnjOrdInt.cpp
 * Author: b60210
 *
 * Created on 15 de marzo de 2018, 11:53 AM
 */

#include <stdlib.h>
#include <iostream>
#include "CnjOrdInt.h"

/*
 * Simple C++ Test Suite
 */

void testCnjOrdInt() {
    CnjOrdInt cnjOrdInt;
    string h = cnjOrdInt.aHil(); // suponemos que el método aHil() funciona bien.
    if (h != "{}") {
        std::cout << "%TEST_FAILED% time=0 testname=testCnjOrdInt (PrbCnjOrdInt) el constructor estándar o el método falló" << std::endl;
    }
}

void testCnjOrdInt2() {
    CnjOrdInt orig;
    CnjOrdInt cnjOrdInt(orig);
    string h = cnjOrdInt.aHil(); // suponemos que el método aHil() funciona bien.
    if (h != "{}") {
        std::cout << "%TEST_FAILED% time=0 testname=testCnjOrdInt2 (PrbCnjOrdInt) el constructor copias o el méteodo aHil falló" << std::endl;
    }
}

void testInsertarOrd() {
    CnjOrdInt cnjOrdInt;
    bool result = cnjOrdInt.insertarOrd(0); // ( 0 )
    string h = cnjOrdInt.aHil();
    if (!result || h != "(0)") {
        std::cout << "%TEST_FAILED% time=0 testname=testInsertarOrd (PrbCnjOrdInt) falló el método insertarOrd con x == 0" << std::endl;
    };

    result = cnjOrdInt.insertarOrd(3);
    h = cnjOrdInt.aHil();
     if (!result || h != "(0,3)") {
        std::cout << "%TEST_FAILED% time=0 testname=testInsertarOrd (PrbCnjOrdInt) falló el método insertarOrd con x == 0 , 3" << std::endl;
    };
    
    result = cnjOrdInt.insertarOrd(7);
    h = cnjOrdInt.aHil();
    if (!result || h != "(0,3, 7)") {
        std::cout << "%TEST_FAILED% time=0 testname=testInsertarOrd (PrbCnjOrdInt) falló el método insertarOrd con x == 0 , 3, 7" << std::endl;
    };
}

void testEliminar() {
    CnjOrdInt cnjOrdInt;
    bool result = cnjOrdInt.eliminar(0);
    if (result) {
        std::cout << "%TEST_FAILED% time=0 testname=testEliminar (PrbCnjOrdInt) falló método eliminar con conjunto vacío" << std::endl;
    }
    
    cnjOrdInt.insertarOrd(0);
    cnjOrdInt.insertarOrd(3);
    cnjOrdInt.insertarOrd(7);
    cnjOrdInt.insertarOrd(11); // (0,3,7,11)
    result = cnjOrdInt.eliminar(5);
        if (result) {
        std::cout << "%TEST_FAILED% time=0 testname=testEliminar (PrbCnjOrdInt) falló método eliminar(5) con conjunto (0,3,7,11)" << std::endl;
    }
    
    CnjOrdInt cnjOrdInt2(cnjOrdInt);
    result = cnjOrdInt2.eliminar(0);
     string h = cnjOrdInt2.aHil();
    if (result || h != "(3,7,11)") {
        std::cout << "%TEST_FAILED% time=0 testname=testEliminar (PrbCnjOrdInt) falló método eliminar(0) con conjunto (0,3,7,11)" << std::endl;
    }
    
        CnjOrdInt cnjOrdInt3(cnjOrdInt);
    result = cnjOrdInt3.eliminar(11);
    h = cnjOrdInt3.aHil();
    if (result || h != "(0,3,7)") {
        std::cout << "%TEST_FAILED% time=0 testname=testEliminar (PrbCnjOrdInt) falló método eliminar(11) con conjunto (0,3,7,11)" << std::endl;
    }
    
            CnjOrdInt cnjOrdInt4(cnjOrdInt);
    result = cnjOrdInt4.eliminar(7);
    h = cnjOrdInt4.aHil();
    if (result || h != "(0,3,11)") {
        std::cout << "%TEST_FAILED% time=0 testname=testEliminar (PrbCnjOrdInt) falló método eliminar(7) con conjunto (0,3,7,11)" << std::endl;
    }
}

void testBuscar() {
    CnjOrdInt cnjOrdInt;
    bool result = cnjOrdInt.buscar(5);
    if (result) {
        std::cout << "%TEST_FAILED% time=0 testname=testBuscar (PrbCnjOrdInt) falló el método buscar (5) con ()" << std::endl;
    } 
    cnjOrdInt.insertarOrd(0);
    cnjOrdInt.insertarOrd(3);
    cnjOrdInt.insertarOrd(7);
    cnjOrdInt.insertarOrd(11); // (0,3,7,11)
    result = cnjOrdInt.buscar(5);
    if (result) {
        std::cout << "%TEST_FAILED% time=0 testname=testBuscar (PrbCnjOrdInt) falló el método buscar (5) con (0,3,7,11)" << std::endl;
    }
    
    result = cnjOrdInt.buscar(0);
    if (!result) {
        std::cout << "%TEST_FAILED% time=0 testname=testBuscar (PrbCnjOrdInt) falló el método buscar (0) con (0,3,7,11)" << std::endl;
    } 
    
    result = cnjOrdInt.buscar(11);
    if (!result) {
        std::cout << "%TEST_FAILED% time=0 testname=testBuscar (PrbCnjOrdInt) falló el método buscar (11) con (0,3,7,11)" << std::endl;
    } 
    
    result = cnjOrdInt.buscar(7);
    if (!result) {
        std::cout << "%TEST_FAILED% time=0 testname=testBuscar (PrbCnjOrdInt) falló el método buscar (7) con (0,3,7,11)" << std::endl;
    } 
}


void testUnion() {
    CnjOrdInt a;
    CnjOrdInt b;
    CnjOrdInt c;
    CnjOrdInt d;
    
    a.insertarOrd(4);
    a.insertarOrd(8);
    a.insertarOrd(12);
    
    b.insertarOrd(0);
    b.insertarOrd(1);
    
    c.insertarOrd(14);
    
    d.insertarOrd(5);
    d.insertarOrd(9);
    
    CnjOrdInt r1 = a + b; // --> (0,1,4,8,12)
    string h = r1.aHil(); 
    if (h != "{0,1,4,8,12}"){
    std::cout << "%TEST_FAILED% time=0 testname=testUnion (PrbCnjOrdInt) falló la union de (0,1) y (4, 8,12)" << std::endl;
    } 
    
    CnjOrdInt r2 = a+c; // --> (4,8,12,14)
    h = r2.aHil(); 
    if (h != "(4,8,12,14)"){
    std::cout << "%TEST_FAILED% time=0 testname=testUnion (PrbCnjOrdInt) falló la union de (4, 8,12) y (14)" << std::endl;
    }
    
    CnjOrdInt r3 = a+d; // (4,5,8,9,12)
    h = r3.aHil(); 
    if (h != "(4,5,8,9,12)"){
    std::cout << "%TEST_FAILED% time=0 testname=testUnion (PrbCnjOrdInt) falló la union de (4, 8,12) y (14)" << std::endl;
    }
}


void testInterseccion(){
    CnjOrdInt a;
    CnjOrdInt b;
    CnjOrdInt c;
    CnjOrdInt d;
    CnjOrdInt e;
    
    a.insertarOrd(4);
    a.insertarOrd(8);
    a.insertarOrd(10);
    a.insertarOrd(12);
    
    b.insertarOrd(5);
    b.insertarOrd(7);
    b.insertarOrd(9);
    
    
    CnjOrdInt r1 = a*b;
    string h = r1.aHil();
    if (h != "()"){
    std::cout << "%TEST_FAILED% time=0 testname=testInsterseccion (PrbCnjOrdInt) falló la interseccion de (4,8,10,12) con  (5,7,9)" << std::endl;
    }
    
    c.insertarOrd(4); 
    CnjOrdInt r2 = a*c;
    h = r2.aHil();
    if (h != "(4)"){
    std::cout << "%TEST_FAILED% time=0 testname=testInsterseccion (PrbCnjOrdInt) falló la interseccion de (4,8,10,12) con  (4)" << std::endl;
    }
    
    d.insertarOrd(8);
    d.insertarOrd(10);
    
    CnjOrdInt r3 = a*d;
    h = r3.aHil();
    if (h != "(8,10)"){
    std::cout << "%TEST_FAILED% time=0 testname=testInsterseccion (PrbCnjOrdInt) falló la interseccion de (4,8,10,12) con  (8,10)" << std::endl;
    }
    
    e.insertarOrd(8);
    e.insertarOrd(10);
    e.insertarOrd(12);
    
    CnjOrdInt r4 = a*e;
    h = r4.aHil();
    if (h != "(8,10,12)"){
    std::cout << "%TEST_FAILED% time=0 testname=testInsterseccion (PrbCnjOrdInt) falló la interseccion de (4,8,10,12) con  (8,10,12)" << std::endl;
    }
}

void testDiferencia(){
    CnjOrdInt a;
    CnjOrdInt b;
    CnjOrdInt c;
    CnjOrdInt d;
    CnjOrdInt e;
    
    a.insertarOrd(4);
    a.insertarOrd(8);
    a.insertarOrd(10);
    a.insertarOrd(12);
    
    b.insertarOrd(5);
    b.insertarOrd(7);
    b.insertarOrd(9);
    
    c.insertarOrd(4);
    c.insertarOrd(8);
    
    d.insertarOrd(5);
    d.insertarOrd(7);
    d.insertarOrd(9);
    d.insertarOrd(11);

    e.insertarOrd(7);
    e.insertarOrd(8);
    e.insertarOrd(11);
    e.insertarOrd(12);  
    
    CnjOrdInt r1 = a - b;
    string h = r1.aHil();
    if (h != "(4,8,10,12)"){
    std::cout << "%TEST_FAILED% time=0 testname=testDiferencia (PrbCnjOrdInt) falló la diferencia de (4,8,10,12) con  (5,7,9)" << std::endl;
    }
    
    CnjOrdInt r2 = a - c;
    h = r2.aHil();
    if (h != "(10,12)"){
    std::cout << "%TEST_FAILED% time=0 testname=testDiferencia (PrbCnjOrdInt) falló la diferencia de (4,8,10,12) con  (4,8)" << std::endl;
    }
    
    CnjOrdInt r3 = b - d;
    h = r3.aHil();
    if (h != "()"){
    std::cout << "%TEST_FAILED% time=0 testname=testDiferencia (PrbCnjOrdInt) falló la diferencia de (5,7,9) con  (5,7,9,11)" << std::endl;
    }
    
    CnjOrdInt r4 = d - e;
    h = r4.aHil();
    if (h != "(5,9)"){
    std::cout << "%TEST_FAILED% time=0 testname=testDiferencia (PrbCnjOrdInt) falló la diferencia de (5,7,9,11) con  (7,8,11,12)" << std::endl;
    }
    
}
 // A ds B = A U B - A i B.

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% PrbCnjOrdInt" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testCnjOrdInt (PrbCnjOrdInt)" << std::endl;
    testCnjOrdInt();
    std::cout << "%TEST_FINISHED% time=0 testCnjOrdInt (PrbCnjOrdInt)" << std::endl;

    std::cout << "%TEST_STARTED% testCnjOrdInt2 (PrbCnjOrdInt)" << std::endl;
    testCnjOrdInt2();
    std::cout << "%TEST_FINISHED% time=0 testCnjOrdInt2 (PrbCnjOrdInt)" << std::endl;

    std::cout << "%TEST_STARTED% testInsertarOrd (PrbCnjOrdInt)" << std::endl;
    testInsertarOrd();
    std::cout << "%TEST_FINISHED% time=0 testInsertarOrd (PrbCnjOrdInt)" << std::endl;
    
    std::cout << "%TEST_STARTED% testBuscar (PrbCnjOrdInt)" << std::endl;
    testBuscar();
    std::cout << "%TEST_FINISHED% time=0 testBuscar (PrbCnjOrdInt)" << std::endl;
    
    std::cout << "%TEST_STARTED% testEliminar (PrbCnjOrdInt)" << std::endl;
    testEliminar();
    std::cout << "%TEST_FINISHED% time=0 testEliminar (PrbCnjOrdInt)" << std::endl;

    std::cout << "%TEST_STARTED% testUnion (PrbCnjOrdInt)" << std::endl;
    testUnion();
    std::cout << "%TEST_FINISHED% time=0 testUnion (PrbCnjOrdInt)" << std::endl;
    
    std::cout << "%TEST_STARTED% testInterseccion (PrbCnjOrdInt)" << std::endl;
    testInterseccion();
    std::cout << "%TEST_FINISHED% time=0 testInterseccion (PrbCnjOrdInt)" << std::endl;
    
    
    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

