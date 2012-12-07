/* 
 * File:   FrecuenciaTexto2.cpp
 * Author: javier
 * 
 * Created on 7 de diciembre de 2012, 10:07
 */

#include "FrecuenciaTexto2.h"
#include "DispCerrada.h"

FrecuenciaTexto2::FrecuenciaTexto2(char* diccionario) {
    ifstream dicc(diccionario);
    
    if (dicc) {
        string palabra;
        while ( dicc >> palabra ) {
            arbol.insertar(FrecuenciaTerminoMejorada(palabra));
        }
    }
}

void FrecuenciaTexto2::compruebaTexto(char* texto) {
    ifstream txt(texto);
    
    if (txt) {
        string palabra;
        pair<FrecuenciaTermino*,bool> termino;
        while ( txt >> palabra ) {
            termino = arbol.buscar(FrecuenciaTerminoMejorada(palabra));
            if ( termino.second ) {
                termino.first->ocurrencias++;
            }
            else {
                inexistentes.insert(palabra);
            }
        }
    }
}

vector<FrecuenciaTermino> FrecuenciaTexto2::verFrecuencias() {
    vector<FrecuenciaTermino> output;
    vector<FrecuenciaTerminoMejorada> entradas = arbol.obtenerEntradas();
    
    for ( vector<FrecuenciaTerminoMejorada>::iterator it = entradas.begin(); it != entradas.end(); it++ ) {
        if ( (*it).ocurrencias > 0 ) {
            output.push_back(*it);
        }
    }
    
    sort(output.begin(), output.end(), Comparador() );
    return output;
}


