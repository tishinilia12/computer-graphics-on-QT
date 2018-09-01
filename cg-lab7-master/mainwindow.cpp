#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>
#include <QGraphicsScene>
#include <QBrush>
#include <QPen>
#include <cmath>
#include <qmath.h>
#include <QDebug>
#include <QRect>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>

const qreal PARAM = 2.;
const qreal CONST_A = -.5;
const qreal CONST_B = 30.;
const qreal STRETCH = .004;
const qreal STEP = .01;
int m=3;
int n=6;
const qreal RELATIVE_WIDTH = 200.;
const qreal RELATIVE_HEIGHT = 100.;

const int POINT_RADIUS = 3;

const int WINDOW_SPACE = 10;
const int TOP_SPACE = 60;



GraphicsData::GraphicsData() {
    this->Points.resize(0);
}

void GraphicsData::Add(QPoint point) {
        this->Points.push_back(point);
}



void GraphicsData::Clear(void) {
    this->Points.resize(0);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    this->GraphData.MyMin.resize(10);
    for(int i=0;i<m;i++){
        this->GraphData.MyMin[i]=0;
    }
    for(int i=m;i<=n+m;i++){
        this->GraphData.MyMin[i]=1.0/((qreal)n)*((qreal)(i-m));
    }
    ui->setupUi(this);

    //this->GraphParams.SetParams = false;
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    this->Configure();
    connect(&(this->ResizeTimer), SIGNAL(timeout()), this, SLOT(ResizeCheck()));
    this->ResizeTimer.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DrawBasis(void) {
    QGraphicsScene *scene = ui->graphicsView->scene();
    QPen pen(Qt::gray);
    qreal basis[2] = {this->GraphParams.basis_x, this->GraphParams.basis_y};
    QLineF line_x(0, basis[1], scene->width() - 1, basis[1]);
    QLineF line_y(basis[0], 0, basis[0], scene->height() - 1);

    scene->addLine(line_x, pen);
    scene->addLine(line_y, pen);
}

int MainWindow::GetCurrWidth(void) {
    //qDebug() << "CurrWidth = " << this->GraphParams.basis_x * 2;
    //return this->GraphParams.basis_x * 2;
    return ui->graphicsView->width();
}

int MainWindow::GetCurrHeight(void) {
    //qDebug() << "CurrHeight = " << this->GraphParams.basis_y * 2;
    //return this->GraphParams.basis_y * 2;
    return ui->graphicsView->height();
}

int MainWindow::TransformToAbsoluteX(int x) {
    return x + this->GraphParams.basis_x;
}

int MainWindow::TransformToAbsoluteY(int y) {
    y = -y;
    return y + this->GraphParams.basis_y;
}


void MainWindow::DrawGraph(void) {
    QGraphicsScene *scene = ui->graphicsView->scene();
    qreal x[2];
    qreal y[2];
    if (this->GraphData.Points.size() >= 3) {
        DrawPointsFromData();
        DrawBesier();
    }
    //scene->add
}

void MainWindow::DrawPoint(QPoint pnt) {
    int x = pnt.x();
    int y = pnt.y();
    y = -y;
    QGraphicsScene *scene = ui->graphicsView->scene();
    int rect_x = x + this->GraphParams.basis_x - POINT_RADIUS;
    int rect_y = y + this->GraphParams.basis_y - POINT_RADIUS;
    int side = POINT_RADIUS * 2;

    scene->addEllipse(rect_x, rect_y, side, side, this->GraphParams.Pen, this->GraphParams.Brush);
}

void MainWindow::DrawPointsFromData(void) {
    QGraphicsScene *scene = ui->graphicsView->scene();
    for (int i = 0; i < this->GraphData.Points.size(); i++) {
        QPoint curr = this->GraphData.Points[i];
        DrawPoint(curr);
        //DrawPoint(QPoint(TransformToAbsoluteX(curr.x()), TransformToAbsoluteY(curr.y())));
        /*if (i > 0) {
            QPoint prev = this->GraphData.Points[i - 1];
            QLineF line(TransformToAbsoluteX(prev.x()), TransformToAbsoluteY(prev.y()), TransformToAbsoluteX(curr.x()), TransformToAbsoluteY(curr.y()));
            scene->addLine(line, this->GraphParams.Pen);
        }*/
    }
}

qreal MainWindow::Nfun(int i,int m,qreal t){
    if(m==1){
        if(t<this->GraphData.MyMin[i+1]
           &&t>=this->GraphData.MyMin[i]){
            return 1.0/(this->GraphData.MyMin[i+1]-this->GraphData.MyMin[i]);
        }
        return 0.0;
    }
    if(this->GraphData.MyMin[i+m]-this->GraphData.MyMin[i]<0.0000001)
            return 0;
    return ((this->GraphData.MyMin[i+m]-t)*Nfun(i+1,m-1,t)+(t-this->GraphData.MyMin[i])*Nfun(i,m-1,t))
            /(this->GraphData.MyMin[i+m]-this->GraphData.MyMin[i]);
}
qreal MainWindow::FuncX(qreal t) {
    qreal x[6];
    for(int i=0;i<6;i++){
        x[i]=(qreal) this->GraphData.Points[i].x();
    }
    qreal Sum=0;
    qreal Sum1=0;
    for(int i=0;i<6;i++){
        Sum+=Nfun(i+1,3,t)*x[i]*this->GraphData.W[i];
        Sum1+=Nfun(i+1,3,t)*this->GraphData.W[i];
    }
    return Sum/Sum1;
}

qreal MainWindow::FuncY(qreal t) {
    qreal y[6];
    for(int i=0;i<6;i++){
        y[i]=(qreal) this->GraphData.Points[i].y();
    }
    qreal Sum=0;
    qreal Sum1=0;
    for(int i=0;i<6;i++){
        Sum+=Nfun(i+1,3,t)*y[i]*this->GraphData.W[i];
        Sum1+=Nfun(i+1,3,t)*this->GraphData.W[i];
    }
    return Sum/Sum1;
}

void MainWindow::DrawBesier(void) {
    QGraphicsScene *scene = ui->graphicsView->scene();
    qreal last_value_x = 0.;
    qreal last_value_y = 0.;
    bool first = true;
    for (qreal t = 0; t <= 1.; t += STEP) {
        if (first) {
            first = false;
            last_value_x = FuncX(t);
            last_value_y = FuncY(t);
            continue;
        }
        qreal curr_value_x = FuncX(t);
        qreal curr_value_y = FuncY(t);
        QLineF line(TransformToAbsoluteX(curr_value_x), TransformToAbsoluteY(curr_value_y),
                    TransformToAbsoluteX(last_value_x), TransformToAbsoluteY(last_value_y));
        scene->addLine(line, QPen(Qt::red));
        last_value_x = curr_value_x;
        last_value_y = curr_value_y;
    }
}

void MainWindow::Configure(void) {
    this->LastWidth = this->width();
    this->LastHeight = this->height();

    ui->graphicsView->setGeometry(WINDOW_SPACE, WINDOW_SPACE + TOP_SPACE*3/2, this->width() - 2 * WINDOW_SPACE, this->height() - 2 * WINDOW_SPACE - TOP_SPACE*3/2);
    /*QRect geom_tmp = (ui->Label1->geometry());
    geom_tmp.setY(this->height() - 30);
    ui->Label1->setGeometry(geom_tmp);*/
    //ui->Label1->setGeometry(ui->Label1->geo);
    QGraphicsScene *scene = ui->graphicsView->scene();
    scene->clear();
    scene->setSceneRect(0, 0, ui->graphicsView->width() - 2, ui->graphicsView->height() - 2);
    this->GraphParams.Pen.setColor(Qt::black);
    this->GraphParams.Brush = QBrush(Qt::black);
    this->GraphParams.basis_x = scene->width() / 2;
    this->GraphParams.basis_y = scene->height() / 2;
    this->DrawBasis();
    /*if (this->GraphParams.SetParams) {
        this->DrawGraph();
    }*/
    this->DrawGraph();
}
void MainWindow::ResizeCheck(void) {
    if (this->width() != this->LastWidth || this->height() != this->LastHeight) {
        this->Configure();
    }
}

//void MainWindow::mousePressEvent(QGraphicsSceneMouseEvent *event) {
/*void MainWindow::mousePressEvent(QMouseEvent *event) {
    qDebug() << "Press";
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    qDebug() << "Move";
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
    qDebug() << "Release";
}

void QGraphicsView::mousePressEvent(QMouseEvent *event) {
    qDebug() << "Press";
}

void QGraphicsView::mouseMoveEvent(QMouseEvent *event) {
    qDebug() << "Move";
}

void QGraphicsView::mouseReleaseEvent(QMouseEvent *event) {
    qDebug() << "Release";
}*/

void MainWindow::on_Apply_clicked()
{
    QPoint p1(ui->x1->text().toInt(), ui->y1->text().toInt());
    QPoint p2(ui->x2->text().toInt(), ui->y2->text().toInt());
    QPoint p3(ui->x3->text().toInt(), ui->y3->text().toInt());
    QPoint p4(ui->x4->text().toInt(), ui->y4->text().toInt());
    QPoint p5(ui->x5->text().toInt(), ui->y5->text().toInt());
    QPoint p6(ui->x6->text().toInt(), ui->y6->text().toInt());


    GraphData.Clear();
    GraphData.Add(p1);
    GraphData.Add(p2);
    GraphData.Add(p3);
    GraphData.Add(p4);
    GraphData.Add(p5);
    GraphData.Add(p6);

    GraphData.W.clear();
    GraphData.W.push_back(ui->w1->text().toFloat());
    GraphData.W.push_back(ui->w2->text().toFloat());
    GraphData.W.push_back(ui->w3->text().toFloat());
    GraphData.W.push_back(ui->w4->text().toFloat());
    GraphData.W.push_back(ui->w5->text().toFloat());
    GraphData.W.push_back(ui->w6->text().toFloat());

    this->Configure();
    //ui->graphicsView->scene()->clear()
}
