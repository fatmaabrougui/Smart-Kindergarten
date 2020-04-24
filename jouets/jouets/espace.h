#ifndef ESPACE_H
#define ESPACE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class espace
{
public:
    espace();
    espace(int,QString,int  );
    int get_id_espace();
    QString get_fonction_espace();
    //QString get_categorie();

    int get_capacite();
    bool ajouter_espace();
    QSqlQueryModel * afficher_espace();
    bool supprimer_espace(int);
    bool modifier_espace(int);
      QSqlQueryModel * trie();
      QSqlQueryModel * display();


private:
    QString fonction_espace;
    int id_espace,capacite;
};

#endif // espace_H
