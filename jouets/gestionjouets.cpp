#include "gestionjouets.h"
#include "ui_gestionjouets.h"
#include "espace.h"
#include "jouets.h"
#include "smtp.h"
#include "connexion.h"
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

gestionjouets::gestionjouets(QWidget *parent) : QMainWindow(parent)
    , ui(new Ui::gestionjouets)

{
    ui->setupUi(this);
    //QMainWindow(parent)
ui->boxajout->setModel(tmpespace.display());
ui->boxmodif->setModel(tmpespace.display());

}


gestionjouets::~gestionjouets()
{
    delete ui;
}


/*void gestionjouets::on_pb_ajouterS_released()
{
    int capacite = ui->capaciteAdd->text().toInt();
    QString fonction_espace= ui->fonction_espaceAdd->text();

     int id_espace = ui->idAdd->text().toInt();



//espace s( id_espace,fonction_espace,capacite);
espace s(id_espace ,fonction_espace,capacite);
  bool test=s.ajouter_espace();
  if(test)
{

      ui->tableViewespace->setModel(tmpespace.afficher_espace());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une espace"),
                  QObject::tr("espace ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une espace"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}*/

bool gestionjouets::on_pb_chercherS_released()
{

    QSqlQuery query;
    int cod = ui->idEdit->text().toInt();

    QString res = QString::number(cod);
    query.prepare("SELECT * FROM espace WHERE id_espace = :cod");
    query.bindValue(":cod", res);
    query.exec();
    if(query.first())
    {
        QMessageBox::information(this, tr("Modifier espace"), tr("La espace est trouvé avec success, Veuillez entrer les nouvelles informations."));
         ui->idEdit->setText(query.value(0).toString());
        ui->fonctionEdit->setText(query.value(1).toString());
        ui->capaciteEdit->setText(query.value(2).toString());

        return true;
}


}

void gestionjouets::on_pb_confirmerS_released()
{
    QString fonction_espace ;
    int id_espace=0,capacite=0;
    QSqlQuery query;


    int cod = ui->idEdit->text().toInt();
    int codd = ui->capaciteEdit->text().toInt();
    QString res = QString::number(cod);
    QString ress = QString::number(codd);
    id_espace = ui->idEdit->text().toInt();
    fonction_espace = ui->fonctionEdit->text();
   // categorie = ui->categorieEdit->text();

    capacite=ui->capaciteEdit->text().toInt();
QMessageBox::information(this, tr("Modifier espace"), tr("OK!"));

    espace s(id_espace, fonction_espace, capacite);
    if(s.modifier_espace(cod))
    {
         ui->tableViewespace->setModel(tmpespace.afficher_espace());
        QMessageBox::information(this, tr("Modifier espace"), tr("L'espace a été modifié avec success."));
    }
}

