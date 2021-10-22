#include "event.h"
#include <QDebug>
#include <QKeyEvent>
bool
Event::eventFilter(
    QObject *obj,
    QEvent *event)
{
  if (event->type() == QEvent::KeyPress) {
    QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
    if( keyEvent->key() == Qt::Key_A )
     qDebug() << "Tecla 'A' presionada";
    return true;
  }

  return QObject::eventFilter(obj, event);
}
