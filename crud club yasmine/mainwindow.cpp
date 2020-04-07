#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "club.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);

ui->tabclub->setModel(tmpclub.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int idclub = ui->lineEdit_idclub->text().toInt();
    QString nomclub= ui->lineEdit_nomclub->text();
    QString categclub= ui->lineEdit_categclub->text();
    QString descclub= ui->lineEdit_descclub->text();
  Club l(idclub,nomclub,categclub, descclub);
  bool test=l.ajouter();
  if(test)
{

      ui->tabclub->setModel(tmpclub.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un club"),
                  QObject::tr("club ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un club"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
int id = ui->lineEdit_id_2->text().toInt();
bool test=tmpclub.supprimer(id);
if(test)
{ui->tabclub->setModel(tmpclub.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un club"),
                QObject::tr("club supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un club"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}



bool MainWindow::on_pb_chercherC_released()
{

    QSqlQuery query;
    int cod = ui->idEdit->text().toInt();

    QString res = QString::number(cod);
    query.prepare("SELECT * FROM club WHERE idclub = :cod");
    query.bindValue(":cod", res);
    query.exec();
    if(query.first())
    {
        QMessageBox::information(this, tr("Modifier Employe"), tr("Le club est trouvé avec succès, Veuillez saisir les nouvelles informations."));
        ui->idEdit->setText(query.value(0).toString());
        ui->nomEdit->setText(query.value(1).toString());
        ui->descEdit->setText(query.value(2).toString());
        ui->categEdit->setText(query.value(3).toString());

        return true;
}
}


void MainWindow::on_pb_confirmerC_released()
{   QString nomclub, categclub, descclub;
    int idclub=0;
    QSqlQuery query;


    int cod = ui->idEdit->text().toInt();
    QString codd = ui->nomEdit->text();
    QString res = QString::number(cod);
    QString ress = codd;
    idclub = ui->idEdit->text().toInt();
   nomclub = ui->nomEdit->text();
  categclub= ui->categEdit->text();
   descclub = ui->descEdit->text().toInt();


    Club c(idclub, nomclub, categclub, descclub);

    if(c.modifier_club(cod))

    {
        ui->tabclub->setModel(tmpclub.afficher());//refresh
         ui->tabclub->setModel(tmpclub.afficher());
         QMessageBox::information(nullptr, QObject::tr("Modifier un club"),
                                    QObject::tr("Club modifié.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

