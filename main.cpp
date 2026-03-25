#include <iostream>
#include "Lista.hpp"


using namespace std;

int main()
{

    try{
    // ================ PROGRAMA =================== //
        Lista<int> pares, impares;

    // =========================================== //
    }catch(const char* error){
        cerr << "Error: " << error << endl;
    }catch(...){
        cerr << "Ocurrio un error inesperado..." << endl;
    }
    return 0;
}
