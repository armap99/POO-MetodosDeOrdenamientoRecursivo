//Lista.h
#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <iomanip>

#include "error.h"

class Lista
{
private:
    int numeros[100000];
    int last;
    bool isValidPos(const int&);
    void ordenaMerge(const int&, const int&);
    void ordenaQuick(const int&, const int&);

public:
    Lista();
    bool Vacia();
    bool Llena();
    void Inserta(const int&, const int&);
    void Borrar(const int&);
    int Recupera(const int&);
    int getPrimero();
    int getUltimo();
    int getSeguiente(const int&);
    int getAnterior(const int&);
    void Anula();
    void Mostrar();
    int busquedaLineal(const int&);
    int busquedaBinaria(const int&);
    void swapData(int&, int&);
    void ordenaBurbuja();
    void ordenaShell();
    void ordenaInsert();
    void ordenaSelect();
    void ordenaMerge();
    void ordenaQuick();
};

#endif // LISTA_H
