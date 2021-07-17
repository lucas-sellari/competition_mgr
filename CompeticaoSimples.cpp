#include "CompeticaoSimples.h"

#include <iostream>
#include <string>
#include <stdexcept>

#include "Equipe.h"
#include "Competicao.h"
#include "Modalidade.h"

using namespace std;


CompeticaoSimples::CompeticaoSimples(string nome, Equipe** equipes, int quantidade, Modalidade* m): Competicao(nome, equipes, quantidade)
{
    if(quantidade < 2)
        throw new invalid_argument("Numero de equipes menor que 2");

    //this->modalidade = new Modalidade;
    modalidade = m;
}

CompeticaoSimples::~CompeticaoSimples()
{
    //
}

Modalidade* CompeticaoSimples::getModalidade()
{
    return modalidade;
}

Tabela* CompeticaoSimples::getTabela()
{
    return modalidade->getTabela();
}

void CompeticaoSimples::imprimir()
{
    cout << nome << endl;

    /*if(modalidade->temResultado() == false) {
        for(int i = 0; i < quantidade; i++) {
            cout << "\t" << equipes[i]->getNome() << endl;
        }
    }

    else {

    } */

    modalidade->imprimir(); // NOT RLY SURE
}
