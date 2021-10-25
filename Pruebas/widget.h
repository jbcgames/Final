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
#include "piedramov.h"
#include "manzana.h"
#include "piedramovsen.h"
#include "piedramovpend.h"
#include "rect.h"
#include <QKeyEvent>
#include "nivel.h"
#include "nivelimg.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int a,w=100,z=100,v=0,level[714],ux,uy,ah,velocidad,scenea=1;
    bool move=true;
    Score *score;
    Sprite *donalt;
    Nivel *ni;
    PiedraMovSen *piedrasen;
    void keyPressEvent(QKeyEvent *e);
    void lecturaArchivo();
    void lecturaArchivo2();
    void lecturaArchivo3();
    QGraphicsScene *scene,*scene2,*scene3,*nivel;
    Explosion *exp;
    Piedra *piedra;
    IMG *img;
    void Explos();
private slots:
    void on_pushButton_clicked();

private:
    Rect *rect;
    Ui::Widget *ui;
    Manzana *manzana;
    Objeto *objeto;
    QTimer *timer,*timer2;
    Platano *platano;
    PiedraMovPend *piedrapend;
    Uva *uva;
    PiedraMov *piedramov;
    float x,y,ancho,alto;

    void Scene();
    void Scene2();

};
#endif // WIDGET_H
