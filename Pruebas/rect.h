#ifndef RECT_H
#define RECT_H


#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
class Rect : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Rect(QObject *parent = nullptr);
    QTimer *timer;
    QPixmap *pixmap;
    float filas,columnas,ancho,alto;
    void setFilas(int);
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);


};
#endif // RECT_H
