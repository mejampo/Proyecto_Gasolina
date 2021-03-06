#ifndef CARRO_H
#define CARRO_H
#include <QString>
#include <stdio.h>
#include <string>
#include <sstream>
#include <gasolina.h>

using namespace std;

class Carro{

protected:QString placa;
protected:QString marca;
protected:QString cilindraje;
protected:QString año;

public:

    Carro(QString placa, QString marca, QString cilindraje,QString año);
    Carro(const Carro &r);


    virtual QString toString()const;
    virtual int cantidadGas();

    QString getPlaca() const;
    void setPlaca(const QString &value);
    QString getMarca() const;
    void setMarca(const QString &value);
    QString getCilindraje() const;
    void setCilindraje(const QString &value);
    QString getAño() const;
    void setAño(const QString &value);


};

#endif // CARRO_H
