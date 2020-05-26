#include "gestiond_emp.h"
#include "ui_gestiond_emp.h"
#include "employe.h"
#include "departement.h"
#include "smtp.h"
#include "connexion.h"
//#include "statestique.h"
#include<QtPrintSupport/QPrinter>
#include <QVector2D>
#include <QVector>
#include <QTextEdit>
#include <QMessageBox>
#include<QPdfWriter>
#include <QPainter>
#include <QSqlQuery>
#include<QPainter>
#include <QAbstractSocket>
#include<QDesktopServices>
#include<QPdfWriter>
#include <QMessageBox>
#include<QUrl>
#include<QFileDialog>
#include <QPixmap>
#include <QTabWidget>
#include <QtSql/QSqlQueryModel>
#include<QtSql/QSqlQuery>
#include<QVariant>

GestionD_emp::GestionD_emp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GestionD_emp)
{
ui->setupUi(this);

ui->tabemploye->setModel(tmpemploye.afficher());
ui->tabdepartement->setModel(tmpdepartement.afficher());
ui->comboBox->setModel(tmpdepartement.afficher());
ui->comboBox_2->setModel(tmpemploye.afficher());
ui->comboBox_3->setModel(tmpdepartement.afficher());
}

GestionD_emp::~GestionD_emp()
{
    delete ui;
}

