#include "glwidget.h"
#include <QtCore/qmath.h>
#include <QVector3D>
#include <QDebug>
#include <qmath.h>
#include <QMouseEvent>

const double LARGE_SIDE = 1.6;
const qreal GL_PI = 3.1415926;

//scale height diameter approximation
const qreal SCALE_MIN = .2;
const qreal SCALE_MAX = 3.;
const qreal HEIGHT_MIN = .5;
const qreal HEIGHT_MAX = 20.;
const qreal DIAMETER_MIN = 1;
const qreal DIAMETER_MAX = 5;
const int APPROXIMATION_MIN = 4.;
const int APPROXIMATION_MAX = 60.;
const qreal LIGHT_MIN = .5;
const qreal LIGHT_MAX = 5.;

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    resize(300,300);
    xRotation = 0;
    yRotation = 0;
    zRotation = 0;
    scale = 2;//чёто с размером
    Approximation = 5;
    functionLen = 4;
    heightParam = 5.;
}

void GLWidget::initializeGL() {
    qglClearColor(Qt::white);
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
    glShadeModel(GL_FLAT);
    glEnable(GL_CULL_FACE);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glEnable (GL_BLEND);
    //glEnable(GL_DIFFUSE);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //fillCoordinateMatrix();

    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glEnable(GL_NORMALIZE);
}

void GLWidget::drawParaboloide() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();

    glScalef(scale, scale, scale);// маштаб
    glRotatef(xRotation, 1.0f, 0.0f, 0.0f);
    glRotatef(yRotation, 0.0f, 1.0f, 0.0f);
    glRotatef(zRotation, 0.0f, 0.0f, 1.0f);
    float ambient[4] = {0.5, 0.5, 0.5, 1};

    //QColor clr(0, 64, 128, (int) qAbs(255 * qCos(currentTimeValue)));//механика
    QColor clr(0, 64, 128, 128);
    //QColor clr(0, 64, 128, 127);
    //QColor clr_lines(0, 0, 0, 255);
    qglColor(clr);

    /*glBegin(GL_LINE_LOOP);
    glVertex3f(0., 0., 0.);
    glVertex3f(.1, .1, .1);
    glEnd();*/

    currentScale = .3;
    qreal stepRotate = 2 * GL_PI / Approximation;
    qreal stepFunction = GL_PI / Approximation;
    qreal halfLen = GL_PI;

    for (qreal current = 0.; current < 2. * GL_PI; current += stepRotate) {
        qreal i;
        for (i = 0.; i < halfLen; i += stepFunction) {
            if (!polyFillStatus) {
                glBegin(GL_LINE_LOOP);
            } else {
                glBegin(GL_POLYGON);
            }
            qDebug() << current << " " << i;
            QVector3D currentPoly[4];
            currentPoly[3] = getVector(i, current,currentTimeValue);
            currentPoly[2] = getVector(i + stepFunction, current,currentTimeValue);
            currentPoly[1] = getVector(i + stepFunction, current + stepRotate,currentTimeValue);
            currentPoly[0] = getVector(i, current + stepRotate,currentTimeValue);
            glVertex3f(currentPoly[0].x(), currentPoly[0].y(), currentPoly[0].z());
            glVertex3f(currentPoly[1].x(), currentPoly[1].y(), currentPoly[1].z());
            glVertex3f(currentPoly[2].x(), currentPoly[2].y(), currentPoly[2].z());
            glVertex3f(currentPoly[3].x(), currentPoly[3].y(), currentPoly[3].z());
            glEnd();
        }
    }
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);

}

void GLWidget::paintGL() {
    //drawPiramide();
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);

    float ambience[4] = {0.3f, 0.3f, 0.3f, 1.0};//СѓСЃС‚Р°РЅРѕРІРєР° "РјРёСЂРѕРІРѕРіРѕ" СЃРІРµС‚Р°, РєРѕРіРґР° РјС‹ РЅРµ Р·Р°РґР°РµРј РґСЂСѓРіРѕРµ РѕСЃРІРµС‰РµРЅРёРµ
    glLightfv( GL_LIGHT0, GL_AMBIENT,  ambience);
    GLfloat light0_diffuse[] = {lightIntensity, lightIntensity, lightIntensity};
    GLfloat light0_direction[] = {lightIntensity, lightIntensity, 0.};

    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_direction);

    drawParaboloide();
    /*GLfloat light0_position[] = { 3.0, 3.0, 3.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);*/
}

void GLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void GLWidget::mousePressEvent(QMouseEvent* pe)
{
    mousePos = pe->pos();
}

void GLWidget::mouseMoveEvent(QMouseEvent* pe)
{
    xRotation += (pe->y() - mousePos.y()) * 1.1 * GL_PI / 180;
    zRotation += (pe->x() - mousePos.x()) * 1.1 * GL_PI / 180;

    updateGL();
}

