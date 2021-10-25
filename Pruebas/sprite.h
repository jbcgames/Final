#ifndef SPRITE_H
#define SPRITE_H
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include "explosion.h"
class Sprite : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Sprite(QObject *parent = nullptr);

    QTimer *timer;
    QTimer *timer2;
    QTimer *timer3;
    QPixmap *pixmap;
    Explosion *exp;
    float filas,columnas,ancho,alto;
    void setFilas(int);
    QRectF boundingRect() const;

    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
signals:
public slots:
    void Actualizacion();
    void Comer();
    void Columna();
    void Muerte();
};

#endif // SPRITE_H
