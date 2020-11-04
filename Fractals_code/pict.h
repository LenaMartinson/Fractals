#ifndef PICT_H
#define PICT_H


#include <QObject>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QList>
#include <QColor>

class Pict : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Pict(QObject *parent = 0);
    ~Pict();


signals:



public slots:


protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:

public:
    double mas1, mas2;
    double x0, y0, x1, y1;
};


#endif // PICT_H

