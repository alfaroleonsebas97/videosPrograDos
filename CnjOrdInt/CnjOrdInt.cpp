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

shared_ptr<CnjOrdInt> CnjOrdInt::cnj_nvo_ptr(nullptr);

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
    if (cnj_nvo_ptr != nullptr){
        cnj_nvo_ptr.reset();
    }
    cnj_nvo_ptr = shared_ptr<CnjOrdInt>(new CnjOrdInt());
    shared_ptr<NdoInt>  p, q, ultimo;
    p = inicio;
    q = b.inicio;
    ultimo = nullptr;
    int addMe = -1;
        while((p != nullptr) || (q != nullptr)){
            if(p == nullptr){
                addMe = q->dato;
                q = q->sgt;
            }else{
                if( q == nullptr){
                    addMe = p->dato;
                    p = p->sgt;
                }else{
                    if(p->dato < q->dato){
                        addMe = p->dato;
                        p = p->sgt;
                    } else {
                        if(p->dato > q->dato){
                            addMe = q->dato;
                            q = q->sgt;
                        } else{
                            addMe = p->dato;
                            p = p->sgt;
                            q = q->sgt;
                        }
                    }
                }
            }
            if (ultimo == nullptr){
                cnj_nvo_ptr->inicio = shared_ptr<NdoInt>(new NdoInt(addMe));
                ultimo = cnj_nvo_ptr->inicio;
            }else{
                ultimo->sgt = shared_ptr<NdoInt>(new NdoInt(addMe));
                ultimo = ultimo->sgt;
            }
        }
        return *cnj_nvo_ptr;     
}

CnjOrdInt& CnjOrdInt::operator*(const CnjOrdInt& b) const {
    if (cnj_nvo_ptr != nullptr){
        cnj_nvo_ptr.reset();
    }
    cnj_nvo_ptr = shared_ptr<CnjOrdInt>(new CnjOrdInt());
    shared_ptr<NdoInt>  p, q, ultimo;
    p = inicio;
    q = b.inicio;
    ultimo = nullptr;
    
    while((p != nullptr)&&(q != nullptr)){
        if(p->dato < q->dato){
            p = p->sgt;
        } else{
            if (q->dato < p->dato){
                q = q->sgt;
            }else{
                if (ultimo == nullptr){
                    cnj_nvo_ptr->inicio = shared_ptr<NdoInt>(new NdoInt(p->dato));
                    ultimo = cnj_nvo_ptr->inicio;
                } else {
                    ultimo->sgt = shared_ptr<NdoInt>(new NdoInt(p->dato));
                    ultimo = ultimo->sgt;
                }
                p = p->sgt; 
                q = q->sgt;
            }    
        }
    }
    return *cnj_nvo_ptr;
}

CnjOrdInt& CnjOrdInt::operator-(const CnjOrdInt& b) const{
    if (cnj_nvo_ptr != nullptr){
        cnj_nvo_ptr.reset();
    }
    cnj_nvo_ptr = shared_ptr<CnjOrdInt>(new CnjOrdInt());
    shared_ptr<NdoInt>  p, q, ultimo;
    p = inicio;
    q = b.inicio;
    ultimo = nullptr;
    int addMe = -1;
    bool addIt;
    while(p != nullptr){
        addIt = true;
        if(q == nullptr){
            addMe = p->dato;
            p = p->sgt;
        }else{
            if(p->dato < q->dato){
                addMe = p->dato;
                p = p->sgt;
            }else{
                if(p->dato == q->dato){
                    addIt = false;
                    addMe = -1;
                    p = p->sgt;
                    q =q->sgt;
                }else{
                    addIt = false;
                    addMe = -1;
                    q = q->sgt;
                }
            }
        }
        if(addIt){
            if (ultimo == nullptr){
                cnj_nvo_ptr->inicio = shared_ptr<NdoInt>(new NdoInt(addMe));
                ultimo = cnj_nvo_ptr->inicio;
            }else{
                ultimo->sgt = shared_ptr<NdoInt>(new NdoInt(addMe));
                ultimo = ultimo->sgt;
            }
        }
    }
    return *cnj_nvo_ptr;
}

CnjOrdInt& CnjOrdInt::operator/(const CnjOrdInt& b) const{
        if (cnj_nvo_ptr != nullptr){
        cnj_nvo_ptr.reset();
    }
    cnj_nvo_ptr = shared_ptr<CnjOrdInt>(new CnjOrdInt());
    shared_ptr<NdoInt>  p, q, ultimo;
    p = inicio;
    q = b.inicio;
    ultimo = nullptr;
    int addMe = -1;
    bool addIt;
    while((p != nullptr) || (q != nullptr)){
        addIt = true;
        if(p == nullptr){
            addMe = q->dato;
            q = q->sgt;
        }else{
            if(q == nullptr){
                addMe = p->dato;
                p = p->sgt;
            }else{
                if(p->dato < q->dato){
                    addMe = p->dato;
                    p = p->sgt;
                }else{
                    if(p->dato > q->dato){
                        addMe = q->dato;
                        q = q->sgt;
                    }else{
                        p = p->sgt;
                        q = q->sgt;
                        addIt = false;
                    }
                }
            }
        }
        if(addIt){
            if (ultimo == nullptr){
                cnj_nvo_ptr->inicio = shared_ptr<NdoInt>(new NdoInt(addMe));
                ultimo = cnj_nvo_ptr->inicio;
            }else{
                ultimo->sgt = shared_ptr<NdoInt>(new NdoInt(addMe));
                ultimo = ultimo->sgt;
            }
        }
    }
    return *cnj_nvo_ptr;   
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