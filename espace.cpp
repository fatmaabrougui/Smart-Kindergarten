#include "espace.h"
#include <QDebug>
#include "connexion.h"


espace::espace()
{
    id_espace=0;
    fonction_espace="";
    capacite=0;
  }
espace::espace(int id_espace,QString fonction_espace,int capacite  )
{
  this->id_espace=id_espace;
  this->fonction_espace=fonction_espace;
  this->capacite=capacite;
}

QString espace ::get_fonction_espace(){return  fonction_espace;}

int espace::get_id_espace(){return  id_espace;}
int espace::get_capacite(){return capacite;}




bool espace::ajouter_espace ()
{
QSqlQuery query;

QString res= QString::number(capacite);

query.prepare("INSERT INTO espace ( fonction_espace, CAPACITE) "
                  "VALUES (:fonction_espace, :capacite)");
query.bindValue(":capacite", res);

query.bindValue(":fonction_espace", fonction_espace);

//query.bindValue(":capacite", capacite);
//query.bindValue(":categorie", categorie);


return    query.exec();

}

QSqlQueryModel * espace::afficher_espace()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from espace ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_espace"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("fonction_espace "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Capacité"));
//model->setHeaderData(3, Qt::Horizontal, QObject::tr("Categorie"));

    return model;
}
bool espace::supprimer_espace(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from espace where ID_espace = :id_espace");
query.bindValue(":id_espace", res);
return    query.exec();
}

bool espace::modifier_espace(int cod)
{
    QSqlQuery query;

   QString res = QString::number(cod);
   QString ress = QString::number(capacite);
//query.prepare("UPDATE espace "" SET ID_espace = :id_espace, fonction_espace = :fonction_espace, CAPACITE = :capacite,  ""WHERE ID_espace = :cod");
query.prepare("UPDATE espace set fonction_espace= :fonction_espace, CAPACITE= :capacite where id_espace= :cod");
    query.bindValue(":cod", res);
    query.bindValue(":fonction_espace", fonction_espace);

    //query.bindValue(":capacite", capacite);
query.bindValue(":capacite", ress);
//query.bindValue(":categorie", categorie);

    return query.exec();
}
QSqlQueryModel *espace::trie()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from espace order by capacite ASC");
    return model;
}

QSqlQueryModel *espace::display()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select fonction_espace from espace fonction_espace");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("fonction_espace"));
    return model;

}
