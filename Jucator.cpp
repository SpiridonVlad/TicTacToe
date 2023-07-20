#include "Jucator.h"

Jucator::Jucator(string name,string piesa)
{
    this->name = name;
    this->piesa = piesa;
    this->scor = 0;
}


int Jucator::GetScor()
{
    return this->scor;
}

string Jucator::GetName()
{
    return name;
}

string Jucator::GetPiesa()
{
    return this->piesa;
}

void Jucator::operator++()
{
    this->scor++;
}
