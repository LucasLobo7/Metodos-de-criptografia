#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <locale.h>
#include "CifraDeCesar.cpp"
#include "criptografia.cpp"
#include "Polialfabetica.cpp"
#include "CifraDeUsoUnico.cpp"
#include "CifraDeTransposicaoDeColunas.cpp"
#include "enigma.cpp"

using namespace std;

int main()
{
    ofstream arquivoS;
    ifstream arquivoE;

    CifraDeCesar c(0, "", "", "");
    Polialfabetica p("", "", "");
    CifraDeUsoUnico u("", "", "");
    CifraDeTransposicaoDeColunas t("", "", "");
    enigma e("","","",0);
    int i=1,k =0, j=0, menu=0;
    char c1,c2;
    string s;
    setlocale(LC_ALL,"");

    while(i)
    {
        try{
            system("cls");
            cout<<"Programa de Criptografia, Digite:"<<endl<<"1: para usar a cifra de C�sar"<<endl<<"2: para usar a cifra polialfab�tica"<<endl<<"3: para usar a cifra de uso �nico"<<endl<<"4: para usar a cifra de transposi��o de colunas"<<endl<<"5: para usar a m�quina enigma"<<endl<<"6: para acessar o hist�rico:"<<endl<<"0: para sair"<<endl;
            cin>>menu;
            if (menu < 0 || menu > 6)
                throw EntradaInvalida("O n�mero deve estar entre 0 e 6");
        }
        catch(EntradaInvalida &invalida){
            cout<<"Erro: "<<invalida.what()<<endl;
            menu = 7;
        }

        if(menu==1)
        {
            system("cls");
            arquivoS.open("cezar.txt", ios::app);
            if(arquivoS.is_open())
            {
                cout<<"Cifra de c�sar:"<<endl<<"Digite 1 para encriptar:"<<endl<<"Digite 2 para decriptar:"<<endl;
                cin>>i;
                if(i==1)
                {
                    try{
                        system("cls");
                        cout<<endl<<"Digite a frase que ser� encriptada: (Somente letras min�sculas sem espa�os)"<<endl;
                        cin.ignore();
                        getline(cin, s);
                        c.setEntrada(s);
                        cout<<"Digite o quanto quer deslocar os caracteres: (n�mero inteiro de tamanho infinito)"<<endl;
                        cin.ignore();
                        getline(cin, s);
                        c.setdesloca(i);
                        c.encripta();
                        arquivoS<<"criptografia:  "<<"  Entrada:"<<c.getEntrada()<<"  Deslocamento:"<<c.getdesloca()<<"  Saida:"<<c.getSaida()<<endl;
                        arquivoS.close();
                        cout<<endl<<"A mensagem encriptada �: "<<c.getSaida();
                    }
                    catch(EntradaInvalida &invalida){
                        cout<<"Erro: "<<invalida.what()<<endl;
                    }
                }
                if(i==2)
                {
                    try{
                        system("cls");
                        cout<<endl<<"Digite a frase encriptada: (Somente letras min�sculas sem espa�os)"<<endl;
                        cin.ignore();
                        getline(cin, s);
                        c.setSaida(s);
                        cout<<"Digite o quanto os caracteres foram deslocados: (n�mero inteiro de tamanho infinito)"<<endl;
                        cin.ignore();
                        getline(cin, s);
                        c.setdesloca(i);
                        c.desencripta();
                        arquivoS<<"decriptografia:   "<<"Entrada:"<<c.getSaida()<<"  Deslocamento:"<<c.getdesloca()<<"  Saida:"<<c.getEntrada()<<endl;
                        arquivoS.close();
                        cout<<endl<<"A mensagem decriptada �:"<<c.getEntrada();
                    }
                    catch(EntradaInvalida &invalida){
                        cout<<"Erro: "<<invalida.what()<<endl;
                    }
                }
            }
            else
            {
                system("cls");
                cout<<"N�o foi poss�vel abrir o arquivo";
            }

        }
        if(menu==2)
        {
            system("cls");
            arquivoS.open("poli.txt", ios::app);
            if(arquivoS.is_open())
            {
                cout<<"Cifra polialfab�tica"<<endl<<"Digite 1 para encriptar:"<<endl<<"Digite 2 para decriptar:"<<endl;
                cin>>i;
                if(i==1)
                {
                    try{
                        system("cls");
                        cout<<"Digite frase que ser� encriptada: (Somente letras min�sculas sem espa�os)"<<endl;
                        cin.ignore();
                        getline(cin, s);
                        p.setEntrada(s);
                        cout<<endl<<"Digite a palavra chave: (Uma palavra de qualquer tamanho contendo apenas letras min�sculas)"<<endl;
                        cin.ignore();
                        getline(cin, s);
                        p.setChave(s);
                        p.encripta();
                        arquivoS<<"criptografia:   "<<"Entrada:"<<p.getEntrada()<<"  Chave:"<<p.getChave()<<"  Saida:"<<p.getSaida()<<endl;
                        arquivoS.close();
                        cout<<endl<<"A mensagem encriptada �:"<<p.getSaida();
                    }
                    catch(EntradaInvalida &invalida){
                        cout<<"Erro: "<<invalida.what()<<endl;
                    }
                }

                if(i==2)
                 {
                    try{
                        system("cls");
                        cout<<"Digite a frase que ser� decriptada: (Somente letras min�sculas sem espa�os)"<<endl;
                        cin.ignore();
                        getline(cin, s);
                        p.setSaida(s);
                        cout<<endl<<"Digite a palavra chave:  (Uma palavra de qualquer tamanho contendo apenas letras min�sculas)"<<endl;
                        cin.ignore();
                        getline(cin, s);
                        p.setChave(s);
                        p.desencripta();
                        cout<<endl<<"A mensagem decriptada �:"<<p.getEntrada();
                        arquivoS<<"descriptografia:   "<<"Entrada:"<<p.getSaida()<<"  Chave:"<<p.getChave()<<"  Saida:"<<p.getEntrada()<<endl;
                        arquivoS.close();
                    }
                    catch(EntradaInvalida &invalida){
                        cout<<"Erro: "<<invalida.what()<<endl;
                    }
                }
            }
            else
            {
                system("cls");
                cout<<"N�o foi possivel abrir o arquivo";
            }

        }
        if(menu==3)
        {
            system("cls");
            arquivoS.open("unico.txt", ios::app);
            if(arquivoS.is_open())
            {
                cout<<"Cifra de uso �nico:"<<endl<<"Digite 1 para encriptar:"<<endl<<"Digite 2 para decriptar:"<<endl;
                cin>>i;
                if(i==1)
                {
                    try{
                        system("cls");
                        cout<<endl<<"Digite a frase que ser� encriptada: (Somente letras min�sculas sem espa�os)"<<endl;
                        cin.ignore();
                        getline(cin, s);
                        u.setEntrada(s);
                        cout<<"Gerando chave aleat�ria: ";
                        u.tamanhoChaveEntrada();
                        u.geraChave();
                        for(i=0; i<u.getEntrada().size(); i++)
                        {
                            cout<<"  "<<u.getChaves(i);
                        }
                        u.encripta();
                        arquivoS<<"criptografia:   "<<"Entrada:"<<u.getEntrada()<<"  Chave:";
                        for(i=0; i<u.getEntrada().size(); i++)
                        {
                            arquivoS<<" "<<u.getChaves(i);
                        }
                        arquivoS<<"  Saida:"<<u.getSaida()<<endl;
                        arquivoS.close();
                        cout<<endl<<endl<<"A mensagem encriptada �: "<<u.getSaida();
                    }
                    catch(EntradaInvalida &invalida){
                        cout<<"Erro: "<<invalida.what()<<endl;
                    }
                }
                if(i==2)
                {
                    try{
                        system("cls");
                        cout<<endl<<"Digite a frase encriptada: (Somente letras min�sculas)"<<endl;
                        cin.ignore();
                        getline(cin, s);
                        u.setSaida(s);
                        u.tamanhoChaveSaida();
                        cout<<endl<<"Digite as chaves:"<<endl;
                        for(i=0; i<u.getSaida().size(); i++)
                        {
                            cout<<i +1<<"�"<<" chave:";
                            cin>>k;
                            u.setChaves(i,k);
                        }
                        u.descriptografa();
                        arquivoS<<"descriptografia:   "<<"Entrada:"<<u.getSaida()<<"  Chave:";
                        for(i=0; i<u.getSaida().size(); i++)
                        {
                            arquivoS<<" "<<u.getChaves(i);
                        }
                        arquivoS<<"  Saida:"<<u.getEntrada()<<endl;
                        arquivoS.close();
                        cout<<endl<<endl<<"A frase decriptada �:"<<u.getEntrada();
                    }
                    catch(EntradaInvalida &invalida){
                        cout<<"Erro: "<<invalida.what()<<endl;
                    }
                }
            }
            else
            {
                system("cls");
                cout<<"N�o foi possivel abrir o arquivo";
            }
        }
        if(menu==4)
        {
            system("cls");
            arquivoS.open("coluna.txt", ios::app);
            if(arquivoS.is_open())
            {
                cout<<"Cifra de transposi��o de colunas:"<<endl<<"Digite 1 para encriptar:"<<endl<<"Digite 2 para decriptar:"<<endl;
                cin>>i;
                if(i==1)
                {
                    try{
                        system("cls");
                        cout<<endl<<"Digite a palavra chave: (Palavra de qualquer tamanho sem caracteres repetidos e somente com letras min�sculas)"<<endl;
                        cin.ignore();
                        getline(cin, s);
                        t.setChave(s);
                        cout<<"Digite a frase que ser� encriptada: (Somente letras min�sculas sem espa�os)"<<endl;
                        cin.ignore();
                        getline(cin, s);
                        t.setEntrada(s);
                        t.encripta();
                        arquivoS<<"criptografia:  "<<"Entrada:"<<t.getEntrada()<<"  Chave:"<<t.getChave()<<"  Saida:"<<t.getSaida()<<endl;
                        arquivoS.close();
                        cout<<endl<<"A mensagem encriptada �:"<<t.getSaida();
                    }
                    catch(DividirPorZero &divisao){
                        cout<<"Erro: "<<divisao.what()<<endl;
                    }
                    catch(EntradaInvalida &invalida){
                        cout<<"Erro: "<<invalida.what()<<endl;
                    }
                }

                if(i==2)
                {
                    try{
                        system("cls");
                        cout<<endl<<"Digite a palavra chave: (Palavra de qualquer tamanho sem caracteres repetidos e somente com letras min�sculas)"<<endl;
                        cin.ignore();
                        getline(cin, s);
                        t.setChave(s);
                        cout<<"Digite a mensagem que ser� decriptada: (Somente letras min�sculas sem espa�os)"<<endl;
                        cin.ignore();
                        getline(cin, s);
                        t.setEntrada(s);
                        t.descriptografa();
                        arquivoS<<"descriptografia:  "<<"Entrada:"<<t.getEntrada()<<"  Chave:"<<t.getChave()<<"  Saida:"<<t.getSaida()<<endl;
                        arquivoS.close();
                        cout<<endl<<"A mensagem decriptada �:"<<t.getSaida();
                        }
                    catch(DividirPorZero &divisao){
                        cout<<"Erro: "<<divisao.what()<<endl;
                    }
                    catch(EntradaInvalida &invalida){
                        cout<<"Erro: "<<invalida.what()<<endl;
                    }
                }
            }
            else
            {
                system("cls");
                cout<<"N�o foi poss�vel abrir o arquivo.";
            }
        }
        if(menu==5)
        {
            system("cls");
            arquivoS.open("enigma.txt", ios::app);
            if(arquivoS.is_open())
            {
                cout<<"M�quina enigma"<<endl;
                cout<<endl<<"Defina quais rotores ir� usar(3 n�meros diferentes de 1 a 5)"<<endl;
                for(k=0;k<3;k++)
                {
                    try{
                        cout<<"rotor "<<k+1<<":";
                        cin>>i;
                        e.setescolha(k,i);
                    }
                    catch(EntradaInvalida &invalida){
                        cout<<"Erro: "<<invalida.what()<<endl;
                        k--;
                    }
                }

                cout<<endl<<"Defina os an�is dos rotores (3 n�meros  de 1 a 26)"<<endl;
                for(k=0;k<3;k++)
                {
                    try{
                        cout<<"anel "<<k+1<<":";
                        cin>>i;
                        e.setanel(k,i);
                    }
                    catch(EntradaInvalida &invalida){
                        cout<<"Erro: "<<invalida.what()<<endl;
                        k--;
                    }
                }

                cout<<endl<<"Defina a rota��o dos rotores(3 n�meros de 1 a 26)"<<endl;
                for(k=0;k<3;k++)
                {
                    try{
                        cout<<"rota��o "<<k+1<<":";
                        cin>>i;
                        e.setrotacao(k,i);
                    }
                    catch(EntradaInvalida &invalida){
                        cout<<"Erro: "<<invalida.what()<<endl;
                        k--;
                    }
                }

                arquivoS<<"Rotores escolhidos: "<<e.getescolha(0)<<","<<e.getescolha(1)<<","<<e.getescolha(2);
                arquivoS<<"  Posic�o dos an�is: "<<e.getanel(0)<<","<<e.getanel(1)<<","<<e.getanel(2);
                arquivoS<<"  Rotac�o dos rotores: "<<e.getrotacao(0)<<","<<e.getrotacao(1)<<","<<e.getrotacao(2);
                while (i){
                    try{
                        cout<<endl<<"Digite a frase de entrada: (Somente letras min�sculas sem espa�os)"<<endl;
                        cin.ignore();
                        getline(cin, s);
                        e.setEntrada(s);
                        i = 0;
                    }
                    catch(EntradaInvalida &invalida){
                        cout<<"Erro: "<<invalida.what()<<endl;
                        i = 1;
                    }
                }
                arquivoS<<"  Letras trocadas: ";
                while(i)
                {
                    cout<<endl<<"Digite 1 para conectar letras, 0 para continuar:";
                    cin>>i;
                    if(i==1)
                    {
                        try{
                            cout<<"Digite a 1 letra:";
                            cin>>c1;
                            cout<<"Digite a 2 letra:";
                            cin>>c2;
                            e.trocaletras(c1,c2);
                            arquivoS<<c1<<"&"<<c2<<" , ";
                            e.setletras(c1,c2);
                        }
                        catch(EntradaInvalida &invalida){
                            cout<<"Erro: "<<invalida.what()<<endl;
                        }
                    }

                }
                e.encripta();
                e.auxiliatroca();
                cout<<endl<<"A mensagem encriptada �: "<<e.getSaida();
                arquivoS<<" Entrada:"<<s<<"  Sa�da:"<<e.getSaida()<<endl;
                arquivoS.close();
            }
            else
            {
                system("cls");
                cout<<"N�o foi poss�vel abrir o arquivo.";
            }

        }
        if(menu==6)
        {
            try{
                system("cls");
                cout<<"Digite qual m�todo quer acessar o historico:"<<endl<<"1:Cifra de C�sar:"<<endl<<"2:Cifra polialfab�tica:"<<endl<<"3:Cifra de uso �nico:"<<endl<<"4:Cifra de transposi��o de colunas:"<<endl<<"5:M�quina enigma"<<endl;
                cin>>i;
                if (i < 1 || i > 5)
                    throw EntradaInvalida ("Somente valores entre 1 e 5");
            }
            catch(EntradaInvalida &invalida){
                cout<<"Erro: "<<invalida.what()<<endl;
            }

            if(i==1)
            {
                system("cls");
                arquivoE.open("cezar.txt");
                if(arquivoE.is_open())
                {
                    while(getline(arquivoE,s))
                        cout<<s<<endl<<endl;
                    arquivoE.close();
                }
                else
                {
                    system("cls");
                    cout<<"N�o foi poss�vel abrir o arquivo";
                }
            }

            if(i==2)
            {
            	system("cls");
                arquivoE.open("poli.txt");
                if(arquivoE.is_open())
                {
                    while(getline(arquivoE,s))
                        cout<<s<<endl<<endl;
                    arquivoE.close();
                }
                else
                {
                    system("cls");
                    cout<<"N�o foi poss�vel abrir o arquivo";
                }

            }
            if(i==3)
            {
                system("cls");
                arquivoE.open("unico.txt");
                if(arquivoE.is_open())
                {
                    while(getline(arquivoE,s))
                        cout<<s<<endl<<endl;
                    arquivoE.close();
                }
                else
                {
                    system("cls");
                    cout<<"N�o foi poss�vel abrir o arquivo";
                }

            }
            if(i==4)
            {
                system("cls");
                arquivoE.open("coluna.txt");
                if(arquivoE.is_open())
                {
                    while(getline(arquivoE,s))
                        cout<<s<<endl<<endl;
                    arquivoE.close();
                }
                else
                {
                    system("cls");
                    cout<<"N�o foi poss�vel abrir o arquivo";
                }

            }
            if(i==5)
            {
                system("cls");
                arquivoE.open("enigma.txt");
                if(arquivoE.is_open())
                {
                    while(getline(arquivoE,s))
                        cout<<s<<endl<<endl;
                    arquivoE.close();
                }
                else
                {
                    system("cls");
                    cout<<"N�o foi poss�vel abrir o arquivo";
                }
            }
        }

        if (menu){
            cout<<endl<<"Digite 1 para continuar usando o programa ou 0 para sair";
            cin>>i;
        }
        else
            i = 0;

    }

    return 0;
}

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <locale.h>
#include "CifraDeCesar.cpp"
#include "criptografia.cpp"
#include "Polialfabetica.cpp"
#include "CifraDeUsoUnico.cpp"
#include "CifraDeTransposicaoDeColunas.cpp"
#include "enigma.cpp"

