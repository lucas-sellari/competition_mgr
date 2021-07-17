#ifndef TABELA_H
#define TABELA_H

#include <iostream>
#include <stdexcept>

#include "Equipe.h"

using namespace std;


class Tabela
{
    public:
        Tabela(Equipe** participantes, int quantidade);
        virtual ~Tabela();

        virtual int getPosicao (Equipe* participante) = 0;  //ABSTRATO
        virtual Equipe** getEquipesEmOrdem() = 0; //ABSTRATO
        virtual int getQuantidadeDeEquipes();
        virtual void imprimir() = 0;    //ABSTRATO


    protected:
        Equipe** participantes;
        int quantidade;

    private:

};

#endif // TABELA_H
