#include "criptografia.h"
#include <string.h>

#ifndef POLIALFABETICA_H
#define POLIALFABETICA_H

class Polialfabetica : public Criptografia{
public:
	Polialfabetica(string, string, string);
    void encripta();
    void desencripta();
};

#endif
