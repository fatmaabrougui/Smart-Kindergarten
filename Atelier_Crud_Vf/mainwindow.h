#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employe.h"
#include "departement.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    //Employé

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    bool on_pb_chercherE_released();

    void on_pb_confirmerE_released();



    //Departement

    void on_pb_ajouter_2_clicked();

    void on_pb_supprimer_2_clicked();

    bool on_pb_chercherD_released();

    void on_pb_confirmerD_released();

    //metiers

    void on_pdf_clicked();

    void on_mail_2_released();

    //void on_afficher_stat_clicked();

    void on_afficher_stat2_clicked();

private:
    Ui::MainWindow *ui;
    Employe tmpemploye;
    Departement tmpdepartement;
};

#endif // MAINWINDOW_H
