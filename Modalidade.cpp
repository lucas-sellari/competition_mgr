#include "Modalidade.h"

#include <iostream>
#include <string>
#include <stdexcept>

#include "Equipe.h"
#include "TabelaComOrdem.h"

using namespace std;


Modalidade::Modalidade(string nome, Equipe** participantes, int quantidade) //quanridade == quanridade de equipes
{
    if(quantidade < 2) {
        throw new invalid_argument("quantidade de equipes menor que 2");
    }

    this->nome = nome;
    this->quantidade = quantidade;

    this->participantes = new Equipe*[quantidade];
    this->participantes = participantes;

    this->tabela = new TabelaComOrdem(participantes, quantidade);
}

Modalidade::~Modalidade()
{
    delete tabela;
}

string Modalidade::getNome()
{
    return nome;
}

Equipe** Modalidade::getEquipes()
{
    return participantes;
}

int Modalidade::getQuantidadeDeEquipes()
{
    return quantidade;
}

void Modalidade::setResultado(Equipe** ordem)
{
    tabela->setResultado(ordem);
    hasResult = true;
}

bool Modalidade::temResultado()
{
    return hasResult;
}

TabelaComOrdem* Modalidade::getTabela()
{
    return tabela;
}

void Modalidade::imprimir()
{
    //cout << "Modalidade: " << nome << endl;
    tabela->imprimir();
}
