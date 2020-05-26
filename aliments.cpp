#include "Aliments.h"
#include <QDebug>
#include "connexion.h"
Aliments::Aliments()
{
ID_ALIMENT=0;
ID_MENU=0;
DISPO=0;
NOM_ALIMENT="";
TYPE_ALIMENT="";
}
Aliments::Aliments(int ID_ALIMENT,QString NOM_ALIMENT,QString TYPE_ALIMENT,int DISPO,int ID_MENU)
{
  this->ID_ALIMENT=ID_ALIMENT;
  this->NOM_ALIMENT=NOM_ALIMENT;
  this->TYPE_ALIMENT=TYPE_ALIMENT;
  this->DISPO=DISPO;
  this->ID_MENU=ID_MENU;
}
int Aliments::get_ID_ALIMENT(){return ID_ALIMENT;}
QString Aliments::get_NOM_ALIMENT(){return  NOM_ALIMENT;}
QString Aliments::get_TYPE_ALIMENT(){return TYPE_ALIMENT;}
int Aliments::get_DISPO(){return  DISPO;}
int Aliments::get_ID_MENU(){return  ID_MENU;}

bool Aliments::ajouter()
{
QSqlQuery query;
QString res= QString::number(ID_ALIMENT);
query.prepare("INSERT INTO  ALIMENTS(ID_ALIMENT, NOM_ALIMENT, TYPE_ALIMENT, DISPO,ID_MENU) "
                    "VALUES (:ID_ALIMENT, :NOM_ALIMENT, :TYPE_ALIMENT,:DISPO,:ID_MENU )");
query.bindValue(":ID_ALIMENT", ID_ALIMENT);
query.bindValue(":NOM_ALIMENT", NOM_ALIMENT);
query.bindValue(":TYPE_ALIMENT", TYPE_ALIMENT);
query.bindValue(":DISPO", DISPO);
query.bindValue(":ID_MENU", ID_MENU);

return    query.exec();
}

QSqlQueryModel * Aliments::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from ALIMENTS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_ALIMENT"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_ALIMENT"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_ALIMENT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DISPO"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_MENU"));
    return model;
}

bool Aliments::supprimer(int ID_ALIMENTd)
{
QSqlQuery query;
QString res= QString::number(ID_ALIMENTd);
query.prepare("Delete from ALIMENTS where ID_ALIMENT = :ID_ALIMENT ");
query.bindValue(":ID_ALIMENT", res);
return    query.exec();
}

bool Aliments::modifier_aliments(int cod)
{
    QSqlQuery query;

   QString res = QString::number(cod);
   QString ress = QString::number(DISPO);
   QString resss = QString::number(ID_MENU);
//query.prepare("UPDATE salle "" SET ID_SALLE = :id_salle, FONCTION = :fonction, CAPACITE = :capacite,  ""WHERE ID_SALLE = :cod");
query.prepare("UPDATE ALIMENTS set DISPO= :DISPO, ID_MENU= :ID_MENU, NOM_ALIMENT=:NOM_ALIMENT, TYPE_ALIMENT=:TYPE_ALIMENT where ID_ALIMENT= :cod");
    query.bindValue(":cod", res);
    query.bindValue(":NOM_ALIMENT", NOM_ALIMENT);
    query.bindValue(":TYPE_ALIMENT", TYPE_ALIMENT);
    //query.bindValue(":capacite", capacite);
query.bindValue(":DISPO", ress);
query.bindValue(":ID_MENU", resss);
    return query.exec();
}
QSqlQueryModel * Aliments::trie()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from ALIMENTS order by DISPO ASC");
    return model;
}

