#ifndef ENIGMA_H
#define ENIGMA_H
#include "criptografia.h"

class enigma :public Criptografia{
	int rotores[5][26], rotacao[3], escolha[3], anel[3];
	string trocada, letras;
public:
	enigma(string,string,string,int);
	void setrotacao(int,int);
	void setescolha(int,int);
	void setanel(int,int);
	int getrotores(int, int) const;
	int getrotacao(int) const;
	int getescolha(int) const;
	int getanel(int) const;
	void rotaciona();
	void encripta();
	void trocaletras(char, char);
	void setletras(char,char);
	string getletras();
	void trocasaida(char, char);
	void auxiliatroca();
};
#endif