#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QGraphicsItem>
#include <QRectF>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QtDebug>
#include "sprite.h"
#include <conio.h>
#include "objeto.h"
#include "score.h"
#include "platano.h"
#include "uva.h"
#include <QObject>
#include "piedra.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int a,w=100,z=100,v=0,level[714];
    Score *score;
    Sprite *donalt;
    void keyPressEvent(QKeyEvent *e);
    void lecturaArchivo();

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;

    Objeto *objeto;
    QTimer *timer;
    Platano *platano;
    Piedra *piedra;
    Uva *uva;
    float x,y,ancho,alto;

    void movimiento();

};
#endif // WIDGET_H
