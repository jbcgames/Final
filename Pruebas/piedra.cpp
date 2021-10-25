#include "piedra.h"
#include <QGraphicsScene>
Piedra::Piedra(QObject *parent) : QObject(parent)
{
    timer=new QTimer();
    pixmap = new QPixmap(":/cubo.png");
    ancho=30;
    alto=30;
}

QRectF Piedra::boundingRect() const
{
    return QRectF(-ancho,-alto,ancho,alto);
}

void Piedra::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(-ancho,-alto,*pixmap,0,0,ancho,alto);

}




