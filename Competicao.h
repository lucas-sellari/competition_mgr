#ifndef COMPETICAO_H
#define COMPETICAO_H

#include <iostream>
#include <string>
#include <stdexcept>

#include "Equipe.h"
#include "Tabela.h"

using namespace std;

class Competicao
{
    public:
        Competicao(string nome, Equipe** equipes, int quantidade);
        virtual ~Competicao();

        string getNome();
        Equipe** getEquipes();
        int getQuantidadeDeEquipes();

        virtual Tabela* getTabela() = 0;  //ABSTRATOH
        virtual void imprimir() = 0;      //ABSTRATOH

    protected:
        string nome;
        Equipe** equipes;
        int quantidade;

    private:



};

#endif // COMPETICAO_H
