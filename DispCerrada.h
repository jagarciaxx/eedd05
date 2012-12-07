/* 
 * File:   DispCerrada.h
 * Author: javier
 *
 * Created on 5 de diciembre de 2012, 20:28
 */

#ifndef DISPCERRADA_H
#define	DISPCERRADA_H

#include <vector>
#include <cmath>

using namespace std;

enum Estados { VACIA, DISPONIBLE, OCUPADA };

template<class T>
class Entrada {
public:
    long clave;
    T dato;
    Estados estado;
    
    Entrada(): estado(VACIA) {}
    Entrada(long clave, T dato): clave(clave), dato(dato), estado(OCUPADA) {}
};

template<class T>
class DispCerrada {
    vector< Entrada<T> > tabla;
public:
    DispCerrada() {}
    DispCerrada( unsigned tam ): tabla(tam) {}
    
    void insertar( long clave, const T &dato ) {
        long indice; // indice de la tabla
        int i = 0; // intentos
        
        do {
            indice = fDisp(clave + pow(i++,2));
        } while ( tabla.at(indice).estado == OCUPADA );
        
        tabla.at(indice) = Entrada<T>(clave, dato);
    }
    
    pair<T*,bool> buscar( long clave ) {
        pair<T*,bool> encontrado(0,false);
        
        long indice;
        int i = 0;
        
        do {
            indice = fDisp(clave + pow(i++,2));
            if ( tabla.at(indice).clave == clave ) {
                encontrado.first = &tabla.at(indice).dato;
                encontrado.second = true;
            }
        } while ( !encontrado.second && tabla.at(indice).estado != VACIA );
        
        return encontrado;
    }
    
    vector<T> obtenerEntradas() {
        vector<T> output;
        
        for (typename vector< Entrada<T> >::iterator it = tabla.begin(); it != tabla.end(); it++) {
            if ( (*it).estado == OCUPADA ) {
                output.push_back((*it).dato);
            }
        }
        
        return output;
    }
    
    void aumentar( size_t n ) {
        tabla.resize(n);
    }
    
private:
    long fDisp( long clave ) {
        return clave % tabla.size();
    }

};

#endif	/* DISPCERRADA_H */

