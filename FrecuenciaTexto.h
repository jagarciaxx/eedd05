/* 
 * File:   FrecuenciaTexto.h
 * Author: javier
 *
 * Created on 5 de diciembre de 2012, 20:16
 */

#ifndef FRECUENCIATEXTO_H
#define	FRECUENCIATEXTO_H

#include <set>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

#include "DispCerrada.h"

using namespace std;

class FrecuenciaTermino {
public:
    string termino;
    unsigned ocurrencias;
    
    FrecuenciaTermino(): ocurrencias(0) {}
    FrecuenciaTermino(string termino): termino(termino), ocurrencias(0) {}
};

class FrecuenciaTexto {
    DispCerrada<FrecuenciaTermino> tablaDisp;
    set<string> inexistentes;
public:
    FrecuenciaTexto( char *diccionario, unsigned tamTablaDisp );
    void compruebaTexto( char *texto );
    vector<string> verInexistentes();
    vector<FrecuenciaTermino> verFrecuencias();
private:
    unsigned djb2( const char *palabra );

};

class Comparador {
public:
    bool operator() (FrecuenciaTermino i, FrecuenciaTermino j) {
        return ( i.ocurrencias > j.ocurrencias );
    }
};

#endif	/* FRECUENCIATEXTO_H */

