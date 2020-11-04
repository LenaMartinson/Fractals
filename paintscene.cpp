#include "paintscene.h"

paintScene::paintScene(QObject *parent) : QGraphicsScene(parent)
{

}

paintScene::~paintScene()
{

}

void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF a = event->scenePos();
    emit rose(a);
}

void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF a = event->scenePos();
    emit rose2(a);
}

void paintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    emit rose3();
}
