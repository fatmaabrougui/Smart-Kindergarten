#include "evennement_club.h"
#include "ui_evennement_club.h"

evennement_club::evennement_club(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::evennement_club)
{
    ui->setupUi(this);
}

evennement_club::~evennement_club()
{
    delete ui;
}
