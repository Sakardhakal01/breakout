#include "ball.h"

ball::ball()
{
    dx = 4.0;
    dy = 4.0;
    x = 0.0;
    y = 0.0;
    w = 20.0;
    h = 20.0;
    awrtx = 90;
    dir = DOWN;
    //ballMap = QPixmap(":/images/ball.png");
    //ballMap = ballMap.scaled(50, 50, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
}

void ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    static QColor color = Qt::blue;
    painter->setBrush(color);
    painter->drawEllipse(-w/2, -h/2, w, h);
}

QRectF ball::boundingRect() const
{
     qreal adjust = 1.0;
     return QRectF(-w/2 - adjust, -h/2 - adjust, w + adjust, h + adjust);
}

void ball::advance(int step)
{
    if(step == 0)
        return;
}

QPainterPath ball::shape() const
{
    QPainterPath path;
    path.addRect(-w/2, -h/2, w, h);
    return path;
}

void ball::move()
{
    if(awrtx == 90)
    {
        x = this->pos().rx();
        y = this->pos().ry();
        y = y + dy;
        setPos(x, y);
    }
    if(awrtx == 30)
    {        
        switch (dir)
        {
            case UP:    x = this->pos().rx();
                        y = this->pos().ry();
                        dx = 4;
                        dy = 0.5 * dx;
                        x = x + dx;
                        y = y - dy;
                        setPos(x, y);
                        break;

            case DOWN:  x = this->pos().rx();
                        y = this->pos().ry();
                        dx = 4;
                        dy = 0.5 * dx;                      
                        x = x + dx;
                        y = y + dy;
                        setPos(x, y);
                        break;
            default:
                        break;
        }
    }
    if(awrtx == 60)
    {
        switch (dir)
        {
            case UP:    x = this->pos().rx();
                        y = this->pos().ry();
                        dx = 2;
                        dy = 2 * dx;
                        x = x + dx;
                        y = y - dy;
                        setPos(x, y);
                        break;

            case DOWN:  x = this->pos().rx();
                        y = this->pos().ry();
                        dx = 2;
                        dy = 2 * dx;
                        x = x + dx;
                        y = y + dy;
                        setPos(x, y);
                        break;
            default:
                        break;
        }
    }
    if(awrtx == -30)
    {
        switch (dir)
        {
            case UP:    x = this->pos().rx();
                        y = this->pos().ry();
                        dx = 4;
                        dy = 0.5 * dx;
                        x = x - dx;
                        y = y - dy;
                        setPos(x, y);
                        break;

            case DOWN:  x = this->pos().rx();
                        y = this->pos().ry();
                        dx = 4;
                        dy = 0.5 * dx;
                        x = x - dx;
                        y = y + dy;
                        setPos(x, y);
                        break;
            default:
                        break;
        }
    }
    if(awrtx == -60)
    {
        switch (dir)
        {
            case UP:    x = this->pos().rx();
                        y = this->pos().ry();
                        dx = 2;
                        dy = 2 * dx;
                        x = x - dx;
                        y = y - dy;
                        setPos(x, y);
                        break;

            case DOWN:  x = this->pos().rx();
                        y = this->pos().ry();
                        dx = 2;
                        dy = 2 * dx;
                        x = x - dx;
                        y = y + dy;
                        setPos(x, y);
                        break;
            default:
                        break;
        }
    }
}
