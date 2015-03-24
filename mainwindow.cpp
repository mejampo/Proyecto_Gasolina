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

QList<Carro> carros;
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
    carros.append(a);
    carros.append(b);
    carros.append(c);
    carros.append(d);
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

        Automatico c(placa,marca,cilindraje,año,tipo);
        carros.append(c);

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
        carros.append(c);

        QMessageBox::information(this,tr("Agregar"),tr("Agregado Exitosamente"));
        ui->LE_Placa->setText("");
        ui->LE_Marca->setText("");
        ui->LE_Cilindraje->setText("");
        ui->LE_Year->setText("");
    }


}

void MainWindow::on_B_AgregarGaso_clicked()
{

    QString fecha;
    double lempiras;
    double litros;
    double kilometros;
    QString placa;


    placa = ui->CB_AgregarGaso->currentText();
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

void MainWindow::on_B_Eliminar_clicked()
{
    QString eliminando = ui->CB_Eliminar->currentText();

    for(int i=0;i<carros.length();i++){
        Carro carrod = carros.at(i);
        QString placa= carros.at(i).getPlaca();
        if(eliminando==carrod.toString()){
            carros.removeAt(i);
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

void MainWindow::on_B_CargarEliminar_clicked()
{
    do{
        ui->CB_Eliminar->removeItem(ui->CB_Eliminar->currentIndex());
    }while(ui->CB_Eliminar->currentIndex()!=-1);

    for(int i=0;i<carros.length();i++){
        Carro carrod = carros.at(i);
        ui->CB_Eliminar->addItem(carrod.toString());
    }
}

void MainWindow::on_B_CargarGaso_clicked()
{
    do{
        ui->CB_AgregarGaso->removeItem(ui->CB_AgregarGaso->currentIndex());
    }while(ui->CB_AgregarGaso->currentIndex()!=-1);

    for(int i=0;i<carros.length();i++){
        Carro carrod = carros.at(i);
        ui->CB_AgregarGaso->addItem(carrod.getPlaca());
    }
}

void MainWindow::on_B_CargarReporte_clicked()
{
    do{
        ui->CB_Reporte->removeItem(ui->CB_Reporte->currentIndex());
    }while(ui->CB_Reporte->currentIndex()!=-1);

    for(int i=0;i<carros.length();i++){
        Carro carrod = carros.at(i);
        ui->CB_Reporte->addItem(carrod.toString());
    }
}

void MainWindow::on_B_CargarModi_clicked()
{
    do{
        ui->CB_Modificar->removeItem(ui->CB_Modificar->currentIndex());
    }while(ui->CB_Modificar->currentIndex()!=-1);

    for(int i=0;i<carros.length();i++){
        Carro carrod = carros.at(i);
        ui->CB_Modificar->addItem(carrod.toString());
    }
}

void MainWindow::on_B_SelectReporte_clicked()
{
    QString escogido = ui->CB_Reporte->currentText();
    QString placa;
    ui->TE_Reportes->clear();
    for(int i=0;i<carros.length();i++){
        Carro carrod = carros.at(i);
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
            ui->TE_Reportes->appendPlainText(gas.toString());
            totLempi+= gas.getLempiras();
            totLitr+=gas.getLitros();
            totKilo+=gas.getKilometros();
        }
    }

    ui->LE_LempirasRep->setText(QString::number(totLempi));
    ui->LE_LitrosRep->setText(QString::number(totLitr));
    ui->LE_KilometrosRep->setText(QString::number(totKilo));
    double km = totKilo/totLitr;
    double lit = totLitr/totKilo;
    ui->LE_Km_Litro->setText(QString::number(km));
    ui->LE_Litros_Km->setText(QString::number(lit));

}

void MainWindow::on_B_SelectModi_clicked()
{
    QString placa;
    QString marca;
    QString cilindraje;
    QString año;

    QString select = ui->CB_Modificar->currentText();
    for(int i=0;i<carros.length();i++){
        Carro carrod = carros.at(i);
        if(select==carrod.toString()){
            placa= carros.at(i).getPlaca();
            marca=carros.at(i).getMarca();
            cilindraje=carros.at(i).getCilindraje();
            año=carros.at(i).getAño();
        }
    }
    ui->LE_PlacaModi->setText(placa);
    ui->LE_MarcaModi->setText(marca);
    ui->LE_CilindrajeModi->setText(cilindraje);
    ui->LE_YearModi->setText(año);
}

void MainWindow::on_B_ModificarCarro_clicked()
{
    QString placa;
    QString marca;
    QString cilindraje;
    QString año;

    placa=ui->LE_Placa->text();
    marca=ui->LE_Marca->text();
    cilindraje=ui->LE_Cilindraje->text();
    año= ui->LE_Year->text();

    QString eliminando = ui->CB_Eliminar->currentText();
    Carro c(placa,marca,cilindraje,año);
    int eli=0;
    for(int i=0;i<carros.length();i++){
        Carro carrod = carros.at(i);
        if(eliminando==carrod.toString()){
            eli=i;
        }
    }
    carros.replace(eli,c);

    QMessageBox::information(this,tr("Modificar"),tr("Modificado Exitosamente"));
    ui->LE_PlacaModi->setText("");
    ui->LE_MarcaModi->setText("");
    ui->LE_CilindrajeModi->setText("");
    ui->LE_YearModi->setText("");
}


void MainWindow::on_B_SelectGaso_clicked()
{

}


void MainWindow::on_rb_Mecanico_clicked()
{

}

void MainWindow::on_rb_Automatico_clicked()
{

}
