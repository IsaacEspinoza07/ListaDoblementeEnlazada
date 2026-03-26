#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include "Lista.hpp"
#include "CapturaSegura.hpp"

void LimpiarConsola();
void Pausar();

void ImprimirEstado(Lista<int> &l, const char* nombre);

void MenuAgregar    (Lista<int> &l);
void MenuEliminar   (Lista<int> &l);
void MenuObtener    (Lista<int> &l);
void MenuImprimir   (Lista<int> &l);
void MenuTransferir (Lista<int> &l1, Lista<int> &l2);

#endif // MENU_HPP_INCLUDED
