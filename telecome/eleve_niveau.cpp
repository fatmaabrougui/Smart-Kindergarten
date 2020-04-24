#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "eleve_niveau.h"
#include "ui_eleve_niveau.h"
#include "smtp.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtCharts/QChartView>
#include <QtWidgets/QStatusBar>
#include <QtCharts/QChartView>
#include "donutbreakdownchart.h"




#include <QDebug>
#include <QMessageBox>

#include <QVariant>
#include <QDebug>

QT_CHARTS_USE_NAMESPACE

eleve_niveau::eleve_niveau(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::eleve_niveau),uin(new Ui::eleve_niveau)
{
   // ui->setupUi(this);
    ui->setupUi(this);

   ui->tabeleve->setModel(tmpeleve.afficher());
   ui->tableniveau->setModel(tmpniveau.afficherNiveau());
    ui->comboBox->setModel(tmpniveau.chargerID());
   // ui->tableniveau->setModel(tmpniveau.afficherNiveau());




}



eleve_niveau::~eleve_niveau()
{
    delete ui;
   // delete ui;
}
#include <QDebug>
#include "connexion.h"


Niveau::Niveau(){
    idNiveau=nbrHeurs=ageNiveau=0;
    nomNiveau=Matiers="";
}

Eleve::Eleve()
{
id=0;
nom="";
prenom="";
age=0;
idniv=0;
}

Niveau::Niveau(int idNiveau,QString nomNiveau,int nbrHeurs,int ageNiveau,QString Matiers){
    this->idNiveau=idNiveau;
    this->nomNiveau=nomNiveau;
    this->nbrHeurs=nbrHeurs;
    this->ageNiveau=ageNiveau;
    this->Matiers=Matiers;

}

Eleve::Eleve(int id,QString nom,QString prenom,int age,int idniv)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->age=age;
    this->idniv=idniv ;
}

QString Niveau::get_Matiers(){return Matiers;}
QString Niveau::get_nomNiveau(){return  nomNiveau;}
int Niveau::get_idNiveau(){return  idNiveau;}
int Niveau::get_nbrHeurs(){return nbrHeurs;}
int Niveau::get_ageNiveau(){return  ageNiveau;}


QString Eleve::get_nom(){return  nom;}
QString Eleve::get_prenom(){return prenom;}
int Eleve::get_id(){return  id;}
int Eleve::get_age(){return age;}
int Eleve::get_idniv(){return idniv;}


bool Niveau::ajouterNiveau(){

    QSqlQuery query;

    QString nnn= QString::number(idNiveau);
    QString nnni= QString::number(ageNiveau);
    QString nnno= QString::number(nbrHeurs);


    query.prepare("INSERT INTO NIVEAU ( ID_NIVEAU, NOM_NIVEAU, NBR_HEURE_NIVEAU ,AGE_NIVEAU, MATIER_NIVEAU) "
                      "VALUES (:idNiveau, :nomNiveau, :nbrHeurs, :ageNiveau, :Matiers)");

    query.bindValue(":idNiveau", nnn);
    query.bindValue(":nomNiveau", nomNiveau);
    query.bindValue(":nbrHeurs", nnno);
    query.bindValue(":ageNiveau", nnni);
    query.bindValue(":Matiers", Matiers);

    return    query.exec();

}


bool Eleve::ajouter()
{
QSqlQuery query;

QString nnn= QString::number(id);
QString nnni= QString::number(age);
QString nnnn= QString::number(idniv);

query.prepare("INSERT INTO ELEVE ( ID_ELEVE, NOM_ELEVE, PRENOM_ELEVE ,AGE_ELEVE, ID_NIVEAU) "
                  "VALUES (:id, :nom, :prenom, :age, :idniv )");
query.bindValue(":id", nnn);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":age", nnni);
query.bindValue(":idniv", nnnn);


return    query.exec();
}

QSqlQueryModel * Niveau::afficherNiveau(){
    QSqlQueryModel * modeln= new QSqlQueryModel();
    modeln->setQuery("select * from NIVEAU");
    modeln->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_NIVEAU"));
    modeln->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_NIVEAU "));
    modeln->setHeaderData(2, Qt::Horizontal, QObject::tr("NBR_HEURE_NIVEAU"));
    modeln->setHeaderData(3, Qt::Horizontal, QObject::tr("Age_NIVEAU"));
    modeln->setHeaderData(4, Qt::Horizontal, QObject::tr("MATIER_NIVEAU"));
        return modeln;
}

