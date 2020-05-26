#include "acceuille.h"
#include "ui_acceuille.h"
#include "departement_employe.h"
#include "aliment_menu.h"
#include "evennement_club.h"
#include "espace_jouet.h"
#include "eleve_niveau.h"
#include "salle_materiel.h"
#include "gestionsalle.h"
#include "gestionjouets.h"
#include "gestiond_emp.h"
#include "gestioncuisine.h"
#include "evenement_club.h"
#include "evennement_club.h"
Acceuille::Acceuille(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Acceuille)
{
    ui->setupUi(this);
}

Acceuille::~Acceuille()
{
    delete ui;
}

void Acceuille::on_pushButton_clicked()
{
    GestionD_emp GestionD_emp ;
    GestionD_emp.setModal(true);
GestionD_emp.exec();
}

void Acceuille::on_pushButton_2_clicked()
{
    gestioncuisine gestioncuisine;
    gestioncuisine.setModal(true);
    gestioncuisine.exec();
}

void Acceuille::on_pushButton_3_clicked()
{
    evenement_club evenement_club;
    evenement_club.setModal(true);
    evenement_club.exec();
}

void Acceuille::on_pushButton_4_clicked()
{
    //hide();
   gestionjouets gestionjouets;
    gestionjouets.setModal(true);
    gestionjouets.exec();
}

void Acceuille::on_pushButton_5_clicked()
{
    hide();
    eleve_niveau eleve_niveau;
    eleve_niveau.setModal(true);
    eleve_niveau.exec();
}

void Acceuille::on_pushButton_6_clicked()
{
    hide();
    gestionSalle gestionSalle;
    gestionSalle.setModal(true);
    gestionSalle.exec();
    //gestionSalle.show();

    /*
    salle_materiel salle_materiel;
    salle_materiel.setModal(true);
    salle_materiel.exec();*/

}

