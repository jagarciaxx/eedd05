/* 
 * File:   FrecuenciaTextoBase.h
 * Author: javier
 *
 * Created on 7 de diciembre de 2012, 11:40
 */

#ifndef FRECUENCIATEXTOBASE_H
#define	FRECUENCIATEXTOBASE_H

#include <set>
#include <vector>
#include <string>

#include "FrecuenciaTermino.h"

using namespace std;

class FrecuenciaTextoBase {
protected:
    set<string> inexistentes;
    
public:
    virtual void compruebaTexto( char *texto ) = 0;
    virtual vector<FrecuenciaTermino> verFrecuencias() = 0;
    
    vector<string> verInexistentes() {
        vector<string> output(inexistentes.size());
    
        for (set<string>::iterator it = inexistentes.begin(); it != inexistentes.end(); it++) {
            output.push_back(*it);
        }
        
        return output;
    }

};

#endif	/* FRECUENCIATEXTOBASE_H */

