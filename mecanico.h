#ifndef MECANICO_H
#define MECANICO_H
#include "carro.h"

class Mecanico : public Carro{
    QString placa;
    QString marca;
    QString cilindraje;
    QString año;
    QString tipo;
public:
    Mecanico(QString placa, QString marca, QString cilindraje,QString año,QString tipo);
    Mecanico(const Mecanico &r);

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

#endif // MECANICO_H
