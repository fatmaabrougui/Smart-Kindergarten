#include "aliment_menu.h"
#include "ui_aliment_menu.h"

aliment_menu::aliment_menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aliment_menu)
{
    ui->setupUi(this);
}

aliment_menu::~aliment_menu()
{
    delete ui;
}
