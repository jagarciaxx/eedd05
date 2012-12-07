/* 
 * File:   FrecuenciaTermino.h
 * Author: javier
 *
 * Created on 7 de diciembre de 2012, 10:58
 */

#ifndef FRECUENCIATERMINO_H
#define	FRECUENCIATERMINO_H

#include <string>

using namespace std;

class FrecuenciaTermino {
public:
    string termino;
    unsigned ocurrencias;
    
    FrecuenciaTermino(): ocurrencias(0) {}
    FrecuenciaTermino(string termino): termino(termino), ocurrencias(0) {}
};

class FrecuenciaTerminoMejorada: public FrecuenciaTermino {
public:
    FrecuenciaTerminoMejorada(): FrecuenciaTermino() {}
    FrecuenciaTerminoMejorada(string termino): FrecuenciaTermino(termino) {}
    
    bool operator==( const FrecuenciaTerminoMejorada &i ) const {
        return (termino == i.termino);
    }
    
    bool operator<( const FrecuenciaTerminoMejorada &i ) const {
        return (termino < i.termino);
    }
    
    bool operator>( const FrecuenciaTerminoMejorada &i ) const {
        return (termino > i.termino);
    }
};

class Comparador {
public:
    bool operator() (FrecuenciaTermino i, FrecuenciaTermino j) {
        return ( i.ocurrencias > j.ocurrencias );
    }
};

#endif	/* FRECUENCIATERMINO_H */

