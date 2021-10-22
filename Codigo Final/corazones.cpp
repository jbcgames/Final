/*
#include "corazones.h"

Corazones::Corazones(QObject *parent) : QObject(parent)
{
    timer = new QTimer();
    filas = 0;
    columnas = 0;
    pixmap = new QPixmap(":/vidas.png");
    ancho = 355;
    alto = 81;
    timer->start(50);
    connect(timer, &QTimer::timeout,this,&Corazones::Actualizacion);

}
QRectF Corazones::boundingRect() const
{
    return QRectF(-ancho,-alto,ancho,alto);
}

void Corazones::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho,-alto,*pixmap,columnas,0,ancho,alto);
}
void Corazones::Actualizacion()
{
     this->update(-ancho,-alto,ancho,alto);
}
*/

