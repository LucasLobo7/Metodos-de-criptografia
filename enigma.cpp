#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include "criptografia.h"
#include "enigma.h"

using namespace std;

enigma::enigma(string entrada,string chave,string saida,int inteiro):Criptografia(entrada,saida,chave)
{
	int codigos[5][26] = {101,107,109,102,108,103,100,113,118,122,110,116,111,119,121,104,120,117,115,112,97,105,98,114,99,106,97,106,100,107,115,105,114,117,120,98,108,104,119,116,109,99,113,103,122,110,112,121,102,118,111,101,98,100,102,104,106,108,99,112,114,116,120,118,122,110,121,101,105,119,103,97,107,109,117,115,113,111,101,115,111,118,112,122,106,97,121,113,117,105,114,104,120,108,110,102,116,103,107,100,99,109,119,98,118,122,98,114,103,105,116,121,117,112,115,100,110,104,108,120,97,119,109,106,113,111,102,101,99,107};
	for(int i =0; i<5; i++)
	{
		for(int j= 0; j<26; j++)
			rotores[i][j] = codigos[i][j];
	}

	for(int i=0;i<2;i++)
	{
		rotacao[i] = inteiro;
		escolha[i] = inteiro;
		anel[i] = inteiro;
	}
	this->trocada = entrada;
}

void enigma::setrotacao(int i, int j)
{
    if(j < 1 || j > 26)
        throw EntradaInvalida("Escolha um número de 1 a 26");

	rotacao[i] = j;
}

void enigma::setescolha(int i, int j)
{
    if(j < 1 || j > 5)
        throw EntradaInvalida("Escolha um número de 1 a 5");

	escolha[i] = j;
}

void enigma::setanel(int i, int j)
{
    if(j < 1 || j > 26)
        throw EntradaInvalida("Escolha um número de 1 a 26");

	anel[i] = j;
}

int enigma::getrotores(int i, int j) const
{
	return rotores[i][j];
}

int enigma::getrotacao(int i) const
{
	return rotacao[i];
}

int enigma::getescolha(int i) const
{
	return escolha[i];
}

int enigma::getanel(int i) const
{
	return anel[i];
}

void enigma::rotaciona()
{
	int aux = rotacao[1];
	rotacao[2]++;
	if(rotacao[2] > 26)
		rotacao[2] = 1;
	switch(escolha[2])
	{
		case 1:
			if(rotacao[2] == 18)
				rotacao[1]++;
			break;
		case 2:
			if(rotacao[2] == 6)
				rotacao[1]++;
			break;
		case 3:
			if(rotacao[2] == 23)
				rotacao[1]++;
			break;
		case 4:
			if(rotacao[2] == 11)
				rotacao[1]++;
			break;
		case 5:
			if(rotacao[2] == 1)
				rotacao[1]++;
			break;
	}
	if(rotacao[1] > 26)
		rotacao[1] = 1;

	switch(escolha[1])
	{
		case 1:
			if(rotacao[1] == 18 && rotacao[1] !=aux)
				rotacao[0]++;
			break;
		case 2:
			if(rotacao[1] == 6 && rotacao[1] !=aux)
				rotacao[0]++;
			break;
		case 3:
			if(rotacao[1] == 23 && rotacao[1] !=aux)
				rotacao[0]++;
			break;
		case 4:
			if(rotacao[1] == 11 && rotacao[1] !=aux)
				rotacao[0]++;
			break;
		case 5:
			if(rotacao[1] == 1 &&rotacao[1] !=aux)
				rotacao[0]++;
			break;
	}
	if(rotacao[0] > 26)
		rotacao[0] = 1;
}

