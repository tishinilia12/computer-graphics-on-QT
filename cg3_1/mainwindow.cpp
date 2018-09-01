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
const qreal STRETCH = .84;
const qreal STEP = .01;
qreal myFocus=3.0;
qreal pi=3.14159265359;

const int WINDOW_SPACE = 10;
const int TOP_SPACE = 70;

//norm
bool MainWindow::chekRob(int a,int b){
     mySide tmp = this->sqr.A[a][b];
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
bool MainWindow::chekRobl(int a){
     mytri tmp = this->sqr.lA[a];
     myPoint a_V;
     myPoint b_V;
     myPoint c_V;
     c_V.x=myFocus-tmp.c[0].x;
     c_V.y=-tmp.c[0].y;
     c_V.z=-tmp.c[0].z;
     a_V.x=tmp.c[1].x-tmp.c[0].x;
     a_V.y=tmp.c[1].y-tmp.c[0].y;
     a_V.z=tmp.c[1].z-tmp.c[0].z;
     b_V.x=tmp.c[2].x-tmp.c[0].x;
     b_V.y=tmp.c[2].y-tmp.c[0].y;
     b_V.z=tmp.c[2].z-tmp.c[0].z;

     qreal ans=c_V.x*(b_V.z*a_V.y-a_V.z*b_V.y)+
             c_V.y*(b_V.x*a_V.z-a_V.x*b_V.z)+
             c_V.z*(b_V.y*a_V.x-a_V.y*b_V.x);
     return ans<0;
}
bool MainWindow::chekRobr(int a){
     mytri tmp = this->sqr.rA[a];
     myPoint a_V;
     myPoint b_V;
     myPoint c_V;
     c_V.x=myFocus-tmp.c[0].x;
     c_V.y=-tmp.c[0].y;
     c_V.z=-tmp.c[0].z;
     a_V.x=tmp.c[1].x-tmp.c[0].x;
     a_V.y=tmp.c[1].y-tmp.c[0].y;
     a_V.z=tmp.c[1].z-tmp.c[0].z;
     b_V.x=tmp.c[2].x-tmp.c[0].x;
     b_V.y=tmp.c[2].y-tmp.c[0].y;
     b_V.z=tmp.c[2].z-tmp.c[0].z;

     qreal ans=c_V.x*(b_V.z*a_V.y-a_V.z*b_V.y)+
             c_V.y*(b_V.x*a_V.z-a_V.x*b_V.z)+
             c_V.z*(b_V.y*a_V.x-a_V.y*b_V.x);
     return ans<0;
}

//norm
myPara::myPara(){
    mid =3;
    paral=1;

}

//norm
void myPara::create(){
    l.x=1;
    l.y=0;
    l.z=0;
    r.y=0;
    r.x=-1;
    r.z=0;

    B.resize(paral);

    qreal sh=pi/((qreal)(paral+1));
    qreal ch=2*pi/((qreal)mid);
    qreal ish=sh;
    for(int i=0;i<paral;i++){
        B[i].resize(mid);
        qreal jsh=0.0;
        for(int j=0;j<mid;j++){
            B[i][j].x=cos(ish);
            B[i][j].y=sin(ish)*sin(jsh);
            B[i][j].z=sin(ish)*cos(jsh);
            jsh+=ch;
        }
        ish+=sh;
    }
}

//norm
void myPara::find(){
    lA.resize(B[0].size());
    rA.resize(B[0].size());
    A.resize(B.size()-1);
    for(size_t i=0;i<lA.size();i++){
        lA[i].c[0]=l;
        lA[i].c[1]=B[0][i];
        lA[i].c[2]=B[0][(i+1)%lA.size()];
    }
    for(size_t i=0;i<rA.size();i++){
        rA[i].c[0]=r;
        rA[i].c[2]=B[B.size()-1][i];
        rA[i].c[1]=B[B.size()-1][(i+1)%lA.size()];
    }
    for(size_t i=0;i<A.size();i++){
        A[i].resize(B[0].size());
        for(size_t j=0;j<B[0].size();j++){
            A[i][j].c[0]=B[i][j];
            A[i][j].c[1]=B[i+1][j];
            A[i][j].c[2]=B[i+1][(j+1)%B[0].size()];
            A[i][j].c[3]=B[i][(j+1)%B[0].size()];;
        }
    }

}

//norm
void myPara::Pow_X(qreal tmp){
    qreal zzz;
   for(size_t i=0;i<B.size();i++){
       for(size_t j=0;j<B[i].size();j++){
           zzz=B[i][j].y*cos(tmp)-B[i][j].z*sin(tmp);
           B[i][j].z=B[i][j].z*cos(tmp)+B[i][j].y*sin(tmp);
           B[i][j].y=zzz;
       }
   }
   zzz=r.y*cos(tmp)-r.z*sin(tmp);
   r.z=r.z*cos(tmp)+r.y*sin(tmp);
   r.y=zzz;
   zzz=l.y*cos(tmp)-l.z*sin(tmp);
   l.z=l.z*cos(tmp)+l.y*sin(tmp);
   l.y=zzz;

}
void myPara::Pow_Y(qreal tmp){
    qreal zzz;
    for(size_t i=0;i<B.size();i++){
        for(size_t j=0;j<B[i].size();j++){
            zzz=B[i][j].x*cos(tmp)+B[i][j].z*sin(tmp);
            B[i][j].z=B[i][j].z*cos(tmp)-B[i][j].x*sin(tmp);
            B[i][j].x=zzz;
        }
    }
    zzz=l.x*cos(tmp)+l.z*sin(tmp);
    l.z=l.z*cos(tmp)-l.x*sin(tmp);
    l.x=zzz;
    zzz=r.x*cos(tmp)+r.z*sin(tmp);
    r.z=r.z*cos(tmp)-r.x*sin(tmp);
    r.x=zzz;
}
void myPara::Pow_Z(qreal tmp){
    qreal zzz;
    for(size_t i=0;i<B.size();i++){
        for(size_t j=0;j<B[i].size();j++){
            zzz=B[i][j].y*cos(tmp)-B[i][j].x*sin(tmp);
            B[i][j].x=B[i][j].x*cos(tmp)+B[i][j].y*sin(tmp);
            B[i][j].y=zzz;
        }
    }

    zzz=r.y*cos(tmp)-r.x*sin(tmp);
    r.x=r.x*cos(tmp)+r.y*sin(tmp);
    r.y=zzz;
    zzz=l.y*cos(tmp)-l.x*sin(tmp);
    l.x=l.x*cos(tmp)+l.y*sin(tmp);
    l.y=zzz;
}

//norm
void MainWindow::Print(){
    ui->graphicsView->scene()->clear();
    this->sqr.find();
    for(size_t i=0;i<this->sqr.lA.size();i++){
        if(this->chekRobr(i))
            this->Draw3Dr(i);
        if(this->chekRobl(i))
            this->Draw3Dl(i);
    }
    for(size_t i=0;i<this->sqr.A.size();i++){
        for(size_t j=0;j<this->sqr.A[0].size();j++){
            if(this->chekRob(i,j))
                this->Draw3D(i,j);
        }
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    this->sqr.create();
    this->Configure();
    connect(&(this->ResizeTimer), SIGNAL(timeout()), this, SLOT(ResizeCheck()));
    this->ResizeTimer.start();
    this->Print();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//norm
void MainWindow::Draw3Dl(int a) {
    QGraphicsScene *scene = ui->graphicsView->scene();

    qreal x[3];
    qreal y[3];

    for(int i=0;i<3;i++){
        qreal c=-1.0/(this->sqr.lA[a].c[i].x-myFocus)*(this->sqr.lA[a].c[i].y);
        qreal c1=-1.0/(this->sqr.lA[a].c[i].x-myFocus)*(this->sqr.lA[a].c[i].z);
        x[i]=c* STRETCH * ui->graphicsView->height();
        y[i]=c1* STRETCH * ui->graphicsView->height();
    }
    QPolygon polygon1;

    qreal shift_x = this->GraphParams.basis_x;
    qreal shift_y = this->GraphParams.basis_y;

    polygon1 << QPoint(x[0] + shift_x, y[0] + shift_y)
            << QPoint(x[1] + shift_x, y[1] + shift_y)
            << QPoint(x[2] + shift_x, y[2] + shift_y);
    scene->addPolygon(polygon1,this->GraphParams.Pen,this->GraphParams.Brush);
}
void MainWindow::Draw3Dr(int a) {
    QGraphicsScene *scene = ui->graphicsView->scene();

    qreal x[3];
    qreal y[3];

    for(int i=0;i<3;i++){
        qreal c=-1.0/(this->sqr.rA[a].c[i].x-myFocus)*(this->sqr.rA[a].c[i].y);
        qreal c1=-1.0/(this->sqr.rA[a].c[i].x-myFocus)*(this->sqr.rA[a].c[i].z);
        x[i]=c* STRETCH * ui->graphicsView->height();
        y[i]=c1* STRETCH * ui->graphicsView->height();
    }
    QPolygon polygon1;

    qreal shift_x = this->GraphParams.basis_x;
    qreal shift_y = this->GraphParams.basis_y;

    polygon1 << QPoint(x[0] + shift_x, y[0] + shift_y)
            << QPoint(x[1] + shift_x, y[1] + shift_y)
            << QPoint(x[2] + shift_x, y[2] + shift_y);
    scene->addPolygon(polygon1,this->GraphParams.Pen,this->GraphParams.Brush);
}
void MainWindow::Draw3D(int a,int b) {
    QGraphicsScene *scene = ui->graphicsView->scene();

    qreal x[4];
    qreal y[4];

    for(int i=0;i<4;i++){
        qreal c=-1.0/(this->sqr.A[a][b].c[i].x-myFocus)*(this->sqr.A[a][b].c[i].y);
        qreal c1=-1.0/(this->sqr.A[a][b].c[i].x-myFocus)*(this->sqr.A[a][b].c[i].z);
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

//norm
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
    this->Print();
}
//norm
void MainWindow::ResizeCheck(void) {
    if (this->width() != this->LastWidth || this->height() != this->LastHeight) {
        this->Configure();
    }
}

//norm
void MainWindow::on_BottomZ_clicked()
{
    this->sqr.Pow_Z(0.1);
    this->Print();
}
void MainWindow::on_BottomK_clicked()
{
    myFocus+=0.5;
    this->Print();
}
void MainWindow::on_BottomY_clicked()
{

    this->sqr.Pow_Y(0.1);
    this->Print();
}
void MainWindow::on_BottomX_clicked()
{

    this->sqr.Pow_X(0.1);
    this->Print();
}
void MainWindow::on_TopZ_clicked()
{
    this->sqr.Pow_Z(-0.1);
    this->Print();
}
void MainWindow::on_TopY_clicked()
{
    this->sqr.Pow_Y(-0.1);
    this->Print();
}
void MainWindow::on_TopX_clicked()
{

    this->sqr.Pow_X(-0.1);
    this->Print();
}
void MainWindow::on_TopK_clicked()


{
    myFocus-=0.5;
    this->Print();
}
void MainWindow::on_PushNew_clicked()
{
    if(ui->median->text().length() == 0 || ui->parallels->text().length() == 0  ){
        return;
    }
    this->sqr.mid=ui->median->text().toInt();
    this->sqr.paral=ui->parallels->text().toInt();
    this->sqr.create();
    this->Print();
}

