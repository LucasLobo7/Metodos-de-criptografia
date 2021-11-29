#ifndef CRIPTOGRAFIA_H
#define CRIPTOGRAFIA_H
#include <iostream>
#include <string>
#include "excecaoDiv0.h"
#include "excecaoEntradaInvalida.h"

using namespace std;

class Criptografia{
	string entrada, saida, chave;
public:
    Criptografia(string, string, string);
    void setEntrada(string);
    void setSaida(string);
    void setChave(string);
    string getEntrada() const;
    string getSaida() const;
    string getChave() const;
};

#endif // CRIPTOGRAFIA_H
