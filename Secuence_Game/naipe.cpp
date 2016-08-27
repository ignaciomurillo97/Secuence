#include "naipe.h"

Naipe::Naipe(int valor, QString palo, QString Url)
{
    setPixmap(Url);
    this->valor = valor;
    this->palo = palo;

    setPos(50, 50);
}

int Naipe::getValor() const
{
    return valor;
}

void Naipe::setValor(int value)
{
    valor = value;
}

QString Naipe::getPalo() const
{
    return palo;
}

void Naipe::setPalo(const QString &value)
{
    palo = value;
}

