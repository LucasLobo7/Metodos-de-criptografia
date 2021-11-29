#include <stdexcept>
#include <iostream>

using std::string;
using std::runtime_error;

class DividirPorZero : public runtime_error
{
public:
    DividirPorZero( string mensagem = "Tentou dividir por zero" ) : runtime_error( mensagem ){}
};
