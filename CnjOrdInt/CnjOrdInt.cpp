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

CnjOrdInt::CnjOrdInt():inicio(nullptr) {
}

CnjOrdInt::CnjOrdInt(const CnjOrdInt& orig) {
    shared_ptr<NdoInt> p = orig.inicio;
    if (p == nullptr){
        inicio = nullptr;
    }else{
        inicio = shared_ptr<NdoInt>(new NdoInt(orig.inicio->dato));
        p = p->sgt;
        shared_ptr<NdoInt> ultimo = inicio;
        while(p != nullptr){ //mientras la secuencia de nodos de orig no se acabe.
            ultimo->sgt = shared_ptr<NdoInt>(new NdoInt(p->dato));
            p = p->sgt;
            ultimo = ultimo->sgt;
        }
    }
}

CnjOrdInt::~CnjOrdInt() {
    /*shared_ptr<NdoInt> p = inicio;
    shared_ptr<NdoInt> q = nullptr;
    while(p != nullptr){
        q = p->sgt;
        //delete p;
        p = q;
    }*/
}

bool CnjOrdInt::insertarOrd(int x) {
    bool rsl = false;
    shared_ptr<NdoInt> p = inicio;
    shared_ptr<NdoInt> ant = nullptr;
    if(inicio == nullptr){ //se agrega el primer elemento a *this
        inicio = shared_ptr<NdoInt>(new NdoInt(x));
        rsl = true;
    } else{
        if (inicio->dato > x){ // inserción antes del inicio
        p = shared_ptr<NdoInt>(new NdoInt(x)); // se crea el nuevo nodo
        p->sgt = inicio; // se liga con el anterior inicio
        inicio = p; // se cambia inicio
        rsl = true;
        } else{
            p = inicio;
            while(p != nullptr){
                if(p->dato == x){ // se encontró x en *this, por lo tanto no se agrega
                    p = nullptr;
                } else{ //todavía no se encuentra pero puede que esté más adelante
                    if(p->dato < x){
                        ant = p;
                        p = p->sgt;
                        if (p == nullptr){
                            rsl = true;
                        }
                    } else { //se concluye que x no está en *this
                        p = nullptr;
                        rsl = true; //hay que agregarlo
                    }
                }
            }
            if (rsl){ // sirve para agregar en medio y al final
                p = ant->sgt; // p podría ser null o cero
                ant->sgt = shared_ptr<NdoInt>(new NdoInt(x));
                ant->sgt->sgt  = p;
            }
        }
    }
    return rsl;
}

bool CnjOrdInt::eliminar(int x) {
    bool rsl = false;
    shared_ptr<NdoInt> p = inicio;
    shared_ptr<NdoInt> ant = nullptr;
    if (inicio != nullptr && inicio->dato <= x ){
        if (inicio->dato == x){
            p = inicio->sgt;
            //delete inicio;
            inicio = p;
        } else {
            while (p != nullptr){ // hay que buscar a x
                if (p->dato == x){
                    rsl = true;
                    p = nullptr;
                } else { //hay que seguir buscando
                    if (p->dato < x){
                        ant = p;
                        p = p->sgt;
                    } else p = nullptr; // no está y no hay nada que eliminar
                }
            }
            if (rsl){ // si hay que eliminar en medio o al final 
                p = ant->sgt->sgt;
                //delete ant->sgt;
                ant->sgt = p;
            }
        }
    }
    return rsl;
}

bool CnjOrdInt::buscar(int x) const {
    bool rsl = false;
    shared_ptr<NdoInt> p = inicio;
    while(p != nullptr){
        if(p->dato == x){ //ya s encontró x en *this 
            rsl = true;
            p = nullptr;
        }else{ //todavía no se encuentra pero puede que esté más adelante
            if(p->dato < x){
                p = p->sgt;
            }
            else{ //se concluye que x no está en *this
                p = nullptr;
            }
        }
    }
    return rsl;
}

CnjOrdInt& CnjOrdInt::operator+(const CnjOrdInt& b) const {
}

CnjOrdInt& CnjOrdInt::operator*(const CnjOrdInt& b) const {
    CnjOrdInt* cnj_nvo_ptr = new CnjOrdInt();
    shared_ptr<NdoInt>  p, q, ultimo;
    p = inicio;
    q = inicio;
    ultimo = nullptr;
    
    while((p != nullptr)&&(q != nullptr)){
        if(p->dato < q->dato){
            p = p->sgt;
        } else{
            if (q->dato < p->dato){
                q = q->sgt;
            }else{
                if (ultimo == nullptr){
                    cnj_nvo_ptr->inicio = shared_ptr<NdoInt>(new NdoInt(q->dato));
                    ultimo = cnj_nvo_ptr->inicio;
                } else {
                    ultimo->sgt = shared_ptr<NdoInt>(new NdoInt(q->dato));
                }
                p = p->sgt; q->sgt;
            }    
        }
    }
    return *cnj_nvo_ptr;
}

CnjOrdInt& CnjOrdInt::operator-(const CnjOrdInt& b) const{
}

CnjOrdInt& CnjOrdInt::operator/(const CnjOrdInt& b) const{
}

string CnjOrdInt::aHil() {
    stringstream fs; //constituye una instancia de flujo de salida
    fs << '{';
    shared_ptr<NdoInt> p = inicio;
    while (p != nullptr){
        fs << p->dato;
        if(p->sgt != nullptr)
            fs << ',';
        p = p->sgt;   
    }
        fs << '}';
        return fs.str();
}