using namespace std;

int main()
{
    ofstream arquivoS;
    ifstream arquivoE;

    CifraDeCesar c(0, "", "", "");
    Polialfabetica p("", "", "");
    CifraDeUsoUnico u("", "", "");
    CifraDeTransposicaoDeColunas t("", "", "");
    enigma e("","","",0);
    int i=1,k =0, j=0, menu=0;
    char c1,c2;
    string s;
    setlocale(LC_ALL,"");

    while(i)
    {
        try{
            system("cls");
            cout<<"Programa de Criptografia, Digite:"<<endl<<"1: para usar a cifra de C�sar"<<endl<<"2: para usar a cifra polialfab�tica"<<endl<<"3: para usar a cifra de uso �nico"<<endl<<"4: para usar a cifra de transposi��o de colunas"<<endl<<"5: para usar a m�quina enigma"<<endl<<"6: para acessar o hist�rico:"<<endl<<"0: para sair"<<endl;
            cin>>menu;
            if (menu < 0 || menu > 6)
                throw EntradaInvalida("O n�mero deve estar entre 0 e 6");
        }
        catch(EntradaInvalida &invalida){
            cout<<"Erro: "<<invalida.what()<<endl;
            menu = 7;
        }

        if(menu==1)
        {
            system("cls");
            arquivoS.open("cezar.txt", ios::app);
            if(arquivoS.is_open())
            {
                cout<<"Cifra de c�sar:"<<endl<<"Digite 1 para encriptar:"<<endl<<"Digite 2 para decriptar:"<<endl;
                cin>>i;
                if(i==1)
                {
                    try{
                        system("cls");
                        cout<<endl<<"Digite a frase que ser� encriptada: (Somente letras min�sculas sem espa�os)"<<endl;
                        cin.ignore();
                        getline(cin, s);
                        c.setEntrada(s);
                        cout<<"Digite o quanto quer deslocar os caracteres: (n�mero inteiro de tamanho infinito)"<<endl;
                        cin.ignore();
                        getline(cin, s);
                        c.setdesloca(i);
                        c.encripta();
                        arquivoS<<"criptografia:  "<<"  Entrada:"<<c.getEntrada()<<"  Deslocamento:"<<c.getdesloca()<<"  Saida:"<<c.getSaida()<<endl;
                        arquivoS.close();
                        cout<<endl<<"A mensagem encriptada �: "<<c.getSaida();
                    }
                    catch(EntradaInvalida &invalida){
                        cout<<"Erro: "<<invalida.what()<<endl;
                    }
                }
                if(i==2)
                {
                    try{
                        system("cls");
                        cout<<endl<<"Digite a frase encriptada: (Somente letras min�sculas sem espa�os)"<<endl;
                        cin.ignore();
                        getline(cin, s);
                        c.setSaida(s);
                        cout<<"Digite o quanto os caracteres foram deslocados: (n�mero inteiro de tamanho infinito)"<<endl;
                        cin.ignore();
                        getline(cin, s);
                        c.setdesloca(i);
                        c.desencripta();
                        arquivoS<<"decriptografia:   "<<"Entrada:"<<c.getSaida()<<"  Deslocamento:"<<c.getdesloca()<<"  Saida:"<<c.getEntrada()<<endl;
                        arquivoS.close();
                        cout<<endl<<"A mensagem decriptada �:"<<c.getEntrada();
                    }
                    catch(EntradaInvalida &invalida){
                        cout<<"Erro: "<<invalida.what()<<endl;
                    }
                }
            }
            else
            {
                system("cls");
                cout<<"N�o foi poss�vel abrir o arquivo";
            }

        }
        if(menu==2)
        {
            system("cls");
            arquivoS.open("poli.txt", ios::app);
            if(arquivoS.is_open())
            {
                cout<<"Cifra polialfab�tica"<<endl<<"Digite 1 para encriptar:"<<endl<<"Digite 2 para decriptar:"<<endl;
                cin>>i;
                if(i==1)
                {
                    try{
                        system("cls");
                        cout<<"Digite frase que ser� encriptada: (Somente letras min�sculas sem espa�os)"<<endl;
                        cin.ignore();
                        getline(cin, s);
                        p.setEntrada(s);
                        cout<<endl<<"Digite a palavra chave: (Uma palavra de qualquer tamanho contendo apenas letras min�sculas)"<<endl;
                        cin.ignore();
                        getline(cin, s);
                        p.setChave(s);
                        p.encripta();
                        arquivoS<<"criptografia:   "<<"Entrada:"<<p.getEntrada()<<"  Chave:"<<p.getChave()<<"  Saida:"<<p.getSaida()<<endl;
                        arquivoS.close();
                        cout<<endl<<"A mensagem encriptada �:"<<p.getSaida();
                    }
                    catch(EntradaInvalida &invalida){
                        cout<<"Erro: "<<invalida.what()<<endl;
                    }
                }

                if(i==2)
                 {
                    try{
                        system("cls");
                        cout<<"Digite a frase que ser� decriptada: (Somente letras min�sculas sem espa�os)"<<endl;
                        cin.ignore();
                        getline(cin, s);
                        p.setSaida(s);
                        cout<<endl<<"Digite a palavra chave:  (Uma palavra de qualquer tamanho contendo apenas letras min�sculas)"<<endl;
                        cin.ignore();
                        getline(cin, s);
                        p.setChave(s);
                        p.desencripta();
                        cout<<endl<<"A mensagem decriptada �:"<<p.getEntrada();
                        arquivoS<<"descriptografia:   "<<"Entrada:"<<p.getSaida()<<"  Chave:"<<p.getChave()<<"  Saida:"<<p.getEntrada()<<endl;
                        arquivoS.close();
                    }
                    catch(EntradaInvalida &invalida){
                        cout<<"Erro: "<<invalida.what()<<endl;
                    }
                }
            }
            else
            {
                system("cls");
                cout<<"N�o foi possivel abrir o arquivo";
            }

        }
        if(menu==3)
        {
            system("cls");
            arquivoS.open("unico.txt", ios::app);
            if(arquivoS.is_open())
            {
                cout<<"Cifra de uso �nico:"<<endl<<"Digite 1 para encriptar:"<<endl<<"Digite 2 para decriptar:"<<endl;
                cin>>i;
                if(i==1)
                {
                    try{
                        system("cls");
                        cout<<endl<<"Digite a frase que ser� encriptada: (Somente letras min�sculas sem espa�os)"<<endl;
                        cin.ignore();
                        getline(cin, s);
                        u.setEntrada(s);
                        cout<<"Gerando chave aleat�ria: ";
                        u.tamanhoChaveEntrada();
                        u.geraChave();
                        for(i=0; i<u.getEntrada().size(); i++)
                        {
                            cout<<"  "<<u.getChaves(i);
                        }
                        u.encripta();
                        arquivoS<<"criptografia:   "<<"Entrada:"<<u.getEntrada()<<"  Chave:";
                        for(i=0; i<u.getEntrada().size(); i++)
                        {
                            arquivoS<<" "<<u.getChaves(i);
                        }
                        arquivoS<<"  Saida:"<<u.getSaida()<<endl;
                        arquivoS.close();
                        cout<<endl<<endl<<"A mensagem encriptada �: "<<u.getSaida();
                    }
                    catch(EntradaInvalida &invalida){
                        cout<<"Erro: "<<invalida.what()<<endl;
                    }
                }
                if(i==2)
                {
                    try{
                        system("cls");
                        cout<<endl<<"Digite a frase encriptada: (Somente letras min�sculas)"<<endl;
                        cin.ignore();
                        getline(cin, s);
                        u.setSaida(s);
                        u.tamanhoChaveSaida();
                        cout<<endl<<"Digite as chaves:"<<endl;
                        for(i=0; i<u.getSaida().size(); i++)
                        {
                            cout<<i +1<<"�"<<" chave:";
                            cin>>k;
                            u.setChaves(i,k);
                        }
                        u.descriptografa();
                        arquivoS<<"descriptografia:   "<<"Entrada:"<<u.getSaida()<<"  Chave:";
                        for(i=0; i<u.getSaida().size(); i++)
                        {
                            arquivoS<<" "<<u.getChaves(i);
                        }
                        arquivoS<<"  Saida:"<<u.getEntrada()<<endl;
                        arquivoS.close();
                        cout<<endl<<endl<<"A frase decriptada �:"<<u.getEntrada();
                    }
                    catch(EntradaInvalida &invalida){
                        cout<<"Erro: "<<invalida.what()<<endl;
                    }
                }
            }
            else
            {
                system("cls");
                cout<<"N�o foi possivel abrir o arquivo";
            }
        }
        if(menu==4)
        {
            system("cls");
            arquivoS.open("coluna.txt", ios::app);
            if(arquivoS.is_open())
            {
                cout<<"Cifra de transposi��o de colunas:"<<endl<<"Digite 1 para encriptar:"<<endl<<"Digite 2 para decriptar:"<<endl;
                cin>>i;
                if(i==1)
                {
                    try{
                        system("cls");
                        cout<<endl<<"Digite a palavra chave: (Palavra de qualquer tamanho sem caracteres repetidos e somente com letras min�sculas)"<<endl;
                        cin.ignore();
                        getline(cin, s);
                        t.setChave(s);
                        cout<<"Digite a frase que ser� encriptada: (Somente letras min�sculas sem espa�os)"<<endl;
                        cin.ignore();
                        getline(cin, s);
                        t.setEntrada(s);
                        t.encripta();
                        arquivoS<<"criptografia:  "<<"Entrada:"<<t.getEntrada()<<"  Chave:"<<t.getChave()<<"  Saida:"<<t.getSaida()<<endl;
                        arquivoS.close();
                        cout<<endl<<"A mensagem encriptada �:"<<t.getSaida();
                    }
                    catch(DividirPorZero &divisao){
                        cout<<"Erro: "<<divisao.what()<<endl;
                    }
                    catch(EntradaInvalida &invalida){
                        cout<<"Erro: "<<invalida.what()<<endl;
                    }
                }

                if(i==2)
                {
                    try{
                        system("cls");
                        cout<<endl<<"Digite a palavra chave: (Palavra de qualquer tamanho sem caracteres repetidos e somente com letras min�sculas)"<<endl;
                        cin.ignore();
                        getline(cin, s);
                        t.setChave(s);
                        cout<<"Digite a mensagem que ser� decriptada: (Somente letras min�sculas sem espa�os)"<<endl;
                        cin.ignore();
                        getline(cin, s);
                        t.setEntrada(s);
                        t.descriptografa();
                        arquivoS<<"descriptografia:  "<<"Entrada:"<<t.getEntrada()<<"  Chave:"<<t.getChave()<<"  Saida:"<<t.getSaida()<<endl;
                        arquivoS.close();
                        cout<<endl<<"A mensagem decriptada �:"<<t.getSaida();
                        }
                    catch(DividirPorZero &divisao){
                        cout<<"Erro: "<<divisao.what()<<endl;
                    }
                    catch(EntradaInvalida &invalida){
                        cout<<"Erro: "<<invalida.what()<<endl;
                    }
                }
            }
            else
            {
                system("cls");
                cout<<"N�o foi poss�vel abrir o arquivo.";
            }
        }
        if(menu==5)
        {
            system("cls");
            arquivoS.open("enigma.txt", ios::app);
            if(arquivoS.is_open())
            {
                cout<<"M�quina enigma"<<endl;
                cout<<endl<<"Defina quais rotores ir� usar(3 n�meros diferentes de 1 a 5)"<<endl;
                for(k=0;k<3;k++)
                {
                    try{
                        cout<<"rotor "<<k+1<<":";
                        cin>>i;
                        e.setescolha(k,i);
                    }
                    catch(EntradaInvalida &invalida){
                        cout<<"Erro: "<<invalida.what()<<endl;
                        k--;
                    }
                }

                cout<<endl<<"Defina os an�is dos rotores (3 n�meros  de 1 a 26)"<<endl;
                for(k=0;k<3;k++)
                {
                    try{
                        cout<<"anel "<<k+1<<":";
                        cin>>i;
                        e.setanel(k,i);
                    }
                    catch(EntradaInvalida &invalida){
                        cout<<"Erro: "<<invalida.what()<<endl;
                        k--;
                    }
                }

                cout<<endl<<"Defina a rota��o dos rotores(3 n�meros de 1 a 26)"<<endl;
                for(k=0;k<3;k++)
                {
                    try{
                        cout<<"rota��o "<<k+1<<":";
                        cin>>i;
                        e.setrotacao(k,i);
                    }
                    catch(EntradaInvalida &invalida){
                        cout<<"Erro: "<<invalida.what()<<endl;
                        k--;
                    }
                }

                arquivoS<<"Rotores escolhidos: "<<e.getescolha(0)<<","<<e.getescolha(1)<<","<<e.getescolha(2);
                arquivoS<<"  Posic�o dos an�is: "<<e.getanel(0)<<","<<e.getanel(1)<<","<<e.getanel(2);
                arquivoS<<"  Rotac�o dos rotores: "<<e.getrotacao(0)<<","<<e.getrotacao(1)<<","<<e.getrotacao(2);
                while (i){
                    try{
                        cout<<endl<<"Digite a frase de entrada: (Somente letras min�sculas sem espa�os)"<<endl;
                        cin.ignore();
                        getline(cin, s);
                        e.setEntrada(s);
                        i = 0;
                    }
                    catch(EntradaInvalida &invalida){
                        cout<<"Erro: "<<invalida.what()<<endl;
                        i = 1;
                    }
                }
                arquivoS<<"  Letras trocadas: ";
                while(i)
                {
                    cout<<endl<<"Digite 1 para conectar letras, 0 para continuar:";
                    cin>>i;
                    if(i==1)
                    {
                        try{
                            cout<<"Digite a 1 letra:";
                            cin>>c1;
                            cout<<"Digite a 2 letra:";
                            cin>>c2;
                            e.trocaletras(c1,c2);
                            arquivoS<<c1<<"&"<<c2<<" , ";
                            e.setletras(c1,c2);
                        }
                        catch(EntradaInvalida &invalida){
                            cout<<"Erro: "<<invalida.what()<<endl;
                        }
                    }

                }
                e.encripta();
                e.auxiliatroca();
                cout<<endl<<"A mensagem encriptada �: "<<e.getSaida();
                arquivoS<<" Entrada:"<<s<<"  Sa�da:"<<e.getSaida()<<endl;
                arquivoS.close();
            }
            else
            {
                system("cls");
                cout<<"N�o foi poss�vel abrir o arquivo.";
            }

        }
        if(menu==6)
        {
            try{
                system("cls");
                cout<<"Digite qual m�todo quer acessar o historico:"<<endl<<"1:Cifra de C�sar:"<<endl<<"2:Cifra polialfab�tica:"<<endl<<"3:Cifra de uso �nico:"<<endl<<"4:Cifra de transposi��o de colunas:"<<endl<<"5:M�quina enigma"<<endl;
                cin>>i;
                if (i < 1 || i > 5)
                    throw EntradaInvalida ("Somente valores entre 1 e 5");
            }
            catch(EntradaInvalida &invalida){
                cout<<"Erro: "<<invalida.what()<<endl;
            }

            if(i==1)
            {
                system("cls");
                arquivoE.open("cezar.txt");
                if(arquivoE.is_open())
                {
                    while(getline(arquivoE,s))
                        cout<<s<<endl<<endl;
                    arquivoE.close();
                }
                else
                {
                    system("cls");
                    cout<<"N�o foi poss�vel abrir o arquivo";
                }
            }

            if(i==2)
            {
            	system("cls");
                arquivoE.open("poli.txt");
                if(arquivoE.is_open())
                {
                    while(getline(arquivoE,s))
                        cout<<s<<endl<<endl;
                    arquivoE.close();
                }
                else
                {
                    system("cls");
                    cout<<"N�o foi poss�vel abrir o arquivo";
                }

            }
            if(i==3)
            {
                system("cls");
                arquivoE.open("unico.txt");
                if(arquivoE.is_open())
                {
                    while(getline(arquivoE,s))
                        cout<<s<<endl<<endl;
                    arquivoE.close();
                }
                else
                {
                    system("cls");
                    cout<<"N�o foi poss�vel abrir o arquivo";
                }

            }
            if(i==4)
            {
                system("cls");
                arquivoE.open("coluna.txt");
                if(arquivoE.is_open())
                {
                    while(getline(arquivoE,s))
                        cout<<s<<endl<<endl;
                    arquivoE.close();
                }
                else
                {
                    system("cls");
                    cout<<"N�o foi poss�vel abrir o arquivo";
                }

            }
            if(i==5)
            {
                system("cls");
                arquivoE.open("enigma.txt");
                if(arquivoE.is_open())
                {
                    while(getline(arquivoE,s))
                        cout<<s<<endl<<endl;
                    arquivoE.close();
                }
                else
                {
                    system("cls");
                    cout<<"N�o foi poss�vel abrir o arquivo";
                }
            }
        }

        if (menu){
            cout<<endl<<"Digite 1 para continuar usando o programa ou 0 para sair";
            cin>>i;
        }
        else
            i = 0;

    }

    return 0;
}
