#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include "criptografia.h"
#include "CifraDeUsoUnico.h"

using namespace std;

CifraDeUsoUnico::CifraDeUsoUnico(string entrada, string saida, string chave):Criptografia(entrada, saida, chave)
{
}

CifraDeUsoUnico::~CifraDeUsoUnico()
{
	delete chaves;
}

void CifraDeUsoUnico::tamanhoChaveEntrada()
{
	int i , c;
	c =getEntrada().size();
	chaves = new int[c];
}

void CifraDeUsoUnico::tamanhoChaveSaida()
{
	int i ,c;
	c =getSaida().size();
	chaves = new int[c];
}

void CifraDeUsoUnico::geraChave()
{
	srand(time(NULL));
	for(int i=0; i<getEntrada().size(); i++)
	{
		chaves[i] = (rand()%27);
	}
}


void CifraDeUsoUnico::encripta()
{
	int i,k;
	string s = getEntrada();

	for(i=0; i<getEntrada().size(); i++)
	{
		k = getEntrada()[i];

        k  += chaves[i];
        if(k>122)
            k-=26;
        s[i] = k;

	}
	setSaida(s);
}

void CifraDeUsoUnico::descriptografa()
{
	int i,k;
	string s = getSaida();

	for(i=0; i<getSaida().size(); i++)
	{
		k = getSaida()[i];

        k  -= chaves[i];
        if(k<97)
            k+=26;
        s[i] = k;

	}
	setEntrada(s);
}

int CifraDeUsoUnico::getChaves(int i) const
{
	return chaves[i];
}

void CifraDeUsoUnico::setChaves(int i, int c)
{
	chaves[i] = c;
}