void gestionjouets::on_pb_supprimerS_released()
{
    int id_espace = ui->idDelete->text().toInt();
    bool test=tmpespace.supprimer_espace(id_espace);
    if(test)
    {
        ui->tableViewespace->setModel(tmpespace.afficher_espace());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un espace"),
                    QObject::tr("espace supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une salle"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);




}

void gestionjouets::on_pb__viderS_released()
{
    ui->fonctionEdit->setText("");
    ui->capaciteEdit->setText("");

}



void gestionjouets::on_pb_supprimerM_released()
{


    int id_jouets = ui->idmDelete->text().toInt();
    bool test=tmpjouets.supprimer_jouets(id_jouets);
    if(test)
    {
        ui->tableViewjouets->setModel(tmpjouets.afficher_jouets());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un jouet"),
                    QObject::tr("jouets supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un jouet"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

bool gestionjouets::on_pb_chercherM_released()
{
    QSqlQuery query;
    int cod = ui->idmEdit->text().toInt();
    QString res = QString::number(cod);
    query.prepare("SELECT * FROM jouets WHERE id_jouets = :cod");
    query.bindValue(":cod", res);
    query.exec();
    if(query.first())
    {
        QMessageBox::information(this, tr("Modifier jouet"), tr("Le jouet est trouvé avec success, Veuillez entrer les nouvelles informations."));
         ui->idmEdit->setText(query.value(0).toString());
        ui->nomEdit->setText(query.value(1).toString());
        ui->etatEdit->setText(query.value(2).toString());

        return true;

}
}

/*void gestionjouets::on_pb_confirmerM_released()
{

    QString nom_jouets;
    int id_jouets=0,qt_jouets=0;
    QSqlQuery query;


    int cod = ui->idmEdit->text().toInt();
    int codd = ui->etatEdit->text().toInt();
    QString res = QString::number(cod);
    QString ress = QString::number(codd);
    id_jouets = ui->idmEdit->text().toInt();
   nom_jouets = ui->nomEdit->text();
   qt_jouets=ui->etatEdit->text().toInt();
QMessageBox::information(this, tr("Modifier jouets"), tr("test1"));

    espace s(id_jouets, nom_jouets, qt_jouets);
    QMessageBox::information(this, tr("Modifier jouets"), tr("test2"));
    if(s.modifier_espace(cod))
    {
         ui->tableViewespace->setModel(tmpespace.afficher_espace());
        QMessageBox::information(this, tr("Modifier jouets"), tr("La espace été modifié avec success."));
    }
}
*/


void gestionjouets::on_pb__viderM_released()
{

    ui->nomEdit->setText("");
    ui->etatEdit->setText("");
}

void gestionjouets::on_pb_trierS_released()
{
    espace  *sa ;
    ui->tableViewespace->setModel(sa->trie());
     ui->tableViewjouets->setModel(tmpjouets.afficher_jouets());//refresh

}



/*void gestionjouets::on_testAjout_released()
{
    int qt_jouets = ui->qt_jouetsAdd->text().toInt();
    QString nom_jouets= ui->nom_jouetsAdd->text();

     int id_jouets = ui->idmAdd->text().toInt();

jouets m(id_jouets ,nom_jouets,qt_jouets);
QMessageBox::information(nullptr, QObject::tr("Ajouter un jouets"),
                  QObject::tr("kbal ajout.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
  bool test=m.ajouter_jouets();
  if(test)
{

  ui->tableViewjouets->setModel(tmpjouets.afficher_jouets());//refresh
      ui->tableViewjouets->setModel(tmpjouets.afficher_jouets());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un jouets"),
                  QObject::tr("jouets ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un jouets"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);







}
*/
//confirmation modift jouets
/*void gestionjouets::on_pushButton_released()
{
    QString nom_jouets;
    int id_jouets=0,qt_jouets=0;
    QSqlQuery query;


    int cod = ui->idmEdit->text().toInt();
    int codd = ui->etatEdit->text().toInt();
    QString res = QString::number(cod);
    QString ress = QString::number(codd);
    id_jouets = ui->idmEdit->text().toInt();
   nom_jouets = ui->nomEdit->text();
   qt_jouets=ui->etatEdit->text().toInt();


    jouets m(id_jouets, nom_jouets, qt_jouets);

    if(m.modifier_jouets(cod))

    {
        ui->tableViewjouets->setModel(tmpjouets.afficher_jouets());//refresh
         ui->tableViewjouets->setModel(tmpjouets.afficher_jouets());
        QMessageBox::information(this, tr("Modifier jouets"), tr("La espace été modifié avec success."));
    }
}*/

/*void gestionjouets::on_ajoutM_released()
{

    int qt_jouets = ui->qt_jouetsAdd->text().toInt();
    QString nom_jouets= ui->nom_jouetsAdd->text();

     int id_jouets = ui->idmAdd->text().toInt();

jouets m(id_jouets ,nom_jouets,qt_jouets);

  bool test=m.ajouter_jouets();
  QMessageBox::information(nullptr, QObject::tr("Ajouter un jouets"),
                    QObject::tr("kbal ajout.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
  if(test)
{


QMessageBox::information(nullptr, QObject::tr("Ajouter un jouets"),
                  QObject::tr("jouets ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un jouets"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}*/

/*void gestionjouets::on_ajoutM_clicked()
{

    int qt_jouets = ui->qt_jouetsAdd->text().toInt();
    QString nom_jouets= ui->nom_jouetsAdd->text();

     int id_jouets = ui->idmAdd->text().toInt();

jouets m(id_jouets ,nom_jouets,qt_jouets);

  bool test=m.ajouter_jouets();
  QMessageBox::information(nullptr, QObject::tr("Ajouter un jouets"),
                    QObject::tr("kbal ajout.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
  if(test)
{


QMessageBox::information(nullptr, QObject::tr("Ajouter un jouets"),
                  QObject::tr("jouets ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un jouets"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
*/

/*void gestionjouets::on_ajoutm_released()
{
    int qt_jouets = ui->etatAdd->text().toInt();
    QString nom_jouets= ui->nomAdd->text();

     int id_jouets = ui->idmAdd->text().toInt();

jouets m(id_jouets ,nom_jouets,qt_jouets);

  bool test=m.ajouter_jouets();
  QMessageBox::information(nullptr, QObject::tr("Ajouter un jouets"),
                    QObject::tr("kbal ajout.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
  if(test)
{


QMessageBox::information(nullptr, QObject::tr("Ajouter un jouets"),
                  QObject::tr("jouets ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un jouets"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}
*/
/*void gestionjouets::on_pushButton_2_released()
{
    int qt_jouets = ui->etatAdd->text().toInt();
        QString nom_jouets= ui->nomAdd->text();

         int id_jouets = ui->idmAdd->text().toInt();

    jouets m(id_jouets ,nom_jouets,qt_jouets);

      bool test=m.ajouter_jouets();
      QMessageBox::information(nullptr, QObject::tr("Ajouter un jouets"),
                        QObject::tr("kbal ajout.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
      if(test)
    {


    QMessageBox::information(nullptr, QObject::tr("Ajouter un jouets"),
                      QObject::tr("jouets ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un jouets"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);


}*/

void gestionjouets::on_ajoutm_released()
{
    int qt_jouets = ui->etatAdd->text().toInt();
    QString nom_jouets= ui->nomAdd->text();
     int id_jouets = ui->idmAdd->text().toInt();
     QString cat_jouets= ui->boxajout->currentText();
jouets m(id_jouets ,nom_jouets,qt_jouets,cat_jouets);

       bool test=m.ajouter_jouets();

  if(test)
{


QMessageBox::information(nullptr, QObject::tr("Ajouter un jouets"),
                  QObject::tr("jouet ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un jouets"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}


/*void gestionjouets::on_pushButton_released()
{
    int qt_jouets = ui->etatAdd->text().toInt();
        QString nom_jouets= ui->nomAdd->text();

         int id_jouets = ui->idmAdd->text().toInt();

    jouets m(id_jouets ,nom_jouets,qt_jouets);

      bool test=m.ajouter_jouets();
      QMessageBox::information(nullptr, QObject::tr("Ajouter un jouets"),
                        QObject::tr("kbal ajout.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
      if(test)
    {


    QMessageBox::information(nullptr, QObject::tr("Ajouter un jouets"),
                      QObject::tr("jouets ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un jouets"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);


}*/

void gestionjouets::on_confirmerM_released()
{
    QString nom_jouets,cat_jouets;
    int id_jouets=0,qt_jouets=0;
    QSqlQuery query;


    int cod = ui->idmEdit->text().toInt();
    int codd = ui->etatEdit->text().toInt();
    QString res = QString::number(cod);
    QString ress = QString::number(codd);
    id_jouets = ui->idmEdit->text().toInt();
    nom_jouets = ui->nomEdit->text();
    cat_jouets= ui->boxmodif->currentText();
   qt_jouets=ui->etatEdit->text().toInt();
QMessageBox::information(this, tr("Modifier jouets"), tr("OK!"));

    jouets m(id_jouets, nom_jouets, qt_jouets,cat_jouets );
    if(m.modifier_jouets(cod))
    {
         ui->tableViewespace->setModel(tmpespace.afficher_espace());
        QMessageBox::information(this, tr("Modifier jouets"), tr("Le jouet a été modifié avec success."));
    }

}
/*void gestionjouets::on_pb_ajouterS_released()
{
    int capacite = ui->capaciteAdd->text().toInt();
    QString fonction_espace= ui->fonctionAdd->text();

     int id_espace = ui->idAdd->text().toInt();
 //    QString categorie= ui->categorieAdd->text();




//espace s( id_espace,fonction_espace,capacite);
espace s(id_espace ,fonction_espace,capacite);
  bool test=s.ajouter_espace();
  if(test)
{

      ui->tableViewespace->setModel(tmpespace.afficher_espace());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une espace"),
                  QObject::tr("espace ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

  } }*/
/*
void gestionjouets::on_pb_ajouterS_released()
{      //QString categorie= ui->capaciteAdd_2->text();

    int capacite = ui->capaciteAdd->text().toInt();
    QString fonction_espace= ui->fonctionAdd->text();

     int id_espace = ui->idAdd->text().toInt();




//espace s( id_espace,fonction_espace,capacite);
espace s(id_espace ,fonction_espace,capacite);
  bool test=s.ajouter_espace();
  if(test)
{

      ui->tableViewespace->setModel(tmpespace.afficher_espace());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une espace"),
                  QObject::tr("espace ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

  }*/


void gestionjouets::on_mail_released()
{
    Smtp *s=new Smtp("fournisseurX@gmail.com","fournisseur123","smtp.gmail.com",465);
    s->sendMail("fornisseurX@gmail.com",ui->lineEdit_distinataire->text(),ui->lineEdit_sujetmail->text(),ui->lineEdit_2_text_mail->text());


}


/* void gestionjouets::on_pdf_released()
{
    QPdfWriter pdf("/Users/LENOVO/Desktop/jouets/pdf/joues.pdf");/*il faut toujour changer le nom
   QPainter painter;
    if (! painter.begin(&pdf))
    {
        // failed to open file
                        qWarning("failed to open file, is it writable?");

    }
    QString titre =ui->lineEdit_rese_pdf->text();
    const time_t ctt = time(0);
    QSqlQuery query;
    query.exec("SELECT id_jouets,nom_jouets,quantite,cat_jouets FROM JOUETS WHERE nom_jouets='"+titre+"'");

            while (query.next())
                  {

                QString id_jouets = query.value(0).toString();
                QString nom_jouets = query.value(1).toString();
                QString quantite = query.value(2).toString();
                QString cat_jouets= query.value(3).toString();


        painter.drawText(2200,3500,id_jouets);
        painter.drawText(2200,4000,nom_jouets);
        painter.drawText(2200,4500,quantite);
        painter.drawText(2200,5000,cat_jouets);


        painter.setPen(Qt::blue);
        painter.drawText(4500,2000,"JOUETS");
        painter.setPen(Qt::black);
        painter.drawText(500,2000,asctime(localtime(&ctt)));
        painter.drawText(500,3500,"Id de jouet:");
        painter.drawText(500,4000,"Nom de jouet:");
        painter.drawText(500,4500,"quantite de jouet:");
        painter.drawText(500,5000,"categorie de jouet:");
}
}
*/
void gestionjouets::on_pdf_clicked()
{
    QPdfWriter pdf("/Users/LENOVO/Desktop/jouets/pdf/joues.pdf");/*il faut toujour changer le nom*/
    QPainter painter;
    if (! painter.begin(&pdf))
    {
        // failed to open file
                        qWarning("failed to open file, is it writable?");

    }
    QString titre =ui->lineEdit_rese_pdf->text();
    const time_t ctt = time(0);
    QSqlQuery query;
    query.exec("SELECT id_jouets,nom_jouets,qt_jouets,cat_jouets FROM JOUETS WHERE nom_jouets='"+titre+"'");

            while (query.next())
                  {

                QString id_jouets = query.value(0).toString();
                QString nom_jouets = query.value(1).toString();
                QString qt_jouets = query.value(2).toString();
                QString cat_jouets= query.value(3).toString();


        painter.drawText(2200,3500,id_jouets);
        painter.drawText(2200,4000,nom_jouets);
        painter.drawText(2200,4500,qt_jouets);
        painter.drawText(2200,5000,cat_jouets);


        painter.setPen(Qt::blue);
        painter.drawText(4500,2000,"JOUETS");
        painter.setPen(Qt::black);
        painter.drawText(500,2000,asctime(localtime(&ctt)));
        painter.drawText(500,3500,"Id de jouet:");
        painter.drawText(500,4000,"Nom de jouet:");
        painter.drawText(500,4500,"quantite de jouet:");
        painter.drawText(500,5000,"categorie de jouet:");
}

}



void gestionjouets::on_afficher_stat_clicked()
{
    double dag=0;
    double dir=0;


    QSqlQuery q;
        q.prepare("SELECT * FROM JOUETS WHERE nom_jouets like 'poupee' ");
        q.exec();
          while (q.next())
        {
        dag++;
        }

          q.prepare("SELECT * FROM JOUETS WHERE nom_jouets like 'voiture' ");
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
    labels << "poupee" << "voiture" ;
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
    ui->gplot->yAxis->setLabel("quantite des jouets");
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

void gestionjouets::on_imprimer_clicked()
{
    QString titre =ui->lineEdit_rese_pdf->text();
    QSqlQuery q;

            q.exec("SELECT id_jouets,nom_jouets,qt_jouets,cat_jouets FROM JOUETS WHERE nom_jouets='"+titre+"'");

            while (q.next())
                      {

                        QString id_jouets = q.value(0).toString() ;
                        QString  nom_jouets= q.value(1).toString();
                        QString qt_jouets = q.value(2).toString();
                        QString cat_jouets= q.value(3).toString();}

                //imprimer
                QPrinter printer;
                printer.setPrinterName("desiered printer name");
              QPrintDialog dialog(&printer,this);
                if(dialog.exec()== QDialog::Rejected)
                    return;

}



void gestionjouets::on_pb_ajouterS_released()
{
    int capacite = ui->capaciteAdd->text().toInt();
    QString fonction_espace= ui->fonctionAdd->text();

     int id_espace = ui->idAdd->text().toInt();




//espace s( id_espace,fonction_espace,capacite);
espace s(id_espace ,fonction_espace,capacite);
  bool test=s.ajouter_espace();
  if(test)
{

      ui->tableViewespace->setModel(tmpespace.afficher_espace());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une espace"),
                  QObject::tr("espace ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

  }
}
