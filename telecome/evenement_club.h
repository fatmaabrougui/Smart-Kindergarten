#ifndef EVENEMENT_CLUB_H
#define EVENEMENT_CLUB_H
#include "club.h"
#include"event.h"
#include <QMainWindow>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class evenement_club; }
QT_END_NAMESPACE

class evenement_club : public QDialog
{
    Q_OBJECT

public:
  explicit evenement_club(QWidget *parent = nullptr);
    ~evenement_club();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    bool on_pb_chercherC_released();

    void on_pb_confirmerC_released();

    void on_pb_ajouterE_clicked();

    void on_pb_supprimerE_clicked();

    bool on_pb_chercherE_released();

    void on_pb_confirmerE_released();

    void on_pb_ajouterE_released();

    void on_pdf_2_clicked();

    void on_imprimer_clicked();

    void on_pb_trierEvent_released();

private:
    Ui::evenement_club *ui;
    Club tmpclub;
    Event tmpevent;

};
#endif // EVENEMENT_CLUB_H
