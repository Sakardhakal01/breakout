#ifndef BLOCK_H
#define BLOCK_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QPen>
#include <QBrush>
#include <QRect>

class block : public QGraphicsItem
{
public:
    explicit block();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QPixmap blockMap;
    qreal x, y;
    qreal w,h;


public slots:
    void move();
};

#endif // BLOCK_H


