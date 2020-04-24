#ifndef JOUETS_H
#define JOUETS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class jouets
{
public:
    jouets();
    jouets(int,QString,int,QString);
    int get_id_jouets();
    QString get_nom_jouets();
    QString get_cat_jouets();
    int get_qt_jouets();
    bool ajouter_jouets();
    QSqlQueryModel * afficher_jouets();
    bool supprimer_jouets(int);
    bool modifier_jouets(int);
    QSqlQueryModel * trier();

private:
    QString nom_jouets,cat_jouets;
    int id_jouets,qt_jouets;
};

#endif // jouets_H


