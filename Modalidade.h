#ifndef MODALIDADE_H
#define MODALIDADE_H

#include <iostream>
#include <string>
#include <stdexcept>

#include "Equipe.h"
#include "TabelaComOrdem.h"

using namespace std;


class Modalidade
{
    public:
        Modalidade(string nome, Equipe** participantes, int quantidade);   //quanridade == quanridade de equipes
        virtual ~Modalidade();

        virtual string getNome();
        virtual Equipe** getEquipes();
        virtual int getQuantidadeDeEquipes();
        virtual void setResultado(Equipe** ordem);
        virtual bool temResultado();
        virtual TabelaComOrdem* getTabela();
        virtual void imprimir();

    protected:

    private:
        string nome;
        Equipe** participantes;
        int quantidade;

        bool hasResult = false;

        TabelaComOrdem* tabela;
};

#endif // MODALIDADE_H