void GestionD_emp::on_pb_ajouter_clicked()
{
   /* QSqlQuery query;
    int crash = ui->comboBox->text().toInt();

    QString res = QString::number(cod);
    query.prepare("SELECT id_departement FROM employe WHERE cin = :crash");
    query.bindValue(":crash", res);
    query.exec();
    */





    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString poste=ui->lineEdit_poste->text();
    QString date= ui->lineEdit_date->text();
    int id_dept= ui->lineEdit_iddept_2->text().toInt();
  Employe e(id,nom,poste,date,id_dept);
  bool test=e.ajouter();
  if(test)
{

      ui->tabemploye->setModel(tmpemploye.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un employe"),
                  QObject::tr("Employe ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un employe"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void GestionD_emp::on_pb_supprimer_clicked()
{
int id = ui->lineEdit_id_2->text().toInt();
bool test=tmpemploye.supprimer(id);
if(test)
{ui->tabemploye->setModel(tmpemploye.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un employe"),
                QObject::tr("Employe supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un employe"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void GestionD_emp::on_pb_ajouter_2_clicked() //ajouter Departement
{
    int id =0;
    QString nom= ui->lineEdit_nom_2->text();
    int places= ui->lineEdit_id_3->text().toInt();
  Departement d(id,nom,places);
  bool test=d.ajouter();
  if(test)
{

      ui->tabdepartement->setModel(tmpdepartement.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un département"),
                  QObject::tr("Departement ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un département"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void GestionD_emp::on_pb_supprimer_2_clicked() //supprimer Departement
{
int id = ui->lineEdit_id_4->text().toInt();
bool test=tmpdepartement.supprimer(id);
if(test)
{ui->tabdepartement->setModel(tmpdepartement.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un Département"),
                QObject::tr("Departement supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un département"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
//******************************************************************************************************
//Employe Modification :

bool GestionD_emp::on_pb_chercherE_released()
{

    QSqlQuery query;
    int cod = ui->idEdit->text().toInt();

    QString res = QString::number(cod);
    query.prepare("SELECT * FROM employe WHERE cin = :cod");
    query.bindValue(":cod", res);
    query.exec();
    if(query.first())
    {
        QMessageBox::information(this, tr("Modifier Employe"), tr("L'employe est trouvé avec success, Veuillez entrer les nouvelles informations."));
         ui->idEdit->setText(query.value(0).toString());
        ui->nomEdit->setText(query.value(1).toString());
        ui->posteEdit->setText(query.value(2).toString());
        ui->dateEdit->setText(query.value(3).toString());
        ui->depEdit->setText(query.value(4).toString());

        return true;
}}


void GestionD_emp::on_pdf_clicked()
{int i=0;
    int x=1;
    int y=0;
 //int j=0;
    QPdfWriter pdf("C:/Users/Lenovo/Documents/guinga/fatma+nour+yessine+louay/telecome/PDF File/louaaaay.pdf");/*il faut toujours changer le nom (*/
    QPainter painter;
    if (! painter.begin(&pdf))
    {

                        qWarning("failed to open file, is it writable?");

    }
    //QString titre =ui->lineEdit_rese_pdf->text();
    const time_t ctt = time(0);
    QSqlQuery query;
     qWarning("test1");
    //query.exec("SELECT cin, nom_employe, poste, date_recrutement, id_departement FROM employe WHERE nom_employe='"+titre+"'");
      query.exec("SELECT * FROM employe");
     qWarning("test2");

            while (query.next())//big while where the first typing happens
                  {//j++;


                QString cin = query.value(0).toString();
                QString nom_employe = query.value(1).toString();
                QString poste = query.value(2).toString();
                QString date_recrutement = query.value(3).toString();
                QString id_departement = query.value(4).toString();
                //QString j = query.value(5).toString();
 if (x==3)//pdf page only accepts like 3 full info employees// second while u could say please mark this don't lose it
 { while (query.next()){
         QString cin = query.value(0).toString();
         QString nom_employe = query.value(1).toString();
         QString poste = query.value(2).toString();
         QString date_recrutement = query.value(3).toString();
         QString id_departement = query.value(4).toString();

         painter.drawText(5200,3500+y,cin);
         painter.drawText(5200,4000+y,nom_employe);
         painter.drawText(5200,4500+y,poste);
         painter.drawText(5200,5000+y,date_recrutement);
         painter.drawText(5200,5500+y,id_departement);


         painter.setPen(Qt::red);
         painter.drawText(4500,2000,"Fiche Employe");
         painter.setPen(Qt::black);
         painter.drawText(500,2000,asctime(localtime(&ctt)));
                    //painter.drawText(519,3500+i,j);
                    //painter.drawText(512,4000+i,j);
         painter.drawText(3500,3500+y,"Identifiant Employe:");
         painter.drawText(3500,4000+y,"Nom Employe:");
         painter.drawText(3500,4500+y,"poste:");
         painter.drawText(3500,5000+y,"Date de recrutement:");
         painter.drawText(3500,5500+y,"Id departement:");

         x++;
         y=y+3000;}}//'y' is 'i' because I had to reinitialize 'i' but if I do it it wouldn't work(it would go back to 0 each time) so I have to create another variable



 //back to the big while
        //painter.drawText(500,3500+i,j);
        //painter.drawText(500,4000+i,j);
        painter.drawText(2200,3500+i,cin);
        painter.drawText(2200,4000+i,nom_employe);
        painter.drawText(2200,4500+i,poste);
        painter.drawText(2200,5000+i,date_recrutement);
        painter.drawText(2200,5500+i,id_departement);


        painter.setPen(Qt::red);
        painter.drawText(4500,2000,"Fiche Employe");
        painter.setPen(Qt::black);
        painter.drawText(500,2000,asctime(localtime(&ctt)));
        //painter.drawText(519,3500+i,j);
        //painter.drawText(512,4000+i,j);
        painter.drawText(500,3500+i,"Identifiant Employe:");
        painter.drawText(500,4000+i,"Nom Employe:");
        painter.drawText(500,4500+i,"poste:");
        painter.drawText(500,5000+i,"Date de recrutement:");
        painter.drawText(500,5500+i,"Id departement:");

x++;
i=i+3000;

            }
}

void GestionD_emp::on_pb_confirmerE_released()
{ //capacite=dept
    QString nom_employe,date_recrutement,poste;
    int cin=0, id_departement=0;
    QSqlQuery query;


    int cod = ui->idEdit->text().toInt();
    int codd = ui->depEdit->text().toInt();
    QString res = QString::number(cod);
    QString ress = QString::number(codd);
    cin = ui->idEdit->text().toInt();
   nom_employe = ui->nomEdit->text();
   poste = ui->posteEdit->text();
   date_recrutement= ui->dateEdit->text();
   id_departement = ui->depEdit->text().toInt();


    Employe e(cin, nom_employe, poste, date_recrutement, id_departement);

    if(e.modifier_employe(cod))

    {
        ui->tabemploye->setModel(tmpemploye.afficher());//refresh
         ui->tabemploye->setModel(tmpemploye.afficher());
         QMessageBox::information(nullptr, QObject::tr("Modifier un employe"),
                                    QObject::tr("Employe modifié.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}




//**************************************************************************************************************
//Departement Modification:


bool GestionD_emp::on_pb_chercherD_released()
{
    QSqlQuery query;
    int cod = ui->idEdit_2->text().toInt();

    QString res = QString::number(cod);
    query.prepare("SELECT * FROM departements WHERE id_departement = :cod");
    query.bindValue(":cod", res);
    query.exec();
    if(query.first())
    {
        QMessageBox::information(this, tr("Modifier Département"), tr("Le département est trouvé avec success, Veuillez entrer les nouvelles informations."));
         ui->idEdit_2->setText(query.value(0).toString());
        ui->nomEdit_2->setText(query.value(1).toString());
        ui->placesEdit_2->setText(query.value(2).toString());

        return true;

}
}
void GestionD_emp::on_pb_confirmerD_released()
{
    QString nom_departement;
    int id_departement=0 ,postes_vacant=0;
    QSqlQuery query;


    int cod = ui->idEdit_2->text().toInt();
    QString codd = ui->nomEdit_2->text();
    QString res = QString::number(cod);
    QString ress = codd;
    id_departement = ui->idEdit_2->text().toInt();
   nom_departement = ui->nomEdit_2->text();
   postes_vacant = ui->placesEdit_2->text().toInt();


    Departement d(id_departement, nom_departement, postes_vacant);

    if(d.modifier_departement(cod))

    {
        ui->tabdepartement->setModel(tmpdepartement.afficher());//refresh
         ui->tabdepartement->setModel(tmpdepartement.afficher());
         QMessageBox::information(nullptr, QObject::tr("Modifier un département"),
                                    QObject::tr("Departement modifié.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}


void GestionD_emp::on_mail_2_released()
{
    Smtp *s=new Smtp("smart.kindergarten0@gmail.com","Guingangoun01","smtp.gmail.com",465);
    s->sendMail("smart.kindergarten0@gmail.com",ui->lineEdit_distinataire_2->text(),ui->lineEdit_sujetmail_2->text(),ui->lineEdit_2_text_mail_2->text());

}


void GestionD_emp::on_afficher_stat2_clicked()
{
    double dag=0;
    double dir=0;


    QSqlQuery q;
        q.prepare("SELECT postes_vacant FROM departements WHERE nom_departement like 'Cuisine' ");
        q.exec();
          while (q.next())
        {
        dag++;
        }

          q.prepare("SELECT postes_vacant FROM departement WHERE nom_departement like 'Etudes' ");
          q.exec();
            while (q.next())
          {
          dir++;
          }

    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->gplot->setBackground(QBrush(gradient));

    // create empty bar chart objects:

    QCPBars *fossil = new QCPBars(ui->gplot->xAxis, ui->gplot->yAxis);
    fossil->setAntialiased(false);


    fossil->setStackingGap(1);
    // set names and colors:
    /*fossil->setName("nembre des offres");
    fossil->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    fossil->setBrush(QColor(111, 9, 176));*/


    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 ;
    labels << "Cuisine" << "Etudes" ;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->gplot->xAxis->setTicker(textTicker);
    ui->gplot->xAxis->setTickLabelRotation(60);
    ui->gplot->xAxis->setSubTicks(false);
    ui->gplot->xAxis->setTickLength(0, 4);
    ui->gplot->xAxis->setRange(0, 13);
    ui->gplot->xAxis->setBasePen(QPen(Qt::white));
    ui->gplot->xAxis->setTickPen(QPen(Qt::white));
    ui->gplot->xAxis->grid()->setVisible(true);
    ui->gplot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->gplot->xAxis->setTickLabelColor(Qt::white);
    ui->gplot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->gplot->yAxis->setRange(0, 10);
    ui->gplot->yAxis->setPadding(5); // a bit more space to the left border
    ui->gplot->yAxis->setLabel("Nombre de places disponibles");
    ui->gplot->yAxis->setBasePen(QPen(Qt::white));
    ui->gplot->yAxis->setTickPen(QPen(Qt::white));
    ui->gplot->yAxis->setSubTickPen(QPen(Qt::white));
    ui->gplot->yAxis->grid()->setSubGridVisible(true);
    ui->gplot->yAxis->setTickLabelColor(Qt::white);
    ui->gplot->yAxis->setLabelColor(Qt::white);
    ui->gplot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->gplot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> fossilData;

    fossilData  << dag << dir ;
    fossil->setData(ticks, fossilData);

    ui->gplot->legend->setVisible(true);
    ui->gplot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->gplot->legend->setBrush(QColor(255, 255, 255, 100));
    ui->gplot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->gplot->legend->setFont(legendFont);
    ui->gplot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

}
/*void GestionD_emp::on_afficher_stat2_clicked()

{       statestique p;

    ui->labeluno->setText("fonction:playground") ;
      ui->labeldos->setText("fonction: salle de jeux") ;



}*/

