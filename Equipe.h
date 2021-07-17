#ifndef EQUIPE_H
#define EQUIPE_H

#include <iostream>
#include <string>

using namespace std;

class Equipe
{
    public:
        Equipe(string nome);
        virtual ~Equipe();

        virtual string getNome();
        virtual void imprimir();

    protected:

    private:
        string nome;
};

#endif // EQUIPE_H
