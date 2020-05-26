#ifndef GESTIOND_EMP_H
#define GESTIOND_EMP_H
#include "employe.h"
#include "departement.h"
#include <QMainWindow>
#include <QDialog>
QT_BEGIN_NAMESPACE
namespace Ui { class GestionD_emp; }
QT_END_NAMESPACE

class GestionD_emp : public QDialog
{
    Q_OBJECT

public:
    explicit GestionD_emp(QWidget *parent = nullptr);
    ~GestionD_emp();


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
    Ui::GestionD_emp *ui;
    Employe tmpemploye;
    Departement tmpdepartement;
};
#endif // GESTIOND_EMP_H
