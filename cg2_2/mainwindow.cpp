#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPolygonItem>
#include <QBrush>
#include <QPen>
#include <cmath>
#include <QDebug>
#include <QRect>
#include <QPolygon>
#include <QPoint>
#include <QWidget>

const qreal PARAM = 2.;
const qreal CONST_A = -.5;
const qreal CONST_B = 30.;
const qreal STRETCH = .54;
const qreal STEP = .01;
qreal myFocus=3.0;

const int WINDOW_SPACE = 10;
const int TOP_SPACE = 70;

bool MainWindow::chekRob(int a){
     mySide tmp = this->sqr.a[a];
     myPoint a_V;
     myPoint b_V;
     myPoint c_V;
     c_V.x=myFocus-tmp.c[0].x;
     c_V.y=-tmp.c[0].y;
     c_V.z=-tmp.c[0].z;
     a_V.x=tmp.c[1].x-tmp.c[0].x;
     a_V.y=tmp.c[1].y-tmp.c[0].y;
     a_V.z=tmp.c[1].z-tmp.c[0].z;
     b_V.x=tmp.c[3].x-tmp.c[0].x;
     b_V.y=tmp.c[3].y-tmp.c[0].y;
     b_V.z=tmp.c[3].z-tmp.c[0].z;

     qreal ans=c_V.x*(b_V.z*a_V.y-a_V.z*b_V.y)+
             c_V.y*(b_V.x*a_V.z-a_V.x*b_V.z)+
             c_V.z*(b_V.y*a_V.x-a_V.y*b_V.x);
     return ans<0;
}

