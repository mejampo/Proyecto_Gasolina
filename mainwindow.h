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

    void on_B_AgregarGaso_clicked();

    void on_B_Eliminar_clicked();

    void on_B_CargarEliminar_clicked();

    void on_B_CargarGaso_clicked();

    void on_B_CargarReporte_clicked();

    void on_B_CargarModi_clicked();

    void on_B_SelectGaso_clicked();

    void on_B_SelectReporte_clicked();

    void on_B_SelectModi_clicked();

    void on_B_ModificarCarro_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
