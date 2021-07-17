/*VERIFICACAO DE ERROS DAJIFGKDFNSLAMKERÇLSKDFDJGNk*/

#include "PersistenciaDeCompeticao.h"

#include <iostream>
#include <string>
#include <stdexcept>

#include <fstream>

#include "Competicao.h"
#include "Equipe.h"
#include "Modalidade.h"
#include "Competicao.h"
#include "CompeticaoSimples.h"
#include "CompeticaoMultimodalidades.h"

#include <list>

using namespace std;

PersistenciaDeCompeticao ::PersistenciaDeCompeticao ()
{

}

PersistenciaDeCompeticao ::~PersistenciaDeCompeticao ()
{
    //dtor
}


Competicao* PersistenciaDeCompeticao::carregar(string arquivo)  //CRIA UM NOVO OBJETO COMPETICAO A PARTIR DAS INFOS DO TXT
{
    ifstream leitura;
    leitura.open(arquivo);

    if(leitura.fail())
        throw new invalid_argument("Arquivo nao encontrado");

    int quantidadeEquipes;
    leitura >> quantidadeEquipes;
    if(leitura.fail())
        throw new invalid_argument("Formato de arquivo incorreto");

    Equipe** equipes = new Equipe*[quantidadeEquipes];    //VETOR COM AS EQUIPES PARTICIPANTES

    for(int i = 0; i < quantidadeEquipes; i++) {
        string nomeEquipe;
        leitura >> nomeEquipe;
        if(leitura.fail())
            throw new invalid_argument("Formato de arquivo incorreto");
        equipes[i] = new Equipe(nomeEquipe);
    }

    string nomeCompeticao;
    leitura >> nomeCompeticao;
    if(leitura.fail())
        throw new invalid_argument("Formato de arquivo incorreto");

    int tipoDeCompeticao;
    leitura >> tipoDeCompeticao;
    if(leitura.fail())
        throw new invalid_argument("Formato de arquivo incorreto");

    if(tipoDeCompeticao == 0) {           //COMPETICAO SIMPLES
        string nomeModalidade;
        leitura >> nomeModalidade;
        if(leitura.fail())
            throw new invalid_argument("Formato de arquivo incorreto");

        int hasResultado;
        leitura >> hasResultado;
        if(leitura.fail())
            throw new invalid_argument("Formato de arquivo incorreto");

        int quantidadeParticipantes;
        leitura >> quantidadeParticipantes;
        if(leitura.fail())
            throw new invalid_argument("Formato de arquivo incorreto");

        Equipe** participantes = new Equipe*[quantidadeParticipantes];

        for(int i = 0; i < quantidadeParticipantes; i++) {
            string nomeParticipante;
            leitura >> nomeParticipante;
            if(leitura.fail())
                throw new invalid_argument("Formato de arquivo incorreto");

            for(int j = 0; j < quantidadeEquipes; j++) {
                if(equipes[j]->getNome() == nomeParticipante) {
                    participantes[i] = equipes[j];
                }
            }
        }

        Modalidade* modalidade = new Modalidade(nomeModalidade, participantes, quantidadeParticipantes);

        if(hasResultado == 1) {
            modalidade->setResultado(participantes);
        }

        CompeticaoSimples* competicao = new CompeticaoSimples(nomeCompeticao, equipes, quantidadeEquipes, modalidade);

        leitura.close();

        return competicao;
    }

    else {                            //COMPETICAO MULTIMODALIDADES
        int numeroModalidades;
        leitura >> numeroModalidades;
        if(leitura.fail())
            throw new invalid_argument("Formato de arquivo incorreto");

        CompeticaoMultimodalidades* competicao = new CompeticaoMultimodalidades(nomeCompeticao, equipes, quantidadeEquipes);

        for(int i = 0; i < numeroModalidades; i++) {
            string nomeModalidade;
            leitura >> nomeModalidade;
            if(leitura.fail())
                throw new invalid_argument("Formato de arquivo incorreto");

            int hasResultado;
            leitura >> hasResultado;
            if(leitura.fail())
                throw new invalid_argument("Formato de arquivo incorreto");

            int quantidadeParticipantes;
            leitura >> quantidadeParticipantes;
            if(leitura.fail())
                throw new invalid_argument("Formato de arquivo incorreto");

            Equipe** participantes = new Equipe*[quantidadeParticipantes];

            for(int i = 0; i < quantidadeParticipantes; i++) {
                string nomeParticipante;
                leitura >> nomeParticipante;
                if(leitura.fail())
                    throw new invalid_argument("Formato de arquivo incorreto");

                for(int j = 0; j < quantidadeEquipes; j++) {
                    if(equipes[j]->getNome() == nomeParticipante) {
                        participantes[i] = equipes[j];
                    }
                }
            }

            Modalidade* modalidade = new Modalidade(nomeModalidade, participantes, quantidadeParticipantes);

            if(hasResultado == 1) {
                modalidade->setResultado(participantes);
            }

            competicao->adicionar(modalidade);

        }

        leitura.close();

        return competicao;
    }


}

