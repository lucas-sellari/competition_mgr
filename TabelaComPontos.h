#ifndef TABELACOMPONTOS_H
#define TABELACOMPONTOS_H

#include <iostream>
#include <stdexcept>

#include "Equipe.h"
#include "Tabela.h"

using namespace std;


class TabelaComPontos : public Tabela
{
    public:
        TabelaComPontos (Equipe** participantes, int quantidade);
        virtual ~TabelaComPontos();

        int getPontos (Equipe* participante);
        void pontuar (Equipe* participante, int pontos);

        //METODOS ANTES ABSTRATOS
        virtual int getPosicao (Equipe* participante);  //VRITUAIS?? amada
        virtual Equipe** getEquipesEmOrdem();
        virtual void imprimir();

    protected:

    private:
        int* pontuacao;
        bool temResultado = false;
};

#endif // TABELACOMPONTOS_H
