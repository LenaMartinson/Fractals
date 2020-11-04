#ifndef RECT_H
#define RECT_H

#include <QObject>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QList>
#include <QColor>

class Rect : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Rect(QObject *parent = 0);
    ~Rect();


signals:



public slots:


protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public:
    QPointF firstPoint;
    QPointF nowPoint;

};


#endif // RECT_H

