#include <iostream>
#include "Lista.hpp"


using namespace std;

int main()
{

    try{
    // ================ PROGRAMA =================== //
        Lista<int> l1,l2;

        for(int i = 0; i < 20; ++i){
            if(i%2 == 0) l1.AgregarAlFinal(i);
            else l2.AgregarAlFinal(i);
        }

        cout << "l1: ";
        l1.Imprimir();

        cout << "l2: ";
        l2.Imprimir();

        l1.TransferirElementos(l2,0,2);

        cout << "l1: ";
        l1.Imprimir();

        cout << "l2: ";
        l2.Imprimir();

        l1.TransferirElementos(l2,2);

        cout << "l1: ";
        l1.Imprimir();

        cout << "l2: ";
        l2.Imprimir();

        l2.TransferirElementos(l1);

        cout << "l1: ";
        l1.Imprimir();

        cout << "l2: ";
        l2.Imprimir();



    // =========================================== //
    }catch(const char* error){
        cerr << "Error: " << error << endl;
    }catch(...){
        cerr << "Ocurrio un error inesperado..." << endl;
    }
    return 0;
}
