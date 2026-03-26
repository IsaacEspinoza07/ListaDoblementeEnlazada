/** \file Lista.tpp
 *  En este archivo se encuentran la implementaci&oacute;n de la clase 'Lista', con sus m&eacute;todos, estructuras y utilidades necesarias para su buena funci&oacute;n.
 *
 * \authors Angulo Gil, David Armando
        Espinoza Hern&aacute;ndez, Isaac
 * \date 25/03/2026

 \code {.cpp}

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

            cout << "El elemento en \'6\' hay: " << l.ObtenerElem(7) << endl;

            cout <<"Elemento en pos 2: " << l[2] << endl;

            l.Imprimir();
            l.EliminarCondicion(MenorOIgual<int>, 18);
            l.Imprimir();

            l.EliminarCondicion(EsPrimo);




        // =========================================== //
        }catch(const char* error){
            cerr << "Error: " << error << endl;
        }catch(...){
            cerr << "Ocurrio un error inesperado..." << endl;
        }
        return 0;
    }
 \endcode
 */
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
    - [x] Buscar un valor (creo que es el boleano que dice si está o no)
    - [x] Buscar la posicion del valor en la lista (La primera ocurrencia)
    - [x] Conocer si esta vacia la lista o no
    - [x] Obtener el primer elemento de la lista
    - [x] Obtener el ultimo elemento de la lista
    - [x] Obtener el elemento en cierta posición (o indice) de la lista.
    - [x] Vaciar la lista
    - [x] Imprimir la lista (De primero a ultimo: izq a derecha)
    - [x] Imprimir la lista alreves (De ultimo a primero: derecha a izq)

        === Sobrecargar op ===
    - [x] Acceder a un elemento de la lista usando []
    - [x] [] para modificar un elemento
    - [x] [] para Obtener un elemento

        === Otras indicaciones ===
    - [x] Eliminar más especificos:
        - [x] Un eliminar que borre toda ocurrencia de un valor
        - [x] Un eliminar que borre todo elemento que cumpla cierta condicion
              (recibira un puntero a funcion obviously para la condicion)
        - [x] Elimina todo elemento repetido (solo dejar una ocurrencia {no indica cual, tonses PREGUNTAR!!!})

    - [ ] Intercambiar una lista con otra (este tampoco... sepa la bola que sea, PREGUNTAR!!!!!!)
    - [ ] Transferir elementos de una lista a otra:
        - [ ] Los elementos desde una posicion hasta otra posicion (o desde un índice a otro)
        - [ ] Los elementos a partir de cierta posicion (o índice)
        - [ ] Todos los elementos
*/


/**
 * Plantilla de clase 'Lista', aplicando la metodolog&iacute;a de Lista Enlazada Doble.
 *
 */
template<typename T>
class Lista{
public:

    // Constructores
    /** \brief Constructor por default de la clase 'Lista', aplicando como lista enlazada doble.
     *
     *
     */
    Lista();
    /** \brief Destructor de la clase 'Lista'.
     *
     *
     */
    ~Lista();
    /** \brief Constructor de copias de la clase 'Lista'.
     *
     * \param l Lista a copiar
     *
     */
    Lista(const Lista &l);
    /** \brief Sobrecarga del operador de asignaci&oacute;n para la clase 'Lista'.
     *
     * \param l Lista a asignar.
     * \return Lista copiada mediante la asignaci&oacute;n.
     *
     */
    Lista &operator=(const Lista<T> &l);


    // Agregar
    /** \brief M&eacute;todo que agrega un elemento al principio de la lista.
     *
     *
     * \param valor Valor a asignar en el nuevo elemento.
     * \return Nada
     *
     * \warning Advertencia: Si el sistema no tiene m&aacute;s memoria para asignar, el programa tirar&aacute; un error.
     * \throw std::bad_alloc.
     */
    void AgregarAlPrincipio(T valor);
    /** \brief M&eacute;todo que agrega un elemento al final de la lista.
     *
     *
     * \param valor Valor a asignar en el nuevo elemento.
     * \return Nada
     *
     * \warning Advertencia: Si el sistema no tiene m&aacute;s memoria para asignar, el programa tirar&aacute; un error.
     * \throw std::bad_alloc.
     */
    void AgregarAlFinal(T valor);
    /** \brief M&eacute;todo que agrega un elemento en cualquier &iacute;ndice de la lista.
     *
     *
     * \param valor Valor a asignar en el nuevo elemento.
     * \param indice Indice en el cual agregar el nuevo elemento.
     * \return Nada
     *
     * \warning Advertencia: Si se ingresa un &iacute;ndice menor a 0 o mayor/igual al n&uacute;mero de elementos, el programa no aceptar&aacute; el &iacute;ndice puesto por el usuario, a lo cual tirar&aacute; un error.
     * \warning Advertencia: Si el sistema no tiene m&aacute;s memoria para asignar, el programa tirar&aacute; un error.
     * \throw IndiceExcedente y std::bad_alloc.
     * \see IndiceExcedente
     */
    void Agregar(T valor,int indice);

