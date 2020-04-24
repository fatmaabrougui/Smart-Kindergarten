#include "departement_employe.h"
#include "ui_departement_employe.h"

departement_employe::departement_employe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::departement_employe)
{
    ui->setupUi(this);
}

departement_employe::~departement_employe()
{
    delete ui;
}
