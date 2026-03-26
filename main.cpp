#include <iostream>
#include "Lista.hpp"
#include "Menu.hpp"

using namespace std;

int main()
{
    Lista<int> l1, l2;
    int op;

    // Programa!!
    do {
        LimpiarConsola();
        cout << "===== Estado de las Listas =====\n";
        ImprimirEstado(l1, "L1");
        ImprimirEstado(l2, "L2");
        cout << "================================\n\n";
        cout << "1. Agregar    (L1)\n";
        cout << "2. Eliminar   (L1)\n";
        cout << "3. Obtener    (L1)\n";
        cout << "4. Imprimir   (L1)\n";
        cout << "5. Transferir (L1 -> L2)\n";
        cout << "6. Intercambiar L1 y L2\n";
        cout << "7. L2 = L1 (copia)\n";
        cout << "8. Agregar    (L2)\n";
        cout << "9. Eliminar   (L2)\n";
        cout << "10. Imprimir  (L2)\n";
        cout << "\n0. Salir\n";
        CapturaSegura(op, "Opcion: ");

        LimpiarConsola();
        cout << "===== Estado de las Listas =====\n";
        ImprimirEstado(l1, "L1");
        ImprimirEstado(l2, "L2");
        cout << "================================\n";


        switch(op){
            case 1:
                MenuAgregar(l1);
                break;

            case 2:
                MenuEliminar(l1);

                break;
            case 3:
                MenuObtener(l1);

                break;
            case 4:
                MenuImprimir(l1);

                break;
            case 5:
                MenuTransferir(l1, l2);

                break;
            case 6:
                l1.IntercambiarCon(l2);
                cout << "Intercambiadas.\n";
                break;

            case 7:
                l2 = l1;
                cout << "L2 = copia de L1.\n";

                break;
            case 8:
                MenuAgregar(l2);
                break;

            case 9:
                MenuEliminar(l2);
                break;

            case 10:
                MenuImprimir(l2);
                break;

            case 0: // pa salirme
                break;
            default: cout << "Opcion invalida.\n";
        }

        if(op != 0) Pausar();

    } while(op != 0);
    // acaba el programa.
    LimpiarConsola();
    cout << "Bye bye...........................................\n\n";
    return 0;
}