void GLWidget::mouseReleaseEvent(QMouseEvent *pe)
{
}

void GLWidget::setScalePercent(int percent) {
    qreal diff = SCALE_MAX - SCALE_MIN;
    qreal one_perc = diff / 100;
    scale = SCALE_MIN + one_perc * percent;

    updateGL();
}

void GLWidget::setHeightPercent(int percent) {
    qreal diff = HEIGHT_MAX - HEIGHT_MIN;
    qreal one_perc = diff / 100;
    heightParam = HEIGHT_MIN + one_perc * percent;

    updateGL();
}

void GLWidget::setDiameterPercent(int percent) {
    qreal diff = DIAMETER_MAX - DIAMETER_MIN;
    qreal one_perc = diff / 100;
    functionLen = DIAMETER_MIN + one_perc * percent;

    updateGL();
}

void GLWidget::setApproximationPercent(int percent) {
    qreal diff = APPROXIMATION_MAX - APPROXIMATION_MIN;
    qreal one_perc = diff / 100;
    Approximation = APPROXIMATION_MIN + one_perc * percent;

    updateGL();
}

void GLWidget::setLightPercent(int percent) {
    qreal diff = LIGHT_MAX - LIGHT_MIN;
    qreal one_perc = diff / 100;
    lightIntensity = LIGHT_MIN + one_perc * percent;

    updateGL();
}

void GLWidget::setPolyFillState(bool status) {
    polyFillStatus = status;

    updateGL();
}

void GLWidget::drawAxis()
{
    glLineWidth(3.0f);

    glColor4f(1.00f, 0.00f, 0.00f, 1.0f);
    glBegin(GL_LINES);
        glVertex3f( 1.0f,  0.0f,  0.0f);
        glVertex3f(-1.0f,  0.0f,  0.0f);
    glEnd();

    QColor halfGreen(0, 128, 0, 255);
    qglColor(halfGreen);
    glBegin(GL_LINES);
        glVertex3f( 0.0f,  1.0f,  0.0f);
        glVertex3f( 0.0f, -1.0f,  0.0f);

        glColor4f(0.00f, 0.00f, 1.00f, 1.0f);
        glVertex3f( 0.0f,  0.0f,  1.0f);
        glVertex3f( 0.0f,  0.0f, -1.0f);
    glEnd();
}

void GLWidget::wheelEvent(QWheelEvent* pe)
{
    if ((pe->delta()) > 0) {
        scale *= 1.1;
    } else if ((pe->delta())<0) {
        scale /= 1.1;
    }
    updateGL();
}

/*void Widget::drawPiramide() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glScalef(scale, scale, scale);
    glRotatef(xRotation, 1.0f, 0.0f, 0.0f);
    glRotatef(yRotation, 0.0f, 1.0f, 0.0f);
    glRotatef(zRotation, 0.0f, 0.0f, 1.0f);
    //drawAxis();
    QColor clr(0, 64, 128, 255);
    //QColor clr_lines(0, 0, 0, 255);
    qglColor(clr);
    currentScale = .3;
    for (size_t i = 0; i < SIDES_NUM; i++) {
        if (!isVisibleSide(i)) {
            continue;
        }
        glBegin(GL_LINE_LOOP);
        //glBegin(GL_POLYGON);
            for (size_t j = 0; j < VERTEX_NUM; j++) {
                glVertex3f(currentScale * Coordinates[i][j][0], currentScale * Coordinates[i][j][1],
                        currentScale * Coordinates[i][j][2]);
                //qDebug() << "[" << i << ", " << j << "]\n";
                //qDebug() << "{" << Coordinates[i][j][0] << ", " << Coordinates[i][j][1] << ", " << Coordinates[i][j][2] << "}\n";
            }
        glEnd();
    }
}*/

QVector3D GLWidget::getVector(qreal ish, qreal jsh,qreal ksh) {

    qreal pos = 0.1;
    QVector3D res(cos(ish)*pos*sin(ksh), sin(ish)*sin(jsh)*pos, sin(ish)*cos(jsh)*pos);

    return res;
}
/*
QVector3D GLWidget::getVector(qreal pos_in, qreal angle) {
    qreal pos = pos_in * .1;

    QVector3D res(pos * qCos(angle), pos * qSin(angle), getFunctionValue(pos));

    return res;
}*/
QVector3D GLWidget::getNormalZero(qreal pos_in) {
    qreal pos = 0.1;
    QVector3D res(0., 0.,0.);

    return res;
}



void GLWidget::animationRealize(void) {
    currentTimeValue += .2;
    updateGL();
}

void GLWidget::animationClear(void) {
    currentTimeValue = GL_PI/2;
    updateGL();
}
