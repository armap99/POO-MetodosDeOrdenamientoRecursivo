//Lista.cpp
#include "lista.h"

Lista::Lista() : last(-1){}

bool Lista::isValidPos(const int &p)
{
    return p > -2 && p <= last;
}

bool Lista::Vacia()
{
    return last == -1;
}

bool Lista::Llena()
{
    return last == 99999;
}

void Lista::Inserta(const int &e, const int &pos)
{
    if(!isValidPos(pos) or pos< -1 or Llena()){
        throw Error("Desbordamineto de datos,Inserta nueva1");
    }
    int i(last);
    while(i>pos){
        numeros[i+1] = numeros[i];
        i--;
    }
    numeros[pos+1] = e;
    last++;
}

void Lista::Borrar(const int &pos)
{
    if(!isValidPos(pos)){
        throw Error("Posicion a eleminar no valida,borrar");
    }
    if(Vacia()){
        throw Error("Lista vacia,borrar");
    }
    int i(pos);
    while (i < last) {
        numeros[i]=numeros[i+1];
        i++;
    }
    last--;
}

int Lista::Recupera(const int &pos)
{
    if(!isValidPos(pos)){
        throw Error("Posicion Invalida,Recupera");
    }
    return numeros[pos];
}

int Lista::getPrimero()
{
    if(Vacia()){
        throw Error("La playlist esta vacia,getprimero");
    }
    return 0;
}

int Lista::getUltimo()
{
    if(Vacia()){
        throw Error("La playlist esta vacia,getultimo");
    }
 return last;
}

int Lista::getSeguiente(const int &pos)
{
    if(!isValidPos(pos)){
        throw Error("Posicion invalida,getSiguiente");
    }
    if(Vacia()){
        throw Error("La lista esta vacia,getsiguiente");
    }
    return pos+1;
}

int Lista::getAnterior(const int &pos)
{
    if(!isValidPos(pos)){
        throw Error("Posicion invalida,getanterior");
    }
    if(Vacia()){
        throw Error("La lista esta vacia,getanterior");
    }
    return pos-1;
}

void Lista::Anula()
{
    last = -1;
}

void Lista::Mostrar()
{
    if(Vacia()){
        throw Error("Datos insuficientes,mostrar");
    }
    int i=0,j=0;
    while(i<=last) {
        std::cout << numeros[i] << " ";
        i++;
        j++;
        if(j==10){
            std::cout << std::endl;
            j=0;
        }
    }
}

int Lista::busquedaLineal(const int&c)
{
    for(int j(0); j <= last; j++){
        if(numeros[j] == c){
            return j;
        }
    }
    return -1;

}

int Lista::busquedaBinaria(const int &c)
{
    int i(0), j(last),m;
    while(i<=j){
        m = (1+j)/2;
        if(numeros[m] == c){
            return m;
        }
        if(c < numeros[m]){
            j = m-1;
        }
        i = m+1;
    }
    return -1;
}

void Lista::swapData(int &a, int &b)
{
    int Aux(a);
    a=b;
    b=Aux;
}


void Lista::ordenaBurbuja()
{
    int i(last),j;
    bool flag;
    do{
        flag = false;
        j = 0;
        while(j < i){
            if(numeros[j] > numeros[j+1]){
                swapData(numeros[j], numeros[j+1]);
                flag = true;
            }
            j++;
        }
        i--;
    }while(flag);
}

void Lista::ordenaShell()
{
    float fact(3.0/4.0);
    int dif((last+1)*fact),lim,i;
    while(dif > 0){
        lim = last -dif;
        i = 0;
        while(i <= lim){
            if(numeros[i] > numeros[i+dif]){
                swapData(numeros[i], numeros[i+dif]);
            }
            i++;
        }
        dif*=fact;
    }
}

void Lista::ordenaInsert()
{
    int i(1),j;
    int aux;
    while(i <= last){
        aux = numeros[i];
        j = i;
        while(j > 0 and aux < numeros[j-1]){
            numeros[j] = numeros[j-1];
            j--;
        }
        if(i != j){
            numeros[j] = aux;
        }
        i++;
    }
}

void Lista::ordenaSelect()
{
    int i(0),j,m;
    while(i < last){
        m = i;
        j = i+1;
        while(j <= last){
            if(numeros[j] < numeros[m]){
                m = j;
            }
            j++;
        }
        if(i != m){
            swapData(numeros[i],numeros[m]);
        }
        i++;
    }
}

void Lista::ordenaMerge()
{
    ordenaMerge(0,last);
}

void Lista::ordenaMerge(const int &left, const int &right)
{
    ///Criterio de paro
        if(left >= right) {
            return;
            }
        int m((left + right) / 2);

        /// Divide y vencerás
        ordenaMerge(left, m);
        ordenaMerge(m + 1, right);

        /// Copia a temporal
        static int temp[100000];

        for(int z(left); z <= right; z++) {
            temp[z] = numeros[z];
        }
        //Intercalacion
        int i(left), j(m + 1), x(left);

        while(i <= m and j <= right) {
            while(i <= m and temp[i] <= temp[j]) {
                numeros[x++] = temp[i++];
            }
            if(i <= m) {
                while(j <= right and temp[j] <= temp[i]) {
                    numeros[x++] = temp[j++];
                }
            }
        }

        while(i <= m) {
            numeros[x++] = temp[i++];
        }
        while(j <= right) {
            numeros[x++] = temp[j++];
        }
}

void Lista::ordenaQuick()
{
    ordenaQuick(0,last);
}

void Lista::ordenaQuick(const int &left, const int &right)
{
    if(left >= right) {
            return;
            }
        int i(left);
        int j(right);

        while(i<j) {
            while( i < j and numeros[i] <= numeros[right]) {
                i++;
                }
            while(i < j and numeros[j] >= numeros[right]) {
                j--;
                }
            if(i != j) {
                swapData(numeros[i],numeros[j]);
                }
            }
        if( i != right) {
            swapData(numeros[i], numeros[right]);
            }

        ///Divide y vencerás
        ordenaQuick(left, i-1);
        ordenaQuick(i+1, right);
}
