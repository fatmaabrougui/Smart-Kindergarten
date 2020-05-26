#include "evenement_club.h"
#include "ui_evenement_club.h"
#include "club.h"
#include "event.h"
#include <QMessageBox>
#include <QPdfWriter>
#include <QPainter>
//#include <QPrinter>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>

evenement_club::evenement_club(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::evenement_club)
{
    ui->setupUi(this);

    ui->tabclub->setModel(tmpclub.afficherC());
    ui->tabevent->setModel(tmpevent.afficherE());
    ui->comboBox_2->setModel(tmpclub.afficherC());
    ui->comboBox_3->setModel(tmpclub.afficherC());
    ui->comboBox_4->setModel(tmpevent.afficherE());

}

evenement_club::~evenement_club()
{
    delete ui;
}


/**club**/
void evenement_club::on_pb_ajouter_clicked()
{
    int idclub = ui->lineEdit_idclub->text().toInt();
    QString nomclub= ui->lineEdit_nomclub->text();
    QString categclub= ui->lineEdit_categclub->text();
    QString descclub= ui->lineEdit_descclub->text();
  Club l(idclub,nomclub,categclub, descclub);
  bool test=l.ajouterC();
  if(test)
{

      ui->tabclub->setModel(tmpclub.afficherC());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un club"),
                  QObject::tr("club ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un club"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void evenement_club::on_pb_supprimer_clicked()
{
    int id = ui->comboBox_3->currentIndex();
  //  int id = ui->lineEdit_id_2->text().toInt();
bool test=tmpclub.supprimerC(id);
if(test)
{ui->tabclub->setModel(tmpclub.afficherC());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un club"),
                QObject::tr("club supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un club"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}



bool evenement_club::on_pb_chercherC_released()
{

    QSqlQuery query;
    int cod = ui->idEdit->text().toInt();

    QString res = QString::number(cod);
    query.prepare("SELECT * FROM club WHERE idclub = :cod");
    query.bindValue(":cod", res);
    query.exec();
    if(query.first())
    {
        QMessageBox::information(this, tr("Modifier Club"), tr("Le club est trouvé avec succès, Veuillez saisir les nouvelles informations."));
        ui->idEdit->setText(query.value(0).toString());
        ui->nomEdit->setText(query.value(1).toString());
        ui->categEdit->setText(query.value(2).toString());
        ui->descEdit->setText(query.value(3).toString());

        return true;
}
    return false;
}


void evenement_club::on_pb_confirmerC_released()
{   QString nomclub, categclub, descclub;
    int idclub=0;
    QSqlQuery query;


    int cod = ui->idEdit->text().toInt();
    QString codd = ui->nomEdit->text();
    QString res = QString::number(cod);
    QString ress = codd;
    idclub = ui->idEdit->text().toInt();
   nomclub = ui->nomEdit->text();
  categclub= ui->categEdit->text();
   descclub = ui->descEdit->text();


    Club c(idclub, nomclub, categclub, descclub);

    if(c.modifier_club(cod))

    {
        ui->tabclub->setModel(tmpclub.afficherC());//refresh
         ui->tabclub->setModel(tmpclub.afficherC());
         QMessageBox::information(nullptr, QObject::tr("Modifier un club"),
                                    QObject::tr("Club modifié.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

/************************************************************************************************************************/

    /**evenement**/
   void evenement_club::on_pb_ajouterE_clicked()
    {
        int idevent = ui->lineEdit_idevent->text().toInt();
        QString nomevent= ui->lineEdit_nomevent->text();
        QString dateevent= ui->lineEdit_dateevent->text();
        QString descevent= ui->lineEdit_descevent->text();
      Event m(idevent,nomevent,dateevent,descevent);
      bool test=m.ajouterE();
      if(test)
    {

          ui->tabevent->setModel(tmpevent.afficherE());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un evenement"),
                      QObject::tr("Evenement ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un evenement"),
                      QObject::tr("Erreur!\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);


    }

    void evenement_club::on_pb_supprimerE_clicked()
    {
    int id = ui->lineEdit_id_3->text().toInt();
    bool test=tmpevent.supprimerE(id);
    if(test)
    {ui->tabevent->setModel(tmpevent.afficherE());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un evenement"),
                    QObject::tr("Evenement supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un evenement"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }



    bool evenement_club::on_pb_chercherE_released()
    {

        QSqlQuery query;
        int cod = ui->idEvEdit->text().toInt();

        QString res = QString::number(cod);
        query.prepare("SELECT * FROM event WHERE idevent = :cod");
        query.bindValue(":cod", res);
        query.exec();
        if(query.first())
        {
            QMessageBox::information(this, tr("Modifier Evenement"), tr("L'evenement est trouvé avec succès, Veuillez saisir les nouvelles informations."));
            ui->idEvEdit->setText(query.value(0).toString());
            ui->nomEvEdit->setText(query.value(1).toString());
            ui->descEvEdit->setText(query.value(2).toString());
            ui->dateEvEdit->setText(query.value(3).toString());

            return true;
    }
        return false;
    }


    void evenement_club::on_pb_confirmerE_released()
    {   QString nomevent, descevent, dateevent;
        int idevent=0;
        QSqlQuery query;


        int cod = ui->idEvEdit->text().toInt();
     //   QString codd = ui->nomEdit->text();
        QString res = QString::number(cod);
    //    QString ress = codd;
        idevent = ui->idEvEdit->text().toInt();
       nomevent = ui->nomEvEdit->text();
       descevent = ui->descEvEdit->text();
      dateevent= ui->dateEvEdit->text();


        Event e(idevent, nomevent,descevent,dateevent);

        if(e.modifier_event(cod))

        {
            ui->tabevent->setModel(tmpevent.afficherE());//refresh
             ui->tabevent->setModel(tmpevent.afficherE());
             QMessageBox::information(nullptr, QObject::tr("Modifier un evenement"),
                                        QObject::tr("Evenement modifié.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }




/**evenement**/
/*
void evenement_club::on_pb_ajouterE_released()
{

    int idevent = ui->lineEdit_idevent->text().toInt();
    QString nomevent= ui->lineEdit_nomevent->text();
    QString descevent= ui->lineEdit_descevent->text();
    QString dateevent= ui->lineEdit_dateevent->text();

  Event m(idevent,nomevent,descevent,dateevent);
  bool test=m.ajouterE();
  if(test)
{

      ui->tabevent->setModel(tmpevent.afficherE());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un evenement"),
                  QObject::tr("Evenement ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un evenement"),
                  QObject::tr("Erreur!\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}
*/

void evenement_club::on_pdf_2_clicked()
{

    QPdfWriter pdf("C:/Users/Lenovo/Documents/guinga/fatma+nour+yessine+louay/telecome/pdf_club/club.pdf");/*il faut toujour changer le nom (*/

    QPainter painter;

    if (! painter.begin(&pdf))

    {



                        qWarning("failed to open file, is it writable?");



    }

    QString titre =ui->lineEdit_rese_pdf->text();
//copi men andi lienedit
    const time_t ctt = time(0);

    QSqlQuery query;


    query.exec("SELECT idevent, descevent, dateevent FROM Event WHERE nomevent='"+titre+"'");




            while (query.next())

                  {



                QString idevent = query.value(0).toString();

                QString nomevent = query.value(1).toString();

                QString descevent = query.value(2).toString();

                QString dateevent = query.value(3).toString();


//intervalle 500
        painter.drawText(2200,3500,idevent);

        painter.drawText(2200,4000,nomevent);

        painter.drawText(2200,4500,descevent);

        painter.drawText(2200,5000,dateevent);



//intervalle 500

        painter.setPen(Qt::red);

        painter.drawText(4500,2000,"EVENEMENTS");

        painter.setPen(Qt::black);

        painter.drawText(500,2000,asctime(localtime(&ctt)));

        painter.drawText(500,3500,"ID evenement:");

        painter.drawText(500,4000,"Nom evenement:");

        painter.drawText(500,4500,"description  evenement:");

        painter.drawText(500,5000,"Date evenement:");







            }
}

void evenement_club::on_imprimer_clicked()
{



    QString titre =ui->lineEdit_rese_pdf->text();

    QSqlQuery q;



            q.exec("SELECT idevent,nomevent,descevent,dateeevent FROM Event WHERE nomevent='"+titre+"'");


            while (q.next())

                      {



                        QString idevent = q.value(0).toString() ;

                        QString  nomevent= q.value(1).toString();

                        QString descevent = q.value(2).toString();

                        QString dateevent= q.value(3).toString();}



                //imprimer

                QPrinter printer;

                printer.setPrinterName("desiered printer name");

              QPrintDialog dialog(&printer,this);

                if(dialog.exec()== QDialog::Rejected)

                    return;



}


void evenement_club::on_pb_trierEvent_released()
{
    Event  *ev ;
    ui->tabevent->setModel(ev->trier());
     ui->tabclub->setModel(tmpclub.afficherC());//refresh
}
