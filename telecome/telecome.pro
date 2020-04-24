QT       += core sql gui printsupport network charts

QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network printsupport

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    acceuille.cpp \
    aliment_menu.cpp \
    connexion.cpp \
    departement_employe.cpp \
    eleve_niveau.cpp \
    espace_jouet.cpp \
    evennement_club.cpp \
    main.cpp \
    mainwindow.cpp \
    salle_materiel.cpp \
    donutbreakdownchart.cpp \
    mainslice.cpp \
    smtp.cpp

HEADERS += \
    acceuille.h \
    aliment_menu.h \
    connexion.h \
    departement_employe.h \
    eleve_niveau.h \
    espace_jouet.h \
    evennement_club.h \
    mainwindow.h \
    salle_materiel.h \
    donutbreakdownchart.h \
    mainslice.h \
    smtp.h

FORMS += \
    acceuille.ui \
    aliment_menu.ui \
    departement_employe.ui \
    eleve_niveau.ui \
    espace_jouet.ui \
    evennement_club.ui \
    mainwindow.ui \
    salle_materiel.ui

QT +=sql

# Default rules for deployment.


qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path):

target.path = $$[QT_INSTALL_EXAMPLES]/charts/donutbreakdown

INSTALLS += target
