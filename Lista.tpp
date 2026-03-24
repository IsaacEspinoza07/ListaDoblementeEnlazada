#include <iostream>
#include <exception>
#include "Lista.hpp"
#include "Condiciones.hpp"

using std::cout, std::endl;

// ===== CONSTRUCTORES ===== //
template<typename T>
Lista<T>::Lista(): num_elem(0), primero(nullptr), ultimo(nullptr) {}

template<typename T>
Lista<T>::~Lista()
{
    Vaciar();
}

template<typename T>
Lista<T>::Lista(const Lista &l): num_elem(0), primero(nullptr), ultimo(nullptr)
{
    *this = l;
}


template<typename T>
Lista<T> &Lista<T>::operator=(const Lista<T> &l)
{
    if(this == &l) return *this;

    Vaciar();

    Elemento *aux = l.primero;
    for(int i = 0; i < l.num_elem; ++i){
        this->AgregarAlFinal(aux->valor);
        aux = aux->siguiente;
    }

    return *this;
}


// Constructor del elemento
template<typename T>
Lista<T>::Elemento::Elemento(T n, Elemento *ant/*= nullptr*/
                                , Elemento *sig/*= nullptr*/): valor(n), anterior(ant),siguiente(sig) {}

// ======= Agregar Elementos ======= //
template<typename T>
void Lista<T>::AgregarAlPrincipio(T valor)
{
    try{
        if(num_elem == 0){
            Elemento *nuevo = new Elemento(valor,nullptr,nullptr);

            primero = nuevo;
            ultimo = nuevo;
        }else{
            Elemento *nuevo = new Elemento(valor, nullptr, primero);
            primero->anterior = nuevo;
            primero = nuevo;
            // El anterior apunta a nullptr, pues para allá se agregan
        }

    ++num_elem;
    }catch(std::bad_alloc &){
        throw "No hay suficiente memoria";
    }

}
// =============== //

template<typename T>
void Lista<T>::AgregarAlFinal(T valor)
{
    try{
        if(num_elem == 0){
            Elemento *nuevo = new Elemento(valor,nullptr,nullptr);
            primero = nuevo;
            ultimo = nuevo;

        }else{
            Elemento *nuevo = new Elemento(valor,ultimo,nullptr);
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
        }

    ++num_elem;
    }catch(std::bad_alloc &){
        throw "No hay suficiente memoria";
    }
}
// =============== //

