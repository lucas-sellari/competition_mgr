#ifndef PERSISTENCIADECOMPETICAO_H
#define PERSISTENCIADECOMPETICAO_H

#include <iostream>
#include <string>
#include <stdexcept>

#include <fstream>

#include "Competicao.h"

using namespace std;

class PersistenciaDeCompeticao
{
    public:
        PersistenciaDeCompeticao();
        virtual ~PersistenciaDeCompeticao();

        Competicao* carregar(string arquivo);
        void salvar(string arquivo, Competicao* c);


    protected:

    private:
        //string arquivo;
};

#endif // PERSISTENCIADECOMPETICAO _H
