#include "Ball.h"

#include <cmath>
#include <QPainter>

#define CIRCLE_RADIUS 15
#define SPEED 3
#define PI 3.14159265

Ball::Ball()
    : angle(315)
{
}

QRectF Ball::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-adjust -CIRCLE_RADIUS, -adjust -CIRCLE_RADIUS, 
                    adjust + CIRCLE_RADIUS, adjust + CIRCLE_RADIUS);
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
    if(scene_pos.x() > 200 - CIRCLE_RADIUS || scene_pos.x() < -200 + CIRCLE_RADIUS
            || scene_pos.y() < -200 + CIRCLE_RADIUS || scene_pos.y() > 200 - CIRCLE_RADIUS)
    {
        angle -= 90;
        setRotation(angle);
    }
    setPos(mapToParent(0, 2 * SPEED));
}
