#include "nivelimg.h"
#include <QGraphicsScene>
IMG::IMG(QObject *parent) : QObject(parent)
{
    timer=new QTimer();
    pixmap = new QPixmap(":/nivel.png");
    ancho=1100;
    alto=700;
    timer=new QTimer();
    timer->start(2000);
    connect(timer,&QTimer::timeout,this,&IMG::set);
}

QRectF IMG::boundingRect() const
{
    return QRectF(-ancho,-alto,ancho,alto);
}

void IMG::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(-ancho,-alto,*pixmap,0,0,ancho,alto);

}
void IMG::set(){

        delete this;

}
