#ifndef COMIENDO_H
#define COMIENDO_H


#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class Comiendo: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Comiendo(QObject *parent = nullptr);
    bool m;
    int mx,inix,my,iniy,s;
    void setMx(int);
    void setMy(int);
    QTimer *timer,*timer2;
    QPixmap *pixmap;
    float filas,columnas,ancho,alto;
    void setFilas(int);
    void Mov();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
signals:
public slots:
    void Actualizacion();
};

#endif // COMIENDO_H
