#ifndef BALL_H
#define BALL_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QPen>
#include <QBrush>
#include <QRect>
#include <QtMath>

#define UP 0
#define DOWN 1

class ball : public QGraphicsItem
{
public:
    explicit ball();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    qreal awrtx;
    int dir;

protected:
    void advance(int step);

private:
    QPixmap ballMap;
    qreal dx, dy;
    qreal x, y;
    qreal w,h;


public slots:
    void move();
};

#endif // BALL_H
