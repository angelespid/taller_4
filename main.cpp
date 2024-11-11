#include <iostream>
#include "enrutador.h"

using namespace std;

int main()
{
    Enrutador mienrutador1("A");
    //mienrutador1.encender();
    //mienrutador1.agregarConexion("B",5);
    //mienrutador1.verConexiones();
    mienrutador1.eliminarConexion("B");
    mienrutador1.encender();

    mienrutador1.agregarConexion("B", 5);
    mienrutador1.verConexiones();
    mienrutador1.eliminarConexion("B");
    mienrutador1.verConexiones();



    /*cout << "Hello World!" << endl;*/
    return 0;
}
