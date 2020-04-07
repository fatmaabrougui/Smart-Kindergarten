#ifndef GESTIONjouets_H
#define GESTIONjouets_H
#include <QMainWindow>
#include<QVector>
#include <qcustomplot.h>
#include <QTextEdit>
#include<QtPrintSupport/QPrinter>
#include "espace.h"
#include "jouets.h"
#include "qcustomplot.h"
#include "smtp.h"
#include<QPdfWriter>
#include <QPainter>
#include<QPainter>
#include<QDesktopServices>
#include<QPdfWriter>
#include <QMessageBox>
#include<QUrl>
#include<QFileDialog>
#include <QPixmap>
#include "smtp.h"
QT_BEGIN_NAMESPACE
namespace Ui { class gestionjouets; }
QT_END_NAMESPACE

class gestionjouets : public QMainWindow
{
    Q_OBJECT

public:
    gestionjouets(QWidget *parent = nullptr);
    ~gestionjouets();

private slots:
    void on_pb_ajouterS_released();

    bool on_pb_chercherS_released();

    void on_pb_confirmerS_released();

    void on_pb_supprimerS_released();

    void on_pb__viderS_released();

    //void on_pb_ajouterM_released();

    void on_pb_supprimerM_released();

    bool on_pb_chercherM_released();

    //void on_pb_confirmerM_released();

    void on_pb__viderM_released();

    void on_pb_trierS_released();



    //void on_testAjout_released();

    void on_pushButton_released();

  // void on_ajoutM_released();

    //void on_ajoutM_clicked();

   void on_ajoutm_released();

 //  void on_pushButton_2_released();

   void on_confirmerM_released();

   void on_mail_released();

   void on_pdf_released();

   void on_pdf_clicked();

   void on_afficher_stat_clicked();

   void on_imprimer_clicked();

   void on_capaciteAdd_2_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::gestionjouets *ui;
    espace tmpespace;
    jouets tmpjouets;
};
#endif // GESTIONjouets_H
