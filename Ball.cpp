#include "Ball.h"

#include <cmath>
#include <QPainter>

#define CIRCLE_RADIUS 15
#define SPEED 1
#define PI 3.14159265

Ball::Ball()
    : angle(-45)
{
    setRotation(0);
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

    //qreal dx = ::sin(angle);

    //setRotation(rotation() + dx);
    //setPos(mapToParent(0, 1));
    
    setX(x() + ::cos(angle) * SPEED);
    setY(y() + ::sin(angle) * SPEED);
    setPos(x(), y());
}
