#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_B_AgregarCarro_clicked();

    void on_B_CargarModi_A_clicked();

    void on_B_CargarModi_M_clicked();

    void on_B_SelectModi_A_clicked();

    void on_B_SelectModi_M_clicked();

    void on_B_AgregarGaso_A_clicked();

    void on_B_AgregarGaso_M_clicked();

    void on_B_CargarGaso_A_clicked();

    void on_B_CargarGaso_M_clicked();

    void on_B_CargarEli_A_clicked();

    void on_B_CargarEli_M_clicked();

    void on_B_Eli_A_clicked();

    void on_B_Eli_M_clicked();

    void on_B_CargarReporte_A_clicked();

    void on_B_CargarReporte_M_clicked();

    void on_B_SelectReporte_A_clicked();

    void on_B_SelectReporte_M_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
