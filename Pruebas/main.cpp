#include "widget.h"
#include <QApplication>
#include "keys.h"
Widget *w;
Sprite *mk;
PiedraMov *mov;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    w=new Widget();
    mk=new Sprite();
        mov=new PiedraMov();
        w->show();

    return a.exec();
}