void enigma::encripta()
{
	int i,z,j, aux1, refletor[26] = {121,114,117,104,113,115,108,100,112,120,110,103,111,107,109,105,101,98,102,122,99,119,118,106,97,116};

	string s = getEntrada();
	for(i=0;i<getEntrada().size(); i++)
	{
		rotaciona();
		z = s[i];
		//passando pelo primeiro rotor:
		aux1 = z - 97 + (rotacao[2] - 1) - (anel[2] -1);
		if(aux1 <0)
		   	aux1 += 26;
		if(aux1 > 25)
		   	aux1 -= 26;

		z = rotores[escolha[2]-1][aux1];
		z += ((anel[2] -1) - (rotacao[2] - 1));
		if(z <97)
		   	z += 26;
		if(z > 122)
		   	z -= 26;
		//passando pelo segundo rotor:

		aux1 = z - 97  + (rotacao[1] - 1) - (anel[1] -1);
		if(aux1 <0)
		   	aux1 += 26;
		if(aux1 > 25)
		   	aux1 -= 26;
		z = rotores[escolha [1]-1][aux1];
		z += ((anel[1] -1) - (rotacao[1] - 1));
		if(z <97)
		   	z += 26;
		if(z > 122)
		   	z -= 26;

		//passando pelo 3 rotor

		aux1 = z - 97 + (rotacao[0] - 1) - (anel[0] -1);
		if(aux1 <0)
		   	aux1 += 26;
		if(aux1 > 25)
		   	aux1 -= 26;
		z = rotores[escolha [0]-1][aux1];
		z += ((anel[0] -1) - (rotacao[0] - 1));
		if(z <97)
		   	z += 26;
		if(z > 122)
		   	z -= 26;

		//a partir daqui o sinal volta pelo 3->2->1 rotor

		z = refletor[z - 97];

		//ATE AKI TD CERTO

		//passando pelo 3 rotor

		z += ((rotacao[0] - 1) - (anel[0] - 1));
		if(z <97)
		   	z += 26;
		if(z > 122)
		   	z -= 26;
		for(j=0; j<26;j++)
		{
			if(rotores[escolha[0] - 1][j] == z)
				break;
		}
		z = j + 97 - (rotacao[0] - 1) + (anel[0] - 1);
		if(z <97)
		   	z += 26;
		if(z > 122)
		   	z -= 26;


		// passando pelo 2 rotor
		z += ((rotacao[1] - 1) - (anel[1] - 1));
		if(z <97)
		   	z += 26;
		if(z > 122)
		   	z -= 26;
		for(j=0; j<26;j++)
		{
			if(rotores[escolha[1] - 1][j] == z)
				break;
		}
		z = j + 97 - (rotacao[1] - 1) + (anel[1] - 1);
		if(z <97)
		   	z += 26;
		if(z > 122)
		   	z -= 26;

		//passando pelo primeiro rotor:
		z += ((rotacao[2] - 1) - (anel[2] - 1));
		if(z <97)
		   	z += 26;
		if(z > 122)
		   	z -= 26;
		for(j=0; j<26;j++)
		{
			if(rotores[escolha[2] - 1][j] == z)
				break;
		}
		z = j + 97 - (rotacao[2] - 1) + (anel[2] - 1);
		if(z <97)
		   	z += 26;
		if(z > 122)
		   	z -= 26;
		s[i] = z;
	}
	setSaida(s);
}

void enigma::trocaletras(char l1, char l2)
{
	int i;
	int checagem[getEntrada().size()];
	trocada = getEntrada();
	for(i=0;i<trocada.size();i++)
	{
		if(trocada[i] == l1)
		{
			trocada[i] = l2;
			checagem[i] = 1;
		}
	}

	for(i=0;i<trocada.size();i++)
	{
		if(trocada[i] == l2 && checagem[i] != 1)
			trocada[i] = l1;
	}
	setEntrada(trocada);
}

void enigma::setletras(char c1,char c2)
{
	string l1, l2;
	l1 = c1;
	l2 = c2;
	letras += l1 + l2;
}
void enigma::trocasaida(char l1, char l2)
{
	int i;
	int checagem[getSaida().size()];
	trocada = getSaida();
	for(i=0;i<trocada.size();i++)
	{
		if(trocada[i] == l1)
		{
			trocada[i] = l2;
			checagem[i] = 1;
		}
	}

	for(i=0;i<trocada.size();i++)
	{
		if(trocada[i] == l2 && checagem[i] != 1)
			trocada[i] = l1;
	}
	setSaida(trocada);
}

string enigma::getletras()
{
	return letras;
}

void enigma::auxiliatroca()
{
	for(int i=0; i<letras.size(); i+=2)
		trocasaida(letras[i],letras[i+1]);
}