void PersistenciaDeCompeticao::salvar(string arquivo, Competicao* c)  //CRIA UM TXT COM AS INFOS DA COMPETICAO
{
    ofstream escrita;
    escrita.open(arquivo, ios_base::app);

    if(escrita.fail())
        throw new invalid_argument("Arquivo nao encontrado");

    int quantidadeEquipes = c->getQuantidadeDeEquipes();
    escrita << quantidadeEquipes;
    escrita << "\n";

    Equipe** equipes = c->getEquipes();

    for(int i = 0; i < quantidadeEquipes; i++) {
        string nomeEquipe = equipes[i]->getNome();
        escrita << nomeEquipe;
        escrita << "\n";
    }

    string nomeCompeticao = c->getNome();
    escrita << nomeCompeticao;
    escrita << "\n";

    //COMO SABER QUAL EH O TIPO DE COMPETICAO???
    int tipoCompeticao;
    CompeticaoSimples* competicaoSimples = dynamic_cast<CompeticaoSimples*>(c);
    CompeticaoMultimodalidades* competicaoMulti = dynamic_cast<CompeticaoMultimodalidades*>(c);

    if(competicaoSimples != NULL)
        tipoCompeticao = 0;
    else
        tipoCompeticao = 1;

    escrita << tipoCompeticao;
    escrita << "\n";

    if(tipoCompeticao == 0) {       //SE EH COMPETICAO SIMPLES
        string nomeModalidade = competicaoSimples->getModalidade()->getNome();
        escrita << nomeModalidade;
        escrita << "\n";

        bool hasResult = competicaoSimples->getModalidade()->temResultado();  //VERIFICA SE A MODALIDADE TEM RESULTS

        Equipe** participantesEmOrdem;

        if(hasResult == true) {
            escrita << 1;
            escrita << "\n";
            participantesEmOrdem = competicaoSimples->getModalidade()->getTabela()->getEquipesEmOrdem();
        }

        else {
            escrita << 0;
            escrita << "\n";
            participantesEmOrdem = competicaoSimples->getModalidade()->getEquipes();
        }

        int quantidadeParticipantes = competicaoSimples->getModalidade()->getQuantidadeDeEquipes();

        escrita << quantidadeParticipantes;
        escrita << "\n";

        for(int i = 0; i < quantidadeParticipantes; i++) {
            string nomeParticipante = participantesEmOrdem[i]->getNome();
            escrita << nomeParticipante;
            escrita << "\n";
        }
    }

    else {           //SE EH COMPETICAO MULTIMODALIDADES...
        list<Modalidade*>* listaModalidades = competicaoMulti->getModalidades();
        int numeroModalidades = listaModalidades->size();
        escrita << numeroModalidades;
        escrita << "\n";


        list<Modalidade*>::iterator i = listaModalidades->begin();

        while(i != listaModalidades->end()) {
            string nomeModalidade = (*i)->getNome();
            escrita << nomeModalidade;
            escrita << "\n";

            bool hasResult = (*i)->temResultado();

            Equipe** participantesEmOrdem;

            if(hasResult == true) {
                escrita << 1;
                escrita << "\n";
                participantesEmOrdem = (*i)->getTabela()->getEquipesEmOrdem();
            }

            else {
                escrita << 0;
                escrita << "\n";
                participantesEmOrdem = (*i)->getEquipes();
            }

            int quantidadeParticipantes = (*i)->getQuantidadeDeEquipes();

            escrita << quantidadeParticipantes;
            escrita << "\n";

            for(int j = 0; j < quantidadeParticipantes; j++) {
                string nomeParticipante = participantesEmOrdem[j]->getNome();
                escrita << nomeParticipante;
                escrita << "\n";
            }

            i++;

        }

    }

    escrita.close();
}

