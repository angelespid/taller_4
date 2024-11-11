#ifndef ENRUTADOR_H
#define ENRUTADOR_H

#include <vector>
#include <set>
#include <string>
#include <iostream>

using namespace std;

class Enrutador
{
private:
    bool estadoEncendido;
    string id;  // Identificador único del enrutador
    set<pair<string, int>> conexiones;  // Lista de conexiones (enrutador, costo)

public:
    Enrutador(string id);
    void agregarConexion(const string& destino, int costo);
    void eliminarConexion(const string& destino);  // Elimina una conexión específica
    bool existeConexion(const string& destino) const;
    void verConexiones() const;
    int obtenerCosto(const string& destino) const;

    // Métodos para manejar el estado del enrutador
    void encender();
    void apagar();
    bool estadoOn() const;
};

#endif // ENRUTADOR_H
