/**
 * \file  Menu.hpp
 * Se encuentra las funciones condicionales para el m&eacute;todo de eliminar con condici&oacute;n.
 * \author Angulo Gil, David Armando
        Espinoza Hern&aacute;ndez, Isaac
 * \date 25/03/2026
 */
#ifndef CONDICIONES_HPP_INCLUDED
#define CONDICIONES_HPP_INCLUDED

template<typename T>
/** \brief Funci&oacute;n que dice si un valor es mayor que otro, una de las funciones para la condici&oacute;n de eliminar.
 *
 * \param a Primer elemento
 * \param b Segundo elemento
 * \return Si 'a' es mayor a 'b' o no.
 *
 */
bool Mayor(T a, T b);

template<typename T>
/** \brief Funci&oacute;n que dice si un valor es mayor o igual que otro, una de las funciones para la condici&oacute;n de eliminar.
 *
 * \param a Primer elemento
 * \param b Segundo elemento
 * \return Si 'a' es mayor o igual a 'b' o no.
 *
 */
bool MayorOIgual(T a, T b);

template<typename T>
/** \brief Funci&oacute;n que dice si un valor es menor que otro, una de las funciones para la condici&oacute;n de eliminar.
 *
 * \param a Primer elemento
 * \param b Segundo elemento
 * \return Si 'a' es menor a 'b' o no.
 *
 */
bool Menor(T a, T b);

template<typename T>
/** \brief Funci&oacute;n que dice si un valor es menor o igual que otro, una de las funciones para la condici&oacute;n de eliminar.
 *
 * \param a Primer elemento
 * \param b Segundo elemento
 * \return Si 'a' es menor o igual a 'b' o no.
 *
 */
bool MenorOIgual(T a, T b);

template<typename T>
/** \brief Funci&oacute;n que dice si un valor es igual que otro, una de las funciones para la condici&oacute;n de eliminar.
 *
 * \param a Primer elemento
 * \param b Segundo elemento
 * \return Si 'a' es igual a 'b' o no.
 *
 */
bool Igual(T a, T b);

template<typename T>
/** \brief Funci&oacute;n que dice si un valor es distinto que otro, una de las funciones para la condici&oacute;n de eliminar.
 *
 * \param a Primer elemento
 * \param b Segundo elemento
 * \return Si 'a' es distinto a 'b' o no.
 *
 */
bool Distinto(T a, T b);

/** \brief Funci&oacute;n que dice si un valor es par, una de las funciones para la condici&oacute;n de eliminar.
 *
 * \param a N&uacute;mero al cual descubrir si es par
 * \return Si 'a' es par o no.
 *
 */
bool EsPar(int a);

/** \brief Funci&oacute;n que dice si un valor es impar, una de las funciones para la condici&oacute;n de eliminar.
 *
 * \param a N&uacute;mero al cual descubrir si es impar
 * \return Si 'a' es impar o no.
 *
 */
bool EsImpar(int a);

template<typename T>
/** \brief Funci&oacute;n que si dice si un valor es positivo, una de las funciones para la condici&oacute;n de eliminar.
 *
 * \param a N&uacute;mero al cual descubrir si es positivo
 * \return Si 'a' es positivo o no.
 *
 */
bool EsPositivo(T a);

template<typename T>
/** \brief Funci&oacute;n que dice si un valor es negativo, una de las funciones para la condici&oacute;n de eliminar.
 *
 * \param a N&uacute;mero al cual descubrir si es negativo
 * \return Si 'a' es negativo o no.
 *
 */
bool EsNegativo(T a);

/** \brief Funci&oacute;n que si dice si un valor es primo, una de las funciones para la condici&oacute;n de eliminar.
 *
 * \param a N&uacute;mero al cual descubrir si es primo
 * \return Si 'a' es primo o no.
 *
 */
bool EsPrimo(int a);

/** \brief Funci&oacute;n que dice si un car&aacute;cter es vocal, una de las funciones para la condici&oacute;n de eliminar.
 *
 * \param a Car&aacute;cter a checar.
 * \return Si 'a' es una vocal o no.
 *
 */
bool EsVocal(char a);

/** \brief Funci&oacute;n que dice si un car&aacute;cter es mayuscula, una de las funciones para la condici&oacute;n de eliminar.
 *
 * \param a Car&aacute;cter a checar.
 * \return Si 'a' es una mayuscula o no.
 *
 */
bool EsMayuscula(char a);

/** \brief Funci&oacute;n que dice si un car&aacute;cter es minuscula, una de las funciones para la condici&oacute;n de eliminar.
 *
 * \param a Car&aacute;cter a checar.
 * \return Si 'a' es una minuscula o no.
 *
 */
bool EsMinuscula(char a);

/** \brief Funci&oacute;n que dice si un car&aacute;cter es un digito, una de las funciones para la condici&oacute;n de eliminar.
 *
 * \param a Car&aacute;cter a checar.
 * \return Si 'a' es un digito o no.
 *
 */
bool EsDigito(char a);

#include "Condiciones.tpp"

#endif // CONDICIONES_HPP_INCLUDED
