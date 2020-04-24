#include "departement.h"
#include <QDebug>
#include "connexion.h"
Departement::Departement()
{
id_departement=0;
nom_departement="";
places_disponibles=0;
}
Departement::Departement(int places_disponibles, QString nom_departement, int id_departement)
{
  this->id_departement=id_departement;
  this->nom_departement=nom_departement;
  this->places_disponibles=places_disponibles;
}
int Departement::get_id(){return  id_departement;}
QString Departement::get_nom(){return  nom_departement;}
int Departement::get_places(){return places_disponibles;}

bool Departement::ajouter()
{
QSqlQuery query;
QString res= QString::number(id_departement);
query.prepare("INSERT INTO departements (id_departement, nom_departement,places_disponibles) "
                    "VALUES (:id_departement, :nom_departement, :places_disponibles)");
query.bindValue(":id_departement", id_departement);
query.bindValue(":nom_departement", nom_departement);
query.bindValue(":places_disponibles", places_disponibles);
return    query.exec();
}

QSqlQueryModel * Departement::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from departements");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_departement"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_departement "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("places_disponibles"));
    return model;
}

bool Departement::supprimer(int id_departementd)
{

QSqlQuery query;
QString res= QString::number(id_departementd);
query.prepare("Delete from departements WHERE id_departement = :id_departement ");
query.bindValue(":id_departement", res);
return    query.exec();
}
bool Departement::modifier_departement(int cod)
{
    QSqlQuery query;

   QString res = QString::number(cod);
   QString ress = nom_departement;
query.prepare("UPDATE departements SET nom_departement= :nom_departement, places_disponibles= :places_disponibles WHERE id_departement= :cod");
    query.bindValue(":cod", res);
    query.bindValue(":nom_departement", ress);

    query.bindValue(":places_disponibles", places_disponibles);

    return query.exec();
}


