#ifndef CIFRADECESAR_H
#define CIFRADECESAR_H
#include "criptografia.h"
#include <string.h>

class CifraDeCesar: public Criptografia{
	int desloca;
public:
    CifraDeCesar(int, string, string, string);
    void setdesloca(int);
    int getdesloca();
    void encripta();
    void desencripta();
};

#endif // CIFRADECESAR_H
