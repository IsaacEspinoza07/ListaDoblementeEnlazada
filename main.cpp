#include <iostream>
#include "Lista.hpp"

using namespace std;

int main()
{

    try{
    // ================ PROGRAMA =================== //
        Lista<int> l;

        for(int i = 1; i <= 30; ++i){
            l.AgregarAlFinal(i);
        }
        l.Imprimir(); cout << endl;


        l.EliminarAlPrincipio();
        l.Imprimir();

        l.EliminarAlFinal();
        l.Imprimir();

        cout << "\nBorrando en indice 3\n";
        l.Eliminar(3);
        l.Imprimir();

        cout << "El elemento en el indice \'6\' es: " << l.ObtenerElem(6) << endl;

        cout <<"Elemento en pos 2: " << l[2] << endl;

        l.Imprimir();

        l.EliminarCondicion(EsPrimo);

        cout << endl; l.Imprimir();








    // =========================================== //
    }catch(const char* error){
        cerr << "Error: " << error << endl;
    }catch(...){
        cerr << "Ocurrio un error inesperado..." << endl;
    }
    return 0;
}
