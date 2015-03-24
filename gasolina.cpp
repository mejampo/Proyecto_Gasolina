#include "gasolina.h"

Gasolina::Gasolina(QString fecha,double lempiras,double litros,double kilometros,QString placa){
    this -> fecha=fecha;
    this -> lempiras=lempiras;
    this -> litros=litros;
    this -> kilometros=kilometros;
    this -> placa=placa;
}


Gasolina::Gasolina(const Gasolina &r){
    this -> fecha=r.getFecha();
    this -> lempiras=r.getLempiras();
    this -> litros=r.getLitros();
    this -> kilometros=r.getKilometros();
    this -> placa=r.getPlaca();
}



QString Gasolina::getPlaca() const
{
    return placa;
}

void Gasolina::setPlaca(const QString &value)
{
    placa = value;
}

QString Gasolina::getFecha() const
{
    return fecha;
}

void Gasolina::setFecha(const QString &value)
{
    fecha = value;
}

QString Gasolina::toString()
{
   // QString lemp = lempiras.toStdString();
    QString q= placa+" , "+QString::number(lempiras)+" , "+QString::number(litros)+" , "+QString::number(kilometros)+" , "+fecha;
    return q;
}

double Gasolina::getLempiras() const
{
    return lempiras;
}

void Gasolina::setLempiras(double value)
{
    lempiras = value;
}

double Gasolina::getLitros() const
{
    return litros;
}

void Gasolina::setLitros(double value)
{
    litros = value;
}

double Gasolina::getKilometros() const
{
    return kilometros;
}

void Gasolina::setKilometros(double value)
{
    kilometros = value;
}


