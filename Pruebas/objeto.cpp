#include "sprite.h"
#include "objeto.h"
#include <QGraphicsScene>
Objeto::Objeto(QObject *parent) : QObject(parent)
{
    timer=new QTimer();
    filas=0;
    columnas=0;
    pixmap = new QPixmap(":/oorjG.png");
    ancho=90;
    alto=90;
    timer->start(1000);
    connect(timer, &QTimer::timeout,this,&Objeto::Actualizacion);
}

void Objeto::setFilas(int a)
{
    this->filas=a*90;
}

QRectF Objeto::boundingRect() const
{
    return QRectF(-ancho,-alto,ancho,alto);
}

void Objeto::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(-ancho,-alto,*pixmap,columnas,filas,ancho,alto);

}



void Objeto::Actualizacion()
{
    columnas +=90;
    if(columnas>=450){
        columnas=0;
    }

    this->update(-ancho,-alto,ancho,alto);

}
