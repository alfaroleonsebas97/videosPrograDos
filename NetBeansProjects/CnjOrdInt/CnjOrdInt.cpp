/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CnjOrdInt.cpp
 * Author: b60210
 * 
 * Created on 15 de marzo de 2018, 10:13 AM
 */

#include "CnjOrdInt.h"
#include <sstream>

CnjOrdInt::CnjOrdInt():inicio(0) {
}

CnjOrdInt::CnjOrdInt(const CnjOrdInt& orig) {
    NdoInt* p = orig.inicio;
    if (p == 0){
        inicio = 0;
    }else{
        inicio = new NdoInt(orig.inicio->dato);
        p = p->sgt;
        NdoInt* ultimo = inicio;
        while(p != 0){ //mientras la secuencia de nodos de orig no se acabe.
            ultimo->sgt = new NdoInt(p->dato);
            p = p->sgt;
            ultimo = ultimo->sgt;
        }
    }
}

CnjOrdInt::~CnjOrdInt() {
    NdoInt* p = inicio;
    NdoInt* q = 0;
    while(p != 0){
        q = p->sgt;
        delete p;
        p = q;
    }
}

bool CnjOrdInt::insertarOrd(int x) {
    bool rsl = false;
    NdoInt* p = inicio;
    NdoInt* ant = 0;
    if(inicio == 0){ //se agrega el primer elemento a *this
        inicio = new NdoInt(x);
        rsl = true;
    } else{
        if (inicio->dato > x){ // inserción antes del inicio
        p = new NdoInt(x); // se crea el nuevo nodo
        p->sgt = inicio; // se liga con el anterior inicio
        inicio = p; // se cambia inicio
        rsl = true;
        } else{
            p = inicio;
            while(p != 0){
                if(p->dato == x){ // se encontró x en *this, por lo tanto no se agrega
                    p = 0;
                } else{ //todavía no se encuentra pero puede que esté más adelante
                    if(p->dato < x){
                        ant = p;
                        p = p->sgt;
                        if (p == 0){
                            rsl = true;
                        }
                    } else { //se concluye que x no está en *this
                        p = 0;
                        rsl = true; //hay que agregarlo
                    }
                }
            }
            if (rsl){ // sirve para agregar en medio y al final
                p = ant->sgt; // p podría ser null o cero
                ant->sgt = new NdoInt(x);
                ant->sgt->sgt  = p;
            }
        }
    }
    return rsl;
}

bool CnjOrdInt::eliminar(int x) {
    bool rsl = false;
    NdoInt* p = inicio;
    NdoInt* ant = 0;
    if (inicio != 0 && inicio->dato <= x ){
        if (inicio->dato == x){
            p = inicio->sgt;
            delete inicio;
            inicio = p;
        } else {
            while (p != 0){ // hay que buscar a x
                if (p->dato == x){
                    rsl = true;
                    p = 0;
                } else { //hay que seguir buscando
                    if (p->dato < x){
                        ant = p;
                        p = p->sgt;
                    } else p = 0; // no está y no hay nada que eliminar
                }
            }
            if (rsl){ // si hay que eliminar en medio o al final 
                p = ant->sgt->sgt;
                delete ant->sgt;
                ant->sgt = p;
            }
        }
    }
    return rsl;
}

bool CnjOrdInt::buscar(int x) const {
    bool rsl = false;
    NdoInt* p = inicio;
    while(p != 0){
        if(p->dato == x){ //ya s encontró x en *this 
            rsl = true;
            p = 0;
        }else{ //todavía no se encuentra pero puede que esté más adelante
            if(p->dato < x){
                p = p->sgt;
            }
            else{ //se concluye que x no está en *this
                p = 0;
            }
        }
    }
    return rsl;
}

CnjOrdInt& CnjOrdInt::operator+(const CnjOrdInt b) const {
}

CnjOrdInt& CnjOrdInt::operator*(const CnjOrdInt b) const {
}

CnjOrdInt& CnjOrdInt::operator-(const CnjOrdInt b) const{
}

CnjOrdInt& CnjOrdInt::operator/(const CnjOrdInt b) const{
}

string CnjOrdInt::aHil() {
    stringstream fs; //constituye una instancia de flujo de salida
    fs << '{';
    NdoInt* p = inicio;
    while (p != 0){
        fs << p->dato;
        if(p->sgt != 0)
            fs << ',';
        p = p->sgt;   
    }
        fs << '}';
        return fs.str();
}