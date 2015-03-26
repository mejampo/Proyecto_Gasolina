#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <fstream>
#include <QString>
#include <QList>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include "carro.h"
#include "gasolina.h"
#include "automatico.h"
#include "mecanico.h"
#include <iostream>
#include <QMessageBox>
#include <string>
#include <cstdlib>
#include "stdio.h"
#include "string.h"

QList<Mecanico> mecanicos;
QList<Automatico> automaticos;
QList<Gasolina> gasolina;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Mecanico a("PBT5525", "Toyota","8","2005","Turismo");
    Automatico b("PDY4015", "Hyunday","12","2012","Camioneta");
    Mecanico c("PED1275", "Mazda","10","2009","Turismo");
    Mecanico d("PTF1302", "Dodge","10","2007","Otro");
    Automatico e("PDG2075", "Dodge","13","2010","Turismo");

    mecanicos.append(a);
    automaticos.append(b);
    mecanicos.append(c);
    mecanicos.append(d);
    automaticos.append(e);

    Gasolina f("03/03/2015",400.00,30.25,150.00,"PBT5525");
    Gasolina r("15/03/2015",500.00,35.00,200.00,"PBT5525");
    Gasolina w("20/01/2015",1000.00,60.00,500.00,"PED1275");
    Gasolina q("28/02/2015",700.00,45.7,376.00,"PDG2075");
    Gasolina p("02/02/2015",100.00,10.00,50.00,"PTF1302");
    Gasolina v("03/03/2015",400.00,30.25,150.00,"PDY4015");

    gasolina.append(f);
    gasolina.append(r);
    gasolina.append(w);
    gasolina.append(q);
    gasolina.append(p);
    gasolina.append(v);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_B_AgregarCarro_clicked()
{
    QString placa;
    QString marca;
    QString cilindraje;
    QString año;
    QString tipo;

    if(ui->rb_Automatico->isChecked()){
        placa=ui->LE_Placa->text();
        marca=ui->LE_Marca->text();
        cilindraje=ui->LE_Cilindraje->text();
        año= ui->LE_Year->text();
        if(ui->rb_Turismo->isChecked()){
            tipo="Turismo";
        }else if(ui->rb_Camioneta->isChecked()){
            tipo="Camioneta";
        }else if(ui->rb_Otro->isChecked()){
            tipo="Otro";
        }

        Automatico c (placa,marca,cilindraje,año,tipo);
        automaticos.append(c);

        QMessageBox::information(this,tr("Agregar"),tr("Agregado Exitosamente"));
        ui->LE_Placa->setText("");
        ui->LE_Marca->setText("");
        ui->LE_Cilindraje->setText("");
        ui->LE_Year->setText("");

    }else if(ui->rb_Mecanico->isChecked()){
        placa=ui->LE_Placa->text();
        marca=ui->LE_Marca->text();
        cilindraje=ui->LE_Cilindraje->text();
        año= ui->LE_Year->text();
        if(ui->rb_Turismo->isChecked()){
            tipo="Turismo";
        }else if(ui->rb_Camioneta->isChecked()){
            tipo="Camioneta";
        }else if(ui->rb_Otro->isChecked()){
            tipo="Otro";
        }

        Mecanico c(placa,marca,cilindraje,año,tipo);
        mecanicos.append(c);

        QMessageBox::information(this,tr("Agregar"),tr("Agregado Exitosamente"));
        ui->LE_Placa->setText("");
        ui->LE_Marca->setText("");
        ui->LE_Cilindraje->setText("");
        ui->LE_Year->setText("");
    }
}


void MainWindow::on_B_CargarModi_A_clicked()
{
    do{
        ui->CB_Modificar_A->removeItem(ui->CB_Modificar_A->currentIndex());
    }while(ui->CB_Modificar_A->currentIndex()!=-1);

    for(int i=0;i<automaticos.length();i++){
        Automatico carrod = automaticos.at(i);
        ui->CB_Modificar_A->addItem(carrod.toString());

    }
}

void MainWindow::on_B_CargarModi_M_clicked()
{
    do{
        ui->CB_Modificar_M->removeItem(ui->CB_Modificar_M->currentIndex());
    }while(ui->CB_Modificar_M->currentIndex()!=-1);

    for(int i=0;i<mecanicos.length();i++){
        Mecanico carrod = mecanicos.at(i);
        ui->CB_Modificar_M->addItem(carrod.toString());
    }
}

