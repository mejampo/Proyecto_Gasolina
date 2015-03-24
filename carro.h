#ifndef CARRO_H
#define CARRO_H
#include <QString>
#include <stdio.h>
#include <string>
#include <sstream>
#include <gasolina.h>

using namespace std;

class Carro{

    QString placa;
    QString marca;
    QString cilindraje;
    QString año;

public:

    Carro(QString placa, QString marca, QString cilindraje,QString año);
    Carro(const Carro &r);


    virtual QString toString();
    QString getPlaca() const;
    void setPlaca(const QString &value);
    QString getMarca() const;
    void setMarca(const QString &value);
    QString getCilindraje() const;
    void setCilindraje(const QString &value);
    QString getAño() const;
    void setAño(const QString &value);
    QString getTipo() const;
    void setTipo(const QString &value);

};

#endif // CARRO_H
