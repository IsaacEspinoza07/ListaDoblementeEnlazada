#ifndef LISTA_HPP_INCLUDED
#define LISTA_HPP_INCLUDED

/*
== ATRIBUTOS ==
    - [x] Tamaño de la lista
    - [x] Puntero al ultimo (hasta la derecha en los dibujitos)
    - [x] Puntero al primero (hasta la izquierda en los dibujutos

== CONSTRUCTORES ==
    - [x] Por default
    - [x] Constructor de copias
    - [x] Destructor (importante, pa no dejar memoria por ahi regada)
    - [x] Operador =

== MÉTODOS ==

        === Agregar ===
    - [x] Agregar un elemento al inicio de la lista
    - [x] Agregar un elemento al final de la lista
    - [x] Agregar un elemento en cierta posición (o indice)

        === Eliminar ===
    - [x] Eliminar el elemento del frente
    - [x] Eliminar el elemento del final
    - [x] Eliminar el elemento de cierta posición (o índice)

        === Otros ===
    - [ ] Buscar un valor (creo que es el boleano que dice si está o no)
    - [ ] Buscar la posicion del valor en la lista (La primera ocurrencia)
    - [x] Conocer si esta vacia la lista o no
    - [x] Obtener el primer elemento de la lista
    - [x] Obtener el ultimo elemento de la lista
    - [ ] Obtener el elemento en cierta posición (o indice) de la lista.
    - [x] Vaciar la lista
    - [x] Imprimir la lista (De primero a ultimo: izq a derecha)
    - [ ] Imprimir la lista alreves (De ultimo a primero: derecha a izq)

        === Sobrecargar op ===
    - [ ] Acceder a un elemento de la lista usando []
    - [ ] [] para modificar un elemento
    - [ ] [] para Obtener un elemento

        === Otras indicaciones ===
    - [ ] Eliminar más especificos:
        - [ ] Un eliminar que borre toda ocurrencia de un valor
        - [ ] Un eliminar que borre todo elemento que cumpla cierta condicion
              (recibira un puntero a funcion obviously para la condicion)
        - [ ] Elimina todo elemento repetido (solo dejar una ocurrencia {no indica cual, tonses PREGUNTAR!!!})

    - [ ] Intercambiar una lista con otra (este tampoco... sepa la bola que sea, PREGUNTAR!!!!!!)
    - [ ] Transferir elementos de una lista a otra:
        - [ ] Los elementos desde una posicion hasta otra posicion (o desde un índice a otro)
        - [ ] Los elementos a partir de cierta posicion (o índice)
        - [ ] Todos los elementos
*/


template<typename T>
class Lista{
public:

    // Constructores
    Lista();
    ~Lista();
    Lista(const Lista &l);
    Lista &operator=(const Lista<T> &l);


    // Agregar
    void AgregarAlPrincipio(T valor);
    void AgregarAlFinal(T valor);
    void Agregar(T valor,int indice);

    // Eliminar
    void EliminarAlPrincipio();
    void EliminarAlFinal();
    void Eliminar(int indice);
    void Vaciar();

    bool EstaVacia();
    void Imprimir();

    T ObtenerPrimero();
    T ObtenerUltimo();
    int ObtenerTam();

    // PRUEBAS
    void infoElem(int n);

private:
    int num_elem;

    struct Elemento{
        T valor;
        Elemento *anterior;
        Elemento *siguiente;

        Elemento(T n, Elemento *ant = nullptr, Elemento *sig = nullptr);

    }*primero, *ultimo;


};

#include "Lista.tpp"

#endif // LISTA_HPP_INCLUDED
