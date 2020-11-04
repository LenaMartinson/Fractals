#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <math.h>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new paintScene();
    rect = new Rect();
    pict = new Pict();

    ui->graphicsView->resize(610, 610);
    ui->graphicsView->setScene(scene);

    pict->mas1 = 0.005;
    pict->mas2 = 0.005;
    pict->x0 = -3;
    pict->x1 = 3;
    pict->y0 = -3;
    pict->y1 = 3;

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
    timer->start(0);

    scene->addEllipse(300, 300, 10, 10, QPen(65000));

    connect(scene, &paintScene::rose, this, &MainWindow::draw);
    connect(scene, &paintScene::rose2, this, &MainWindow::chang);
    connect(scene, &paintScene::rose3, this, &MainWindow::far);
    /*
    for (int i = 0; i < 600; i++) {
        for (int j  = 0; j < 600; j++) {
            scene->addLine(i, j, i, j, QPen(QColor(255, 0, 255)));
        }
    }
    */


    scene->addItem(rect);
    scene->addItem(pict);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    close();
}

void MainWindow::slotTimer() {
    timer->stop();
    //scene->setSceneRect(-150, -150, 300, 300);
}


void MainWindow::resizeEvent(QResizeEvent *event)
{
    timer->start(0);
    //QWidget::resizeEvent(event);
}

void MainWindow::draw(QPointF a) {
    int x = a.x(), y = a.y();
    rect->firstPoint = a;
    rect->nowPoint = a;
    scene->removeItem(rect);
    scene->addItem(rect);
}

void MainWindow::chang(QPointF a) {
    int x = a.x(), y = a.y();
    rect->nowPoint = a;
    scene->removeItem(rect);
    scene->addItem(rect);
}

void MainWindow::far() {
    QPointF a = rect->firstPoint;
    QPointF b = rect->nowPoint;
    qreal x0 = a.rx() - 300, y0 = a.ry()- 300;
    qreal x1 = b.rx() - 300, y1 = b.ry() - 300;
    if (x0 > x1) {
        qreal x2 = x0;
        x0 = x1;
        x1 = x2;
    }
    if (y0 > y1) {
        qreal y2 = y0;
        y0 = y1;
        y1= y2;
    }
    double mas1 = pict->mas1;
    double mas2 = pict->mas2;
    double one = fabs(pict->x0 + pict->x1) / 2;
    double two = fabs(pict->y0 + pict->y1) / 2;
    pict->x0 = x0 * mas1 - one;
    pict->x1 = x1 * mas1 - one;
    pict->y0 = y0 * mas2 - two;
    pict->y1 = y1 * mas2 - two;
    scene->removeItem(pict);
    scene->addItem(pict);
}
