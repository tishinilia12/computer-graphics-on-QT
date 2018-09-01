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
    QSlider *SliderHeight;
    QLabel *label_2;
    QSlider *SliderDiameter;
    QLabel *label_3;
    QLabel *label_4;
    QSlider *SliderApproximation;
    QCheckBox *isPolyFill;
    QPushButton *animationControl;
    QLabel *label_5;
    QSlider *SliderLight;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(552, 312);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new GLWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 351, 331));
        SliderHeight = new QSlider(centralWidget);
        SliderHeight->setObjectName(QStringLiteral("SliderHeight"));
        SliderHeight->setGeometry(QRect(370, 30, 171, 20));
        SliderHeight->setValue(50);
        SliderHeight->setOrientation(Qt::Horizontal);
        SliderHeight->setTickPosition(QSlider::NoTicks);
        SliderHeight->setTickInterval(0);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(370, 10, 81, 16));
        SliderDiameter = new QSlider(centralWidget);
        SliderDiameter->setObjectName(QStringLiteral("SliderDiameter"));
        SliderDiameter->setGeometry(QRect(370, 80, 171, 20));
        SliderDiameter->setValue(50);
        SliderDiameter->setOrientation(Qt::Horizontal);
        SliderDiameter->setTickPosition(QSlider::NoTicks);
        SliderDiameter->setTickInterval(0);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(370, 60, 81, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(370, 110, 171, 16));
        SliderApproximation = new QSlider(centralWidget);
        SliderApproximation->setObjectName(QStringLiteral("SliderApproximation"));
        SliderApproximation->setGeometry(QRect(370, 130, 171, 20));
        SliderApproximation->setValue(50);
        SliderApproximation->setOrientation(Qt::Horizontal);
        SliderApproximation->setTickPosition(QSlider::NoTicks);
        SliderApproximation->setTickInterval(0);
        isPolyFill = new QCheckBox(centralWidget);
        isPolyFill->setObjectName(QStringLiteral("isPolyFill"));
        isPolyFill->setGeometry(QRect(370, 200, 171, 21));
        animationControl = new QPushButton(centralWidget);
        animationControl->setObjectName(QStringLiteral("animationControl"));
        animationControl->setGeometry(QRect(370, 250, 171, 31));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(370, 150, 171, 16));
        SliderLight = new QSlider(centralWidget);
        SliderLight->setObjectName(QStringLiteral("SliderLight"));
        SliderLight->setGeometry(QRect(370, 170, 171, 20));
        SliderLight->setValue(50);
        SliderLight->setOrientation(Qt::Horizontal);
        SliderLight->setTickPosition(QSlider::NoTicks);
        SliderLight->setTickInterval(0);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\201\320\276\321\202\320\260", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\320\224\320\270\320\260\320\274\320\265\321\202\321\200", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214 \320\260\320\277\320\277\321\200\320\276\320\272\321\201\320\270\320\274\320\260\321\206\320\270\320\270", Q_NULLPTR));
        isPolyFill->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\320\260\321\201\320\270\321\202\321\214 \320\277\320\276\320\273\320\270\320\263\320\276\320\275\321\213", Q_NULLPTR));
        animationControl->setText(QApplication::translate("MainWindow", "Start animation", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\320\230\320\275\321\202\320\265\320\275\321\201\320\270\320\262\320\275\320\276\321\201\321\202\321\214 \321\201\320\262\320\265\321\202\320\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
