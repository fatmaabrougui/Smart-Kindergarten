#ifndef ELEVE_NIVEAU_H
#define ELEVE_NIVEAU_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>
#include <QMainWindow>



class Eleve
{public:
    Eleve();
    Eleve(int,QString,QString,int,int);
    QString get_nom();
    QString get_prenom();
    int get_id();
    int get_age();
    int get_idniv();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel * trie();
private:
    QString nom,prenom;
    int id,age,idniv;
};

class Niveau
{public:
    Niveau();
    Niveau(int,QString,int,int,QString);
    QString get_nomNiveau();
    QString get_Matiers();
    int get_idNiveau();
    int get_ageNiveau();
    int get_nbrHeurs();
    bool ajouterNiveau();
    QSqlQueryModel * afficherNiveau();
    QSqlQueryModel * chargerID();
    bool supprimerNiveau(int);
    bool modifierNiveau(int);
private:
    QString nomNiveau,Matiers;
    int idNiveau,nbrHeurs,ageNiveau;
};





namespace Ui {
class eleve_niveau;
}

class eleve_niveau : public QDialog
{
    Q_OBJECT

public:
    explicit eleve_niveau(QWidget *parent = nullptr);
    ~eleve_niveau();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pb_chercher_14_clicked();

    void on_pb_confirmer_12_clicked();


    void on_pushButton_ajouter_niv_clicked();

    void on_pB_supprimer_niv_clicked();

    void on_pb_chercher_niv_clicked();

    void on_pB_modif_niv_clicked();


    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pB_envoyer_clicked();

    void on_pB_trie_eleve_clicked();

    void on_pB_stat_eleve_clicked();

private:
    Ui::eleve_niveau *ui,*uin;
    Eleve tmpeleve;
    Niveau tmpniveau;
};





#endif // ELEVE_NIVEAU_H
