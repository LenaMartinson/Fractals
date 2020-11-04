#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsItem>
#include <QMessageBox>
#include <QShortcut>
#include <QPoint>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>

#include <QDebug>

#include <paintscene.h>
#include <rect.h>
#include <pict.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void slotTimer();

private:

    void resizeEvent(QResizeEvent * event);

public slots:
    void draw(QPointF a);
    void chang(QPointF a);
    void far();

public:

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    Rect *rect;
    Pict *pict;

    paintScene *scene;

};

#endif // MAINWINDOW_H
