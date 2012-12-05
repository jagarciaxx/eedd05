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

#include "DispCerrada.h"

using namespace std;

class FrecuenciaTermino {
public:
    string termino;
    unsigned ocurrencias;
    
    FrecuenciaTermino(): ocurrencias(0) {}
};

class FrecuenciaTexto {
    DispCerrada<FrecuenciaTermino> tablaDisp;
    set<string> inexistentes;
public:
    FrecuenciaTexto( char *diccionario, unsigned tamTablaDisp );
    void compruebaTexto( char *texto );
    vector<string> verInexistentes();
private:
    unsigned djb2( char *palabra );

};

#endif	/* FRECUENCIATEXTO_H */

