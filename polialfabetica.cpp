#include <iostream>
#include <string.h>
#include <cstring>
#include "Polialfabetica.h"

using namespace std;

Polialfabetica::Polialfabetica(string entrada, string saida, string chave):Criptografia(entrada, saida, chave)
{
}
void Polialfabetica::encripta()
{
	int i, j, k, l; //i:contador para percorrer a entrada; k:contador para percorrer a chave; j:salva o valor do caracter da entrada; l:salva o valor do caracter da chave
	string s = getEntrada(); //s:string que salva temporariarmente a entrada e saida;

	for(i=0, k=0; i<getEntrada().size(); i++, k++)
	{
		if(k>getChave().size() - 1)
			k=0;

		j = getEntrada()[i];
		l = getChave()[k] - 96;

        j += l;
        if(j>122)
            j-=26;
        s[i] = j;
	}
	setSaida(s);
}

void Polialfabetica::desencripta()
{
	int i, j, k, l; //i:contador para percorrer a entrada; k:contador para percorrer a chave; j:salva o valor do caracter da entrada; l:salva o valor do caracter da chave
	string s = getSaida(); //s:string que salva temporariarmente a saida;

	for(i=0, k=0; i<getSaida().size(); i++, k++)
	{
		if(k>getChave().size() - 1)
			k=0;

		j = getSaida()[i];
		l = getChave()[k] - 96;

        j -= l;
        if(j<97)
            j += 26;
        s[i] = j;

		setEntrada(s);
	}
}
