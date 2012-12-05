/* 
 * File:   FrecuenciaTexto.cpp
 * Author: javier
 * 
 * Created on 5 de diciembre de 2012, 20:16
 */

#include "FrecuenciaTexto.h"

FrecuenciaTexto::FrecuenciaTexto(char* diccionario, unsigned tamTablaDisp) {
    
}

void FrecuenciaTexto::compruebaTexto(char* texto) {
    
}

vector<string> FrecuenciaTexto::verInexistentes() {
    
}

unsigned FrecuenciaTexto::djb2(char* palabra) {
    unsigned hash = 5381;
    int c;
    
    while ( c = *palabra++ ) {
        hash = ( (hash << 5) + hash ) + c;
    }
    
    return hash;
}



