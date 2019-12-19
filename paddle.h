#ifndef PADDLE_H
#define PADDLE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QPen>
#include <QBrush>
#include <QRect>

class paddle : public QGraphicsItem
{
public:
    explicit paddle();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void move(int step);

protected:
      void advance(int step);

private:
    QPixmap paddleMap;
    qreal dx, dy;
    qreal x, y;
    qreal w, h;
};

#endif // PADDLE_H
