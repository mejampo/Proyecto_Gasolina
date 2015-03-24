#ifndef AUTOMATICO_H
#define AUTOMATICO_H
#include "carro.h"


class Automatico : public Carro{
        QString tipo;
public:
        Automatico(QString tipo);
        Automatico(const Carro &r);

        virtual QString toString();
        QString getTipo() const;
        void setTipo(const QString &value);
        };

#endif // AUTOMATICO_H
