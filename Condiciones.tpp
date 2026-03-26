
// int, float, long double, double, unsigned, y así
template<typename T>
bool Mayor(T a, T b) { return a > b;}

template<typename T>
bool MayorOIgual(T a, T b) { return a >= b;}

template<typename T>
bool Menor(T a, T b) { return a < b; }

template<typename T>
bool MenorOIgual(T a, T b) { return a <= b; }

template<typename T>
bool Igual(T a, T b) { return a == b; }

template<typename T>
bool Distinto(T a, T b){ return a != b;}

template<typename T>
bool EsPositivo(T a) { return a > 0; }

template<typename T>
bool EsNegativo(T a) { return a < 0; }



// IMPORTANTEE!!!! inline porque si no el c++ protesta porque
//no son templates en un archivo .tpp, pero pa no tener dos Condiciones.algo
// más facil nomas inline y ya, pa no andar batallando. y como los demás si
// sirven para float double etc, pues ya, asi mero aguanta.

// Solo Enteros.
inline bool EsPar(int a) { return a%2 == 0;}
inline bool EsImpar(int a) {return a%2 != 0;}
inline bool EsPrimo(int a)
{
    if( a < 2) return false;
    for(int i = 2; i*i <= a; ++i){
        if(a%i == 0) return false;
    }
    return true;

}
// Caracteres
inline bool EsVocal(char a) {return a=='a' || a=='e' || a=='i' || a=='o' || a=='u';}
inline bool EsMayuscula(char a) {return isupper(a);}
inline bool EsMinuscula(char a) {return islower(a);}
inline bool EsDigito(char a) { return isdigit(a);}
