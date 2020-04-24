#ifndef SALLE_H
#define SALLE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class salle
{
public:
    salle();
    salle(int,QString,int);
    int get_id_salle();
    QString get_fonction();
    int get_capacite();
    bool ajouter_salle();
    QSqlQueryModel * afficher_salle();
    bool supprimer_salle(int);
    bool modifier_salle(int);
      QSqlQueryModel * trie();
      //bool pdf(QString chemin,QString txt );
   bool afficher_seule_salle (QString fonction);
  QSqlQueryModel * aff_seule_salle();
     QSqlQueryModel * rechercher(QString fonction);


private:
    QString fonction;
    int id_salle,capacite;
};

#endif // SALLE_H
