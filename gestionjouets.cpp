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
#include <QDialog>
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
#include <QPixmap>
#include <QImage>
#include <QDialog>
gestionjouets::gestionjouets(QWidget *parent) : QDialog(parent)
    , ui(new Ui::gestionjouets)

{
    ui->setupUi(this);
    //QMainWindow(parent)
   QPixmap pic("/go.png");
   ui->label_7->setPixmap(pic);

    //ui->label_2->setScaledContents(true);
  //  ui->label_2->setText( "Size: " + QString::number(pic.width()) +" "+ QString::number(pic.width()) );


  // pic= pic.scaledToWidth(ui->label_2->width(), Qt::SmoothTransformation);
 //   ui->label_2->setPixmap(pic);


    ui->tableViewespace->setModel(tmpespace.afficher_espace());//refresh


ui->boxajout->setModel(tmpespace.afficher_espace());
ui->boxmodif->setModel(tmpespace.afficher_espace());
ui->tableViewjouets->setModel(tmpjouets.afficher_jouets());//refresh


}


gestionjouets::~gestionjouets()
{
    delete ui;
}


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

void gestionjouets::on_pb_confirmerEspace_released()
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

void gestionjouets::on_pb__viderM_released()
{

    ui->nomEdit->setText("");
    ui->etatEdit->setText("");
}

void gestionjouets::on_pb_trierEspace_released()
{
    espace  *sa ;
    ui->tableViewespace->setModel(sa->trie());
     ui->tableViewjouets->setModel(tmpjouets.afficher_jouets());//refresh

}



