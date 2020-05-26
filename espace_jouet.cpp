#include "espace_jouet.h"
#include "ui_espace_jouet.h"

espace_jouet::espace_jouet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::espace_jouet)
{
    ui->setupUi(this);
}

espace_jouet::~espace_jouet()
{
    delete ui;
}
