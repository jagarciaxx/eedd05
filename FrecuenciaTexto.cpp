/* 
 * File:   FrecuenciaTexto.cpp
 * Author: javier
 * 
 * Created on 5 de diciembre de 2012, 20:16
 */

#include "FrecuenciaTexto.h"

FrecuenciaTexto::FrecuenciaTexto(char* diccionario, unsigned tamTablaDisp) {
    tablaDisp.aumentar(tamTablaDisp);
    ifstream dicc(diccionario);
    
    if (dicc) {
        string palabra;
        while ( dicc >> palabra ) {
            tablaDisp.insertar(djb2(palabra.c_str()), FrecuenciaTermino(palabra));
        }
    }
}

void FrecuenciaTexto::compruebaTexto(char* texto) {
    ifstream txt(texto);
    
    if (txt) {
        string palabra;
        pair<FrecuenciaTermino*,bool> termino;
        while ( txt >> palabra ) {
            termino = tablaDisp.buscar(djb2(palabra.c_str()));
            if ( termino.second ) {
                termino.first->ocurrencias++;
            }
            else {
                inexistentes.insert(palabra);
            }
        }
    }
}

vector<FrecuenciaTermino> FrecuenciaTexto::verFrecuencias() {
    vector<FrecuenciaTermino> output;
    vector<FrecuenciaTermino> entradas = tablaDisp.obtenerEntradas();
    
    for ( vector<FrecuenciaTermino>::iterator it = entradas.begin(); it != entradas.end(); it++ ) {
        if ( (*it).ocurrencias > 0 ) {
            output.push_back(*it);
        }
    }
    
    sort(output.begin(), output.end(), Comparador() );
    return output;
}

unsigned FrecuenciaTexto::djb2( const char *palabra ) {
        unsigned hash = 5381;
        int c;
        
        while ( c = *palabra++ ) {
            hash = ( (hash << 5) + hash ) + c;
        }
        
        return hash;
    }