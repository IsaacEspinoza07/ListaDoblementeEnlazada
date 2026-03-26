/**
 * \file  Menu.hpp
 * Se encuentra las funciones necesarias para el funcionamiento del men&uacute;.
 * \author Angulo Gil, David Armando
        Espinoza Hern&aacute;ndez, Isaac
 * \date 25/03/2026
 */
#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include "Lista.hpp"
#include "CapturaSegura.hpp"

/** \brief Funci&oacute;n que limpia la consola.
 *
 * \return Nada
 *
 */
void LimpiarConsola();

/** \brief Funci&oacute;n que pausa la consola hasta que el usuario le de Enter.
 *
 * \return Nada
 *
 */
void Pausar();

/** \brief Funci&oacute;n que imprime el estado actual de la lista.
 *
 * \param l Lista a imprimir.
 * \param nombre Nombre de la lista.
 * \return Nada
 *
 */
void ImprimirEstado(Lista<int> &l, const char* nombre);


/** \brief Funci&oacute;n para entrar al men&uacute; con los m&eacute;todos que permiten agregar elementos a la lista.
 *
 * \param l Lista manejada por el usuario.
 * \return Nada
 */
void MenuAgregar    (Lista<int> &l);

/** \brief Funci&oacute;n para entrar al men&uacute; con los m&eacute;todos que permiten eliminar elementos a la lista.
 *
 * \param l Lista manejada por el usuario.
 * \return Nada
 */
void MenuEliminar   (Lista<int> &l);

/** \brief Funci&oacute;n para entrar al men&uacute; con los m&eacute;todos que permiten obtener el valor de elementos a la lista.
 *
 * \param l Lista manejada por el usuario.
 * \return Nada
 */
void MenuObtener    (Lista<int> &l);
/** \brief Funci&oacute;n para entrar al men&uacute; con los m&eacute;todos que permiten imprimir la lista.
 *
 * \param l Lista manejada por el usuario.
 * \return Nada
 */
void MenuImprimir   (Lista<int> &l);

/** \brief Funci&oacute;n para entrar al men&uacute; con los m&eacute;todos que permiten transferir elementos de una lista a otra.
 *
 * \param l Lista manejada por el usuario.
 * \return Nada
 */
void MenuTransferir (Lista<int> &l1, Lista<int> &l2);

#endif // MENU_HPP_INCLUDED
