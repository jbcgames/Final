#ifndef SPRITE_H
#define SPRITE_H
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
class Sprite : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Sprite(QObject *parent = nullptr);

    QTimer *timer;
    QTimer *timer2;
    QPixmap *pixmap;
    float filas,columnas,ancho,alto;
    void setFilas(int);
    QRectF boundingRect() const;

    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
signals:
public slots:
    void Actualizacion();
    void Comer();
    void Columna();
};

#endif // SPRITE_H
