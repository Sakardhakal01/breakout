#include "block.h"

block::block()
{
    x = 0.0;
    y = 0.0;
    w = 100.0;
    h = 20.0;
    //blockMap = QPixmap(":/images/test.png");
    //blockMap = paddleMap.scaled(150, 150, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
}

void block::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    static QColor color = Qt::red;
    painter->setBrush(color);
    painter->drawRect(-w/2, -h/2, w, h);
}

QRectF block::boundingRect() const
{
    qreal adjust = 1.0;
    return QRectF(-w/2 - adjust, -h/2 - adjust, w + adjust, h + adjust);
}

QPainterPath block::shape() const
{
    QPainterPath path;
    path.addRect(-w/2, -h/2, w, h);
    return path;
}

