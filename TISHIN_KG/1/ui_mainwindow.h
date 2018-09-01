/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    GLWidget *widget;
    QLabel *label_4;
    QSlider *SliderApproximation;
    QCheckBox *isPolyFill;
    QLabel *label_5;
    QSlider *SliderLight;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *p1x;
    QLabel *label_3;
    QLineEdit *p1y;
    QLabel *label_6;
    QLineEdit *p1z;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *p2y;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *p2x;
    QLineEdit *p2z;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *p3y;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *p3x;
    QLineEdit *p3z;
    QPushButton *Apply;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(581, 335);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new GLWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 371, 311));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(390, 210, 171, 16));
        SliderApproximation = new QSlider(centralWidget);
        SliderApproximation->setObjectName(QStringLiteral("SliderApproximation"));
        SliderApproximation->setGeometry(QRect(390, 230, 171, 20));
        SliderApproximation->setValue(50);
        SliderApproximation->setOrientation(Qt::Horizontal);
        SliderApproximation->setTickPosition(QSlider::NoTicks);
        SliderApproximation->setTickInterval(0);
        isPolyFill = new QCheckBox(centralWidget);
        isPolyFill->setObjectName(QStringLiteral("isPolyFill"));
        isPolyFill->setGeometry(QRect(400, 290, 171, 21));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(390, 250, 171, 16));
        SliderLight = new QSlider(centralWidget);
        SliderLight->setObjectName(QStringLiteral("SliderLight"));
        SliderLight->setGeometry(QRect(390, 270, 171, 20));
        SliderLight->setValue(50);
        SliderLight->setOrientation(Qt::Horizontal);
        SliderLight->setTickPosition(QSlider::NoTicks);
        SliderLight->setTickInterval(0);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(390, 10, 61, 15));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(390, 30, 16, 16));
        p1x = new QLineEdit(centralWidget);
        p1x->setObjectName(QStringLiteral("p1x"));
        p1x->setGeometry(QRect(400, 30, 41, 23));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(450, 30, 16, 16));
        p1y = new QLineEdit(centralWidget);
        p1y->setObjectName(QStringLiteral("p1y"));
        p1y->setGeometry(QRect(460, 30, 41, 23));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(510, 30, 16, 16));
        p1z = new QLineEdit(centralWidget);
        p1z->setObjectName(QStringLiteral("p1z"));
        p1z->setGeometry(QRect(520, 30, 41, 23));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(390, 80, 16, 16));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(450, 80, 16, 16));
        p2y = new QLineEdit(centralWidget);
        p2y->setObjectName(QStringLiteral("p2y"));
        p2y->setGeometry(QRect(460, 80, 41, 23));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(390, 60, 61, 15));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(510, 80, 16, 16));
        p2x = new QLineEdit(centralWidget);
        p2x->setObjectName(QStringLiteral("p2x"));
        p2x->setGeometry(QRect(400, 80, 41, 23));
        p2z = new QLineEdit(centralWidget);
        p2z->setObjectName(QStringLiteral("p2z"));
        p2z->setGeometry(QRect(520, 80, 41, 23));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(390, 130, 16, 16));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(450, 130, 16, 16));
        p3y = new QLineEdit(centralWidget);
        p3y->setObjectName(QStringLiteral("p3y"));
        p3y->setGeometry(QRect(460, 130, 41, 23));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(390, 110, 61, 15));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(510, 130, 16, 16));
        p3x = new QLineEdit(centralWidget);
        p3x->setObjectName(QStringLiteral("p3x"));
        p3x->setGeometry(QRect(400, 130, 41, 23));
        p3z = new QLineEdit(centralWidget);
        p3z->setObjectName(QStringLiteral("p3z"));
        p3z->setGeometry(QRect(520, 130, 41, 23));
        Apply = new QPushButton(centralWidget);
        Apply->setObjectName(QStringLiteral("Apply"));
        Apply->setGeometry(QRect(390, 170, 171, 31));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "KG_TISHIN", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Approximation accuracy", Q_NULLPTR));
        isPolyFill->setText(QApplication::translate("MainWindow", "Fill polygons", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Light intensity", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "P1:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Z", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "P2:", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Z", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "P3:", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "Z", Q_NULLPTR));
        Apply->setText(QApplication::translate("MainWindow", "Apply", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
