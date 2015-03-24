#ifndef GASOLINA_H
#define GASOLINA_H
#include <QString>
#include <stdio.h>
#include <string>
#include <sstream>

using namespace std;

class Gasolina{

    QString fecha;
    double lempiras;
    double litros;
    double kilometros;
    QString placa;
public:
    Gasolina(QString fecha,double lempiras,double litros,double kilometros,QString placa);
    Gasolina(const Gasolina &r);

    double getLempiras() const;
    void setLempiras(double value);
    double getLitros() const;
    void setLitros(double value);
    double getKilometros() const;
    void setKilometros(double value);
    QString getPlaca() const;
    void setPlaca(const QString &value);
    QString getFecha() const;
    void setFecha(const QString &value);
    QString toString();
};

#endif // GASOLINA_H
