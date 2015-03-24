#ifndef AUTOMATICO_H
#define AUTOMATICO_H
#include "carro.h"


class Automatico : public Carro{
    QString placa;
    QString marca;
    QString cilindraje;
    QString año;
    QString tipo;
public:
        Automatico(QString placa, QString marca, QString cilindraje,QString año,QString tipo);
        Automatico(const Automatico &r);

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

#endif // AUTOMATICO_H
