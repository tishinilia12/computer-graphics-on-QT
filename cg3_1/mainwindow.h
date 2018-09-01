#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPen>
#include <QBrush>
#include <QTimer>
#include <vector>

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
class mytri{
public:
    myPoint c[3];
};

class myPara{
public:
    int mid,paral;
    myPoint l,r;
    std::vector<mytri>lA,rA;
    std::vector<std::vector<mySide>>A;
    std::vector<std::vector<myPoint>> B;
    myPara();
    void create();
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
    void Draw3D(int a,int b);
    void Draw3Dr(int a);
    void Draw3Dl(int a);
    void Configure(void);

    qreal FuncX(qreal t);
    qreal FuncY(qreal t);
    bool chekRob(int a,int b);
    bool chekRobl(int a);
    bool chekRobr(int a);
    void Print();
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
    void on_PushNew_clicked();

private:
    Ui::MainWindow *ui;
    QTimer ResizeTimer;
};

#endif // MAINWINDOW_H
