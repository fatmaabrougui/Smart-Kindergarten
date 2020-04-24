#include "gestionsalle.h"
#include "ui_gestionsalle.h"
#include "salle.h"
#include "smtp.h"
#include "materiel.h"
#include <QDebug>
#include "connexion.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QTabWidget>
#include<QtSql/QSqlQuery>
#include<QVariant>
#include <QtSql/QSqlQueryModel>
#include"qcustomplot.h"

gestionSalle::gestionSalle(QWidget *parent) : QMainWindow(parent)
    , ui(new Ui::gestionSalle)

{
    ui->setupUi(this);
    player_->SetPlaylist(playlist_);
    //affichage des l'xe
    ui->tableViewSalle->setModel(tmpsalle.afficher_salle());
     ui->tableViewMateriel->setModel(tmpmateriel.afficher_materiel());
    ui->comboBox->setModel(tmpsalle.afficher_salle());//refresh
     //ui->qplot->setBackground(QBrush(gradient));

    //QMainWindow(parent)
    gestionSalle :: on_makePlot_released();
    //********PALYLIST*********
    player_->SetVolume(ui->volumeSlider->value());

    connect(player_, SIGNAL(PositionChanged(qint64)), this, SLOT(PositionChangedByPlayer(qint64)));
    connect(player_, SIGNAL(CurrentSongChanged(int)), this, SLOT(CurrentSongChangedByPlayer(int)));
    connect(ui->timeSlider, SIGNAL(sliderMoved(int)), this, SLOT(PositionChangedByUser(int)));
    connect(ui->songList, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(CurrentSongChangedByUser()));
    connect(playlist_, SIGNAL(MediaChanged()), this, SLOT(UpdateSongList()));
  }



//}
 //*************************

gestionSalle::~gestionSalle()
{
    delete ui;
}