void MainWindow::on_B_SelectModi_A_clicked()
{
    QString placa;
    QString marca;
    QString cilindraje;
    QString año;
    QString tipo;

    QString select = ui->CB_Modificar_A->currentText();
    for(int i=0;i<automaticos.length();i++){
        Automatico carrod = automaticos.at(i);
        if(select==carrod.toString()){
            placa= automaticos.at(i).getPlaca();
            marca=automaticos.at(i).getMarca();
            cilindraje=automaticos.at(i).getCilindraje();
            año=automaticos.at(i).getAño();
            tipo=automaticos.at(i).getTipo();

        }
    }
    ui->LE_PlacaModi->setText(placa);
    ui->LE_MarcaModi->setText(marca);
    ui->LE_CilindrajeModi->setText(cilindraje);
    ui->LE_YearModi->setText(año);

    if(tipo=="Turismo"){
        ui->rb_TurismoModi->setChecked(1);
    }else if(tipo=="Camioneta"){
        ui->rb_CamionetaModi->setChecked(1);
    }else if(tipo=="Otro"){
        ui->rb_OtroModi->setChecked(1);
    }
}

void MainWindow::on_B_SelectModi_M_clicked()
{
    QString placa;
    QString marca;
    QString cilindraje;
    QString año;
    QString tipo;

    QString select = ui->CB_Modificar_M->currentText();
    for(int i=0;i<mecanicos.length();i++){
        Mecanico carrod = mecanicos.at(i);
        if(select==carrod.toString()){
            placa= mecanicos.at(i).getPlaca();
            marca=mecanicos.at(i).getMarca();
            cilindraje=mecanicos.at(i).getCilindraje();
            año=mecanicos.at(i).getAño();
            tipo=mecanicos.at(i).getTipo();

        }
    }
    ui->LE_PlacaModi->setText(placa);
    ui->LE_MarcaModi->setText(marca);
    ui->LE_CilindrajeModi->setText(cilindraje);
    ui->LE_YearModi->setText(año);

    if(tipo=="Turismo"){
        ui->rb_TurismoModi->setChecked(1);
    }else if(tipo=="Camioneta"){
        ui->rb_CamionetaModi->setChecked(1);
    }else if(tipo=="Otro"){
        ui->rb_OtroModi->setChecked(1);
    }
}

void MainWindow::on_B_AgregarGaso_A_clicked()
{
    QString fecha;
    double lempiras;
    double litros;
    double kilometros;
    QString placa;


    placa = ui->CB_AgregarGaso_A->currentText();
    fecha= ui->LE_FechaGaso->text();
    lempiras = ui->SP_Lempiras->value();
    litros= ui->SP_Litros->value();
    kilometros = ui->SP_Kilometros->value();
    Gasolina g(fecha,lempiras,litros,kilometros,placa);
    gasolina.append(g);
    QMessageBox::information(this,tr("Agregar"),tr("Agregado Exitosamente"));

    ui->LE_FechaGaso->setText("");
    ui->SP_Lempiras->setValue(0);
    ui->SP_Litros->setValue(0);
    ui->SP_Kilometros->setValue(0);
}

void MainWindow::on_B_AgregarGaso_M_clicked()
{
    QString fecha;
    double lempiras;
    double litros;
    double kilometros;
    QString placa;


    placa = ui->CB_AgregarGaso_M->currentText();
    fecha= ui->LE_FechaGaso->text();
    lempiras = ui->SP_Lempiras->value();
    litros= ui->SP_Litros->value();
    kilometros = ui->SP_Kilometros->value();
    Gasolina g(fecha,lempiras,litros,kilometros,placa);
    gasolina.append(g);
    QMessageBox::information(this,tr("Agregar"),tr("Agregado Exitosamente"));

    ui->LE_FechaGaso->setText("");
    ui->SP_Lempiras->setValue(0);
    ui->SP_Litros->setValue(0);
    ui->SP_Kilometros->setValue(0);
}

void MainWindow::on_B_CargarGaso_A_clicked()
{
    do{
        ui->CB_AgregarGaso_A->removeItem(ui->CB_AgregarGaso_A->currentIndex());
    }while(ui->CB_AgregarGaso_A->currentIndex()!=-1);

    for(int i=0;i<automaticos.length();i++){
        Carro carrod = automaticos.at(i);
        ui->CB_AgregarGaso_A->addItem(carrod.getPlaca());
    }
}

void MainWindow::on_B_CargarGaso_M_clicked()
{
    do{
        ui->CB_AgregarGaso_M->removeItem(ui->CB_AgregarGaso_M->currentIndex());
    }while(ui->CB_AgregarGaso_M->currentIndex()!=-1);

    for(int i=0;i<mecanicos.length();i++){
        Carro carrod = mecanicos.at(i);
        ui->CB_AgregarGaso_M->addItem(carrod.getPlaca());
    }
}

