#include "employe.h"
#include <QDebug>
#include "connexion.h"
Employe::Employe()
{
id_employe=0;
nom_employe="";
date_recrutement="";
id_departement=0;
}
Employe::Employe(int id_employe,QString nom_employe,QString date_recrutement,int id_departement)
{
  this->id_employe=id_employe;
  this->nom_employe=nom_employe;
  this->date_recrutement=date_recrutement;
  this->id_departement=id_departement;
}
QString Employe::get_nom(){return  nom_employe;}
QString Employe::get_date(){return date_recrutement;}
int Employe::get_id(){return  id_employe;}
int Employe::get_id_dep(){return id_departement;}

bool Employe::ajouter()
{
QSqlQuery query;
QString res= QString::number(id_employe);
query.prepare("INSERT INTO employe (id_employe, nom_employe, date_recrutement, id_departement) "
                    "VALUES (:id_employe, :nom_employe, :date_recrutement, :id_departement)");
query.bindValue(":id_employe", id_employe);
query.bindValue(":nom_employe", nom_employe);
query.bindValue(":date_recrutement", date_recrutement);
query.bindValue(":id_departement", id_departement);
return    query.exec();
}

QSqlQueryModel * Employe::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from employe");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_employe"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_employe "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_recrutement"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("id_departement"));
    return model;
}

bool Employe::supprimer(int id_employed)
{
QSqlQuery query;
QString res= QString::number(id_employed);
query.prepare("Delete from employe where id_employe = :id_employe ");
query.bindValue(":id_employe", res);
return    query.exec();
}

bool Employe::modifier_employe(int cod)
{
    QSqlQuery query;

   QString res = QString::number(cod);
   QString ress = QString::number(id_departement);
//query.prepare("UPDATE employe "" SET ID_materiel = :id_materiel, nom = :nom, etat = :etat,  ""WHERE ID_materiel = :cod");
query.prepare("UPDATE employe set nom_employe= :nom_employe, id_departement= :id_departement, date_recrutement= :date_recrutement WHERE id_employe= :cod");
    query.bindValue(":cod", res);
    query.bindValue(":nom_employe", nom_employe);
    //query.bindValue(":id_departement", id_departement);
    query.bindValue(":date_recrutement", date_recrutement);
query.bindValue(":id_departement", ress);
    return query.exec();
}


