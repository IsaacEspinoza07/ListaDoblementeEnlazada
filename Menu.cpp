#include <iostream>
#include "Menu.hpp"
#include "Condiciones.hpp"

using std::cout, std::cin, std::cerr;

// ===== Utilidades ===== //

void LimpiarConsola()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Pausar()
{
#ifdef _WIN32
    system("pause");
#else
    // en español, aca bien perrrrronson.
    cout << "Presiona Enter para continuar...";
    cin.ignore();
    cin.get();
#endif
}

void ImprimirEstado(Lista<int> &l, const char* nombre)
{
    cout << nombre << ": ";
    if(l.EstaVacia())
        cout << "Vacia...";
    else
        l.Imprimir();
    cout << "  (num_elem=" << l.ObtenerTam() << ")\n";
}

// Esta perron mandar cosas al preprocesador. los \ son pa decir que hay otra linea abajo

#define CATCH_LISTA \
    catch(const Lista<int>::ListaVacia &error){  \
        cerr << "Error: " << error.what() << "\n"; \
    }catch(const Lista<int>::IndiceExcedente &error){ \
        cerr << "Error: " << error.what() << "\n"; \
    }catch(const char* error){ \
        cerr << "Error: " << error << "\n"; \
    }catch(...){ \
        cerr << "Ocurrio un error inesperado..." << "\n"; \
    }

// ===== Agregar ===== //

void MenuAgregar(Lista<int> &l)
{
    int op, val, idx;
    CapturaSegura(op,
        "\n-- AGREGAR --\n"
        "1. Al principio\n"
        "2. Al final\n"
        "3. En indice\n"
        "Opcion: ");
    CapturaSegura(val, "Valor: ");

    try{
        switch(op){
            case 1: l.AgregarAlPrincipio(val); break;
            case 2: l.AgregarAlFinal(val);     break;
            case 3:
                CapturaSegura(idx, "Indice: ");
                l.Agregar(val, idx);
                break;
            default: cout << "Opcion invalida.\n"; return;
        }
        cout << "Listo.\n";
    }
    CATCH_LISTA
}

// ===== Eliminar ===== //

void MenuEliminar(Lista<int> &l)
{
    int op;
    CapturaSegura(op,
        "\n-- ELIMINAR --\n"
        "1. Al principio\n"
        "2. Al final\n"
        "3. En indice\n"
        "4. Todas las ocurrencias de un valor\n"
        "5. Por condicion binaria (Mayor que X)\n"
        "6. Por condicion unaria (EsPar)\n"
        "7. Repetidos\n"
        "8. Vaciar\n"
        "Opcion: ");

    try{
        switch(op){
            case 1: l.EliminarAlPrincipio(); cout << "Listo.\n"; break;
            case 2: l.EliminarAlFinal();     cout << "Listo.\n"; break;
            case 3:{
                int idx; CapturaSegura(idx, "Indice: ");
                l.Eliminar(idx);
                cout << "Listo.\n";
                break;
            }
            case 4:{
                int val; CapturaSegura(val, "Valor: ");
                l.EliminarOcurrenciaValor(val);
                cout << "Listo.\n";
                break;
            }
            case 5:{
                int b; CapturaSegura(b, "Eliminar mayores que: ");
                l.EliminarCondicion(Mayor<int>, b);
                cout << "Listo.\n";
                break;
            }
            case 6:
                l.EliminarCondicion(EsPar);
                cout << "Pares eliminados.\n";
                break;
            case 7:
                l.EliminarRepetidos();
                cout << "Repetidos eliminados.\n";
                break;
            case 8:
                l.Vaciar();
                cout << "Lista vaciada.\n";
                break;
            default: cout << "Opcion invalida.\n"; return;
        }
    }
    CATCH_LISTA
}

// ===== Obtener / Buscar ===== //

void MenuObtener(Lista<int> &l)
{
    int op;
    CapturaSegura(op,
        "\n-- OBTENER / BUSCAR --\n"
        "1. Primer elemento\n"
        "2. Ultimo elemento\n"
        "3. Elemento en indice\n"
        "4. Esta un valor?\n"
        "5. Posicion de un valor\n"
        "6. Leer con []\n"
        "7. Escribir con []\n"
        "Opcion: ");

    try{
        switch(op){
            case 1: cout << "Primero: " << l.ObtenerPrimero() << "\n"; break;
            case 2: cout << "Ultimo: "  << l.ObtenerUltimo()  << "\n"; break;
            case 3:{
                int idx; CapturaSegura(idx, "Indice: ");
                cout << "elem[" << idx << "] = " << l.ObtenerElem(idx) << "\n";
                break;
            }
            case 4:{
                int val; CapturaSegura(val, "Valor: ");
                cout << (l.EstaValor(val) ? "Si esta.\n" : "No esta.\n");
                break;
            }
            case 5:{
                int val; CapturaSegura(val, "Valor: ");
                int pos = l.BuscarPos(val);
                if(pos == -1) cout << "No encontrado.\n";
                else          cout << "Posicion: " << pos << "\n";
                break;
            }
            case 6:{
                int idx; CapturaSegura(idx, "Indice: ");
                cout << "l[" << idx << "] = " << l[idx] << "\n";
                break;
            }
            case 7:{
                int idx, val;
                CapturaSegura(idx, "Indice: ");
                CapturaSegura(val, "Nuevo valor: ");
                l[idx] = val;
                cout << "Actualizado.\n";
                break;
            }
            default: cout << "Opcion invalida.\n"; return;
        }
    }
    CATCH_LISTA
}

// ===== Imprimir ===== //

void MenuImprimir(Lista<int> &l)
{
    if(l.EstaVacia()){ cout << "Lista vacia.\n"; return; }

    int op;
    CapturaSegura(op,
        "\n-- IMPRIMIR --\n"
        "1. Izquierda a derecha\n"
        "2. Derecha a izquierda\n"
        "Opcion: ");

    switch(op){
        case 1: l.Imprimir();        break;
        case 2: l.ImprimirAlReves(); break;
        default: cout << "Opcion invalida.\n";
    }
}

// ===== Transferir ===== //

void MenuTransferir(Lista<int> &l1, Lista<int> &l2)
{
    int op;
    CapturaSegura(op,
        "\n-- TRANSFERIR (L1 -> L2) --\n"
        "1. De indice i a indice j\n"
        "2. Desde indice i hasta el final\n"
        "3. Todos\n"
        "Opcion: ");

    try{
        switch(op){
            case 1:{
                int i, j;
                CapturaSegura(i, "i: ");
                CapturaSegura(j, "j: ");
                l1.TransferirElementos(l2, i, j);
                break;
            }
            case 2:{
                int i; CapturaSegura(i, "i: ");
                l1.TransferirElementos(l2, i);
                break;
            }
            case 3:
                l1.TransferirElementos(l2);
                break;
            default: cout << "Opcion invalida.\n"; return;
        }
        cout << "Transferencia completa.\n";
    }
    CATCH_LISTA
}