    // Eliminar
    /** \brief M&eacute;todo que elimina el primer elemento de la lista.
     *
     * \return Nada
     *
     * \warning Advertencia: Si la lista esta vac&iacute;a, no se puede realizar el m&eacute;todo, pues no hay que eliminar, a lo cual el programa tirar&aacute; un error.
     * \throw ListaVacia
     * \see ListaVacia
     */
    void EliminarAlPrincipio();
    /** \brief M&eacute;todo que elimina el &uacute;ltimo elemento de la lista.
     *
     * \return Nada
     *
     * \warning Advertencia: Si la lista esta vac&iacute;a, no se puede realizar el m&eacute;todo, pues no hay que eliminar, a lo cual el programa tirar&aacute; un error.
     * \throw ListaVacia
     * \see ListaVacia
     */
    void EliminarAlFinal();
    /** \brief M&eacute;todo que elimina el elemento espec&iacute;ficado por el usuario de la lista.
     *
     * \param indice Indice del cual eliminar el elemento.
     * \return Nada
     *
     * \warning Advertencia: Si la lista esta vac&iacute;a, no se puede realizar el m&eacute;todo, pues no hay que eliminar, a lo cual el programa tirar&aacute; un error.
     * \warning Advertencia: Si se ingresa un &iacute;ndice menor a 0 o mayor/igual al n&uacute;mero de elementos, el programa no aceptar&aacute; el &iacute;ndice puesto por el usuario, a lo cual tirar&aacute; un error.
     * \throw ListaVacia y IndiceExcedente
     * \see ListaVacia, IndiceExcedente
     */
    void Eliminar(int indice);
    /** \brief M&eacute;todo que vac&iacute;a la lista entera.
     *
     * \return Nada
     *
     */
    void Vaciar();

    /** \brief M&eacute;todo que verifica si la lista esta vac&iacute;a.
     *
     * \return El resultado, aclarando si esta vac&iacute;a o no.
     *
     */
    bool EstaVacia();

    /** \brief M&eacute;todo que imprime la lista.
     *
     * \return Nada
     *
     */
    void Imprimir();

    /** \brief .atsil al emirpmi euq odot;etucae&M
     *
     * \return Nada
     *
     */
    void ImprimirAlReves();

    /** \brief M&eacute;todo que obtiene el valor en el primer elemento de la lista.
     *
     * \tparam T Tipo de valor asignado por el usuario para la lista.
     * \return El valor en el primer elemento de la lista.
     *
     */
    T ObtenerPrimero();

    /** \brief M&eacute;todo que obtiene el valor en el &uacute;ltimo elemento de la lista.
     *
     * \tparam T Tipo de valor asignado por el usuario para la lista.
     * \return El valor en el &uacute;ltimo elemento de la lista.
     *
     */
    T ObtenerUltimo();

    /** \brief M&eacute;todo que obtiene el valor en el elemento aclarado por el usuario de la lista.
     *
     * \param pos &Iacute;ndice en la cual se encuentra el elemento a solicitar.
     * \tparam T Tipo de valor asignado por el usuario para la lista.
     * \return El valor en el elemento aclarado por el usuario de la lista.
     * \warning Advertencia: Si se ingresa un &iacute;ndice menor a 0 o mayor/igual al n&uacute;mero de elementos, el programa no aceptar&aacute; el &iacute;ndice puesto por el usuario, a lo cual tirar&aacute; un error.
     * \throw IndiceExcedente
     * \see IndiceExcedente
     */
    T ObtenerElem(int pos);

    /** \brief M&eacute;todo que devuelve el n&uacute;mero de elementos en la lista.
     *
     * \return N&uacute;mero de elementos en la lista.
     *
     */
    int ObtenerTam();

    // Busqueda de valores
    /** \brief Sobrecarga de los corchetes para el acceso a elementos de la lista y la escritura sobre ellos.
     *
     * \param indice &Iacute;ndice en la cual se encuentra el elemento a solicitar.
     * \return El valor encontrado en el &iacute;ndice.
     *
     * \warning Advertencia: Si se ingresa un &iacute;ndice menor a 0 o mayor/igual al n&uacute;mero de elementos, el programa no aceptar&aacute; el &iacute;ndice puesto por el usuario, a lo cual tirar&aacute; un error.
     * \throw IndiceExcedente
     * \see IndiceExcedente
     *
     */
    T& operator[](int indice); // L-value, escritura.

