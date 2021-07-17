#include "TabelaComPontos.h"

#include <iostream>
#include <stdexcept>

#include "Equipe.h"
#include "Tabela.h"

using namespace std;


TabelaComPontos::TabelaComPontos(Equipe** participantes, int quantidade): Tabela(participantes, quantidade)
{
    if(quantidade < 2)
        throw new invalid_argument("Menos de duas equipes nao neh kk");

    this->pontuacao = new int[quantidade];
    for(int i = 0; i < quantidade; i++)
        pontuacao[i] = 0;
}


TabelaComPontos::~TabelaComPontos()
{
    delete[] pontuacao;
}


int TabelaComPontos::getPontos(Equipe* participante)
{
    for(int i = 0; i < quantidade; i++) {
        if(participantes[i] == participante)
            return pontuacao[i];
    }
    throw new invalid_argument("Equipe nao participante");
}


void TabelaComPontos::pontuar(Equipe* participante, int pontos)
{
    for(int i = 0; i < quantidade; i++) {
        if(participantes[i] == participante) {
            pontuacao[i] = pontuacao[i] + pontos;
            temResultado = true;
        }

    }

    if(temResultado == false)
        throw new invalid_argument("Equipe nao participante");
}


int TabelaComPontos::getPosicao(Equipe* participante)
{
    if(temResultado == false)
        throw new logic_error("Ninguem tem ponto aindah");

    else {

        bool ehParticipante = false;                       //PROCURO SABER SE EH PARTICIPANTE
        for(int i = 0; i < quantidade; i++) {
            if(participante == participantes[i])
                ehParticipante = true;
        }

        if(ehParticipante == false)
            throw new invalid_argument("Essa equipe nao participah");


        int posicaoNaTabela = 1;
        int pontuacaoDeste;

        pontuacaoDeste = getPontos(participante);

        for(int i = 0; i < quantidade; i++) {
            if(pontuacaoDeste < pontuacao[i])
                posicaoNaTabela = posicaoNaTabela + 1;
        }

        return posicaoNaTabela;
    }

}


Equipe** TabelaComPontos::getEquipesEmOrdem()
{
    if(temResultado == false)
        throw new logic_error("Ninguem tem ponto kk");


    Equipe** equipesEmOrdem = new Equipe*[quantidade];

    for(int i = 0; i < quantidade; i++) {         //INCIALIZO O VETOR DE ORDEM COM POSICOES EM NULL
        equipesEmOrdem[i] = NULL;
    }

    for(int i = 0; i < quantidade; i++) {
        int posi = getPosicao(participantes[i]) - 1;//OQ FAZER QUANDO DUAS EQUIPES STAO NA MESMA POSI? SOS

        if(equipesEmOrdem[posi] != NULL)
            equipesEmOrdem[posi + 1] = participantes[i];    //JOGAR PRA PROXIMA POSI
        else
            equipesEmOrdem[posi] = participantes[i];
    }

    return equipesEmOrdem;
}


void TabelaComPontos::imprimir()
{
    if(temResultado == false) {
        for(int i = 0; i < quantidade; i++) {
            cout << "\t" << participantes[i]->getNome() << endl;
        }
    }


    else {
        Equipe** results = getEquipesEmOrdem();


        /*Equipe** results = new Equipe*[quantidade];
        results = getEquipesEmOrdem();*/

        for(int i = 0; i < quantidade; i++) {
            cout << "\t" << i+1 << "o " << results[i]->getNome() << " (" << getPontos(results[i]) << " pontos)" << endl;
        }
    }

}

