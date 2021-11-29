#include "CifraDeTransposicaoDeColunas.h"

CifraDeTransposicaoDeColunas::CifraDeTransposicaoDeColunas(string entrada, string saida, string chave):Criptografia(entrada, saida, chave)
{
}

void CifraDeTransposicaoDeColunas::encripta(){
    int linhas, c, c2, auxi=0;
    bool verif[getEntrada().size()] ;
    char auxc;
    string auxs, saida = getEntrada(), entrada = getEntrada();

   for(c=0; c < getEntrada().size()%getChave().size(); c++){
        auxc = 97 + rand()%26;
        auxs = auxc;
        entrada.append(auxs);    //Todas as colunas devem ter o mesmo número de linhas
    }                            //Portanto, completa-se as colunas incompletas com letras minúsculas aleatórias
    setEntrada(entrada);

    linhas = getEntrada().size()/getChave().size();

    for (c=0; c < getEntrada().size(); c++){
        if (!verif[c]){
            saida[c] = getEntrada()[((c%getChave().size())*linhas) + (c/getChave().size())];
            verif[c] = true;
        } //Para cada posição c da string saida, ele vai mudar o valor pelo da posição (c%NC)*NL + c/NC
    }     //Sendo NC o número de colunas, que é o número de caracteres da chave e NL, o número de linhas

    auxs = saida;

    for (c=30; c < 123; c++){
        if (getChave().find((char)c) + 1){ //Se o caractere não é achado, o valor retornado é -1
            for(c2=0; c2 < linhas; c2++){
                saida[auxi*linhas + c2] = auxs[getChave().find((char)c)*linhas + c2];
            }
            auxi++;
        }
    }

    setSaida(saida);
}

void CifraDeTransposicaoDeColunas::descriptografa(){
    int linhas, c, c2, auxi=0;
    bool verif[getEntrada().size()] ;
    string aux, saida = getEntrada();

    linhas = getEntrada().size()/getChave().size();

    for (c=30; c < 123; c++){
        if (getChave().find((char)c) + 1){ //Se o caractere não é achado, o valor retornado é -1
            for(c2=0; c2 < linhas; c2++){
                saida[getChave().find((char)c)*linhas + c2] = getEntrada()[auxi*linhas + c2];
            }
            auxi++;
        }
    }

    aux = saida;

    for (c=0; c < aux.size(); c++){
        if (!verif[c]){
            saida[c] = aux[((c%linhas)*getChave().size()) + (c/linhas)];
            verif[c] = true;
        } //Para cada posição c da string saida, ele vai mudar o valor pelo da posição (c%NL)*NC + c/NL
    }     //Sendo NC o número de colunas, que é o número de caracteres da chave, e NL o número de linhas

    setSaida(saida);
}
