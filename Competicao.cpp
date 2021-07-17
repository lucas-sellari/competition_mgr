#include "Competicao.h"

#include <iostream>
#include <string>
#include <stdexcept>

#include "Equipe.h"
//#include "Tabela.h"

using namespace std;


Competicao::Competicao(string nome, Equipe** equipes, int quantidade)
{
    if(quantidade < 2)
        throw new invalid_argument("Numero de equipes menor que 2");

    this->nome = nome;
    this->quantidade = quantidade;

    this->equipes = new Equipe*[quantidade];
    this->equipes = equipes;
}

Competicao::~Competicao()
{
    //
}

string Competicao::getNome()
{
    return nome;
}

Equipe** Competicao::getEquipes()
{
    return equipes;
}

int Competicao::getQuantidadeDeEquipes()
{
    return quantidade;
}
