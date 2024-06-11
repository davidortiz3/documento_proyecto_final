/********************************************************************************
** Form generated from reading UI file 'ventana.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANA_H
#define UI_VENTANA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ventana
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ventana)
    {
        if (ventana->objectName().isEmpty())
            ventana->setObjectName("ventana");
        ventana->resize(800, 600);
        centralwidget = new QWidget(ventana);
        centralwidget->setObjectName("centralwidget");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(10, 1, 781, 551));
        ventana->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ventana);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        ventana->setMenuBar(menubar);
        statusbar = new QStatusBar(ventana);
        statusbar->setObjectName("statusbar");
        ventana->setStatusBar(statusbar);

        retranslateUi(ventana);

        QMetaObject::connectSlotsByName(ventana);
    } // setupUi

    void retranslateUi(QMainWindow *ventana)
    {
        ventana->setWindowTitle(QCoreApplication::translate("ventana", "ventana", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ventana: public Ui_ventana {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANA_H
