#include "rect.h"
#include <QGraphicsScene>
Rect::Rect(QObject *parent) : QObject(parent)
{
    timer=new QTimer();
    pixmap = new QPixmap(":/rect.png");
    ancho=1105;
    alto=100;
}

QRectF Rect::boundingRect() const
{
    return QRectF(-ancho,-alto,ancho,alto);
}

void Rect::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(-ancho,-alto,*pixmap,0,0,ancho,alto);

}
