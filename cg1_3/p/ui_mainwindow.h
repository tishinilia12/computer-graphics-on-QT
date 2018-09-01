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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QLineEdit *ParamLeft;
    QLabel *Label3;
    QLineEdit *ParamRight;
    QLabel *Label2;
    QLabel *Label1;
    QLineEdit *ParamA;
    QPushButton *ApplyParams;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(401, 335);
        MainWindow->setMinimumSize(QSize(310, 150));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 100, 381, 221));
        ParamLeft = new QLineEdit(centralWidget);
        ParamLeft->setObjectName(QStringLiteral("ParamLeft"));
        ParamLeft->setGeometry(QRect(89, 10, 31, 23));
        Label3 = new QLabel(centralWidget);
        Label3->setObjectName(QStringLiteral("Label3"));
        Label3->setGeometry(QRect(129, 10, 16, 16));
        ParamRight = new QLineEdit(centralWidget);
        ParamRight->setObjectName(QStringLiteral("ParamRight"));
        ParamRight->setGeometry(QRect(149, 10, 31, 23));
        Label2 = new QLabel(centralWidget);
        Label2->setObjectName(QStringLiteral("Label2"));
        Label2->setGeometry(QRect(69, 10, 16, 16));
        Label1 = new QLabel(centralWidget);
        Label1->setObjectName(QStringLiteral("Label1"));
        Label1->setGeometry(QRect(9, 10, 16, 16));
        ParamA = new QLineEdit(centralWidget);
        ParamA->setObjectName(QStringLiteral("ParamA"));
        ParamA->setGeometry(QRect(29, 10, 31, 23));
        ApplyParams = new QPushButton(centralWidget);
        ApplyParams->setObjectName(QStringLiteral("ApplyParams"));
        ApplyParams->setGeometry(QRect(190, 10, 111, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 211, 41));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ilysha lab1(15)", Q_NULLPTR));
        Label3->setText(QApplication::translate("MainWindow", "B:", Q_NULLPTR));
        Label2->setText(QApplication::translate("MainWindow", "A:", Q_NULLPTR));
        Label1->setText(QApplication::translate("MainWindow", "a:", Q_NULLPTR));
        ApplyParams->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "r=(a*cos(2*t))/cos(t)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