    /** \brief Sobrecarga de los corchetes para el acceso a elementos de la lista y la escritura sobre ellos.
     *
     * \param indice &Iacute;ndice en la cual se encuentra el elemento a solicitar.
     * \return El valor encontrado en el &iacute;ndice.
     *
     * \warning Advertencia: Si se ingresa un &iacute;ndice menor a 0 o mayor/igual al n&uacute;mero de elementos, el programa no aceptar&aacute; el &iacute;ndice puesto por el usuario, a lo cual tirar&aacute; un error.
     * \throw IndiceExcedente
     * \see IndiceExcedente
     *
     */
    const T &operator[](int indice) const; // R-value, lectura (por el const).

    /** \brief M&eacute;todo que verifica si el valor dado por el usuario se encuentra en la lista.
     *
     * \param valor El valor a buscar en la lista.
     * \return Si se encuentra el valor en alg&uacute;n elemento de la lista.
     *
     */
    bool EstaValor(T valor);
    /** \brief M&eacute;todo que busca la posici&oacute;n de un valor espec&iacute;fico, si se encuentra este valor m&uacute;ltiples veces, el m&eacute;todo solo regresa la primera posici&oacute;n.
     *
     * \param valor Valor al cual buscarle la posici&oacute;n.
     * \return Posici&oacute;n del valor en la lista.
     *
     */
    int BuscarPos(T valor);

    /** \brief M&eacute;todo que elimina todas las ocurrencias de un valor espec&iacute;fico
     *
     * \param valor Valor al cual borrar todas sus ocurrencias.
     * \return Nada
     *
     */
    void EliminarOcurrenciaValor(T valor);

    /** \brief Elimina todos los elementos que cumplan con una condici&oacute;n, esta condici&oacute;n depende de otra funci&oacute;n dependiendo que quiera el usuario.
     *
     * \param Puntero a funci&oacute;n, que recibe dos par&aacute;metros y devuelve un booleano.
     * \param b Alg&uacute;n otro valor del cual depende la condici&oacute;n
     * \return Nada
     *
     */
    void EliminarCondicion(bool (*Condicion)(T, T),T b);

    /** \brief Elimina todos los elementos que cumplan con una condici&oacute;n, esta condici&oacute;n depende de otra funci&oacute;n dependiendo que quiera el usuario.
     *
     * \param Puntero a funci&oacute;n, que recibe un par&aacute;metro y devuelve un booleano.
     * \return Nada
     *
     */
    void EliminarCondicion(bool (*Condicion)(T));

    /** \brief M&eacute;todo que elimina todas las repeticiones de cualquier valor en la lista.
     *
     * \return Nada
     *
     */
    void EliminarRepetidos();

    // Otros
    /** \brief M&eacute;todo que intercambia los elementos de una lista con los de otra lista.
     *
     * \param l Lista con la cual intercambiar los elementos.
     * \return Nada
     *
     */
    void IntercambiarCon(Lista &l);

    /** \brief M&eacute;todo con el cual se pueden transferir elementos de una lista a otra.
     *
     * \param l Lista de la cual tomar los elementos.
     * \param i Primer &iacute;ndice del cual se empieza a tomar los elementos.
     * \param j &Uacute;ltimo &iacute;ndice del cual se termina de tomar los elementos.
     * \return Nada
     *
     */
    void TransferirElementos(Lista<T> &l, int i, int j); // Los que esten entre el indice i y el indice j.

    /** \brief M&eacute;todo con el cual se pueden transferir elementos de una lista a otra, desde cierto elemento hasta el final.
     *
     * \param l Lista de la cual tomar los elementos.
     * \param i Primer &iacute;ndice del cual se empieza a tomar los elementos.
     * \return Nada
     *
     */
    void TransferirElementos(Lista<T> &l, int i); // Desde el indice i hasta el final.

    /** \brief M&eacute;todo con el cual se pueden transferir todos los elementos de una lista a otra.
     *
     * \param l Lista de la cual tomar los elementos.
     * \return Nada
     *
     */
    void TransferirElementos(Lista<T> &l); // Transferir todos.

    // PRUEBAS

    /**
     * Subclase ListaVacia para el manejo de excepciones
     */
    class ListaVacia : public std::exception
    {
        public:
            ListaVacia() noexcept;
            virtual const char* what() const noexcept;

        private:
            const char* mensaje;
    } ;

    /**
     * Subclase IndiceExcedente para el manejo de excepciones
     */
    class IndiceExcedente : public std::exception
    {
        public:
            IndiceExcedente() noexcept;
            virtual const char* what() const noexcept;

        private:
            const char* mensaje;
    };

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