void MainWindow::on_B_CargarEli_A_clicked()
{
    do{
        ui->CB_Eliminar_A->removeItem(ui->CB_Eliminar_A->currentIndex());
    }while(ui->CB_Eliminar_A->currentIndex()!=-1);

    for(int i=0;i<automaticos.length();i++){
        Automatico carrod = automaticos.at(i);
        ui->CB_Eliminar_A->addItem(carrod.toString());
    }
}

void MainWindow::on_B_CargarEli_M_clicked()
{
    do{
        ui->CB_Eliminar_M->removeItem(ui->CB_Eliminar_M->currentIndex());
    }while(ui->CB_Eliminar_M->currentIndex()!=-1);

    for(int i=0;i<mecanicos.length();i++){
        Mecanico carrod = mecanicos.at(i);
        ui->CB_Eliminar_M->addItem(carrod.toString());
    }
}

void MainWindow::on_B_Eli_A_clicked()
{
    QString eliminando = ui->CB_Eliminar_A->currentText();

    for(int i=0;i<automaticos.length();i++){
        Automatico carrod = automaticos.at(i);
        QString placa= automaticos.at(i).getPlaca();
        if(eliminando==carrod.toString()){
            automaticos.removeAt(i);
        }
        for(int i=0;i<gasolina.length();i++){
            Gasolina gas= gasolina.at(i);
            if(placa==gasolina.at(i).getPlaca()){
                gasolina.removeAt(i);
            }
        }
    }
    QMessageBox::information(this,tr("Modificar"),tr("Eliminado Exitosamente, Refresque la lista"));

}

void MainWindow::on_B_Eli_M_clicked()
{
    QString eliminando = ui->CB_Eliminar_M->currentText();

    for(int i=0;i<mecanicos.length();i++){
        Mecanico carrod = mecanicos.at(i);
        QString placa= mecanicos.at(i).getPlaca();
        if(eliminando==carrod.toString()){
            mecanicos.removeAt(i);
        }
        for(int i=0;i<gasolina.length();i++){
            Gasolina gas= gasolina.at(i);
            if(placa==gasolina.at(i).getPlaca()){
                gasolina.removeAt(i);
            }
        }
    }
    QMessageBox::information(this,tr("Modificar"),tr("Eliminado Exitosamente, Refresque la lista"));

}

void MainWindow::on_B_CargarReporte_A_clicked()
{
    do{
        ui->CB_Reporte_A->removeItem(ui->CB_Reporte_A->currentIndex());
    }while(ui->CB_Reporte_A->currentIndex()!=-1);

    for(int i=0;i<automaticos.length();i++){
        Automatico carrod = automaticos.at(i);
        ui->CB_Reporte_A->addItem(carrod.toString());
    }
}

void MainWindow::on_B_CargarReporte_M_clicked()
{
    do{
        ui->CB_Reporte_M->removeItem(ui->CB_Reporte_M->currentIndex());
    }while(ui->CB_Reporte_M->currentIndex()!=-1);

    for(int i=0;i<mecanicos.length();i++){
        Mecanico carrod = mecanicos.at(i);
        ui->CB_Reporte_M->addItem(carrod.toString());
    }

}

void MainWindow::on_B_SelectReporte_A_clicked()
{
    QString escogido = ui->CB_Reporte_A->currentText();
    QString placa;
    ui->TE_Reportes_A->clear();
    for(int i=0;i<automaticos.length();i++){
        Automatico carrod = automaticos.at(i);
        if(escogido==carrod.toString()){
            placa=carrod.getPlaca();
        }
    }

    double totLempi=0.0;
    double totLitr=0.0;
    double totKilo=0.0;
    for(int i=0;i<gasolina.length();i++){
        Gasolina gas= gasolina.at(i);
        if(placa==gasolina.at(i).getPlaca()){
            ui->TE_Reportes_A->appendPlainText(gas.toString());
            totLempi+= gas.getLempiras();
            totLitr+=gas.getLitros();
            totKilo+=gas.getKilometros();
        }
    }

    ui->LE_LempirasRep_A->setText(QString::number(totLempi));
    ui->LE_LitrosRep_A->setText(QString::number(totLitr));
    ui->LE_KilometrosRep_A->setText(QString::number(totKilo));
    double km = totKilo/totLitr;
    double lit = totLitr/totKilo;
    double lempi = totLitr/totLempi;
    double lpkm = totLempi/totKilo;
    double lemlit = totLempi/totLitr;
    ui->LE_Km_Litro_A->setText(QString::number(km));
    ui->LE_Litros_Km_A->setText(QString::number(lit));
    ui->LE_Litros_Lemp_A->setText(QString::number(lempi));
    ui->LE_Lemp_Km_A->setText(QString::number(lpkm));
    ui->LE_Lemp_Litro_A->setText(QString::number(lemlit));

}

