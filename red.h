#ifndef RED_H
#define RED_H
#include "enrutador.h"
#include <map>
#include <string>
#include <iostream>

class Red
{
private:
private:
    map<string, Enrutador> enrutadores;  // Mapa de enrutadores identificados por su ID

public:

    Red();  // Constructor
    void agregarEnrutador(const string& id);
    void eliminarEnrutador(const string& id);
    void conectarEnrutadores(const string& id1, const string& id2, int costo);
    void verRed() const;
};

#endif // RED_H
