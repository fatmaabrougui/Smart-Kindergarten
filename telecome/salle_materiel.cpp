#include "salle_materiel.h"
#include "ui_salle_materiel.h"

salle_materiel::salle_materiel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::salle_materiel)
{
    ui->setupUi(this);
}

salle_materiel::~salle_materiel()
{
    delete ui;
}
