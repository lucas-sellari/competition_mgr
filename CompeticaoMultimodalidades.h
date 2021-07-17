#ifndef COMPETICAOMULTIMODALIDADES_H
#define COMPETICAOMULTIMODALIDADES_H

#include <iostream>
#include <string>
#include <stdexcept>

#include <list>
#include <vector>

#include "Competicao.h"
#include "Equipe.h"
#include "Modalidade.h"


using namespace std;

class CompeticaoMultimodalidades : public Competicao
{
    public:
        CompeticaoMultimodalidades(string nome, Equipe** equipes, int quantidade);
        virtual ~CompeticaoMultimodalidades();

        void adicionar(Modalidade* m);
        list<Modalidade*>* getModalidades();

        static void setPontuacao(vector<int>* pontos);   //METODO COM ESCOPO DE CLASSE
        static int getPontoPorPosicao(int posicao);      //METODO COM ESCOPO DE CLASSE

        //ANTES ABSTRATAHS
        virtual Tabela* getTabela();  //ABSTRATOH
        virtual void imprimir();

    protected:

    private:
        list<Modalidade*>* modalidades;
        static vector<int>* pontuacao;

        bool hasModalidade = false;
};

#endif // COMPETICAOMULTIMODALIDADES_H
