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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QPushButton *BottomZ;
    QPushButton *TopZ;
    QPushButton *TopX;
    QPushButton *BottomX;
    QLabel *label_4;
    QPushButton *TopY;
    QPushButton *BottomY;
    QPushButton *TopK;
    QPushButton *BottomK;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(490, 304);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(30, 70, 256, 181));
        BottomZ = new QPushButton(centralWidget);
        BottomZ->setObjectName(QStringLiteral("BottomZ"));
        BottomZ->setGeometry(QRect(180, 40, 61, 23));
        TopZ = new QPushButton(centralWidget);
        TopZ->setObjectName(QStringLiteral("TopZ"));
        TopZ->setGeometry(QRect(240, 40, 71, 23));
        TopX = new QPushButton(centralWidget);
        TopX->setObjectName(QStringLiteral("TopX"));
        TopX->setGeometry(QRect(40, 20, 91, 23));
        BottomX = new QPushButton(centralWidget);
        BottomX->setObjectName(QStringLiteral("BottomX"));
        BottomX->setGeometry(QRect(40, 40, 91, 23));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 0, 141, 16));
        TopY = new QPushButton(centralWidget);
        TopY->setObjectName(QStringLiteral("TopY"));
        TopY->setGeometry(QRect(130, 40, 51, 23));
        BottomY = new QPushButton(centralWidget);
        BottomY->setObjectName(QStringLiteral("BottomY"));
        BottomY->setGeometry(QRect(130, 20, 51, 23));
        TopK = new QPushButton(centralWidget);
        TopK->setObjectName(QStringLiteral("TopK"));
        TopK->setGeometry(QRect(240, 20, 71, 23));
        BottomK = new QPushButton(centralWidget);
        BottomK->setObjectName(QStringLiteral("BottomK"));
        BottomK->setGeometry(QRect(180, 20, 61, 23));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Lab2", Q_NULLPTR));
        BottomZ->setText(QApplication::translate("MainWindow", "\320\262\320\273\320\265\320\262\320\276", Q_NULLPTR));
        TopZ->setText(QApplication::translate("MainWindow", "\320\262\320\277\321\200\320\260\320\262\320\276", Q_NULLPTR));
        TopX->setText(QApplication::translate("MainWindow", "\320\277\321\200\320\276\321\202\320\270\320\262 \321\207\320\260\321\201\320\276\320\262\320\276\320\271", Q_NULLPTR));
        BottomX->setText(QApplication::translate("MainWindow", "\320\277\320\276 \321\207\320\260\321\201\320\276\320\262\320\276\320\271", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\320\272\321\200\321\203\321\202\320\270\321\202\321\214", Q_NULLPTR));
        TopY->setText(QApplication::translate("MainWindow", "\320\262\320\275\320\270\320\267", Q_NULLPTR));
        BottomY->setText(QApplication::translate("MainWindow", "\320\262\320\262\320\265\321\200\321\205", Q_NULLPTR));
        TopK->setText(QApplication::translate("MainWindow", "\320\277\321\200\320\270\320\261\320\273\320\270\320\267\320\270\321\202\321\214", Q_NULLPTR));
        BottomK->setText(QApplication::translate("MainWindow", "\321\203\320\264\320\260\320\273\320\270\321\202\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
