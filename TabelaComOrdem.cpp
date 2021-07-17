#include "TabelaComOrdem.h"

#include <iostream>
#include <stdexcept>

#include "Equipe.h"
#include "Tabela.h"

using namespace std;


TabelaComOrdem::TabelaComOrdem(Equipe** participantes, int quantidade): Tabela(participantes, quantidade)
{

    if(quantidade < 2)
        throw new invalid_argument("Menos de duas equipes participantes nao pode neh kk");

    this->ordem = new Equipe*[quantidade];

    /*for(int i = 0; i < quantidade; i++)
        this->ordem[i] = NULL; */  //NOT SURE IF I NEED THIS
}


TabelaComOrdem::~TabelaComOrdem()
{
    //
}


void TabelaComOrdem::setResultado(Equipe** ordem)
{
    this->ordem = ordem;
    temResultado = true;
}


int TabelaComOrdem::getPosicao (Equipe* participante) {


    if(temResultado == false)
        throw new logic_error("A ordem ainda nao foi definida");

    for(int i = 0; i < quantidade; i++) {
        if(participantes[i] == participante)
            return i + 1;
    }
    throw new invalid_argument("Essa equipe nao participa");
}


Equipe** TabelaComOrdem::getEquipesEmOrdem() {
    if(temResultado == false)
        throw new logic_error("ordem ainda nao definidah");

    return ordem;
}


void TabelaComOrdem::imprimir() {
    if(temResultado == false) {
        for(int i = 0; i < quantidade; i++) {
            cout << "\t" << participantes[i]->getNome() << endl;
        }
    }


    else {
        for(int i = 0; i < quantidade; i++) {
            cout << "\t" << i+1 << "o " << ordem[i]->getNome() << endl;
        }
    }

}
