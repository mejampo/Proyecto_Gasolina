#ifndef MECANICO_H
#define MECANICO_H
#include "carro.h"

class Mecanico : public Carro{

    QString tipo;
public:
    Mecanico();
    Mecanico(QString placa, QString marca, QString cilindraje, QString año, QString tipo);
    Mecanico(const Mecanico &r);

    virtual QString toString()const;

    QString getTipo() const;
    void setTipo(const QString &value);


};

#endif // MECANICO_H
