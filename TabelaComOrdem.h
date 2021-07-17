#ifndef TABELACOMORDEM_H
#define TABELACOMORDEM_H

#include <iostream>
#include <stdexcept>

#include "Equipe.h"
#include "Tabela.h"

using namespace std;


class TabelaComOrdem : public Tabela
{
    public:
        TabelaComOrdem (Equipe** participantes, int quantidade);
        virtual ~TabelaComOrdem();

        void setResultado (Equipe** ordem);

        //METODOS ANTES ABSTRATOS
        virtual int getPosicao (Equipe* participante);   //VIRTUAIS?
        virtual Equipe** getEquipesEmOrdem();
        virtual void imprimir();

    protected:

    private:
        Equipe** ordem;
        bool temResultado = false;
};

#endif // TABELACOMORDEM_H
