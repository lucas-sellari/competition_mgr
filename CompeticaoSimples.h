#ifndef COMPETICAOSIMPLES_H
#define COMPETICAOSIMPLES_H

#include <iostream>
#include <string>
#include <stdexcept>

#include "Equipe.h"
#include "Competicao.h"
#include "Modalidade.h"

using namespace std;

class CompeticaoSimples : public Competicao
{
    public:
        CompeticaoSimples(string nome, Equipe** equipes, int quantidade, Modalidade* m);
        virtual ~CompeticaoSimples();

        Modalidade* getModalidade();

        //ANTES ERAM ABSTRATOS
        virtual Tabela* getTabela();
        virtual void imprimir();

    protected:

    private:
        Modalidade* modalidade;
};

#endif // COMPETICAOSIMPLES_H