QSqlQueryModel * Niveau::chargerID(){
    QSqlQueryModel * modeln= new QSqlQueryModel();
    modeln->setQuery("select ID_NIVEAU from NIVEAU");
    return modeln;
}

QSqlQueryModel * Eleve::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from ELEVE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_ELEVE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_ELEVE "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom_ELEVE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Age_ELEVE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_NIVEAU"));

    return model;
}



bool Niveau::supprimerNiveau(int iddn)
{
QSqlQuery query;
QString nnn= QString::number(iddn);
query.prepare("Delete from NIVEAU where ID_NIVEAU = :idNiveau");
query.bindValue(":idNiveau", nnn);
return    query.exec();
}

bool Eleve::supprimer(int idd)
{
QSqlQuery query;
QString nnn= QString::number(idd);
query.prepare("Delete from ELEVE where ID_ELEVE = :id");
query.bindValue(":id", nnn);
return    query.exec();
}



bool Niveau::modifierNiveau(int codn)
{


    QSqlQuery query;

    QString nnnn = QString::number(codn);



query.prepare("UPDATE NIVEAU set NOM_NIVEAU= :nomNiveau, NBR_HEURE_NIVEAU= :nbrHeurs, AGE_NIVEAU= :ageNiveau, MATIER_NIVEAU= :Matiers where ID_NIVEAU= :codn");
    query.bindValue(":codn", nnnn);
    query.bindValue(":nomNiveau", nomNiveau);
    query.bindValue(":nbrHeurs", nbrHeurs);
    query.bindValue(":ageNiveau", ageNiveau);
    query.bindValue(":Matiers", Matiers);

    return query.exec();
}


bool Eleve::modifier(int cod)
{


    QSqlQuery query;

    QString nnn = QString::number(cod);



query.prepare("UPDATE ELEVE set NOM_ELEVE= :nom, PRENOM_ELEVE= :prenom, AGE_ELEVE= :age where ID_ELEVE= :cod");
    query.bindValue(":cod", nnn);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":age", age);

    return query.exec();
}


QSqlQueryModel * Eleve::trie()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from ELEVE order by AGE_ELEVE ASC");
    return model;
}




//////////////////////////////////////////////////////////////////////////////////////////

