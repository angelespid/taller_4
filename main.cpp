#include <iostream>
#include "enrutador.h"
#include "red.h"

using namespace std;

int main()
{
    Enrutador mienrutador1("A");
    //mienrutador1.encender();
    //mienrutador1.agregarConexion("B",5);
    //mienrutador1.verConexiones();
    /*mienrutador1.eliminarConexion("B");
    mienrutador1.encender();

    mienrutador1.agregarConexion("B", 5);
    mienrutador1.verConexiones();
    mienrutador1.eliminarConexion("B");
    mienrutador1.verConexiones();*/

    Red red;
    red.agregarEnrutador("A");
    red.agregarEnrutador("B");
    red.conectarEnrutadores("A", "B", 10);  // Prueba de conexión
    red.conectarEnrutadores("A", "C", 15);  // Prueba de conexión con enrutador no existente
    red.verRed();

    cout << "Hello World!" << endl;
    return 0;
}
