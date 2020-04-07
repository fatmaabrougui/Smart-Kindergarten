#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "departement.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);

ui->tabemploye->setModel(tmpemploye.afficher());
ui->tabdepartement->setModel(tmpdepartement.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString date= ui->lineEdit_date->text();
    int id_dept= ui->lineEdit_iddept_2->text().toInt();
  Employe e(id,nom,date,id_dept);
  bool test=e.ajouter();
  if(test)
{

      ui->tabemploye->setModel(tmpemploye.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un employe"),
                  QObject::tr("Employe ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un employe"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
int id = ui->lineEdit_id->text().toInt();
bool test=tmpemploye.supprimer(id);
if(test)
{ui->tabemploye->setModel(tmpemploye.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un employe"),
                QObject::tr("Employe supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un employe"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_ajouter_2_clicked()
{
    int id = ui->lineEdit_id_3->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    int places= ui->lineEdit_places_2->text().toInt();
  Departement d(id,nom,places);
  bool test=d.ajouter();
  if(test)
{

      ui->tabdepartement->setModel(tmpdepartement.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un département"),
                  QObject::tr("Departement ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un département"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_2_clicked()
{
int id = ui->lineEdit_id_4->text().toInt();
bool test=tmpdepartement.supprimer(id);
if(test)
{ui->tabdepartement->setModel(tmpdepartement.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un Département"),
                QObject::tr("Departement supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un département"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
//******************************************************************************************************
//Employe Modification :

bool MainWindow::on_pb_chercherE_released()
{

    QSqlQuery query;
    int cod = ui->idEdit->text().toInt();

    QString res = QString::number(cod);
    query.prepare("SELECT * FROM employe WHERE id_employe = :cod");
    query.bindValue(":cod", res);
    query.exec();
    if(query.first())
    {
        QMessageBox::information(this, tr("Modifier Employe"), tr("L'employe est trouvé avec success, Veuillez entrer les nouvelles informations."));
         ui->idEdit->setText(query.value(0).toString());
        ui->nomEdit->setText(query.value(1).toString());
        ui->dateEdit->setText(query.value(2).toString());
        ui->depEdit->setText(query.value(3).toString());

        return true;
}
}

void MainWindow::on_pb_confirmerE_released()
{ //capacite=dept
    QString nom_employe,date_recrutement;
    int id_employe=0, id_departement=0;
    QSqlQuery query;


    int cod = ui->idEdit->text().toInt();
    int codd = ui->depEdit->text().toInt();
    QString res = QString::number(cod);
    QString ress = QString::number(codd);
    id_employe = ui->idEdit->text().toInt();
   nom_employe = ui->nomEdit->text();
   date_recrutement= ui->dateEdit->text();
   id_departement = ui->depEdit->text().toInt();


    Employe e(id_employe, nom_employe, date_recrutement, id_departement);

    if(e.modifier_employe(cod))

    {
        ui->tabemploye->setModel(tmpemploye.afficher());//refresh
         ui->tabemploye->setModel(tmpemploye.afficher());
         QMessageBox::information(nullptr, QObject::tr("Modifier un employe"),
                                    QObject::tr("Employe modifié.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}




//**************************************************************************************************************
//Departement Modification:


bool MainWindow::on_pb_chercherD_released()
{
    QSqlQuery query;
    int cod = ui->idEdit_2->text().toInt();

    QString res = QString::number(cod);
    query.prepare("SELECT * FROM departements WHERE id_departement = :cod");
    query.bindValue(":cod", res);
    query.exec();
    if(query.first())
    {
        QMessageBox::information(this, tr("Modifier Département"), tr("Le département est trouvé avec success, Veuillez entrer les nouvelles informations."));
         ui->idEdit_2->setText(query.value(0).toString());
        ui->nomEdit_2->setText(query.value(1).toString());
        ui->placesEdit_2->setText(query.value(2).toString());

        return true;

}
}
void MainWindow::on_pb_confirmerD_released()
{
    QString nom_departement;
    int id_departement=0 ,places_disponibles=0;
    QSqlQuery query;


    int cod = ui->idEdit_2->text().toInt();
    int codd = ui->nomEdit_2->text().toInt();
    QString res = QString::number(cod);
    QString ress = QString::number(codd);
    //id_departement = ui->idEdit_2->text().toInt();
   nom_departement = ui->nomEdit_2->text();
   places_disponibles = ui->placesEdit_2->text().toInt();


    Departement d(id_departement, nom_departement, places_disponibles);

    if(d.modifier_departement(cod))

    {
        ui->tabdepartement->setModel(tmpdepartement.afficher());//refresh
         ui->tabdepartement->setModel(tmpdepartement.afficher());
         QMessageBox::information(nullptr, QObject::tr("Modifier un département"),
                                    QObject::tr("Departement modifié.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

