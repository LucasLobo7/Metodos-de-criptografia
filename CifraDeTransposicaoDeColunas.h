#ifndef CIFRADETRANSPOSICAODECOLUNAS_H
#define CIFRADETRANSPOSICAODECOLUNAS_H
#include "criptografia.h"
#include <cstdlib>
#include <ctime>

class CifraDeTransposicaoDeColunas:public Criptografia{
public:
    CifraDeTransposicaoDeColunas(string, string, string);
    void encripta();
    void descriptografa();
};

#endif // CIFRADETRANSPOSICAODECOLUNAS_H
