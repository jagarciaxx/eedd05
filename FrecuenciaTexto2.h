/* 
 * File:   FrecuenciaTexto2.h
 * Author: javier
 *
 * Created on 7 de diciembre de 2012, 10:07
 */

#ifndef FRECUENCIATEXTO2_H
#define	FRECUENCIATEXTO2_H

#include <fstream>
#include <algorithm>

#include "Avl.h"
#include "FrecuenciaTextoBase.h"

using namespace std;

class FrecuenciaTexto2: public FrecuenciaTextoBase {
    Avl<FrecuenciaTerminoMejorada> arbol;
public:
    FrecuenciaTexto2( char *diccionario );
    virtual void compruebaTexto( char *texto );
    virtual vector<FrecuenciaTermino> verFrecuencias();
private:

};

#endif	/* FRECUENCIATEXTO2_H */