myPara::myPara(){
    b[0].x=-1;
    b[0].y=0;
    b[0].z=-1;
    b[1].x=1;
    b[1].y=0;
    b[1].z=-1;
    b[2].x=-1;
    b[2].y=1;
    b[2].z=-1;
    b[3].x=1;
    b[3].y=1;
    b[3].z=-1;
    b[4].x=-1;
    b[4].y=1;
    b[4].z=1;
    b[5].x=1;
    b[5].y=1;
    b[5].z=1;
    b[6].x=-1;
    b[6].y=0;
    b[6].z=1;
    b[7].x=1;
    b[7].y=0;
    b[7].z=1;
}
void myPara::find(){
    for(int i=0;i<4;i++){
        a[i].c[0]=b[2*i];
        a[i].c[1]=b[2*i+1];
        a[i].c[2]=b[(2*i+3)%8];
        a[i].c[3]=b[(2*i+2)%8];
    }
    a[4].c[0]=b[6];
    a[4].c[1]=b[0];
    a[4].c[2]=b[2];
    a[4].c[3]=b[4];

    a[5].c[0]=b[1];
    a[5].c[1]=b[7];
    a[5].c[2]=b[5];
    a[5].c[3]=b[3];
}
void myPara::Pow_X(qreal tmp){
    qreal zzz;
   for(int i=0;i<8;i++){
       zzz=b[i].y*cos(tmp)-b[i].z*sin(tmp);
       b[i].z=b[i].z*cos(tmp)+b[i].y*sin(tmp);
       b[i].y=zzz;
   }
}
void myPara::Pow_Y(qreal tmp){
    qreal zzz;
    for(int i=0;i<8;i++){
        zzz=b[i].x*cos(tmp)+b[i].z*sin(tmp);
        b[i].z=b[i].z*cos(tmp)-b[i].x*sin(tmp);
        b[i].x=zzz;
    }
}
void myPara::Pow_Z(qreal tmp){
    qreal zzz;
    for(int i=0;i<8;i++){
        zzz=b[i].y*cos(tmp)-b[i].x*sin(tmp);
        b[i].x=b[i].x*cos(tmp)+b[i].y*sin(tmp);
        b[i].y=zzz;
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    this->Configure();
    connect(&(this->ResizeTimer), SIGNAL(timeout()), this, SLOT(ResizeCheck()));
    this->ResizeTimer.start();
    this->sqr.find();
    for(int i=0;i<6;i++){
        if(this->chekRob(i))
        this->Draw3D(i);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Draw3D(int a) {
    QGraphicsScene *scene = ui->graphicsView->scene();

    qreal x[4];
    qreal y[4];

    for(int i=0;i<4;i++){
        qreal c=-1.0/(this->sqr.a[a].c[i].x-myFocus)*(this->sqr.a[a].c[i].y);
        qreal c1=-1.0/(this->sqr.a[a].c[i].x-myFocus)*(this->sqr.a[a].c[i].z);
        x[i]=c* STRETCH * ui->graphicsView->height();
        y[i]=c1* STRETCH * ui->graphicsView->height();
    }
    QPolygon polygon1;

    qreal shift_x = this->GraphParams.basis_x;
    qreal shift_y = this->GraphParams.basis_y;

    polygon1 << QPoint(x[0] + shift_x, y[0] + shift_y)
            << QPoint(x[1] + shift_x, y[1] + shift_y)
            << QPoint(x[2] + shift_x, y[2] + shift_y)
            << QPoint(x[3] + shift_x, y[3] + shift_y);
    scene->addPolygon(polygon1,this->GraphParams.Pen,this->GraphParams.Brush);
}


void MainWindow::Configure(void) {
    this->LastWidth = this->width();
    this->LastHeight = this->height();

    ui->graphicsView->setGeometry(WINDOW_SPACE, WINDOW_SPACE + TOP_SPACE, this->width() - 2 * WINDOW_SPACE, this->height() - 2 * WINDOW_SPACE - TOP_SPACE);
    QGraphicsScene *scene = ui->graphicsView->scene();
    scene->clear();
    scene->setSceneRect(0, 0, ui->graphicsView->width() - 2, ui->graphicsView->height() - 2);
    this->GraphParams.Pen.setColor(Qt::black);
    this->GraphParams.Brush.setColor(Qt::red);
    this->GraphParams.Brush.setStyle(Qt::SolidPattern);
    this->GraphParams.basis_x = scene->width() / 2;
    this->GraphParams.basis_y = scene->height() / 2;
    this->sqr.find();
        for(int i=0;i<6;i++)
            if(this->chekRob(i))
                this->Draw3D(i);
}
void MainWindow::ResizeCheck(void) {
    if (this->width() != this->LastWidth || this->height() != this->LastHeight) {
        this->Configure();
    }
}

void MainWindow::on_BottomZ_clicked()
{
    this->sqr.Pow_Z(0.1);
    this->sqr.find();
    ui->graphicsView->scene()->clear();
    for(int i=0;i<6;i++)
        if(this->chekRob(i))
        this->Draw3D(i);
}
void MainWindow::on_BottomK_clicked()
{
    myFocus+=0.5;
    this->sqr.find();
    ui->graphicsView->scene()->clear();
    for(int i=0;i<6;i++)
        if(this->chekRob(i))
        this->Draw3D(i);
}
void MainWindow::on_BottomY_clicked()
{

    this->sqr.Pow_Y(0.1);
    this->sqr.find();
    ui->graphicsView->scene()->clear();
    for(int i=0;i<6;i++)
        if(this->chekRob(i))
        this->Draw3D(i);
}
void MainWindow::on_BottomX_clicked()
{

    this->sqr.Pow_X(0.1);
    this->sqr.find();
    ui->graphicsView->scene()->clear();
    for(int i=0;i<6;i++)
        if(this->chekRob(i))
        this->Draw3D(i);
}
void MainWindow::on_TopZ_clicked()
{
    this->sqr.Pow_Z(-0.1);
    this->sqr.find();
    ui->graphicsView->scene()->clear();
    for(int i=0;i<6;i++)
        if(this->chekRob(i))
        this->Draw3D(i);
}
void MainWindow::on_TopY_clicked()
{
    this->sqr.Pow_Y(-0.1);
    this->sqr.find();
    ui->graphicsView->scene()->clear();
    for(int i=0;i<6;i++)
        if(this->chekRob(i))
        this->Draw3D(i);
}
void MainWindow::on_TopX_clicked()
{

    this->sqr.Pow_X(-0.1);
    this->sqr.find();
    ui->graphicsView->scene()->clear();
    for(int i=0;i<6;i++)
        if(this->chekRob(i))
        this->Draw3D(i);
}
void MainWindow::on_TopK_clicked()
{
    myFocus-=0.5;
    this->sqr.find();
    ui->graphicsView->scene()->clear();
    for(int i=0;i<6;i++)
        if(this->chekRob(i))
        this->Draw3D(i);
}
