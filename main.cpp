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
#include "PersistenciaDeCompeticao.h"

using namespace std;

int main()
{
    try {
        string sn, nomeCompeticao, sm;

        cout << "Deseja carregar uma competicao (s/n)? ";
        cin >> sn;

        if(sn == "n") {
            int quantidadeEquipes;

            cout << endl;
            cout << "Informe a quantidade de equipes: ";
            cin >> quantidadeEquipes;

            Equipe** equipes = new Equipe*[quantidadeEquipes];   //TODAS AS EQUIPES PARTICIPANTES DA COMPETICAO

            for(int i = 0; i < quantidadeEquipes; i++) {
                string nomeEquipe;
                cout << "Informe o nome da equipe " << i+1 <<": ";
                cin >> nomeEquipe;

                equipes[i] = new Equipe(nomeEquipe);
            }
            cout << endl;

            cout << "Informe o nome da competicao: ";
            cin >> nomeCompeticao;

            cout << "Competicao simples (s) ou multimodalidades (m): ";
            cin >> sm;
            cout << endl;

            if(sm == "s") {                         //COMPETICAO SIMPLES
                string nomeModalidade;
                cout << "Informe o nome da modalidade: ";
                cin >> nomeModalidade;

                Modalidade* modalidade = new Modalidade(nomeModalidade, equipes, quantidadeEquipes);

                cout << "Tem resultado (s/n): ";
                cin >> sn;


                if(sn == "s") {

                    Equipe** participantesModalidade = new Equipe*[quantidadeEquipes];

                    for(int i = 0; i < quantidadeEquipes; i++) {
                        int colocada;
                        cout << "Informe a equipe " << i+1 <<"a colocada: ";
                        cin >> colocada;

                        participantesModalidade[i] = equipes[colocada-1];
                    }

                    modalidade->setResultado(participantesModalidade);
                }
                cout << endl;

                CompeticaoSimples* competicaoSimples = new CompeticaoSimples(nomeCompeticao, equipes, quantidadeEquipes, modalidade);

                cout << "Deseja salvar a competicao (s/n)? ";
                cin >> sn;


                if(sn == "s") {
                    string nomeArquivo;
                    cout << "Digite o nome do arquivo: ";
                    cin >> nomeArquivo;
                    cout << endl;

                    PersistenciaDeCompeticao* persistencia = new PersistenciaDeCompeticao();
                    persistencia->salvar(nomeArquivo, competicaoSimples);
                }

                cout << endl;

                competicaoSimples->imprimir();

            }

            if(sm == "m") {                         //COMPETICAO MULTIMODALIDADES
                int quantidadeModalidades;
                cout << "Informe a quantidade de modalidades: ";
                cin >> quantidadeModalidades;

                CompeticaoMultimodalidades* competicaoMulti = new CompeticaoMultimodalidades(nomeCompeticao, equipes, quantidadeEquipes);

                for(int i = 0; i < quantidadeModalidades; i++) {
                    string nomeModalidade;
                    cout << "Informe o nome da modalidade " << i+1 << ": ";
                    cin >> nomeModalidade;

                    cout << "Tem resultado (s/n): ";
                    cin >> sn;

                    Modalidade* modalidade = new Modalidade(nomeModalidade, equipes, quantidadeEquipes);

                    if(sn == "s") {

                        Equipe** participantesModalidade = new Equipe*[quantidadeEquipes];

                        for(int j = 0; j < quantidadeEquipes; j++) {
                            int colocada;
                            cout << "Informe a equipe " << j+1 <<"a colocada: ";
                            cin >> colocada;

                            participantesModalidade[j] = equipes[colocada-1];
                        }


                        modalidade->setResultado(participantesModalidade);
                    }

                    competicaoMulti->adicionar(modalidade);
                    cout << endl;
                }




                cout << "Deseja salvar a competicao (s/n)? ";
                cin >> sn;
                cout << endl;

                if(sn == "s") {
                    string nomeArquivo;
                    cout << "Digite o nome do arquivo: ";
                    cin >> nomeArquivo;
                    cout << endl;

                    PersistenciaDeCompeticao* persistencia = new PersistenciaDeCompeticao();

                    persistencia->salvar(nomeArquivo, competicaoMulti);
                }

                competicaoMulti->imprimir();
            }
        }

        else {
            string nomeArquivo;
            cout << "Digite o nome do arquivo: ";
            cin >> nomeArquivo;
            cout << endl;

            PersistenciaDeCompeticao* persistente = new PersistenciaDeCompeticao();

            Competicao* competicaoSM = persistente->carregar(nomeArquivo);

            competicaoSM->imprimir();


        }

        return 0;

    }

    catch (invalid_argument* e) {
        cout << "Erro: " << e->what();
        delete e;
    }

    catch (logic_error* e) {
       cout << "Erro: " << e->what();
       delete e;
    }
}
