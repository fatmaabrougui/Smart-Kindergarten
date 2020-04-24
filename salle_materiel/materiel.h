#ifndef MATERIEL_H
#define MATERIEL_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>




#include <QSqlTableModel>
#include <QTableView>

#include <QPaintEvent>
#include <QPainter>
#include <QVector>

class materiel
{
public:
    materiel();
    materiel(int,QString,int,int,int,int);
    int get_id_materiel();
    QString get_nom();
    int get_etat();
    int get_nombre();
    int get_id_salle();
     int get_total_panne();
    bool ajouter_materiel();
    QSqlQueryModel * afficher_materiel();
    bool supprimer_materiel(int);
    bool modifier_materiel(int);
   //QString chercher_materiel (QString);
    int alert ();


private:
    QString nom;
    int id_materiel,etat,nombre,id_salle,total_panne;
};

#endif // MATERIEL_H
