#include "Tabela.h"

#include <iostream>
#include <stdexcept>

#include "Equipe.h"

using namespace std;

Tabela::Tabela(Equipe** participantes, int quantidade)
{
    if(quantidade < 2)
        throw new invalid_argument("Quantidade de equipes menor que 2");

    this->participantes = new Equipe*[quantidade];
    this->participantes = participantes;

    this->quantidade = quantidade;
}

Tabela::~Tabela()
{
    //
}


int Tabela::getQuantidadeDeEquipes()
{
    return quantidade;
}


