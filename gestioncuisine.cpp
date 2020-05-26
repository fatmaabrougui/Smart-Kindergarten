#include "gestioncuisine.h"
#include "ui_gestioncuisine.h"
#include "aliments.h"
#include "menu.h"
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
gestioncuisine::gestioncuisine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestioncuisine)
{
ui->setupUi(this);
ui->tabaliment_2->setModel(tmpaliment.afficher());
ui->tabmenu_2->setModel(tmpmenu.afficher());
ui->boxajout->setModel(tmpmenu.afficher());
ui->boxsupprimera->setModel(tmpaliment.afficher());
ui->boxsupprimerb->setModel(tmpmenu.afficher());

}

gestioncuisine::~gestioncuisine()
{
    delete ui;
}

void gestioncuisine::on_pb_ajouter_clicked()
{
    int ID_ALIMENT = ui->lineEdit_id->text().toInt();
    QString NOM_ALIMENT= ui->lineEdit_nom->text();
    QString TYPE_ALIMENT= ui->lineEdit_type->text();
    int DISPO= ui->lineEdit_dispo->text().toInt();
    int ID_MENU= ui->boxajout->currentText().toInt();
  Aliments e(ID_ALIMENT,NOM_ALIMENT,TYPE_ALIMENT,DISPO,ID_MENU);
  bool test=e.ajouter();
  if(test)
{

      ui->tabaliment_2->setModel(tmpaliment.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un aliment"),
                  QObject::tr("Aliment ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un aliment"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void gestioncuisine::on_pb_supprimer_clicked()
{
int ID_ALIMENT = ui->boxsupprimera->currentText().toInt();
bool test=tmpaliment.supprimer(ID_ALIMENT);
if(test)
{ui->tabaliment_2->setModel(tmpaliment.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un aliment"),
                QObject::tr("Aliment supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un aliment"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void gestioncuisine::on_pb_ajouter_2_clicked()
{
    int ID_MENU = ui->lineEdit_menu->text().toInt();
    QString NOM_MENU= ui->lineEdit_nom_2->text();
    QString TEMPS= ui->lineEdit_temps->text();
  Menu d(ID_MENU,NOM_MENU,TEMPS);
  bool test=d.ajouter();
  if(test)
{

      ui->tabmenu_2->setModel(tmpmenu.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un menu"),
                  QObject::tr("Menu ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un menu"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void gestioncuisine::on_pb_supprimer_2_clicked()
{
int ID_MENU = ui->boxsupprimerb->currentText().toInt();
bool test=tmpmenu.supprimer(ID_MENU);
if(test)
{ui->tabmenu_2->setModel(tmpmenu.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un menu"),
                QObject::tr("Menu supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un menu"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
bool gestioncuisine::on_pb_chercherS_released()
{

    QSqlQuery query;
    int cod = ui->lineidm->text().toInt();

    QString res = QString::number(cod);
    query.prepare("SELECT * FROM ALIMENTS WHERE ID_ALIMENT = :cod");
    query.bindValue(":cod", res);
    query.exec();
    if(query.first())
    {
        QMessageBox::information(this, tr("Modifier aliment"), tr("L'aliment est trouvé avec success, Veuillez entrer les nouvelles informations."));
         ui->lineidm->setText(query.value(0).toString());
        ui->lineEdit_id_9->setText(query.value(1).toString());
        ui->lineEdit_id_10->setText(query.value(2).toString());
        ui->lineEdit_id_11->setText(query.value(3).toString());
        ui->lineEdit_id_12->setText(query.value(4).toString());

        return true;
}
}

void gestioncuisine::on_pb_confirmerS_released()
{
    QString NOM_ALIMENT,TYPE_ALIMENT;
    int ID_ALIMENT=0,DISPO=0,ID_MENU=0;
    QSqlQuery query;


    int cod = ui->lineidm->text().toInt();
    int codd = ui->lineEdit_id_11->text().toInt();
    int coddd = ui->lineEdit_id_12->text().toInt();
    QString res = QString::number(cod);
    QString ress = QString::number(codd);
    QString resss = QString::number(coddd);
    ID_ALIMENT = ui->lineidm->text().toInt();
    NOM_ALIMENT= ui->lineEdit_id_9->text();
    TYPE_ALIMENT= ui->lineEdit_id_10->text();
    DISPO=ui->lineEdit_id_11->text().toInt();
    ID_MENU=ui->lineEdit_id_12->text().toInt();
QMessageBox::information(this, tr("Modifier aliment"), tr("ok"));

    Aliments s(ID_ALIMENT, NOM_ALIMENT,TYPE_ALIMENT,DISPO, ID_MENU);
    QMessageBox::information(this, tr("Modifier aliment"), tr("Loading"));
    if(s.modifier_aliments(cod))
    {
         ui->tabaliment_2->setModel(tmpaliment.afficher());
        QMessageBox::information(this, tr("Modifier salle"), tr("La salle été modifié avec success."));
    }
}

void gestioncuisine::on_pb_trierS_released()
{
    Aliments  *al ;
    ui->tabaliment_2->setModel(tmpaliment.trie());
     ui->tabaliment_2->setModel(tmpaliment.afficher());//refresh

}

void gestioncuisine::on_pb_trierM_released()
{
    Menu  *m ;
    ui->tabmenu_2->setModel(tmpmenu.trie());
     ui->tabmenu_2->setModel(tmpmenu.afficher());//refresh

}

bool gestioncuisine::on_pb_chercherM_released()
{

    QSqlQuery query;
    int cod = ui->lineEdit_id_6->text().toInt();

    QString res = QString::number(cod);
    query.prepare("SELECT * FROM MENU WHERE ID_MENU = :cod");
    query.bindValue(":cod", res);
    query.exec();
    if(query.first())
    {
        QMessageBox::information(this, tr("Modifier menu"), tr("Le menu est trouvé avec success, Veuillez entrer les nouvelles informations."));
         ui->lineEdit_id_6->setText(query.value(0).toString());
        ui->lineEdit_id_7->setText(query.value(1).toString());
        ui->lineEdit_id_8->setText(query.value(2).toString());

        return true;
}
    return false;
}

void gestioncuisine::on_pb_confirmerM_released()
{
    QString NOM_MENU, TEMPS;
    int ID_MENU=0;
    QSqlQuery query;


    int cod = ui->lineEdit_id_6->text().toInt();
    QString res = QString::number(cod);
    ID_MENU = ui->lineEdit_id_6->text().toInt();
    NOM_MENU= ui->lineEdit_id_7->text();
    TEMPS= ui->lineEdit_id_8->text();
QMessageBox::information(this, tr("Modifier menu"), tr("ok"));

    Menu s(ID_MENU, NOM_MENU,TEMPS);
    QMessageBox::information(this, tr("Modifier menu"), tr("Loading"));
    if(s.modifier_menu(cod))
    {
         ui->tabmenu_2->setModel(tmpmenu.afficher());
        QMessageBox::information(this, tr("Modifier menu"), tr("Le menu a été modifié avec success."));
    }
}

void gestioncuisine::on_pdf_clicked()
{
    QPdfWriter pdf("C:/Users/Moetez/Desktop/Atelier_Crud_Vf/test.pdf");/*il faut toujour changer le nom (*/
    QPainter painter;
    if (! painter.begin(&pdf))
    {

                        qWarning("failed to open file, is it writable?");

    }
    QString titre =ui->lineEdit_id_3->text();
    const time_t ctt = time(0);
    QSqlQuery query;
     qWarning("testpdf1");
    query.exec("SELECT ID_MENU,NOM_MENU, TEMPS FROM MENU WHERE NOM_MENU='"+titre+"'");
      qWarning("testpdf2");

            while (query.next())
                  {

                QString ID_MENU = query.value(0).toString();
                QString NOM_MENU = query.value(1).toString();
                QString TEMPS = query.value(2).toString();

        painter.drawText(2200,3500,ID_MENU);
        painter.drawText(2200,4000,NOM_MENU);
        painter.drawText(2200,4500,TEMPS);


        painter.setPen(Qt::red);
        painter.drawText(4500,2000,"MENU");
        painter.setPen(Qt::black);
        painter.drawText(500,2000,asctime(localtime(&ctt)));
        painter.drawText(500,3500,"ID du menu:");
        painter.drawText(500,4000,"Nom du menu:");
        painter.drawText(500,4500,"Temps de service:");

            }
}

void gestioncuisine::on_afficher_stat_clicked()
{
    double dag=0;
    double dir=0;


    QSqlQuery q;
        q.prepare("SELECT NOM_MENU FROM MENU WHERE TEMPS like '12h' ");
        q.exec();
          while (q.next())
        {
        dag++;
        }

          q.prepare("SELECT NOM_MENU FROM MENU WHERE TEMPS like '10h' ");
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
    labels << "12h" << "10h" ;
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
    ui->gplot->yAxis->setLabel("Temps des menus");
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


