#ifndef gestioncuisine_H
#define gestioncuisine_H
#include "aliments.h"
#include "menu.h"
#include <QMainWindow>
#include <QPdfWriter>
#include <QPainter>
#include <QDialog>
namespace Ui {
class gestioncuisine;
}

class gestioncuisine : public QDialog
{
    Q_OBJECT

public:
    explicit gestioncuisine(QWidget *parent = nullptr);
    ~gestioncuisine();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    bool on_pb_chercherS_released();

    void on_pb_confirmerS_released();

    void on_pb_trierS_released();

    void on_pb_ajouter_2_clicked();

    void on_pb_supprimer_2_clicked();

    bool on_pb_chercherM_released();

    void on_pb_confirmerM_released();

    void on_pb_trierM_released();

    void on_pdf_clicked();

    void on_afficher_stat_clicked();


private:
    Ui::gestioncuisine * ui;
    Aliments tmpaliment;
    Menu tmpmenu;
};

#endif // gestioncuisine_H

