#ifndef CONDICIONES_HPP_INCLUDED
#define CONDICIONES_HPP_INCLUDED

template<typename T>
bool Mayor(T a, T b);

template<typename T>
bool MayorOIgual(T a, T b);

template<typename T>
bool Menor(T a, T b);

template<typename T>
bool MenorOIgual(T a, T b);

template<typename T>
bool Igual(T a, T b);

template<typename T>
bool Distinto(T a, T b);

#include "Condiciones.tpp"

#endif // CONDICIONES_HPP_INCLUDED
