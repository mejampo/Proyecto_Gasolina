#include "automatico.h"
#include "carro.h"

Automatico(QString tipo):Carro(QString placa, QString marca, QString cilindraje,QString año){
    this -> placa=placa;
    this -> marca=marca;
    this -> cilindraje=cilindraje;
    this -> año=año;
    this -> tipo=tipo;
}

Automatico(const Automatico &r):Carro(r){
    this -> placa=r.getPlaca();
    this -> marca=r.getMarca();
    this -> cilindraje=r.getCilindraje();
    this -> año=r.getAño();
    this -> tipo= r.getTipo();
}

QString Automatico::getTipo() const
{
    return tipo;
}

void Automatico::setTipo(const QString &value)
{
    tipo = value;
}

QString Automatico::toString()
{
    QString q=placa+" , "+marca+" , "+cilindraje+" , "+año+tipo;
    return q;

}
