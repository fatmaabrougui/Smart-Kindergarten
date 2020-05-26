#include "menu.h"
#include <QDebug>
#include "connexion.h"
Menu::Menu()
{
ID_MENU=0;
NOM_MENU="";
TEMPS="";
}
Menu::Menu(int ID_MENU,QString NOM_MENU,QString TEMPS)
{
  this->ID_MENU=ID_MENU;
  this->NOM_MENU=NOM_MENU;
  this->TEMPS=TEMPS;
}
int Menu::get_ID_MENU(){return  ID_MENU;}
QString Menu::get_NOM_MENU(){return  NOM_MENU;}
QString Menu::get_TEMPS(){return TEMPS;}

bool Menu::ajouter()
{
QSqlQuery query;
QString res= QString::number(ID_MENU);
query.prepare("INSERT INTO MENU (ID_MENU, NOM_MENU, TEMPS) "
                    "VALUES (:ID_MENU, :NOM_MENU, :TEMPS)");
query.bindValue(":ID_MENU", res);
query.bindValue(":NOM_MENU", NOM_MENU);
query.bindValue(":TEMPS", TEMPS);

return    query.exec();
}

QSqlQueryModel * Menu::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from MENU");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_MENU"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TEMPS"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM_MENU"));
    return model;
}

bool Menu::supprimer(int ID_MENUd)
{
QSqlQuery query;
QString res= QString::number(ID_MENUd);
query.prepare("Delete from MENU where ID_MENU = :ID_MENU ");
query.bindValue(":ID_MENU", res);
return    query.exec();
}

bool Menu::modifier_menu(int cod)
{
    QSqlQuery query;

   QString res = QString::number(cod);
//query.prepare("UPDATE salle "" SET ID_SALLE = :id_salle, FONCTION = :fonction, CAPACITE = :capacite,  ""WHERE ID_SALLE = :cod");
query.prepare("UPDATE MENU set ID_MENU= :ID_MENU, NOM_MENU=:NOM_MENU, TEMPS=:TEMPS where ID_MENU= :cod");
    query.bindValue(":cod", res);
    query.bindValue(":NOM_MENU", NOM_MENU);
    query.bindValue(":TEMPS", TEMPS);
    //query.bindValue(":capacite", capacite);
    return query.exec();
}
QSqlQueryModel * Menu::trie()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select ID_MENU from MENU order by DISPO ASC");
    return model;
}

