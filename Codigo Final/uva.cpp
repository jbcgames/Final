#include "uva.h"
#include "sprite.h"
#include "objeto.h"
#include <QGraphicsScene>
Uva::Uva(QObject *parent) : QObject(parent)
{
    timer=new QTimer();
    filas=0;
    columnas=0;
    pixmap = new QPixmap(":/SpriteUva.png");
    ancho=16;
    alto=25;
    timer->start(300);
    connect(timer, &QTimer::timeout,this,&Uva::Actualizacion);
}

QRectF Uva::boundingRect() const
{
    return QRectF(-ancho,-alto,ancho,alto);
}

void Uva::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(-ancho,-alto,*pixmap,columnas,filas,ancho,alto);

}



void Uva::Actualizacion()
{
    columnas +=16;
    if(columnas>=32){
        columnas=0;
    }

    this->update(-ancho,-alto,ancho,alto);

}
