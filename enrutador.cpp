#include "enrutador.h"

Enrutador::Enrutador(string id) :id(id),estadoEncendido(false){


}

void Enrutador::agregarConexion(const string &destino, int costo)
{for (const auto& conexion : conexiones) {
        if (conexion.first == destino) {
            cout << "La conexión con " << destino << " ya existe. No se ha modificado." << endl;
            return;
        }
    }
    conexiones.insert(make_pair(destino, costo));
    cout << "Conexión agregada: " << id << " -> " << destino << " con costo " << costo << endl;

    //funcional pero con la clase red no funciona
    /*if (!estadoEncendido)

        {
            cout << "El enrutador " << id << " está apagado. Por favor, encienda el dispositivo para agregar una conexión." << endl;
            return; // Sale de la función si el enrutador está apagado
        }
    conexiones.push_back(make_pair(destino, costo));*/
}

void Enrutador::eliminarConexion(const string &destino)
{
    if (!estadoEncendido) {
        cout << "El enrutador " << id << " está apagado. Por favor, encienda el dispositivo para eliminar una conexión." << endl;
        return; // Sale de la función si el enrutador está apagado
    }
    for (auto it = conexiones.begin(); it != conexiones.end(); ++it) {
        if (it->first == destino) {
            conexiones.erase(it);
            cout << "Conexion con " << destino << " eliminada." << endl;
            return;
        }
    }
    cout << "Conexion con " << destino << " no encontrada." << endl;
}

void Enrutador::verConexiones() const
{
    if (conexiones.empty()) {
        cout << "El enrutador " << id << " no tiene conexiones." << endl;
        return;
    }
    cout << "Conexiones de enrutador " << id << ":" << endl;
    for (const auto& conexion : conexiones) {
        cout << " - " << conexion.first << " con costo " << conexion.second << endl;
    }
}

int Enrutador::obtenerCosto(const string &destino) const
{
    for (const auto& conexion : conexiones) {
        if (conexion.first == destino) {
            return conexion.second;
        }
    }
    return -1; // Indica que no se encontró la conexión
}

void Enrutador::encender() {
    estadoEncendido = true;
    cout << "El enrutador " << id << " ha sido encendido." << endl;
}

void Enrutador::apagar() {
    estadoEncendido = false;
    cout << "El enrutador " << id << " ha sido apagado." << endl;
}

bool Enrutador::estadoOn() const {
    return estadoEncendido;
}
bool Enrutador::existeConexion(const string& destino) const {
    for (const auto& conexion : conexiones) {
        if (conexion.first == destino) {
            return true;
        }
    }
    return false;
}
