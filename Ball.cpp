#include "Ball.h"

#include <cmath>
#include <QPainter>

#define CIRCLE_RADIUS 15
#define SPEED 1
#define PI 3.14159265

Ball::Ball()
    : angle(315)
{
}

QRectF Ball::boundingRect() const
{
    return QRectF(-CIRCLE_RADIUS, -CIRCLE_RADIUS, 
                    CIRCLE_RADIUS, CIRCLE_RADIUS);
}

void Ball::paint(QPainter * painter, const QStyleOptionGraphicsItem * options, QWidget * widget)
{
    painter->drawEllipse(-CIRCLE_RADIUS, -CIRCLE_RADIUS,
                        CIRCLE_RADIUS, CIRCLE_RADIUS);
}

void Ball::advance(int phase)
{
    if(!phase)
        return;

    QPointF scene_pos = scenePos();
    if(scene_pos.x() > 200 || scene_pos.x() < -200 
            || scene_pos.y() < -200 || scene_pos.y() > 200)
    {
        angle -= 90;
        setRotation(angle);
    }
    setPos(mapToParent(0, 2));
}
