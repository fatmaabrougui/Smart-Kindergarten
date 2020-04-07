#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Employe
{public:
    Employe();
    Employe(int,QString,QString,int);
    QString get_nom();
    QString get_date();
    int get_id();
    int get_id_dep();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier_employe(int);
private:
    QString nom_employe;
    QString date_recrutement;
    int id_employe,id_departement;
};

#endif // EMPLOYE_H
