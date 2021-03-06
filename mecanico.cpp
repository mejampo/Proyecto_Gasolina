#include "mecanico.h"
#include "carro.h"


Mecanico::Mecanico(QString placa, QString marca, QString cilindraje,QString año,QString tipo):Carro(placa, marca, cilindraje,año),tipo(tipo){

    this -> tipo=tipo;
}

Mecanico::Mecanico(const Mecanico &r):Carro(r){

    this -> tipo= r.getTipo();
}

QString Mecanico::toString() const
{
    QString q=placa+" , "+marca+" , "+cilindraje+" , "+año+" , "+tipo;
    return q;
}

int Mecanico::cantidadGas()
{

}


QString Mecanico::getTipo() const
{
    return tipo;
}

void Mecanico::setTipo(const QString &value)
{
    tipo = value;
}