void eleve_niveau::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    int age = ui->lineEdit_age->text().toInt();
    int idniv =ui->lineEdit_id_niv_eleve_ajout->text().toInt();
  Eleve e(id,nom,prenom,age,idniv);
  bool test=e.ajouter();
  if(test)
{

  ui->tabeleve->setModel(tmpeleve.afficher());//refnnnh
QMessageBox::information(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Etudiant ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void eleve_niveau::on_pb_supprimer_2_clicked()
{
    int id = ui->lineEdit_id_4->text().toInt();
    bool test=tmpeleve.supprimer(id);
    if(test)
    {
        ui->tabeleve->setModel(tmpeleve.afficher());//refnnnh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un étudiant"),
                    QObject::tr("Etudiant supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un étudiant"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



}

void eleve_niveau::on_pb_chercher_14_clicked()
{
    QSqlQuery query;
    int cod = ui->idl->text().toInt();

    QString nnn = QString::number(cod);
    query.prepare("SELECT * FROM eleve WHERE ID_ELEVE = :cod");
    query.bindValue(":cod", nnn);
    query.exec();
    if(query.first())
    {
        QMessageBox::information(this, tr("Modifier Eleve"), tr("Le Eleve est trouvé avec success, Veuillez entrer les nouvelles informations."));
         ui->idl->setText(query.value(0).toString());
        ui->noml->setText(query.value(1).toString());
        ui->prenoml->setText(query.value(2).toString());
        ui->agel->setText(query.value(3).toString());


}

}

void eleve_niveau::on_pb_confirmer_12_clicked()
{
    QString nom, prenom;
    int id = 0;
    int age=0;
    int idniv=0;
    QSqlQuery query;

    int cod = ui->idl->text().toInt();
   // int codi = ui->idl->text().toInt();
    QString nnn = QString::number(cod);
    //QString nnni = QString::number(codi);
    id = ui->idl->text().toInt();
    nom = ui->noml->text();
    prenom = ui->prenoml->text();
    age = ui->agel->text().toInt();

QMessageBox::information(this, tr("Modifier Eleve"), tr("..."));

    Eleve e(id, nom, prenom ,age,idniv);
    QMessageBox::information(this, tr("Modifier Eleve"), tr("...."));
    if(e.modifier(cod))
    {
        ui->tabeleve->setModel(tmpeleve.afficher());//refnnnh
        QMessageBox::information(this, tr("Modifier Eleve"), tr("Le Eleve a été modifié avec success."));
    }
}





void eleve_niveau::on_pushButton_ajouter_niv_clicked()
{
    int idNiveau = ui->lineEdit_id_niv_ajout->text().toInt();
    QString nomNiveau = ui->lineEdit_nom_niv_ajout->text();
    int nbrHeurs= ui->lineEdit_nbr_niv_ajout->text().toInt();
    int ageNiveau= ui->lineEdit_age_niveau_ajout->text().toInt();
    QString Matiers = ui->lineEdit_matiers_ajout->text();

  Niveau n(idNiveau,nomNiveau,nbrHeurs,ageNiveau,Matiers);
  bool test=n.ajouterNiveau();
  if(test)
{

  ui->tableniveau->setModel(tmpniveau.afficherNiveau());//refnnnh
QMessageBox::information(nullptr, QObject::tr("Ajouter un Niveau"),
                  QObject::tr("Niveau ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un Niveau"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void eleve_niveau::on_pB_supprimer_niv_clicked()
{
    int idni = ui->lineEdit_supp_niv->text().toInt();
    bool test=tmpniveau.supprimerNiveau(idni);
    if(test)
    {
        ui->tableniveau->setModel(tmpniveau.afficherNiveau());//refnnnh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un niveau"),
                    QObject::tr("Niveau supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un niveau"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



}

void eleve_niveau::on_pb_chercher_niv_clicked()
{
    QSqlQuery query;
    int cod = ui->lineEdit_id_niv_modif->text().toInt();

    QString nnn = QString::number(cod);
    query.prepare("SELECT * FROM niveau WHERE ID_NIVEAU = :cod");
    query.bindValue(":cod", nnn);
    query.exec();
    if(query.first())
    {
        QMessageBox::information(this, tr("Modifier Niveau"), tr("Le Niveau est trouvé avec success, Veuillez entrer les nouvelles informations."));
         ui->lineEdit_id_niv_modif->setText(query.value(0).toString());
        ui->lineEdit_nom_niv_modif->setText(query.value(1).toString());
        ui->lineEdit_nbrheur_niv_modif->setText(query.value(2).toString());
        ui->lineEdit_age_niv_modif->setText(query.value(3).toString());
        ui->lineEdit_matier_niv_modif->setText(query.value(4).toString());

    }
}

void eleve_niveau::on_pB_modif_niv_clicked()
{




    QString nomNiveau,Matiers;
    int idNiveau(0),nbrHeurs(0),ageNiveau(0);
    QSqlQuery query;

    int cod = ui->lineEdit_id_niv_modif->text().toInt();
   // int codi = ui->idl->text().toInt();
    QString nnn = QString::number(cod);
    //QString nnni = QString::number(codi);
    idNiveau = ui->lineEdit_id_niv_modif->text().toInt();
    nomNiveau = ui->lineEdit_nom_niv_modif->text();
    nbrHeurs = ui->lineEdit_nbrheur_niv_modif->text().toInt();
    ageNiveau = ui->lineEdit_age_niv_modif->text().toInt();
    Matiers = ui->lineEdit_matier_niv_modif->text();

QMessageBox::information(this, tr("Modifier Niveau"), tr("..."));

    Niveau n(idNiveau, nomNiveau, nbrHeurs ,ageNiveau,Matiers);
    QMessageBox::information(this, tr("Modifier Niveau"), tr("...."));
    if(n.modifierNiveau(cod))
    {
        ui->tableniveau->setModel(tmpniveau.afficherNiveau());//refnnnh
        QMessageBox::information(this, tr("Modifier Eleve"), tr("Le Eleve a été modifié avec success."));
    }
}


void eleve_niveau::on_comboBox_currentIndexChanged(const QString &arg1)
{

    ui->lineEdit_id_niv_eleve_ajout->setText(arg1);

}

void eleve_niveau::on_pB_envoyer_clicked()
{
    Smtp *s=new Smtp("fournisseurX@gmail.com","fournisseur123","smtp.gmail.com",465);
    s->sendMail("fornisseurX@gmail.com",ui->lineEdit_destin->text(),ui->lineEdit_objet->text(),ui->lineEdit_message->text());


}

void eleve_niveau::on_pB_trie_eleve_clicked()
{
    Eleve  *e=NULL ;
    ui->tabeleve->setModel(e->trie());

}

//////////////////////staaaaaaaaat

void eleve_niveau::on_pB_stat_eleve_clicked()
{


   // QApplication a(argc, argv);

    int v1,v2,v3,v4,v5,v6,v7,vx;
    v1=v2=v3=v4=v5=v6=v7=vx=0;
  QSqlQuery skiza;


  skiza.prepare("SELECT * FROM ELEVE WHERE AGE_ELEVE = 1 ");
  skiza.exec();
    while (skiza.next())
  {
 v1++;
  }
    skiza.prepare("SELECT * FROM ELEVE WHERE AGE_ELEVE = 2 ");
    skiza.exec();
      while (skiza.next())
    {
     v2++;
    }
      skiza.prepare("SELECT * FROM ELEVE WHERE AGE_ELEVE = 3 ");
      skiza.exec();
        while (skiza.next())
      {
       v3++;
      }
        skiza.prepare("SELECT * FROM ELEVE WHERE AGE_ELEVE = 4 ");
        skiza.exec();
          while (skiza.next())
        {
         v4++;
        }
          skiza.prepare("SELECT * FROM ELEVE WHERE AGE_ELEVE = 5 ");
          skiza.exec();
            while (skiza.next())
          {
           v5++;
          }
            skiza.prepare("SELECT * FROM ELEVE WHERE AGE_ELEVE = 6 ");
            skiza.exec();
              while (skiza.next())
            {
             v6++;
            }
              skiza.prepare("SELECT * FROM ELEVE WHERE AGE_ELEVE = 7 ");
              skiza.exec();
                while (skiza.next())
              {
               v7++;
              }

                skiza.prepare("SELECT * FROM ELEVE WHERE AGE_ELEVE = 9 ");
                skiza.exec();
                  while (skiza.next())
                {
                 vx++;
                }






QPieSeries *series1 = new QPieSeries();
series1->setName("[1-2]");
series1->append("1", v1);
series1->append("2", v2);


QPieSeries *series2 = new QPieSeries();
series2->setName("[2-5]");
series2->append("3", v3);
series2->append("4", v4);
series2->append("5", v5);

QPieSeries *series3 = new QPieSeries();
series3->setName("[5-7]");
series3->append("6 ", v6);
series3->append("7", v7);

QPieSeries *series4 = new QPieSeries();
series4->setName("[7-...]");
series4->append("... ", vx);

//![1]

//![2]
// QSound houhi("test.wav");
//houhi.play();
DonutBreakdownChart *donutBreakdown = new DonutBreakdownChart();
donutBreakdown->setAnimationOptions(QChart::AllAnimations);
donutBreakdown->setTitle("statistic des élèves selon leurs age");
donutBreakdown->legend()->setAlignment(Qt::AlignRight);
donutBreakdown->addBreakdownSeries(series1, Qt::red);
donutBreakdown->addBreakdownSeries(series2, Qt::darkGreen);
donutBreakdown->addBreakdownSeries(series3, Qt::darkBlue);
donutBreakdown->addBreakdownSeries(series4, Qt::yellow);
//![2]

//![3]
QMainWindow window;
QChartView *chartView = new QChartView(donutBreakdown);
chartView->setRenderHint(QPainter::Antialiasing);
window.setCentralWidget(chartView);
window.resize(800, 500);


window.show();

//![3]
//return a.exec();


}
