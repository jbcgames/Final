#ifndef EXPLOSION_H
#define EXPLOSION_H


#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
class Explosion : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Explosion(QObject *parent = nullptr);
    QTimer *timer;
    QPixmap *pixmap;
    float filas,columnas,ancho,alto;
    void setFilas(int);
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
signals:
public slots:
    void Actualizacion();
};


#endif // EXPLOSION_H
