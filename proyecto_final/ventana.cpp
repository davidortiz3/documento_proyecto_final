#include "ventana.h"
#include "ui_ventana.h"

ventana::ventana(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ventana)
{


    ui->setupUi(this);
    ui->graphicsView->setVisible(false);
    ui->widget->setVisible(true);
    ui->widget->setStyleSheet("background-image: url(:/nive1/Cold-war-jfk-1-1.jpg)");
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
}



ventana::~ventana()
{
    delete ui;
    delete game;

}

void ventana::keyPressEvent(QKeyEvent *evente)
{
    game->keyPressEvent(evente);
}

void ventana::on_pushButton_clicked()
{
    ui->graphicsView->setVisible(true);
    ui->widget->setVisible(false);
    game = new clase_base(ui->graphicsView);
}

