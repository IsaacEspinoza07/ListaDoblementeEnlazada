
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


// Solo Enteros.
bool EsPar(int a) { return a%2 == 0;}

bool EsImpar(int a) {return a%2 != 0;}

bool EsPrimo(int a)
{
    if( a < 2) return false;
    for(int i = 2; i*i <= a; ++i){
        if(a%i == 0) return false;
    }
    return true;

}

// Caracteres
bool EsVocal(char a) {return a=='a' || a=='e' || a=='i' || a=='o' || a=='u';}
bool EsMayuscula(char a) {return isupper(a);}
bool EsMinuscula(char a) {return islower(a);}
bool EsDigito(char a) { return isdigit(a);}
