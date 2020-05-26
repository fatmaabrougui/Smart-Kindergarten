#include "employe.h"
#include <QDebug>
#include "connexion.h"
Employe::Employe()
{
cin=0;
nom_employe="";
poste="";
date_recrutement="";
id_departement=0;
}
Employe::Employe(int cin,QString nom_employe,QString poste,QString date_recrutement,int id_departement)
{
  this->cin=cin;
  this->nom_employe=nom_employe;
  this->poste=poste;
  this->date_recrutement=date_recrutement;
  this->id_departement=id_departement;
}
QString Employe::get_nom(){return  nom_employe;}
QString Employe::get_poste(){return poste;}
QString Employe::get_date(){return date_recrutement;}
int Employe::get_id(){return  cin;}
int Employe::get_id_dep(){return id_departement;}

bool Employe::ajouter()
{
QSqlQuery query;
QString res= QString::number(cin);
query.prepare("INSERT INTO employe (cin, nom_employe, poste, date_recrutement, id_departement) "
                    "VALUES (:cin, :nom_employe, :poste, :date_recrutement, :id_departement)");
query.bindValue(":cin", cin);
query.bindValue(":nom_employe", nom_employe);
query.bindValue(":poste", poste);
query.bindValue(":date_recrutement", date_recrutement);
query.bindValue(":id_departement", id_departement);
return    query.exec();
}

QSqlQueryModel * Employe::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from employe");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("poste"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom_employe "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_recrutement"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("id_departement"));
    return model;
}

bool Employe::supprimer(int cind)
{
QSqlQuery query;
QString res= QString::number(cind);
query.prepare("Delete from employe where cin = :cin ");
query.bindValue(":cin", res);
return    query.exec();
}

bool Employe::modifier_employe(int cod)
{
    QSqlQuery query;

   QString res = QString::number(cod);
   QString ress = QString::number(id_departement);
query.prepare("UPDATE employe set nom_employe= :nom_employe, poste= :poste, id_departement= :id_departement, date_recrutement= :date_recrutement WHERE cin= :cod");
    query.bindValue(":cod", res);
    query.bindValue(":nom_employe", nom_employe);
    query.bindValue(":poste", poste);
    //query.bindValue(":id_departement", id_departement);
    query.bindValue(":date_recrutement", date_recrutement);
query.bindValue(":id_departement", ress);
    return query.exec();
}


