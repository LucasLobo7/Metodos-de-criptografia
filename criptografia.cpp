#include <iostream>
#include <string.h>
#include "criptografia.h"

using namespace std;

Criptografia::Criptografia(string entrada, string saida, string chave)
{
    this->entrada = entrada;
    this->saida = saida;
    this->chave = chave;
}

void Criptografia::setEntrada(string entrada)
{
    int c;
    for(c=0; c<entrada.size(); c++)
        if(entrada[c] < 97 || entrada[c] > 122)
            throw EntradaInvalida("Somente letras minusculas e sem espacos");

    this->entrada = entrada;
}

void Criptografia::setSaida(string saida)
{
    this->saida = saida;
}

void Criptografia::setChave(string chave)
{
    int c;
    for(c=0; c<chave.size(); c++)
        if(chave[c] < 97 || chave[c] > 122)
            throw EntradaInvalida("Somente letras minusculas e sem espaco");

    if(!chave.size())
        throw DividirPorZero("A chave tem zero caracteres");

    this->chave = chave;
}

string Criptografia::getEntrada() const
{
    return entrada;
}

string Criptografia::getSaida() const
{
    return saida;
}

string Criptografia::getChave() const
{
    return chave;
}
