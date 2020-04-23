#include "club.h"
#include <QDebug>
#include "connexion.h"
Club::Club()
{
idclub=0;
nomclub="";
categclub="";
descclub="";
}
Club::Club(int idclub,QString nomclub,QString categclub, QString descclub)
{
  this->idclub=idclub;
  this->nomclub=nomclub;
    this->categclub=categclub;
    this->descclub=descclub;
}
QString Club::get_nomclub(){return  nomclub;}
QString Club::get_categclub(){return categclub;}
QString Club::get_descclub(){return descclub;}
int Club::get_idclub(){return  idclub;}

bool Club::ajouter()
{
QSqlQuery query;
QString res= QString::number(idclub);
query.prepare("INSERT INTO Club (id_club, nom_club, categorie_club, description_club) "
                    "VALUES (:idclub, :nomclub, :categclub, :dessclub)");
query.bindValue(":idclub", idclub);
query.bindValue(":nomclub", nomclub);
query.bindValue(":categclub", categclub);
query.bindValue(":descclub", descclub);

return    query.exec();
}

QSqlQueryModel * Club::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from Club");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("idclub"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomclub "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("categclub"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("descclub"));
    return model;
}

bool Club::supprimer(int idclubd)
{
QSqlQuery query;
QString res= QString::number(idclubd);
query.prepare("Delete from Club where id_club = :idclub ");
query.bindValue(":idclub", res);
return    query.exec();
}


bool Club::modifier_club(int cod)
{
    QSqlQuery query;

   QString res = QString::number(cod);
   QString ress = nomclub;
query.prepare("UPDATE club set nom_club= :nomclub, categorie_club= :categclub, description_club= :descclub WHERE id_club= :cod");
    query.bindValue(":cod", res);
    query.bindValue(":categclub", categclub);
    query.bindValue("descclub", descclub);
    query.bindValue(":nomclub", ress);
    return query.exec();
}


