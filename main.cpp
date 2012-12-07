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
#include <ctime>

#include "FrecuenciaTexto.h"
#include "FrecuenciaTexto2.h"
//#include "DispCerrada.h"
//#include "Avl.h"
//#include "FrecuenciaTermino.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    /*
     * 10 Palabras más comunes en el quijote 
     *
    FrecuenciaTexto texto("dicc-espanol.txt", 2327407);
    texto.compruebaTexto("quijote_sinsignos.txt");
    cout << "LISTA DE PALABRAS NO EXISTENTES" << endl;
    vector<string> vect_inexist = texto.verInexistentes();
    for (vector<string>::iterator it = vect_inexist.begin(); it != vect_inexist.end(); it++) {
        cout << *it << ' ';
    }
    
    /*
     * Lista de palabras no existentes
     *
    cout << endl << "10 PALABRAS MAS COMUNES EN EL QUIJOTE" << endl;
    vector<FrecuenciaTermino> vect_entradas = texto.verFrecuencias();
    vector<FrecuenciaTermino>::iterator it = vect_entradas.begin();
    for (int i=0; i < 10; i++) {
        cout << (*it++).termino  << (*it).ocurrencias << ' ';
    }
    
    /*
     * Medir los tiempos de las funciones compruebaTexto
     */
    FrecuenciaTexto texto1("dicc-espanol.txt", 2327407);
    FrecuenciaTexto2 texto2("dicc-espanol.txt");
    
    clock_t t1_ini, t2_ini, t1_fin, t2_fin;
    
    t1_ini = clock();
    texto1.compruebaTexto("quijote_sinsignos.txt");
    t1_fin = clock();
    
    t2_ini = clock();
    texto2.compruebaTexto("quijote_sinsignos.txt");
    t2_fin = clock();
    
    cout << "Tiempo en ms con texto1 " << (double)(t1_fin - t1_ini) << " ms." << endl;
    cout << "Tiempo en ms con texto2 " << (double)(t2_fin - t2_ini) << " ms." << endl;
    
    return 0;
}

