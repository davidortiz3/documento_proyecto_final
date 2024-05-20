#ifndef VENTANA_H
#define VENTANA_H

#include <QMainWindow>
#include "clase_base.h"
#include <QKeyEvent>
#include <QObject>
QT_BEGIN_NAMESPACE
namespace Ui {
class ventana;
}
QT_END_NAMESPACE

class ventana : public QMainWindow
{
    Q_OBJECT

public:
    ventana(QWidget *parent = nullptr);
    ~ventana();
    clase_base *carro;
    void keyPressEvent(QKeyEvent *evente);
private:
    Ui::ventana *ui;
};
#endif // VENTANA_H
