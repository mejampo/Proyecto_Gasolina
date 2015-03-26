#include "automatico.h"
#include "carro.h"


Automatico::Automatico(QString placa, QString marca, QString cilindraje,QString año,QString tipo):Carro(placa, marca, cilindraje,año),tipo(tipo){

}

Automatico::Automatico(const Automatico &r):Carro(r){

    this -> tipo= r.getTipo();
}

QString Automatico::toString() const
{
    QString q=placa+" , "+marca+" , "+cilindraje+" , "+año+" , "+tipo;
    return q;
}

int Automatico::cantidadGas()
{

}



QString Automatico::getTipo() const
{
    return tipo;
}

void Automatico::setTipo(const QString &value)
{
    tipo = value;
}

