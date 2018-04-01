/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CnjOrdInt.h
 * Author: b60210
 *
 * Created on 15 de marzo de 2018, 10:13 AM
 */

#ifndef CNJORDINT_H
#define CNJORDINT_H

#include <string>
#include <iostream>
#include <memory>
using namespace std;

class CnjOrdInt {
    //Representa un conjunto ordenado de enteros.
    
public:
    //EFE: contruye un nuevo conjunto de enteros vacío.
    CnjOrdInt();
    
    // EFE: construye una copia idéntica e independiente de "orig".
    CnjOrdInt(const CnjOrdInt& orig);
    
    ~CnjOrdInt();
    
    //MOD: *this
    //EFE: si x no pertenece al objeto  *this, entonces lo agrega preservando el orden y 
    //retorna true, en caso contrario, no tiene efecto y retorna false.
    bool insertarOrd(int x);
    
    //MOD: modificar *this.
    //EFE: si x pertenece a *this,entonces lo elimina preservando el orden y
    //retorna true, en caso contrario, no tiene efecto y retorna false.
    bool eliminar(int x);
    
    //EFE: retornar true si x pertenece a *this o false en caso contrario.
    bool buscar(int x) const;
    
    //EFE: retorna un nuevo conjunto ordenado que representa la unión de *this con b.
    CnjOrdInt& operator+(const CnjOrdInt& b) const;
    
    //EFE: retorna un nuevo conjunto ordenado que representa la intersección de *this con b.
    CnjOrdInt& operator*(const CnjOrdInt& b) const;
    
    //EFE: retorna un nuevo conjunto ordenado que representa la diferencia de *this con b.
    CnjOrdInt& operator-(const CnjOrdInt& b) const;
    
        //EFE: retorna un nuevo conjunto ordenado que representa la diferencia simétrica de *this con b.
    CnjOrdInt& operator/(const CnjOrdInt& b) const;
    
    // EFE: retornar un ahilera que representa a *this.
    // Por ejemplo: "()" para el conjunto vacío y "( 1, 2 , 3 )"
    string aHil();
private:
    struct NdoInt {
        int dato;
        shared_ptr<NdoInt> sgt;
        NdoInt(int x):dato(x),sgt(0){};
        ~NdoInt(){ cout << "borrando: " << dato <<endl;};
    };  
    
    shared_ptr<NdoInt> inicio;
    static shared_ptr<CnjOrdInt> cnj_nvo_ptr;
};

#endif /* CNJORDINT_H */
