#ifndef NIVELIMG_H
#define NIVELIMG_H


#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
class IMG : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit IMG(QObject *parent = nullptr);
    QTimer *timer;
    QPixmap *pixmap;
    float filas,columnas,ancho,alto;
    void set();
    int a=0;
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);


};

#endif // NIVELIMG_H
