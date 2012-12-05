/* 
 * File:   DispCerrada.h
 * Author: javier
 *
 * Created on 5 de diciembre de 2012, 20:28
 */

#ifndef DISPCERRADA_H
#define	DISPCERRADA_H

#include <vector>

using namespace std;

template<class T>
class Entrada {
public:
    long clave;
    T dato;
    enum { VACIA, DISPONIBLE, OCUPADA } estado;
    
    Entrada(): estado(VACIA) {}
    Entrada(long clave, T dato): clave(clave), dato(dato), estado(OCUPADA) {}
};

template<class T>
class DispCerrada {
    vector< Entrada<T> > tabla;
public:
    DispCerrada();
    DispCerrada(const DispCerrada& orig);
    virtual ~DispCerrada();
private:
    long fDisp( long clave );

};

#endif	/* DISPCERRADA_H */

