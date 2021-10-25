#ifndef PIEDRAMOVPEND_H
#define PIEDRAMOVPEND_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
class PiedraMovPend : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    int mx,inix,my,iniy,s=0,n=2;
    void setMx(int);
    void setMy(int);
    void Mov();
    void Actualizacion();
    void Detect();
    bool m=true;
    explicit PiedraMovPend(QObject *parent = nullptr);
    QTimer *timer;
    QPixmap *pixmap;
    float filas,columnas,ancho,alto;
    void setFilas(int);
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);


};

#endif // PIEDRAMOVPEND_H
