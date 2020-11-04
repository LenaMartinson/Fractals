#include <rect.h>

Rect::Rect(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    nowPoint = {0, 0};
    firstPoint = {0, 0};
}

Rect::~Rect()
{

}
QRectF Rect::boundingRect() const
{
    return QRectF(0, 0, 600, 600);
}

void Rect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int x1 = nowPoint.x();
    int y1 = nowPoint.y();
    int x = firstPoint.x();
    int y = firstPoint.y();

    painter->drawLine(x, y, x1, y);
    painter->drawLine(x, y, x, y1);
    painter->drawLine(x, y1, x1, y1);
    painter->drawLine(x1, y, x1, y1);
    //Q_UNUSED(option);
    //Q_UNUSED(widget);
}