template<typename T>
void Lista<T>::Agregar(T valor,int indice)
{
    if(indice < 0 || indice > num_elem) throw IndiceExcedente();
    if(indice == 0) AgregarAlPrincipio(valor);
    else if(indice == num_elem) AgregarAlFinal(valor);
    else{
        // Realizamos el recorrido dependiendo de la ubicacion del indice
        Elemento *aux;
        if(indice > num_elem/2){
            aux = ultimo;
            for(int i = num_elem-1; i > indice; --i) aux = aux->anterior;

        }else{
            aux = primero;
            for(int i = 0; i < indice; ++i) aux = aux->siguiente;

        }
        // aqui, aux ya está donde quiero poner mi nuevo elemento
        try{

            Elemento *nuevo = new Elemento(valor,aux->anterior,aux);
            aux->anterior->siguiente = nuevo;
            aux->anterior = nuevo;
            ++num_elem;

        }catch(std::bad_alloc &){
            throw "No hay suficiente memoria";
        }
    }
}
// ======= Eliminar Elementos ======= //
template<typename T>
void Lista<T>::EliminarAlPrincipio()
{
    if(EstaVacia()) throw ListaVacia();
    if(num_elem == 1){
        delete primero;
        primero = nullptr;
        ultimo = nullptr;
    }else{
        Elemento *aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
    --num_elem;
}

// =============================== //
template<typename T>
void Lista<T>::EliminarAlFinal()
{
    if(EstaVacia()) throw ListaVacia();
    if(num_elem == 1){
        delete ultimo;
        primero = nullptr;
        ultimo = nullptr;
    }else {
        Elemento *aux = ultimo;
        ultimo = ultimo->anterior;
        delete aux;
    }
    --num_elem;
}

// =============================== //
template<typename T>
void Lista<T>::Eliminar(int indice)
{
    if(EstaVacia()) throw ListaVacia();
    if(indice < 0 || indice >= num_elem) throw IndiceExcedente();

    if(indice == 0) EliminarAlPrincipio();
    else if(indice == num_elem-1) EliminarAlFinal();
    else{
        // Realizamos el recorrido dependiendo de la ubicacion del indice
        Elemento *aux;
        if(indice > num_elem/2){
            aux = ultimo;
            for(int i = num_elem-1; i > indice; --i) aux = aux->anterior;

        }else{
            aux = primero;
            for(int i = 0; i < indice; ++i) aux = aux->siguiente;

        }
        // aqui, aux ya está donde quiero eliminar
        aux->anterior->siguiente = aux->siguiente;
        aux->siguiente->anterior = aux->anterior;
        delete aux;

        --num_elem;
    }
}

// =============================== //
template<typename T>
void Lista<T>::EliminarOcurrenciaValor(T valor)
{
    if(EstaVacia()) throw ListaVacia();
    Elemento *aux = primero;
    int elemento_encontrado = 0;
    while(aux != nullptr){
        if(aux->valor == valor){
            Eliminar(elemento_encontrado);
            break;
        }
        aux = aux->siguiente;
        ++elemento_encontrado;
    }
    if(elemento_encontrado != num_elem) EliminarOcurrenciaValor(valor);

}

// =============================== //
template<typename T>
void Lista<T>::EliminarCondicion(bool (*Condicion)(T, T), T b)
{
    if(EstaVacia()) throw "La lista est\242 vaci\241";

    Elemento *aux = primero;
    while(aux != nullptr){
        Elemento *siguiente = aux->siguiente;

        if(Condicion(aux->valor,b)){
            if(aux == primero) EliminarAlPrincipio();
            else if(aux == ultimo) EliminarAlFinal();
            else{
                aux->anterior->siguiente = aux->siguiente;
                aux->siguiente->anterior = aux->anterior;
                delete aux;
                --num_elem;
            }

        }
        aux = siguiente;
    }

}

// =============================== //
template<typename T>
void Lista<T>::EliminarRepetidos()
{
    if(EstaVacia()) throw ListaVacia();
    Elemento *auxiliar = primero;
    int elemento_auxiliar = 0;
    while(auxiliar != nullptr){
        Elemento *viajero = auxiliar->siguiente;
        int elemento_viajero = elemento_auxiliar+1;
        while(viajero != nullptr){
            if(viajero->valor == auxiliar->valor){
                Elemento *Siguiente = viajero->siguiente;
                Eliminar(elemento_viajero);
                viajero = Siguiente;
            }
            else{
                viajero = viajero->siguiente;
                ++elemento_viajero;
            }
        }
        auxiliar = auxiliar->siguiente;
        ++elemento_auxiliar;
    }

}

// =============================== //
template<typename T>
void Lista<T>::Vaciar()
{
    if(EstaVacia()) return;
    while(num_elem != 0){
        EliminarAlPrincipio();
    }
}

// =============================== //
template<typename T>
bool Lista<T>::EstaVacia()
{
    return (num_elem == 0) ? true : false;

}

// ======= Impresiones ======== //
template<typename T>
void Lista<T>::Imprimir()
{
    Elemento *explorador = primero;
    for(int i = 0; i < num_elem; ++i){
        cout << explorador->valor << ", ";
        explorador = explorador->siguiente;
    }
    cout << "\b\b \n";

}

template<typename T>
void Lista<T>::ImprimirAlReves()
{
    Elemento *explorador = ultimo;
    for(int i = num_elem-1; i >= 0; --i){
        cout << explorador->valor << ", ";
        explorador = explorador->anterior;
    }
    cout << "\b\b \n";
}

// =============================== //
template<typename T>
T Lista<T>::ObtenerPrimero()
{
    if(EstaVacia()) throw ListaVacia();
    return primero->valor;
}

// =============================== //

template<typename T>
T Lista<T>::ObtenerUltimo()
{
    if(EstaVacia()) throw ListaVacia();
    return ultimo->valor;

}

// =============================== //

template<typename T>
int Lista<T>::ObtenerTam()
{
    return num_elem;

}

// =============================== //
template<typename T>
T Lista<T>::ObtenerElem(int pos)
{
    if(pos < 0 || pos >= num_elem) throw IndiceExcedente();
    Elemento *aux = primero;
    for(int i = 0; i < pos; ++i){
        aux = aux->siguiente;
    }
    return aux->valor;
}

// =============================== //
template<typename T>
T &Lista<T>::operator[](int indice)
{
    if(indice < 0 || indice >= num_elem) throw IndiceExcedente();

    Elemento *aux = primero;
    for(int i = 0; i < indice; ++i){
        aux = aux->siguiente;
    }
    return aux->valor;
}

// =============================== //

template<typename T>
const T &Lista<T>::operator[](int indice) const
{
    if(indice < 0 || indice >= num_elem) throw IndiceExcedente();

    Elemento *aux = primero;
    for(int i = 0; i < indice; ++i){
        aux = aux->siguiente;
    }
    return aux->valor;
}

// =============================== //

template<typename T>
bool Lista<T>::EstaValor(T valor)
{
    Elemento *aux = primero;
    for(int i = 0; i < num_elem; ++i){
        if(aux->valor == valor) return true;
        aux = aux->siguiente;
    }
    return false;
}

// =============================== //
template<typename T>
int Lista<T>::BuscarPos(T valor)
{
    if(EstaVacia()) throw ListaVacia();

    Elemento *aux = primero;
    for(int i = 0; i < num_elem; ++i){
        if(aux->valor == valor) return i;
        aux = aux->siguiente;
    }
    return -1;
}


// ============= PRUEBAS/DEBUG ============= //
template<typename T>
void Lista<T>::infoElem(int n)
{
    Elemento *aux = primero;
    for(int i = 0; i < n; ++i){
        aux = aux->siguiente;
    }
    cout << "ant: " << aux->anterior->valor << endl;
    cout << "checando: " << aux->valor << endl;
    cout << "sig: " << aux->siguiente->valor << endl;

}

// ============= CLASES EXCEPCIONES ============= //
template<typename T>
Lista<T>::ListaVacia::ListaVacia() noexcept {}

template<typename T>
const char* Lista<T>::ListaVacia::what() const noexcept
{
    return "La lista se encuentra vac\241a, no se puede efectuar la operaci\242n.";
}

// =============================== //
template<typename T>
Lista<T>::IndiceExcedente::IndiceExcedente() noexcept {}

template<typename T>
const char* Lista<T>::IndiceExcedente::what() const noexcept
{
    return "El \241ndice sale de los l\241mites del n\240mero de elementos de la lista.";
}
