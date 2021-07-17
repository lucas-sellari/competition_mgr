#include "CompeticaoMultimodalidades.h"

#include <iostream>
#include <string>
#include <stdexcept>

#include <list>
#include <vector>

#include "Competicao.h"
#include "Equipe.h"
#include "Modalidade.h"
#include "Tabela.h"
#include "TabelaComPontos.h"
#include "TabelaComOrdem.h"

using namespace std;

vector<int>* CompeticaoMultimodalidades::pontuacao = new vector<int>({13, 10, 8, 7, 5, 4, 3, 2, 1});  //VALOR INCINIAL DESRE ATRIBUTO ESTATICO

CompeticaoMultimodalidades::CompeticaoMultimodalidades(string nome, Equipe** equipes, int quantidade) : Competicao(nome, equipes, quantidade)
{
    if(quantidade < 2)
        throw new invalid_argument("Numero de equipes menor que 2");

    this->modalidades = new list<Modalidade*>();
}

CompeticaoMultimodalidades::~CompeticaoMultimodalidades() {
    //
}

void CompeticaoMultimodalidades::adicionar(Modalidade* m)
{
    modalidades->push_back(m);
    hasModalidade = true;
}

list<Modalidade*>* CompeticaoMultimodalidades::getModalidades()
{
    return modalidades;
}

void CompeticaoMultimodalidades::setPontuacao(vector<int>* pontos)
{
    if(pontos->size() < 3)
        throw new invalid_argument("Que vetor mixuruca kk");

    CompeticaoMultimodalidades::pontuacao = pontos;
}

int CompeticaoMultimodalidades::getPontoPorPosicao(int posicao) //UNSIGNED? sdjfdkjsnmxc
{
    unsigned int posi = posicao;

    if(posi <= 0 || posi > CompeticaoMultimodalidades::pontuacao->size())
        return 0;

    else
        return CompeticaoMultimodalidades::pontuacao->at(posi - 1);
}

Tabela* CompeticaoMultimodalidades::getTabela()     //NOT SURE ABOUT ALL OF THIS
{
    TabelaComPontos* retorno = new TabelaComPontos(equipes, quantidade);

    list<Modalidade*>::iterator i = modalidades->begin();

    while(i != modalidades->end()) { //O END EH O NULL
        if((*i)->temResultado() == true){
            int quantidadeEquipesNaModalidade = (*i)->getQuantidadeDeEquipes(); //QUANTIDADE DE EQUIPES NESTA MODALIDADE

            /*  FOI TRISTE???? NAO FUNFOU, BUT IT SHOULD
            TabelaComOrdem* resultadoDaModalidade = (*i)->getTabela; //PEGA A TABELA COM ORDEM/RESULTADO DA MODALIDADE

            Equipe** ordemDasEquipes = resultadoDaModalidade->getEquipesEmOrdem(); // PEGA O VETOR COM A ORDEM DAS EQUIPES

            */

            Equipe** ordemEquipes = (*i)->getTabela()->getEquipesEmOrdem(); // PEGA O VETOR COM A ORDEM DAS EQUIPES

            for(int j = 0; j < quantidadeEquipesNaModalidade; j++) {
                retorno->pontuar(ordemEquipes[j], CompeticaoMultimodalidades::pontuacao->at(j)); //ATRIBUI A PONTUACAO CORRESPONDENTE DA EQUIPE NESTA MODALDIDAE DE ACORDO COM O VECTOR ESTATICO
            }
        }
        i++;
    }

    return retorno;
}

void CompeticaoMultimodalidades::imprimir()
{
    cout << nome << endl;

    if(hasModalidade != false) {
        getTabela()->imprimir();
    }

}
