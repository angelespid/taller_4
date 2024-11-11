#ifndef RED_H
#define RED_H
#include "enrutador.h"
#include <map>  // Para almacenar enrutadores por identificador
#include <string>
#include <iostream>
using namespace std;

class Red
{
private:
private:
    map<string, Enrutador> enrutadores;  // Mapa de enrutadores identificados por su ID
public:
    Red();
};

#endif // RED_H
