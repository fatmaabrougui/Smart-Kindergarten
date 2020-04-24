#include "acceuille.h"
#include "ui_acceuille.h"
#include "departement_employe.h"
#include "aliment_menu.h"
#include "evennement_club.h"
#include "espace_jouet.h"
#include "eleve_niveau.h"
#include "salle_materiel.h"

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
    departement_employe departement_employe;
    departement_employe.setModal(true);
    departement_employe.exec();
}

void Acceuille::on_pushButton_2_clicked()
{
    aliment_menu aliment_menu;
    aliment_menu.setModal(true);
    aliment_menu.exec();
}

void Acceuille::on_pushButton_3_clicked()
{
    evennement_club evennement_club;
    evennement_club.setModal(true);
    evennement_club.exec();
}

void Acceuille::on_pushButton_4_clicked()
{
    espace_jouet espace_jouet;
    espace_jouet.setModal(true);
    espace_jouet.exec();
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
    salle_materiel salle_materiel;
    salle_materiel.setModal(true);
    salle_materiel.exec();

}
