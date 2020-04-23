/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QTabWidget *tabWidget_2;
    QWidget *tab_5;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_idclub;
    QLineEdit *lineEdit_nomclub;
    QLineEdit *lineEdit_categclub;
    QLineEdit *lineEdit_descclub;
    QPushButton *pb_ajouter;
    QWidget *tab_7;
    QTableView *tabclub;
    QWidget *tab_8;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *idEdit;
    QLineEdit *nomEdit;
    QLineEdit *categEdit;
    QLineEdit *descEdit;
    QPushButton *pb_chercherC;
    QPushButton *pb_confirmerC;
    QWidget *tab_6;
    QLineEdit *lineEdit_id_2;
    QLabel *label_9;
    QPushButton *pb_supprimer;
    QWidget *tab_4;
    QTabWidget *tabWidget_3;
    QWidget *tab_9;
    QLabel *label_10;
    QLineEdit *lineEdit_nomevent;
    QLineEdit *lineEdit_descevent;
    QLineEdit *lineEdit_dateevent;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *lineEdit_idevent;
    QPushButton *pb_ajouterE;
    QWidget *tab_10;
    QTableView *tabevent;
    QPushButton *pdf;
    QPushButton *imprimer;
    QLineEdit *lineEdit_rese_pdf;
    QLabel *label_19;
    QPushButton *pb_trierEvent;
    QWidget *tab_11;
    QLabel *label_17;
    QLineEdit *nomEvEdit;
    QLineEdit *descEvEdit;
    QLineEdit *idEvEdit;
    QLabel *label_16;
    QPushButton *pb_chercherE;
    QPushButton *pb_confirmerE;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *dateEvEdit;
    QWidget *tab_12;
    QLabel *label_18;
    QPushButton *pb_supprimerE;
    QLineEdit *lineEdit_id_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(550, 419);
        MainWindow->setStyleSheet(QString::fromUtf8("QStatusBar {\n"
"    background-color: rgb(207, 203, 255);\n"
"}\n"
"QPushButton\n"
"{\n"
"  border: 0px white;\n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"  background: rgb(170, 170, 255);\n"
"}\n"
"QComboBox {\n"
"    border: 1px solid rgb(170, 170, 255);\n"
"    border-radius: 3px;\n"
"    padding: 1px 18px 1px 3px;\n"
"    min-width: 6em;\n"
"}\n"
"QTableView {\n"
"    selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0.5, y2: 0.5,\n"
"                                stop: 0 #FF92BB, stop: 1 white);\n"
"}\n"
"QLineEdit { background-color: white;\n"
"border: 2px solid rgb(170, 170, 255);\n"
"    border-radius: 4px; }\n"
"\n"
"QFrame {\n"
"    border: 2px solid rgb(170, 170, 255);\n"
"    border-radius: 4px;\n"
"    padding: 2px;\n"
"    background-image: url(images/welcome.png);\n"
"}\n"
" QLabel{\n"
"    border:0px;\n"
"    border-radius: 4px;\n"
"    padding: 0px;\n"
"    background-image: url(images/welcome.png);\n"
"}\n"
"\n"
"\n"
"QStatusBar {\n"
"    background-color: rgb(207, 203"
                        ", 255);\n"
"}\n"
"\n"
"QStatusBar::item {\n"
"    border: 1px solid red;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"\n"
"\n"
"/************************************************/\n"
"QTabWidget::pane { /* The tab widget frame */\n"
"    border-top: 2px solid #ced1ff;\n"
"background-color:black;\n"
"}\n"
"\n"
"\n"
"/* Style the tab using the tab sub-control. Note that\n"
"    it reads QTabBar _not_ QTabWidget */\n"
"QTabWidget::pane { /* The tab widget frame */\n"
"    border-top: 2px solid #ced1ff;\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"    left: 10px; /* move to the right by 5px */\n"
"}\n"
"\n"
"/* Style the tab using the tab sub-control. Note that\n"
"    it reads QTabBar _not_ QTabWidget */\n"
"QTabBar::tab {\n"
"    background:rgb(194, 194, 255);\n"
"    border: 1px solid #ced1ff;\n"
"    border-bottom-color: #C2C7CB; /* same as the pane color */\n"
"    border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"    min-width: 8ex;\n"
"    padding: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:selected, QT"
                        "abBar::tab:hover {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #fafafa, stop: 0.4 #f4f4f4,\n"
"                                stop: 0.5 #e7e7e7, stop: 1.0 #fafafa);\n"
"}\n"
"\n"
"\n"
"\n"
"QTabBar::tab:!selected {\n"
"    margin-top: 2px; /* make non-selected tabs look smaller */\n"
"}\n"
"\n"
"\n"
"\n"
"/*********************************/\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"* {   background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4, radius: 1.35, stop: 0 #8A545D, stop: 1  rgb(255,255, 255));   color: rgb(0,0, 0);   border: 1px solid #ffaaff; }\n"
"/** {   background-color: rgb(255, 215, 255);   color: rgb(0,0, 0);   border: 1px solid #ffaaff; }*/\n"
""));
        tabWidget = new QTabWidget(MainWindow);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget_2 = new QTabWidget(tab_3);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(10, 10, 491, 331));
        tabWidget_2->setMinimumSize(QSize(481, 0));
        tabWidget_2->setStyleSheet(QString::fromUtf8("QStatusBar {\n"
"    background-color: rgb(178, 102, 255);\n"
"}\n"
"QPushButton\n"
"{\n"
"  border: 0px white;\n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"  background: rgb(178, 102, 255);\n"
"}\n"
"QComboBox {\n"
"    border: 1px solid rgb(178, 102, 255);\n"
"    border-radius: 3px;\n"
"    padding: 1px 18px 1px 3px;\n"
"    min-width: 6em;\n"
"}\n"
"QTableView {\n"
"    selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0.5, y2: 0.5,\n"
"                                stop: 0 rgb(194, 194, 255), stop: 1 #E4BBC2);\n"
"}\n"
"QLineEdit { background-color: white;\n"
"border: 2px solid rgb(178, 102, 255);\n"
"    border-radius: 4px; }\n"
"\n"
"QFrame {\n"
"    border: 2px solid #E4BBC2;\n"
"    border-radius: 4px;\n"
"    padding: 2px;\n"
"    background-image: url(images/welcome.png);\n"
"}\n"
" QLabel{\n"
"    border:0px;\n"
"    border-radius: 4px;\n"
"    padding: 0px;\n"
"    background-image: url(images/welcome.png);\n"
"}\n"
"\n"
"\n"
"QStatusBar {\n"
"    background-color: rgb(178, 1"
                        "02, 255);\n"
"}\n"
"\n"
"QStatusBar::item {\n"
"    border: 1px solid red;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"\n"
"\n"
"/************************************************/\n"
"QTabWidget::pane { /* The tab widget frame */\n"
"    border-top: 2px solid#E4BBC2;\n"
"background-color:black;\n"
"}\n"
"\n"
"\n"
"/* Style the tab using the tab sub-control. Note that\n"
"    it reads QTabBar _not_ QTabWidget */\n"
"QTabWidget::pane { /* The tab widget frame */\n"
"    border-top: 2px solid #ced1ff;\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"    left: 10px; /* move to the right by 5px */\n"
"}\n"
"\n"
"/* Style the tab using the tab sub-control. Note that\n"
"    it reads QTabBar _not_ QTabWidget */\n"
"QTabBar::tab {\n"
"    background:rgb(194, 194, 255);\n"
"    border: 1px solid rgb(194, 194, 255);\n"
"    border-bottom-color: #E4BBC2; /* same as the pane color */\n"
"    border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"    min-width: 8ex;\n"
"    padding: 2px;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
""
                        "QTabBar::tab:!selected {\n"
"    margin-top: 2px; /* make non-selected tabs look smaller */\n"
"}\n"
"\n"
"\n"
"\n"
"/*********************************/\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"* {   background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4, radius: 1.35, stop: 0 #E4BBC2, stop: 1  rgb(255,255, 255));   color: rgb(0,0, 0);   border: 1px solid #E4BBC2; }\n"
"/** {   background-color: rgb(255, 215, 255);   color: rgb(0,0, 0);   border: 1px solid #ffaaff; }*/\n"
""));
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        label = new QLabel(tab_5);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 70, 61, 16));
        label_2 = new QLabel(tab_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 110, 51, 16));
        label_3 = new QLabel(tab_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 150, 47, 14));
        label_4 = new QLabel(tab_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 190, 61, 16));
        lineEdit_idclub = new QLineEdit(tab_5);
        lineEdit_idclub->setObjectName(QString::fromUtf8("lineEdit_idclub"));
        lineEdit_idclub->setGeometry(QRect(170, 70, 113, 20));
        lineEdit_nomclub = new QLineEdit(tab_5);
        lineEdit_nomclub->setObjectName(QString::fromUtf8("lineEdit_nomclub"));
        lineEdit_nomclub->setGeometry(QRect(170, 110, 113, 20));
        lineEdit_categclub = new QLineEdit(tab_5);
        lineEdit_categclub->setObjectName(QString::fromUtf8("lineEdit_categclub"));
        lineEdit_categclub->setGeometry(QRect(170, 150, 113, 20));
        lineEdit_descclub = new QLineEdit(tab_5);
        lineEdit_descclub->setObjectName(QString::fromUtf8("lineEdit_descclub"));
        lineEdit_descclub->setGeometry(QRect(170, 190, 113, 20));
        pb_ajouter = new QPushButton(tab_5);
        pb_ajouter->setObjectName(QString::fromUtf8("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(350, 250, 75, 23));
        tabWidget_2->addTab(tab_5, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        tabclub = new QTableView(tab_7);
        tabclub->setObjectName(QString::fromUtf8("tabclub"));
        tabclub->setGeometry(QRect(25, 21, 431, 261));
        tabWidget_2->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        label_5 = new QLabel(tab_8);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(60, 50, 61, 16));
        label_6 = new QLabel(tab_8);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(60, 140, 81, 16));
        label_7 = new QLabel(tab_8);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(60, 220, 101, 16));
        label_8 = new QLabel(tab_8);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(60, 180, 101, 16));
        idEdit = new QLineEdit(tab_8);
        idEdit->setObjectName(QString::fromUtf8("idEdit"));
        idEdit->setGeometry(QRect(170, 50, 113, 20));
        nomEdit = new QLineEdit(tab_8);
        nomEdit->setObjectName(QString::fromUtf8("nomEdit"));
        nomEdit->setGeometry(QRect(170, 140, 113, 20));
        categEdit = new QLineEdit(tab_8);
        categEdit->setObjectName(QString::fromUtf8("categEdit"));
        categEdit->setGeometry(QRect(170, 180, 113, 20));
        descEdit = new QLineEdit(tab_8);
        descEdit->setObjectName(QString::fromUtf8("descEdit"));
        descEdit->setGeometry(QRect(170, 220, 113, 20));
        pb_chercherC = new QPushButton(tab_8);
        pb_chercherC->setObjectName(QString::fromUtf8("pb_chercherC"));
        pb_chercherC->setGeometry(QRect(190, 80, 75, 23));
        pb_confirmerC = new QPushButton(tab_8);
        pb_confirmerC->setObjectName(QString::fromUtf8("pb_confirmerC"));
        pb_confirmerC->setGeometry(QRect(370, 260, 75, 23));
        tabWidget_2->addTab(tab_8, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        lineEdit_id_2 = new QLineEdit(tab_6);
        lineEdit_id_2->setObjectName(QString::fromUtf8("lineEdit_id_2"));
        lineEdit_id_2->setGeometry(QRect(170, 50, 113, 20));
        label_9 = new QLabel(tab_6);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(60, 50, 71, 20));
        pb_supprimer = new QPushButton(tab_6);
        pb_supprimer->setObjectName(QString::fromUtf8("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(190, 80, 75, 23));
        tabWidget_2->addTab(tab_6, QString());
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget_3 = new QTabWidget(tab_4);
        tabWidget_3->setObjectName(QString::fromUtf8("tabWidget_3"));
        tabWidget_3->setGeometry(QRect(10, 10, 531, 371));
        tabWidget_3->setMinimumSize(QSize(481, 0));
        tabWidget_3->setStyleSheet(QString::fromUtf8("QStatusBar {\n"
"    background-color: rgb(178, 102, 255);\n"
"}\n"
"QPushButton\n"
"{\n"
"  border: 0px white;\n"
"  border-radius: 10px;\n"
"  padding: 0 8px;\n"
"  background: rgb(178, 102, 255);\n"
"}\n"
"QComboBox {\n"
"    border: 1px solid rgb(178, 102, 255);\n"
"    border-radius: 3px;\n"
"    padding: 1px 18px 1px 3px;\n"
"    min-width: 6em;\n"
"}\n"
"QTableView {\n"
"    selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0.5, y2: 0.5,\n"
"                                stop: 0 rgb(194, 194, 255), stop: 1 #E4BBC2);\n"
"}\n"
"QLineEdit { background-color: white;\n"
"border: 2px solid rgb(178, 102, 255);\n"
"    border-radius: 4px; }\n"
"\n"
"QFrame {\n"
"    border: 2px solid #E4BBC2;\n"
"    border-radius: 4px;\n"
"    padding: 2px;\n"
"    background-image: url(images/welcome.png);\n"
"}\n"
" QLabel{\n"
"    border:0px;\n"
"    border-radius: 4px;\n"
"    padding: 0px;\n"
"    background-image: url(images/welcome.png);\n"
"}\n"
"\n"
"\n"
"QStatusBar {\n"
"    background-color: rgb(178, 1"
                        "02, 255);\n"
"}\n"
"\n"
"QStatusBar::item {\n"
"    border: 1px solid red;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"\n"
"\n"
"/************************************************/\n"
"QTabWidget::pane { /* The tab widget frame */\n"
"    border-top: 2px solid#E4BBC2;\n"
"background-color:black;\n"
"}\n"
"\n"
"\n"
"/* Style the tab using the tab sub-control. Note that\n"
"    it reads QTabBar _not_ QTabWidget */\n"
"QTabWidget::pane { /* The tab widget frame */\n"
"    border-top: 2px solid #ced1ff;\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"    left: 10px; /* move to the right by 5px */\n"
"}\n"
"\n"
"/* Style the tab using the tab sub-control. Note that\n"
"    it reads QTabBar _not_ QTabWidget */\n"
"QTabBar::tab {\n"
"    background:rgb(194, 194, 255);\n"
"    border: 1px solid rgb(194, 194, 255);\n"
"    border-bottom-color: #E4BBC2; /* same as the pane color */\n"
"    border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"    min-width: 8ex;\n"
"    padding: 2px;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
""
                        "QTabBar::tab:!selected {\n"
"    margin-top: 2px; /* make non-selected tabs look smaller */\n"
"}\n"
"\n"
"\n"
"\n"
"/*********************************/\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"* {   background: qradialgradient(cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4, radius: 1.35, stop: 0 #E4BBC2, stop: 1  rgb(255,255, 255));   color: rgb(0,0, 0);   border: 1px solid #E4BBC2; }\n"
"/** {   background-color: rgb(255, 215, 255);   color: rgb(0,0, 0);   border: 1px solid #ffaaff; }*/\n"
""));
        tab_9 = new QWidget();
        tab_9->setObjectName(QString::fromUtf8("tab_9"));
        label_10 = new QLabel(tab_9);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(60, 70, 61, 16));
        lineEdit_nomevent = new QLineEdit(tab_9);
        lineEdit_nomevent->setObjectName(QString::fromUtf8("lineEdit_nomevent"));
        lineEdit_nomevent->setGeometry(QRect(170, 110, 113, 20));
        lineEdit_descevent = new QLineEdit(tab_9);
        lineEdit_descevent->setObjectName(QString::fromUtf8("lineEdit_descevent"));
        lineEdit_descevent->setGeometry(QRect(170, 150, 113, 20));
        lineEdit_dateevent = new QLineEdit(tab_9);
        lineEdit_dateevent->setObjectName(QString::fromUtf8("lineEdit_dateevent"));
        lineEdit_dateevent->setGeometry(QRect(170, 190, 113, 20));
        label_11 = new QLabel(tab_9);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(60, 110, 51, 16));
        label_12 = new QLabel(tab_9);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(60, 150, 61, 16));
        label_13 = new QLabel(tab_9);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(60, 190, 47, 14));
        lineEdit_idevent = new QLineEdit(tab_9);
        lineEdit_idevent->setObjectName(QString::fromUtf8("lineEdit_idevent"));
        lineEdit_idevent->setGeometry(QRect(170, 70, 113, 20));
        pb_ajouterE = new QPushButton(tab_9);
        pb_ajouterE->setObjectName(QString::fromUtf8("pb_ajouterE"));
        pb_ajouterE->setGeometry(QRect(370, 270, 75, 23));
        tabWidget_3->addTab(tab_9, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName(QString::fromUtf8("tab_10"));
        tabevent = new QTableView(tab_10);
        tabevent->setObjectName(QString::fromUtf8("tabevent"));
        tabevent->setGeometry(QRect(30, 20, 481, 311));
        pdf = new QPushButton(tab_10);
        pdf->setObjectName(QString::fromUtf8("pdf"));
        pdf->setGeometry(QRect(390, 190, 75, 23));
        imprimer = new QPushButton(tab_10);
        imprimer->setObjectName(QString::fromUtf8("imprimer"));
        imprimer->setGeometry(QRect(390, 220, 75, 23));
        lineEdit_rese_pdf = new QLineEdit(tab_10);
        lineEdit_rese_pdf->setObjectName(QString::fromUtf8("lineEdit_rese_pdf"));
        lineEdit_rese_pdf->setGeometry(QRect(380, 160, 101, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Bahnschrift"));
        font.setPointSize(14);
        lineEdit_rese_pdf->setFont(font);
        label_19 = new QLabel(tab_10);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(340, 110, 161, 41));
        pb_trierEvent = new QPushButton(tab_10);
        pb_trierEvent->setObjectName(QString::fromUtf8("pb_trierEvent"));
        pb_trierEvent->setGeometry(QRect(340, 280, 141, 21));
        tabWidget_3->addTab(tab_10, QString());
        tab_11 = new QWidget();
        tab_11->setObjectName(QString::fromUtf8("tab_11"));
        label_17 = new QLabel(tab_11);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(60, 140, 81, 16));
        nomEvEdit = new QLineEdit(tab_11);
        nomEvEdit->setObjectName(QString::fromUtf8("nomEvEdit"));
        nomEvEdit->setGeometry(QRect(170, 140, 113, 20));
        descEvEdit = new QLineEdit(tab_11);
        descEvEdit->setObjectName(QString::fromUtf8("descEvEdit"));
        descEvEdit->setGeometry(QRect(170, 180, 113, 20));
        idEvEdit = new QLineEdit(tab_11);
        idEvEdit->setObjectName(QString::fromUtf8("idEvEdit"));
        idEvEdit->setGeometry(QRect(170, 50, 113, 20));
        label_16 = new QLabel(tab_11);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(60, 220, 101, 16));
        pb_chercherE = new QPushButton(tab_11);
        pb_chercherE->setObjectName(QString::fromUtf8("pb_chercherE"));
        pb_chercherE->setGeometry(QRect(190, 80, 75, 23));
        pb_confirmerE = new QPushButton(tab_11);
        pb_confirmerE->setObjectName(QString::fromUtf8("pb_confirmerE"));
        pb_confirmerE->setGeometry(QRect(370, 260, 75, 23));
        label_14 = new QLabel(tab_11);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(60, 180, 101, 16));
        label_15 = new QLabel(tab_11);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(60, 50, 61, 16));
        dateEvEdit = new QLineEdit(tab_11);
        dateEvEdit->setObjectName(QString::fromUtf8("dateEvEdit"));
        dateEvEdit->setGeometry(QRect(170, 220, 113, 20));
        tabWidget_3->addTab(tab_11, QString());
        tab_12 = new QWidget();
        tab_12->setObjectName(QString::fromUtf8("tab_12"));
        label_18 = new QLabel(tab_12);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(60, 50, 71, 20));
        pb_supprimerE = new QPushButton(tab_12);
        pb_supprimerE->setObjectName(QString::fromUtf8("pb_supprimerE"));
        pb_supprimerE->setGeometry(QRect(190, 80, 75, 23));
        lineEdit_id_3 = new QLineEdit(tab_12);
        lineEdit_id_3->setObjectName(QString::fromUtf8("lineEdit_id_3"));
        lineEdit_id_3->setGeometry(QRect(170, 50, 113, 20));
        tabWidget_3->addTab(tab_12, QString());
        tabWidget->addTab(tab_4, QString());
        MainWindow->setCentralWidget(tabWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(1);
        tabWidget_3->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Identifiant", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Cat\303\251gorie", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        pb_ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QCoreApplication::translate("MainWindow", "Afficher", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Identifiant", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Nouveau Nom", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Nouvelle Description", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Nouvelle Categorie", nullptr));
        pb_chercherC->setText(QCoreApplication::translate("MainWindow", "Chercher", nullptr));
        pb_confirmerC->setText(QCoreApplication::translate("MainWindow", "Confirmer", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_8), QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Identifiant", nullptr));
        pb_supprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Gestion de Clubs", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Identifiant", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        pb_ajouterE->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_9), QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        pdf->setText(QCoreApplication::translate("MainWindow", "pdf", nullptr));
        imprimer->setText(QCoreApplication::translate("MainWindow", "Imprimer", nullptr));
        lineEdit_rese_pdf->setText(QString());
        label_19->setText(QCoreApplication::translate("MainWindow", "Entrer un ID pour la version PDF", nullptr));
        pb_trierEvent->setText(QCoreApplication::translate("MainWindow", "trier par ordre croissant", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_10), QCoreApplication::translate("MainWindow", "Afficher", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Nouveau Nom", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Nouvelle Date", nullptr));
        pb_chercherE->setText(QCoreApplication::translate("MainWindow", "Chercher", nullptr));
        pb_confirmerE->setText(QCoreApplication::translate("MainWindow", "Confirmer", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Nouvelle Description", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Identifiant", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_11), QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Identifiant", nullptr));
        pb_supprimerE->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_12), QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Gestion d'\303\251v\303\251nements", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