void gestionSalle::on_pb_ajouterS_released()
{
    int capacite = ui->capaciteAdd->text().toInt();
    QString fonction= ui->fonctionAdd->text();

     int id_salle = ui->idAdd->text().toInt();




salle s(id_salle ,fonction,capacite);
  bool test=s.ajouter_salle();
  if(test)
{

      ui->tableViewSalle->setModel(tmpsalle.afficher_salle());
      ui->comboBox->setModel(tmpsalle.afficher_salle());//refresh

QMessageBox::information(nullptr, QObject::tr("Ajouter une salle"),
                  QObject::tr("salle ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une salle"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

bool gestionSalle::on_pb_chercherS_released()
{

    QSqlQuery query;
    int cod = ui->idEdit->text().toInt();

    QString res = QString::number(cod);
    query.prepare("SELECT * FROM salle WHERE id_salle = :cod");
    query.bindValue(":cod", res);
    query.exec();
    if(query.first())
    {
        QMessageBox::information(this, tr("Modifier Salle"), tr("La salle est trouvé avec success, Veuillez entrer les nouvelles informations."));
         ui->idEdit->setText(query.value(0).toString());
        ui->fonctionEdit->setText(query.value(1).toString());
        ui->capaciteEdit->setText(query.value(2).toString());

        return true;
}


}

void gestionSalle::on_pb_confirmerS_released()
{
    QString fonction;
    int id_salle=0,capacite=0;
    QSqlQuery query;


    int cod = ui->idEdit->text().toInt();
    int codd = ui->capaciteEdit->text().toInt();
    QString res = QString::number(cod);
    QString ress = QString::number(codd);
    id_salle = ui->idEdit->text().toInt();
    fonction = ui->fonctionEdit->text();
    capacite=ui->capaciteEdit->text().toInt();


    salle s(id_salle, fonction, capacite );

    if(s.modifier_salle(cod))
    {
         ui->tableViewSalle->setModel(tmpsalle.afficher_salle());
        QMessageBox::information(this, tr("Modifier salle"), tr("La salle été modifié avec success."));
    }
}

void gestionSalle::on_pb_supprimerS_released()
{
    int id_salle = ui->idDelete->text().toInt();
    bool test=tmpsalle.supprimer_salle(id_salle);
    if(test)
    {
        ui->tableViewSalle->setModel(tmpsalle.afficher_salle());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une salle "),
                    QObject::tr("salle supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une salle"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);




}

void gestionSalle::on_pb__viderS_released()
{
    ui->fonctionEdit->setText("");
    ui->capaciteEdit->setText("");
     ui->nombreEdit->setText("");

}



void gestionSalle::on_pb_supprimerM_released()
{


    int id_materiel = ui->idmDelete->text().toInt();
    bool test=tmpmateriel.supprimer_materiel(id_materiel);
    if(test)
    {
        ui->tableViewMateriel->setModel(tmpmateriel.afficher_materiel());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un materiel"),
                    QObject::tr("Materiel supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un materiel"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

bool gestionSalle::on_pb_chercherM_released()
{
    QSqlQuery query;
    int cod = ui->idmEdit->text().toInt();

    QString res = QString::number(cod);
    query.prepare("SELECT * FROM materiel WHERE id_materiel = :cod");
    query.bindValue(":cod", res);
    query.exec();
    if(query.first())
    {
        QMessageBox::information(this, tr("Modifier Materiel"), tr("Le materiel est trouvé avec success, Veuillez entrer les nouvelles informations."));
         ui->idmEdit->setText(query.value(0).toString());
        ui->nomEdit->setText(query.value(1).toString());
        ui->etatEdit->setText(query.value(2).toString());
        ui->nombreEdit->setText(query.value(3).toString());

        return true;

}
}



void gestionSalle::on_pb__viderM_released()
{

    ui->nomEdit->setText("");
    ui->etatEdit->setText("");
}

void gestionSalle::on_pb_trierS_released()
{
    salle  *sa ;
    ui->tableViewSalle->setModel(sa->trie());
     ui->tableViewMateriel->setModel(tmpmateriel.afficher_materiel());//refresh

}

void gestionSalle::on_pb_pdfS_released()
{

    QPdfWriter pdf("C:/Users/Lenovo/Documents/salle_materiel/Ab.pdf");/*il faut toujour changer le nom (*/
    //C:\Users\Lenovo\Documents\salle_materiel
    QPainter painter;
    if (! painter.begin(&pdf))
    {

                        qWarning("failed to open file, is it writable?");

    }
    QString titre =ui->pdf_fonction->text();
    const time_t ctt = time(0);
    QSqlQuery query;
     qWarning("testpdf1");
    query.exec("SELECT id_salle,fonction,capacite FROM salle WHERE fonction='"+titre+"'");
      qWarning("testpdf2");

            while (query.next())
                  {

                QString id_salle = query.value(0).toString();
                QString fonction = query.value(1).toString();
                QString capacite = query.value(2).toString();

        painter.drawText(2200,3500,id_salle);
        painter.drawText(2200,4000,fonction);
        painter.drawText(2200,4500,capacite);


        painter.setPen(Qt::red);
        painter.drawText(4500,2000,"SALLE");
        painter.setPen(Qt::black);
        painter.drawText(500,2000,asctime(localtime(&ctt)));
        painter.drawText(500,3500,"Id salle:");
        painter.drawText(500,4000,"fonction:");
        painter.drawText(500,4500,"capacite:");



            }





}


void gestionSalle::on_makePlot_released()
{
    int panne=0;
    int n_panne=0;


       QSqlQuery q;
       q.prepare("SELECT * FROM materiel WHERE etat = 0 ");
       q.exec();
         while (q.next())
       {
       panne++;
       }
         q.prepare("SELECT * FROM materiel WHERE etat=1");
         q.exec();
           while (q.next())
         {
          n_panne++;
         }


   // set dark background gradient:

   QLinearGradient gradient(0, 0, 0, 400);
   gradient.setColorAt(0, QColor(90, 90, 90));
   gradient.setColorAt(0.38, QColor(105, 105, 105));
   gradient.setColorAt(1, QColor(70, 70, 70));
   ui->qplot->setBackground(QBrush(gradient));

   // create empty bar chart objects:

   QCPBars *fossil = new QCPBars(ui->qplot->xAxis, ui->qplot->yAxis);
   fossil->setAntialiased(false);


   fossil->setStackingGap(1);



   // prepare x axis with country labels:
   QVector<double> ticks;
   QVector<QString> labels;
   ticks << 1 << 2 ;
   labels << "materiel en panne" << "materiel en bon etat";
   QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
   textTicker->addTicks(ticks, labels);
   ui->qplot->xAxis->setTicker(textTicker);
   ui->qplot->xAxis->setTickLabelRotation(60);
   ui->qplot->xAxis->setSubTicks(false);
   ui->qplot->xAxis->setTickLength(0, 4);
   ui->qplot->xAxis->setRange(0, 13);
   ui->qplot->xAxis->setBasePen(QPen(Qt::white));
   ui->qplot->xAxis->setTickPen(QPen(Qt::white));
   ui->qplot->xAxis->grid()->setVisible(true);
   ui->qplot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
   ui->qplot->xAxis->setTickLabelColor(Qt::white);
   ui->qplot->xAxis->setLabelColor(Qt::white);

   // prepare y axis:
   ui->qplot->yAxis->setRange(0, 10);
   ui->qplot->yAxis->setPadding(5); // a bit more space to the left border
   //ui->qplot->yAxis->setLabel("nembre des offres par mois");
   ui->qplot->yAxis->setBasePen(QPen(Qt::white));
   ui->qplot->yAxis->setTickPen(QPen(Qt::white));
   ui->qplot->yAxis->setSubTickPen(QPen(Qt::white));
   ui->qplot->yAxis->grid()->setSubGridVisible(true);
   ui->qplot->yAxis->setTickLabelColor(Qt::white);
   ui->qplot->yAxis->setLabelColor(Qt::white);
   ui->qplot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
   ui->qplot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

   // Add data:
   QVector<double> fossilData;

   fossilData  << panne << n_panne;
   fossil->setData(ticks, fossilData);

   ui->qplot->legend->setVisible(true);
   ui->qplot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
   ui->qplot->legend->setBrush(QColor(255, 255, 255, 100));
   ui->qplot->legend->setBorderPen(Qt::NoPen);
   QFont legendFont = font();
   legendFont.setPointSize(10);
   ui->qplot->legend->setFont(legendFont);
   ui->qplot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}



void gestionSalle::on_impri_salle_released()
{






    QString titre =ui->pdf_fonction->text();
     QSqlQuery q;

             q.exec("SELECT id_salle,fonction,capacite FROM salle WHERE fonction='"+titre+"'");

             while (q.next())
                       {

                         QString id_salle = q.value(0).toString();
                         QString  fonction= q.value(1).toString();
                         QString capacite = q.value(2).toString();

                         //QTextDocumentFragment fragment = QTextDocumentFragment::fromHtml("<img src=''>");
                         QSize s{5, 5};
                         QTextEdit w;
                         QTextDocumentFragment fragment;
                                 fragment = QTextDocumentFragment::fromHtml(
                                             QString(R"(<img src='' height="%1" width="%1">)")
                                             .arg(s.width())
                                             .arg(s.height()));
                                 w.textCursor().insertFragment(fragment);



                                             ui->imprimer_edit->insertHtml("<font color=#420002><b>SALLE</b></font>");
                                             ui->imprimer_edit->insertPlainText("\n\n\nid_salle:");
                                             ui->imprimer_edit->insertPlainText(id_salle);
                                             ui->imprimer_edit->insertPlainText("\n\n\nfonction:");
                                             ui->imprimer_edit->insertPlainText(fonction);
                                             ui->imprimer_edit->insertPlainText("\n\n\ncapacite:  ");
                                             ui->imprimer_edit->insertPlainText(capacite);

                                           ui->imprimer_edit->insertPlainText("\n\n ");
                                           //ui->imprimer_edit->insertHtml("<font  color=#40adb9><b>MERCI POUR VOTRE FIDELITE</b></font>") ;
                                          ui->imprimer_edit->setFont(QFont ("MS Serif",10));
     }
                 //imprimer
                 QPrinter printer;
                 printer.setPrinterName("desiered printer name");
                 QPrintDialog dialog(&printer,this);
                 if(dialog.exec()== QDialog::Rejected)
                     return;
                 ui->imprimer_edit->print(&printer);
                 ui->imprimer_edit->clear();



}

void gestionSalle::on_radioButton_released() //en panne
{

      ui->etatEdit->setText("0");
}

void gestionSalle::on_radioButton_2_released() //en bonne etat
{
     ui->etatEdit->setText("1");
}

void gestionSalle::on_ajout_materiel_released()
{
    int etat = ui->etatAdd->text().toInt();
    int nombre = ui->nombreAdd->text().toInt();
    QString nom= ui->nomAdd->text();
    int id_materiel = ui->idmAdd->text().toInt();
     int id_salle = ui->idmsAdd->text().toInt();
     int total_panne;
    materiel m(id_materiel ,nom,etat,nombre,id_salle,total_panne);

          bool test=m.ajouter_materiel();

          if(test)
        {

 ui->tableViewMateriel->setModel(tmpmateriel.afficher_materiel());
        QMessageBox::information(nullptr, QObject::tr("Ajouter un materiel"),
                          QObject::tr("materiel ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

        }
          else
              QMessageBox::critical(nullptr, QObject::tr("Ajouter un materiel"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);


}

void gestionSalle::on_modifier_materiel_released()
{
    QString nom;
    int id_materiel=0,etat=0,nombre=0,id_salle=0,total_panne=0;
    QSqlQuery query;
    int cod = ui->idmEdit->text().toInt();
    int codd = ui->etatEdit->text().toInt();
    int coddd = ui->nombreEdit->text().toInt();
    QString res = QString::number(cod);
    QString ress = QString::number(codd);
      QString resss = QString::number(coddd);
    id_materiel = ui->idmEdit->text().toInt();
   nom = ui->nomEdit->text();
   etat=ui->etatEdit->text().toInt();
 nombre=ui->nombreEdit->text().toInt();

    materiel m(id_materiel, nom, etat,nombre,id_salle,total_panne);

    if(m.modifier_materiel(cod))

    {
        ui->tableViewMateriel->setModel(tmpmateriel.afficher_materiel());//refresh
         //ui->tableViewMateriel->setModel(tmpmateriel.afficher_materiel());
        QMessageBox::information(this, tr("Modifier Materiel"), tr("Le materiel a été modifié avec success."));
    }
}

void gestionSalle::on_chercher_fct_released()
{
    /*QString fonction,fct;
    int id_salle=0,capacite=0;
    QSqlQuery query;



    int cod = ui->idEdit->text().toInt();
    int codd = ui->capaciteEdit->text().toInt();
    QString res = QString::number(id_salle);
    QString ress = QString::number(capacite);
    id_salle = ui->idEdit->text().toInt();
    fonction = ui->fonctionEdit->text();
    capacite=ui->capaciteEdit->text().toInt();
    test1
    QMessageBox::information(this, tr("lawej fct"), tr("ok"));

    salle s(id_salle, fonction, capacite );
    test2
    QMessageBox::information(this, tr("laj fct deux "), tr("aazzert"));
    if(s.afficher_seule_salle(fct))
    {
        ui->chercher_fct->setText(query.value(0).toString());
       ui->chercher_fct->setText(query.value(1).toString());
       ui->chercher_fct->setText(query.value(2).toString());

        QMessageBox::information(this, tr("Modifier salle"), tr("La salle été modifié avec success."));
    }*/




    salle * s;
    ui->afficher_fct->setModel(s->rechercher(ui->pdf_fonction->text()));










}


void gestionSalle::on_comboBox_currentTextChanged(const QString &arg1)
{
    ui->idmsAdd->setText(arg1);
    //ui->comboBox->currentText();
}

void gestionSalle::on_alert_released()

{
    QSqlQuery q;



    QString nom;
    int id_materiel=0,etat=0,nombre=0,id_salle=0,total_panne;
materiel m(id_materiel, nom, etat,nombre,id_salle,total_panne);

  QMessageBox::information(this, tr("Modifier Materiel"), tr("a"));

  QString a = QString::number(etat);
   QString b = QString::number(total_panne);

       q.bindValue(":etat", a);
       QMessageBox::information(this, tr("Modifier Materiel"), tr("A"));

       q.bindValue(":total_panne", b);
       QMessageBox::information(this, tr("Modifier Materiel"), tr("B"));

if (total_panne>2)
 {
    QMessageBox::information(this, tr("Modifier Materiel"), tr("a"));
  QMessageBox::information(this, tr("Modifier Materiel"), tr("b"));

  Smtp *s=new Smtp("fournisseurX@gmail.com","fournisseur123","smtp.gmail.com",465);
  s->sendMail("fournisseurX@gmail.com","nour.helali@esprit.tn","alert sujet","vous avez un materiel en panne");
  QMessageBox::information(this, tr("Modifier Materiel"), tr("c"));
}

}
//***********PLAYLIST ************
void gestionSalle::on_addMediaButton_clicked() {
  QStringList files = QFileDialog::getOpenFileNames(this, tr("mp3 files"), QDir::currentPath(), tr("mp3 files (*.mp3)"));

  if(!files.isEmpty() && playlist_) {
    for (QString song : files) {
      playlist_->AddSong(song);
    }
  }
}

void gestionSalle::on_playButton_clicked() {
  player_->Play();
}

void gestionSalle::on_stopButton_clicked() {
  player_->Stop();
}

void gestionSalle::on_nextButton_clicked() {
  player_->NextSong();
}

void gestionSalle::on_pauseButton_clicked() {
  player_->Pause();
}

void gestionSalle::on_previousButton_clicked() {
  player_->PreviousSong();
}

QString gestionSalle::MillisecondsTo24HString(qint64 milliseconds) {
  int hours = static_cast<int>(milliseconds / 3600000);
  int minutes = static_cast<int>(milliseconds / 60000) - hours * 60;
  int seconds = static_cast<int>(milliseconds / 1000) - minutes * 60;
  QString result = QString().sprintf("%02d:%02d:%02d", hours, minutes, seconds);

  return result;
}

void gestionSalle::SetPlayerPosition(qint64 position) {
  player_->SetPosition(position);
}

void gestionSalle::PositionChangedByPlayer(qint64 position) {
  QString elapsedTime = "00:00:00";
  double duration = player_->GetCurrentSongDuration();
  int currentPosition = 0;

  if (duration > 0) {
    currentPosition = static_cast<int>((position / duration) * 1000);

    if (currentPosition >= 0 && currentPosition <= 1000) {
      ui->timeSlider->setValue(currentPosition);
    }

    elapsedTime = MillisecondsTo24HString(position);
  }

  ui->label->setText(elapsedTime);
}

void gestionSalle::PositionChangedByUser(int position) {
  qint64 duration = player_->GetCurrentSongDuration();
  int changedPosition = static_cast<int>((position / 1000.0) * duration);

  if (changedPosition > 0 && changedPosition <= duration) {
    SetPlayerPosition(changedPosition);
  }
}

void gestionSalle::CurrentSongChangedByPlayer(int playListIndex) {
  for (int i = 0; i < ui->songList->count(); i++) {
    ui->songList->item(i)->setBackgroundColor(Qt::white);
  }

  ui->songList->item(playListIndex)->setBackgroundColor(Qt::blue);
}

void gestionSalle::CurrentSongChangedByUser() {
  int currentIndex = ui->songList->currentRow();

  player_->SetSong(currentIndex);
  player_->Play();
}

void gestionSalle::on_savePlaylistButton_clicked()
{
  QString playlist = QFileDialog::getSaveFileName(this, tr("m3u files"), QDir::currentPath(), tr("m3u files (*.m3u)"));

  playlist_->Save(QUrl::fromLocalFile(playlist));
}

void gestionSalle::on_loadPlaylistButton_clicked()
{
  QString playlist = QFileDialog::getOpenFileName(this, tr("m3u files"), QDir::currentPath(), tr("m3u files (*.m3u)"));

  playlist_->Load(QUrl::fromLocalFile(playlist));
}

void gestionSalle::UpdateSongList() {
  ui->songList->clear();

  if (playlist_) {
    if(playlist_->MediaCount() > 0) {
      for (int i = 0; i < playlist_->MediaCount(); i++) {
        ui->songList->addItem(playlist_->GetPlaylist()->media(i).canonicalUrl().fileName());
      }
    }
  }
}

void gestionSalle::on_removeMediaButton_clicked()
{
  int currentIndex = ui->songList->currentRow();

  playlist_->RemoveSong(currentIndex);
}

void gestionSalle::on_volumeSlider_valueChanged(int value)
{
  player_->SetVolume(value);
}

//********************************
