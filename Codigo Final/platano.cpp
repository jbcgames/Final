#include "platano.h"
#include "sprite.h"
#include "objeto.h"
#include <QGraphicsScene>
Platano::Platano(QObject *parent) : QObject(parent)
{
    timer=new QTimer();
    filas=0;
    columnas=0;
    pixmap = new QPixmap(":/1634791631444.png");
    ancho=25;
    alto=56;
    timer->start(250);
    connect(timer, &QTimer::timeout,this,&Platano::Actualizacion);
}

QRectF Platano::boundingRect() const
{
    return QRectF(-ancho,-alto,ancho,alto);
}

void Platano::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(-ancho,-alto,*pixmap,columnas,filas,ancho,alto);

}



void Platano::Actualizacion()
{
    columnas +=25;
    if(columnas>=50){
        columnas=0;
    }

    this->update(-ancho,-alto,ancho,alto);

}
