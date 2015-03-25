#ifndef AUTOMATICO_H
#define AUTOMATICO_H
#include "carro.h"


class Automatico : public Carro{

    QString tipo;
public:
        Automatico();
        Automatico(QString placa, QString marca, QString cilindraje, QString año,QString tipo);
        Automatico(const Automatico &r);

        virtual QString toString();

        QString getTipo() const;
        void setTipo(const QString &value);
        };

#endif // AUTOMATICO_H
