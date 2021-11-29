#ifndef CIFRADEUSOUNICO_H
#define CIFRADEUSOUNICO_H
#include "criptografia.h"

class CifraDeUsoUnico:public Criptografia{
public:
	int *chaves;
public:
    CifraDeUsoUnico(string, string, string);
    ~CifraDeUsoUnico();
	void encripta();
    void descriptografa();
    void geraChave();
    void tamanhoChaveEntrada();
    void tamanhoChaveSaida();
    int getChaves(int) const;
    void setChaves(int, int);
};

#endif // CIFRADEUSOUNICO_H
