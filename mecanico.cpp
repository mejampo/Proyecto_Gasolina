#include "mecanico.h"
#include "carro.h"


Mecanico(QString placa, QString marca, QString cilindraje,QString año, QString tipo){
    this -> placa=placa;
    this -> marca=marca;
    this -> cilindraje=cilindraje;
    this -> año=año;
    this -> tipo=tipo;
}

Mecanico(const Mecanico &r):Carro(r){
    this -> placa=r.getPlaca();
    this -> marca=r.getMarca();
    this -> cilindraje=r.getCilindraje();
    this -> año=r.getAño();
    this -> tipo= r.getTipo();
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

QString Mecanico::getTipo() const
{
    return tipo;
}

void Mecanico::setTipo(const QString &value)
{
    tipo = value;
}

QString Mecanico::toString()
{
    QString q=placa+" , "+marca+" , "+cilindraje+" , "+año+tipo;
    return q;

}
