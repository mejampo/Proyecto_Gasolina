#include "mecanico.h"
#include "carro.h"


Mecanico(QString):Carro(QString placa, QString marca, QString cilindraje,QString año){
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
