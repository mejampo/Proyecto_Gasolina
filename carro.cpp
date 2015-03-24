#include "carro.h"

Carro::Carro(QString placa, QString marca, QString cilindraje,QString año){
    this -> placa=placa;
    this -> marca=marca;
    this -> cilindraje=cilindraje;
    this -> año=año;
}

Carro::Carro(const Carro &r){
    this -> placa=r.getPlaca();
    this -> marca=r.getMarca();
    this -> cilindraje=r.getCilindraje();
    this -> año=r.getAño();
}


QString Carro::toString()
{
    QString q=placa+" , "+marca+" , "+cilindraje+" , "+año;
    return q;

}

QString Carro::getPlaca() const
{
    return placa;
}

void Carro::setPlaca(const QString &value)
{
    placa = value;
}

QString Carro::getMarca() const
{
    return marca;
}

void Carro::setMarca(const QString &value)
{
    marca = value;
}

QString Carro::getCilindraje() const
{
    return cilindraje;
}

void Carro::setCilindraje(const QString &value)
{
    cilindraje = value;
}

QString Carro::getAño() const
{
    return año;
}

void Carro::setAño(const QString &value)
{
    año = value;
}


