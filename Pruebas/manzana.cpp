#include "manzana.h"

#include "sprite.h"
#include "objeto.h"
#include <QGraphicsScene>
Manzana::Manzana(QObject *parent) : QObject(parent)
{
    timer=new QTimer();
    filas=0;
    columnas=0;
    pixmap = new QPixmap(":/manzana.png");
    ancho=25;
    alto=25;
    timer->start(100);
    connect(timer, &QTimer::timeout,this,&Manzana::Actualizacion);
}

void Manzana::setFilas(int a)
{
    this->filas=a*90;
}

QRectF Manzana::boundingRect() const
{
    return QRectF(-ancho,-alto,ancho,alto);
}

void Manzana::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(-ancho,-alto,*pixmap,columnas,filas,ancho,alto);

}



void Manzana::Actualizacion()
{
    columnas +=25;
    if(columnas>=50){
        columnas=0;
    }

    this->update(-ancho,-alto,ancho,alto);

}
