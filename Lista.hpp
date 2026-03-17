#ifndef LISTA_HPP_INCLUDED
#define LISTA_HPP_INCLUDED

/*
== ATRIBUTOS ==
    - [ ] Tamaño de la lista
    - [ ] Puntero al ultimo (hasta la derecha en los dibujitos)
    - [ ] Puntero al primero (hasta la izquierda en los dibujutos

== CONSTRUCTORES ==
    - [ ] Por default
    - [ ] Constructor de copias
    - [ ] Destructor (importante, pa no dejar memoria por ahi regada)
    - [ ] Operador =

== MÉTODOS ==

        === Agregar ===
    - [ ] Agregar un elemento al inicio de la lista
    - [ ] Agregar un elemento al final de la lista
    - [ ] Agregar un elemento en cierta posición (o indice)

        === Eliminar ===
    - [ ] Eliminar el elemento del frente
    - [ ] Eliminar el elemento del final
    - [ ] Eliminar el elemento de cierta posición (o índice)

        === Otros ===
    - [ ] Buscar un valor (creo que es el boleano que dice si está o no)
    - [ ] Buscar la posicion del valor en la lista (La primera ocurrencia)
    - [ ] Conocer si esta vacia la lista o no
    - [ ] Obtener el primer elemento de la lista
    - [ ] Obtener el ultimo elemento de la lista
    - [ ] Obtener el elemento en cierta posición (o indice) de la lista.
    - [ ] Vaciar la lista
    - [ ] Imprimir la lista (De primero a ultimo: izq a derecha)
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


private:
    int num_elem;

    struct Elemento{
        T valor;
        Elemento *siguiente;
        Elemento *anterior;

    }*frente, *ultimo;


};

#endif // LISTA_HPP_INCLUDED
