#include "paddle.h"

paddle::paddle()
{
    dx = 8;
    dy = 2.5;
    x = 0.0;
    y = 0.0;
    w = 150.0;
    h = 20.0;
    //paddleMap = QPixmap(":/images/test.png");
    //paddleMap = paddleMap.scaled(150, 150, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
}

void paddle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    static QColor color = Qt::white;
    painter->setBrush(color);
    painter->drawRect(-w/2, -h/2, w, h);
}

QRectF paddle::boundingRect() const
{
    qreal adjust = 1.0;
    return QRectF(-w/2 - adjust, -h/2 - adjust, w + adjust, h + adjust);
}

void paddle::advance(int step)
{
    if(step == 0)
        return;
    x = this->pos().rx();
    x = x + dx;
    setPos(x, y);
}

QPainterPath paddle::shape() const
{
    QPainterPath path;
    path.addRect(-w/2, -h/2, w, h);
    return path;
}

void paddle::move(int step)
{
    if(step == 0)
        return;
    x = this->pos().rx();
    y = this->pos().ry();
    x = x + step;
    setPos(x, y);
}
