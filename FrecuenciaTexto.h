/* 
 * File:   FrecuenciaTexto.h
 * Author: javier
 *
 * Created on 5 de diciembre de 2012, 20:16
 */

#ifndef FRECUENCIATEXTO_H
#define	FRECUENCIATEXTO_H

#include <fstream>
#include <algorithm>

#include "DispCerrada.h"
#include "FrecuenciaTextoBase.h"

using namespace std;

class FrecuenciaTexto: public FrecuenciaTextoBase {
    DispCerrada<FrecuenciaTermino> tablaDisp;
public:
    FrecuenciaTexto( char *diccionario, unsigned tamTablaDisp );
    virtual void compruebaTexto( char *texto );
    virtual vector<FrecuenciaTermino> verFrecuencias();
private:
    unsigned djb2( const char *palabra );

};

#endif	/* FRECUENCIATEXTO_H */

