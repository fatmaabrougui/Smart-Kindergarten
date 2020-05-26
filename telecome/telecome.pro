QT       += core sql gui printsupport network charts

QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network printsupport multimedia

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
    aliments.cpp \
    club.cpp \
    connexion.cpp \
    departement.cpp \
    eleve_niveau.cpp \
    employe.cpp \
    espace.cpp \
    espace_jouet.cpp \
    evenement_club.cpp \
    evennement_club.cpp \
    event.cpp \
    gestioncuisine.cpp \
    gestiond_emp.cpp \
    gestionjouets.cpp \
    gestionsalle.cpp \
    jouets.cpp \
    main.cpp \
    mainwindow.cpp \
    materiel.cpp \
    menu.cpp \
    player.cpp \
    playlist.cpp \
    qcustomplot.cpp \
    salle.cpp \
    salle_materiel.cpp \
    donutbreakdownchart.cpp \
    mainslice.cpp \
    smtp.cpp

HEADERS += \
    acceuille.h \
    aliment_menu.h \
    aliments.h \
    club.h \
    connexion.h \
    departement.h \
    eleve_niveau.h \
    employe.h \
    espace.h \
    espace_jouet.h \
    evenement_club.h \
    evennement_club.h \
    event.h \
    gestioncuisine.h \
    gestiond_emp.h \
    gestionjouets.h \
    gestionsalle.h \
    jouets.h \
    mainwindow.h \
    materiel.h \
    menu.h \
    player.h \
    playlist.h \
    qcustomplot.h \
    salle.h \
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
    evenement_club.ui \
    evennement_club.ui \
    gestioncuisine.ui \
    gestiond_emp.ui \
    gestionjouets.ui \
    gestionsalle.ui \
    mainwindow.ui \
    salle_materiel.ui

QT +=sql

# Default rules for deployment.


qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path):

target.path = $$[QT_INSTALL_EXAMPLES]/charts/donutbreakdown

INSTALLS += target

DISTFILES += \
    .gitignore \
    jouets.pro.user \
    jouets.pro.user.e0e3f1b \
    libcrypto-1_1-x64.dll \
    libcrypto-1_1.dll \
    libeay32.dll \
    libssl-1_1-x64.dll \
    libssl-1_1.dll \
    ssleay32.dll \
    telecome.pro.user
