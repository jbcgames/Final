#include "widget.h"
#include <QApplication>
#include "keys.h"
Widget *w;
Sprite *mk;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    w=new Widget();
    mk=new Sprite();
    w->show();
    return a.exec();
}
