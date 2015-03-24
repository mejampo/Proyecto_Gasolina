#ifndef MECANICO_H
#define MECANICO_H
#include "carro.h"

class Mecanico : public Carro{
        QString tipo;
public:
    Mecanico(QString tipo);
    Mecanico(const Carro &r);

    virtual QString toString();
    QString getTipo() const;
    void setTipo(const QString &value);
};

#endif // MECANICO_H
