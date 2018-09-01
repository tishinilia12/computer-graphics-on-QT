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
    QPushButton *BottomX;
    QPushButton *TopX;
    QPushButton *TopY;
    QGraphicsView *graphicsView;
    QPushButton *BottomY;
    QPushButton *BottomK;
    QPushButton *BottomZ;
    QPushButton *TopK;
    QPushButton *TopZ;
    QLineEdit *median;
    QLineEdit *parallels;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *PushNew;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(520, 350);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        BottomX = new QPushButton(centralWidget);
        BottomX->setObjectName(QStringLiteral("BottomX"));
        BottomX->setGeometry(QRect(20, 40, 91, 23));
        TopX = new QPushButton(centralWidget);
        TopX->setObjectName(QStringLiteral("TopX"));
        TopX->setGeometry(QRect(20, 20, 91, 23));
        TopY = new QPushButton(centralWidget);
        TopY->setObjectName(QStringLiteral("TopY"));
        TopY->setGeometry(QRect(110, 40, 41, 23));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(30, 120, 256, 192));
        BottomY = new QPushButton(centralWidget);
        BottomY->setObjectName(QStringLiteral("BottomY"));
        BottomY->setGeometry(QRect(110, 20, 41, 23));
        BottomK = new QPushButton(centralWidget);
        BottomK->setObjectName(QStringLiteral("BottomK"));
        BottomK->setGeometry(QRect(150, 20, 71, 23));
        BottomZ = new QPushButton(centralWidget);
        BottomZ->setObjectName(QStringLiteral("BottomZ"));
        BottomZ->setGeometry(QRect(150, 40, 71, 23));
        TopK = new QPushButton(centralWidget);
        TopK->setObjectName(QStringLiteral("TopK"));
        TopK->setGeometry(QRect(220, 20, 71, 23));
        TopZ = new QPushButton(centralWidget);
        TopZ->setObjectName(QStringLiteral("TopZ"));
        TopZ->setGeometry(QRect(220, 40, 71, 23));
        median = new QLineEdit(centralWidget);
        median->setObjectName(QStringLiteral("median"));
        median->setGeometry(QRect(300, 40, 41, 20));
        parallels = new QLineEdit(centralWidget);
        parallels->setObjectName(QStringLiteral("parallels"));
        parallels->setGeometry(QRect(300, 20, 41, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 0, 47, 13));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(350, 40, 47, 13));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(350, 20, 61, 16));
        PushNew = new QPushButton(centralWidget);
        PushNew->setObjectName(QStringLiteral("PushNew"));
        PushNew->setGeometry(QRect(410, 20, 61, 23));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "lab3", Q_NULLPTR));
        BottomX->setText(QApplication::translate("MainWindow", "\320\277\320\276 \321\207\320\260\321\201\320\276\320\262\320\276\320\271", Q_NULLPTR));
        TopX->setText(QApplication::translate("MainWindow", "\320\277\321\200\320\276\321\202\320\270\320\262 \321\207\320\260\321\201\320\276\320\262\320\276\320\271", Q_NULLPTR));
        TopY->setText(QApplication::translate("MainWindow", "\320\262\320\275\320\270\320\267", Q_NULLPTR));
        BottomY->setText(QApplication::translate("MainWindow", "\320\262\320\262\320\265\321\200\321\205", Q_NULLPTR));
        BottomK->setText(QApplication::translate("MainWindow", "\321\203\320\264\320\260\320\273\320\270\321\202\321\214", Q_NULLPTR));
        BottomZ->setText(QApplication::translate("MainWindow", "\320\262\320\273\320\265\320\262\320\276", Q_NULLPTR));
        TopK->setText(QApplication::translate("MainWindow", "\320\277\321\200\320\270\320\261\320\273\320\270\320\267\320\270\321\202\321\214", Q_NULLPTR));
        TopZ->setText(QApplication::translate("MainWindow", "\320\262\320\277\321\200\320\260\320\262\320\276", Q_NULLPTR));
        median->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        parallels->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\320\272\321\200\321\203\321\202\320\270\321\202\321\214", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\320\274\320\265\320\264\320\270\320\260\320\275\321\213", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\320\277\320\260\321\200\320\260\320\273\320\273\320\265\320\273\320\270", Q_NULLPTR));
        PushNew->setText(QApplication::translate("MainWindow", "\320\276\320\261\320\275\320\276\320\262\320\270\321\202\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
