#include "red.h"

Red::Red() {}

void Red::agregarEnrutador(const string &id)
{
    if (enrutadores.find(id) != enrutadores.end()) {
        cout << "El enrutador " << id << " ya existe en la red." << endl;
        return;
    }
    enrutadores.emplace(id, Enrutador(id));  // Inserta un nuevo enrutador en el mapa
    cout << "Enrutador " << id << " agregado a la red." << endl;
}

void Red::eliminarEnrutador(const string &id)
{
    if (enrutadores.erase(id)) {
        cout << "Enrutador " << id << " eliminado de la red." << endl;
    } else {
        cout << "Enrutador " << id << " no encontrado en la red." << endl;
    }
}

void Red::conectarEnrutadores(const string &id1, const string &id2, int costo)
{
    // Verifica que ambos enrutadores existan en la red antes de intentar conectarlos
    auto it1 = enrutadores.find(id1);
    auto it2 = enrutadores.find(id2);

    if (it1 == enrutadores.end() || it2 == enrutadores.end()) {
        cout << "Uno o ambos enrutadores no se encuentran en la red." << endl;
        return;
    }

    // Agregar conexiones de forma bidireccional si no existen ya
    if (!it1->second.existeConexion(id2)) {
        it1->second.agregarConexion(id2, costo);
        cout << "Conexión agregada: " << id1 << " -> " << id2 << " con costo " << costo << endl;
    } else {
        cout << "La conexión ya existe entre " << id1 << " y " << id2 << "." << endl;
    }

    if (!it2->second.existeConexion(id1)) {
        it2->second.agregarConexion(id1, costo);
        cout << "Conexión agregada: " << id2 << " -> " << id1 << " con costo " << costo << endl;
    }
}

/*
void Red::conectarEnrutadores(const string &id1, const string &id2, int costo)
{
    if (enrutadores.find(id1) == enrutadores.end() || enrutadores.find(id2) == enrutadores.end()) {
        cout << "Uno o ambos enrutadores no se encuentran en la red." << endl;
        return;
    }

    // Imprimir los enrutadores que se van a conectar
    cout << "Conectando " << id1 << " con " << id2 << " con costo " << costo << "." << endl;

    enrutadores[id1].agregarConexion(id2, costo);
    enrutadores[id2].agregarConexion(id1, costo); // Conexión bidireccional
    cout << "Conexión establecida entre " << id1 << " y " << id2 << " con costo " << costo << "." << endl;
}
*/
void Red::verRed() const
{
    for (const auto& [id, enrutador] : enrutadores) {
        cout << "Enrutador: " << id << endl;
        enrutador.verConexiones();
    }
}
