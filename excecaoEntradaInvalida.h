#include <stdexcept>
#include <iostream>

using std::string;
using std::runtime_error;

class EntradaInvalida : public runtime_error
{
public:
    EntradaInvalida(string mensagem = "Entrada invalida") : runtime_error(mensagem){}
};
