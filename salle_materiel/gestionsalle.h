#ifndef GESTIONSALLE_H
#define GESTIONSALLE_H
#include <QMainWindow>
#include "salle.h"
#include "materiel.h"
#include"qcustomplot.h"
#include <QPrinter>
#include<QPrintDialog>
//*******PLAYLIST ********
#include <QFileDialog>
#include <player.h>
#include <QStringList>
#include <QString>
#include <QListWidget>
#include <QListWidgetItem>
//*************************

QT_BEGIN_NAMESPACE
namespace Ui { class gestionSalle; }
QT_END_NAMESPACE

class gestionSalle : public QMainWindow
{
    Q_OBJECT

public:
    gestionSalle(QWidget *parent = nullptr);
    ~gestionSalle();

private slots:
    void on_pb_ajouterS_released();

    bool on_pb_chercherS_released();

    void on_pb_confirmerS_released();

    void on_pb_supprimerS_released();

    void on_pb__viderS_released();

    void on_pb_supprimerM_released();

    bool on_pb_chercherM_released();



    void on_pb__viderM_released();

    void on_pb_trierS_released();

    void on_pb_pdfS_released();



    void on_pushButton_released();



   void on_makePlot_released();


   void on_impri_salle_released();

   void on_radioButton_released();

   void on_radioButton_2_released();

   void on_ajout_materiel_released();

   void on_modifier_materiel_released();

   void on_chercher_fct_released();



   void on_comboBox_currentTextChanged(const QString &arg1);

   void on_alert_released();
   //************PALYLIST ************
   void on_addMediaButton_clicked();
   void on_playButton_clicked();
   void on_stopButton_clicked();
   void on_pauseButton_clicked();
   void on_nextButton_clicked();
   void on_previousButton_clicked();
   void PositionChangedByPlayer(qint64 position);
   void PositionChangedByUser(int position);
   void CurrentSongChangedByPlayer(int playlistIndex);
   void CurrentSongChangedByUser();
   void on_savePlaylistButton_clicked();
   void on_loadPlaylistButton_clicked();
   void UpdateSongList();

   void on_removeMediaButton_clicked();

   void on_volumeSlider_valueChanged(int value);
   //*********************************


private:
    Ui::gestionSalle *ui;
    salle tmpsalle;
    materiel tmpmateriel;

   //*******PLAYLIST***********
    Player * player_ = Player::GetInstance();
    Playlist * playlist_ = new Playlist;

    void SetPlayerPosition(qint64 position);

    QString MillisecondsTo24HString(qint64 milliseconds);

    //*************************

};
#endif // GESTIONSALLE_H
