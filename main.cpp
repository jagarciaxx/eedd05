/* 
 * File:   main.cpp
 * Author: javier
 *
 * Created on 2 de diciembre de 2012, 21:10
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "FrecuenciaTexto.h"
//#include "DispCerrada.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    FrecuenciaTexto texto("dicc-espanol.txt", 2327407);
    
    texto.compruebaTexto("quijote_sinsignos.txt");
    
    /*
     * 10 Palabras más comunes en el quijote 
     */
    cout << "10 PALABRAS MAS COMUNES EN EL QUIJOTE" << endl;
    vector<string> vect_inexist = texto.verInexistentes();
    for (vector<string>::iterator it = vect_inexist.begin(); it != vect_inexist.end(); it++) {
        cout << *it << ' ';
    }
    
    /*
     * Lista de palabras no existentes
     */
    cout << "LISTA DE PALABRAS NO EXISTENTES" << endl;
    vector<FrecuenciaTermino> vect_entradas = texto.verFrecuencias();
    vector<FrecuenciaTermino>::iterator it = vect_entradas.begin();
    for (int i=0; i < 10; i++) {
        cout << (*it++).termino  << (*it).ocurrencias << ' ';
    }
    
    return 0;
}

