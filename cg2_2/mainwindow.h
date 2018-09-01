#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPen>
#include <QBrush>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class myPoint{
public:
    qreal x,y,z;
};

class mySide{
public:
    myPoint c[4];
};

class myPara{
public:
    mySide a[6];
    myPoint b[8];
    myPara();
    void find();
    void Pow_X(qreal tmp);
    void Pow_Y(qreal tmp);
    void Pow_Z(qreal tmp);
};

class GraphicsParams {
public:
    QPen Pen;
    QBrush Brush;
    qreal basis_x;
    qreal basis_y;
    qreal Param;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    myPara sqr;
    GraphicsParams GraphParams;
    int LastWidth;
    int LastHeight;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void Draw3D(int a);
    void Configure(void);

    qreal FuncX(qreal t);
    qreal FuncY(qreal t);
    bool chekRob(int a);
public slots:
    void ResizeCheck(void);

private slots:
    void on_BottomZ_clicked();
    void on_BottomX_clicked();
    void on_BottomY_clicked();
    void on_TopZ_clicked();
    void on_TopX_clicked();
    void on_TopY_clicked();
    void on_BottomK_clicked();
    void on_TopK_clicked();

private:
    Ui::MainWindow *ui;
    QTimer ResizeTimer;
};

#endif // MAINWINDOW_H
