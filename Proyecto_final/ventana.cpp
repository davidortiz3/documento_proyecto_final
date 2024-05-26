#include "ventana.h"
#include "ui_ventana.h"

ventana::ventana(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ventana)
{
    ui->setupUi(this);
    carro=new clase_base(ui->graphicsView);
}



ventana::~ventana()
{
    delete ui;
}

void ventana::keyPressEvent(QKeyEvent *evente)
{
    carro->keyPressEvent(evente);
}
