#include <iostream>
#include <time.h>

#include "lista.h"
using namespace std;

int main()
{
    cout << "Ordenador de 100,000 numeros" << endl;
    Lista original,dos;

    clock_t inicio,final;
    int auxIn;//Datos random
    cout << "Generando numeros..." << endl;
    for(int i(0);i<50000;i++){
        auxIn = rand()%1000000;
        //cout << auxIn << endl;
        original.Inserta(auxIn, i-1);
    }
    //A ordenar
    cout << "Ordenando..." << endl;
    dos = original;
    inicio = clock();
    dos.ordenaBurbuja();
    final = clock();
    cout << "Tiempo de ejecucion de burbuja: " << double(final - inicio)/ CLOCKS_PER_SEC << "Segundos" << endl;
    dos = original;
    inicio = clock();
    dos.ordenaShell();
    final = clock();
    cout << "Tiempo de ejecucion de shell: " << double(final - inicio)/ CLOCKS_PER_SEC << "Segundos" << endl;
    dos = original;
    inicio = clock();
    dos.ordenaInsert();
    final = clock();
    cout << "Tiempo de ejecucion de insercion: " << double(final - inicio)/ CLOCKS_PER_SEC << "Segundos" << endl;
    dos = original;
    inicio = clock();
    dos.ordenaSelect();
    final = clock();
    cout << "Tiempo de ejecucion de seleccion: " << double(final - inicio)/ CLOCKS_PER_SEC << "Segundos" << endl;
    dos = original;
    inicio = clock();
    dos.ordenaMerge();
    final = clock();
    cout << "Tiempo de ejecucion de mezcla: " << double(final - inicio)/ CLOCKS_PER_SEC << "Segundos" << endl;
    dos = original;
    inicio = clock();
    dos.ordenaQuick();
    final = clock();
    cout << "Tiempo de ejecucion de quick: " << double(final - inicio)/ CLOCKS_PER_SEC << "Segundos" << endl;
}