void MainWindow::on_B_SelectReporte_M_clicked()
{

    QString escogido = ui->CB_Reporte_M->currentText();
    QString placa;
    ui->TE_Reportes_M->clear();
    for(int i=0;i<mecanicos.length();i++){
        Mecanico carrod = mecanicos.at(i);
        if(escogido==carrod.toString()){
            placa=carrod.getPlaca();
        }
    }


    double totLempi=0.0;
    double totLitr=0.0;
    double totKilo=0.0;
    for(int i=0;i<gasolina.length();i++){
        Gasolina gas= gasolina.at(i);
        if(placa==gasolina.at(i).getPlaca()){
            ui->TE_Reportes_M->appendPlainText(gas.toString());
            totLempi+= gas.getLempiras();
            totLitr+=gas.getLitros();
            totKilo+=gas.getKilometros();
        }
    }

    ui->LE_LempirasRep_M->setText(QString::number(totLempi));
    ui->LE_LitrosRep_M->setText(QString::number(totLitr));
    ui->LE_KilometrosRep_M->setText(QString::number(totKilo));
    double km = totKilo/totLitr;
    double lit = totLitr/totKilo;
    double lempi = totLitr/totLempi;
    double lpkm = totLempi/totKilo;
    double lemlit = totLempi/totLitr;
    ui->LE_Km_Litro_M->setText(QString::number(km));
    ui->LE_Litros_Km_M->setText(QString::number(lit));
    ui->LE_Litros_Lemp_M->setText(QString::number(lempi));
    ui->LE_Lemp_Km_M->setText(QString::number(lpkm));
    ui->LE_Lemp_Litro_M->setText(QString::number(lemlit));

}



void MainWindow::on_B_Modificar_A_clicked()
{
    QString placa;
    QString marca;
    QString cilindraje;
    QString año;
    QString tipo;

    placa=ui->LE_PlacaModi->text();
    marca=ui->LE_MarcaModi->text();
    cilindraje=ui->LE_CilindrajeModi->text();
    año= ui->LE_YearModi->text();
    if(ui->rb_TurismoModi->isChecked()){
        tipo="Turismo";
    }else if(ui->rb_CamionetaModi->isChecked()){
        tipo="Camioneta";
    }else if(ui->rb_OtroModi->isChecked()){
        tipo="Otro";
    }

    QString modificando = ui->CB_Modificar_A->currentText();
    Automatico c(placa,marca,cilindraje,año,tipo);
    int eli=0;
    for(int i=0;i<automaticos.length();i++){
        Automatico carrod = automaticos.at(i);
        if(modificando==carrod.toString()){
            eli=i;
        }
    }
    automaticos.replace(eli,c);

    QMessageBox::information(this,tr("Modificar"),tr("Modificado Exitosamente"));
    ui->LE_PlacaModi->setText("");
    ui->LE_MarcaModi->setText("");
    ui->LE_CilindrajeModi->setText("");
    ui->LE_YearModi->setText("");
    ui->rb_CamionetaModi->setChecked(1);
}

void MainWindow::on_B_Modificar_M_clicked()
{
    QString placa;
    QString marca;
    QString cilindraje;
    QString año;
    QString tipo;

    placa=ui->LE_PlacaModi->text();
    marca=ui->LE_MarcaModi->text();
    cilindraje=ui->LE_CilindrajeModi->text();
    año= ui->LE_YearModi->text();
    if(ui->rb_TurismoModi->isChecked()){
        tipo="Turismo";
    }else if(ui->rb_CamionetaModi->isChecked()){
        tipo="Camioneta";
    }else if(ui->rb_OtroModi->isChecked()){
        tipo="Otro";
    }

    QString modificando = ui->CB_Modificar_M->currentText();
    Mecanico c(placa,marca,cilindraje,año,tipo);
    int eli=0;
    for(int i=0;i<mecanicos.length();i++){
        Mecanico carrod = mecanicos.at(i);
        if(modificando==carrod.toString()){
            eli=i;
        }
    }
    mecanicos.replace(eli,c);

    QMessageBox::information(this,tr("Modificar"),tr("Modificado Exitosamente"));
    ui->LE_PlacaModi->setText("");
    ui->LE_MarcaModi->setText("");
    ui->LE_CilindrajeModi->setText("");
    ui->LE_YearModi->setText("");
    ui->rb_CamionetaModi->setChecked(1);
}
