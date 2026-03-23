#include <iostream>
#include "Lista.hpp"

using namespace std;

int main()
{

    try{
    // ================ PROGRAMA =================== //
        Lista<int> l;

        for(int i = 1; i <= 15; ++i){
            l.Agregar(2*i,i-1);
        }
        l.Imprimir(); cout << endl;


        l.EliminarAlPrincipio();
        l.Imprimir();

        l.EliminarAlFinal();
        l.Imprimir();

        cout << "\nBorrando en indice 3\n";
        l.Eliminar(3);
        l.Imprimir();








    // =========================================== //
    }catch(const char* error){
        cerr << "Error: " << error << endl;
    }catch(...){
        cerr << "Ocurrio un error inesperado..." << endl;
    }
    return 0;
}
