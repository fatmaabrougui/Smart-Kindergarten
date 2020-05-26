#ifndef ALIMENTS_H
#define ALIMENTS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Aliments
{public:
    Aliments();
    Aliments(int,QString,QString,int,int);
    int get_ID_ALIMENT();
    QString get_NOM_ALIMENT();
    QString get_TYPE_ALIMENT();
    int get_DISPO();
    int get_ID_MENU();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier_aliments(int);
    QSqlQueryModel * trie();
private:
    QString NOM_ALIMENT,TYPE_ALIMENT;
    int ID_ALIMENT,DISPO,ID_MENU;
};

#endif // ALIMENTS_H
