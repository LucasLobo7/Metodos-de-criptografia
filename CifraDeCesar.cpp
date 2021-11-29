#include <iostream>
#include <string.h>
#include <cstring>
#include "CifraDeCesar.h"

using namespace std;

CifraDeCesar::CifraDeCesar(int desloca, string entrada, string saida, string chave):Criptografia(entrada, saida, chave)
{
	this->desloca = desloca;
}

void CifraDeCesar::setdesloca(int desloca)
{
	this->desloca = desloca;
}

int CifraDeCesar::getdesloca()
{
	return desloca;
}

void CifraDeCesar::encripta()
{
	int i,k;
	string s = getEntrada();

	for(i=0; i<getEntrada().size(); i++)
	{
		k = getEntrada()[i];

        k  += desloca;
        if(k>122)
            k-=26;
        s[i] = k;

	}
	setSaida(s);
}
void CifraDeCesar::desencripta()
{
	int i,k;
	string s = getSaida();

	for(i=0; i<getSaida().size(); i++)
	{
		k = getSaida()[i];

        k  -= desloca;
        if(k<97)
            k+=26;
        s[i] = k;

	}
	setEntrada(s);
}