void gestionjouets::on_ajoutm_released()
{ int id_jouets=0;
    int qt_jouets = ui->etatAdd->text().toInt();
    QString nom_jouets= ui->nomAdd->text();
     //int id_jouets = ui->idmAdd->text().toInt();
     QString cat_jouets= ui->boxajout->currentText();
jouets m(id_jouets ,nom_jouets,qt_jouets,cat_jouets);
ui->tableViewespace->setModel(tmpespace.afficher_espace());//refresh

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


void gestionjouets::on_mail_released()
{ QSqlQuery q;

    QString cat_jouets;
    QString nom_jouets;
    int id_jouets=0,qt_jouets=0,totaljouets=0;
    jouets m(id_jouets ,nom_jouets,qt_jouets,cat_jouets);
//int x=m.alert();
    QString a = QString::number(qt_jouets);
     QString b = QString::number(totaljouets);
   q .prepare("SELECT * FROM jouets where qt_jouets=0");
         q.bindValue(":qt_jouets", a);
  if (q.exec()) {
      while (q.next())
          totaljouets++;
  }
  QString res = QString::number(totaljouets);

  ui->lineEdit_sujetmail->setText(res);
  QMessageBox::information(this, tr("Modifier Materiel"), tr("envoi"));

  if (totaljouets<6)
   {
      QMessageBox::information(this, tr("Modifier Materiel"), tr("verif"));
 Smtp *s=new Smtp("fournisseurX@gmail.com","fournisseur123","smtp.gmail.com",465);
    s->sendMail("fournisseurX@gmail.com",ui->email->text(),"Commande de jouets","commande de "+res+" jouets");
QMessageBox::information(this, tr("Modifier Materiel"), tr("envoi3"));

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



void gestionjouets::on_pb_ajouterEspace_released()
{
    int capacite = ui->capaciteAdd->text().toInt();
    QString fonction_espace= ui->fonctionAdd->text();

     int id_espace=0 ;




//espace s( id_espace,fonction_espace,capacite);
espace s(id_espace ,fonction_espace,capacite);
  bool test=s.ajouter_espace();
  ui->tableViewjouets->setModel(tmpjouets.afficher_jouets());//refresh

  if(test)
{

      ui->tableViewespace->setModel(tmpespace.afficher_espace());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une espace"),
                  QObject::tr("espace ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

  }
}



void gestionjouets::on_pdf_clicked()
{
    QPdfWriter pdf("C:/Users/Lenovo/Documents/guinga/fatma+nour+yessine+louay/telecome/pdf/nourMehlaha.pdf");/*il faut toujour changer le nom (*/
    QPainter painter;
    if (! painter.begin(&pdf))
    {

                        qWarning("failed to open file, is it writable?");

    }
    QString titre =ui->lineEdit_rese_pdf->text();
    const time_t ctt = time(0);
    QSqlQuery query;
     qWarning("testpdf1");
    query.exec("SELECT id_jouets, qt_jouets, cat_jouets FROM JOUETS WHERE nom_jouets='"+titre+"'");
      qWarning("testpdf2");

            while (query.next())
                  {

                QString id_jouets = query.value(0).toString();
                QString nom_jouets = query.value(1).toString();
                QString cat_jouets = query.value(2).toString();
                QString qt_jouets = query.value(3).toString();

        painter.drawText(2200,3500,id_jouets);
        painter.drawText(2200,4000,nom_jouets);
        painter.drawText(2200,4500,cat_jouets);
        painter.drawText(2200,5000,qt_jouets);


        painter.setPen(Qt::red);
        painter.drawText(4500,2000,"JOUETS");
        painter.setPen(Qt::black);
        painter.drawText(500,2000,asctime(localtime(&ctt)));
        painter.drawText(500,3500,"ID jouets:");
        painter.drawText(500,4000,"Nom jouets:");
        painter.drawText(500,4500,"Categorie des jouets:");
        painter.drawText(500,5000,"Quantite des jouets:");



            }
}


void gestionjouets::on_pb_trierJouets_clicked()
{
    jouets  *jo ;

    ui->tableViewjouets->setModel(jo->trier());
     ui->tableViewespace->setModel(tmpespace.afficher_espace());//refresh
}



void gestionjouets::on_afficher_stat2_2_clicked()
{
    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(51, 0, 25));
    ui->widget->setBackground(QBrush(gradient));

    // create empty bar chart objects:
    QCPBars *regen = new QCPBars(ui->widget->xAxis, ui->widget->yAxis);

    regen->setAntialiased(false); // gives more crisp, pixel aligned bar borders


    // set names and colors:

    regen->setName("Capacite/Espace");
    regen->setPen(QPen(QColor(255, 168, 0).lighter(130)));
    regen->setBrush(QColor(255, 168, 0));



    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    QVector<double> regenData;


    ticks << 1 << 2  ;
    QSqlQuery q;

    q.prepare("SELECT capacite , count(capacite) nbr FROM espace GROUP BY capacite ");  ;
    if(q.exec()){
    while (q.next()) {
    labels << q.value(0).toString();
    regenData   << q.value(1).toDouble();
    }}
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->widget->xAxis->setTicker(textTicker);

    ui->widget->xAxis->setTickLabelRotation(60);

    ui->widget->xAxis->setTickLength(0, 4);
    ui->widget->xAxis->setRange(0, 5);
    ui->widget->xAxis->setLabel("Fonction");

    ui->widget->xAxis->setBasePen(QPen(Qt::white));
    ui->widget->xAxis->setTickPen(QPen(Qt::white));
    ui->widget->xAxis->grid()->setVisible(true);
    ui->widget->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->widget->xAxis->setTickLabelColor(Qt::white);
    ui->widget->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->widget->yAxis->setRange(0, 8);
    ui->widget->yAxis->setPadding(5); // a bit more space to the left border
    ui->widget->yAxis->setLabel("Capacite");
    ui->widget->yAxis->setBasePen(QPen(Qt::white));
    ui->widget->yAxis->setTickPen(QPen(Qt::white));
    ui->widget->yAxis->setSubTickPen(QPen(Qt::white));
    ui->widget->yAxis->grid()->setSubGridVisible(true);
    ui->widget->yAxis->setTickLabelColor(Qt::white);
    ui->widget->yAxis->setLabelColor(Qt::white);
    ui->widget->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->widget->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:


    regen->setData(ticks, regenData);

    // setup legend:
    ui->widget->legend->setVisible(true);
    ui->widget->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->widget->legend->setBrush(QColor(255, 255, 255, 100));
    ui->widget->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->widget->legend->setFont(legendFont);
    ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);






}

void gestionjouets::on_pushButton_clicked()
{
    QString filename= QFileDialog::getOpenFileName(this, tr("choose"),"",tr("*.png *.jpeg *.bmp"));
    if (QString::compare(filename,QString())!=0)
    { QImage image;
        bool valid= image.load(filename);
        if (valid)
        { image= image.scaledToWidth(ui->label->width(), Qt::SmoothTransformation);
            ui->label->setPixmap(QPixmap::fromImage(image));

    }
    }}

