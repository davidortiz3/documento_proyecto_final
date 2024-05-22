#ifndef SPRITES_H
#define SPRITES_H

#include <QPixmap>
#include <QVector>
#include <QTimer>
#include <QGraphicsPixmapItem>

class Sprites : public QObject {
    Q_OBJECT
public:
    Sprites(QString mainPixmapPath, int frameWidth, int frameHeight, QObject *parent = nullptr);

    void addFrame(QRect frameRect);
    QPixmap getCurrentFrame();

public slots:
    void advanceFrame();

private:
    QPixmap mainPixmap;
    QVector<QPixmap> frames;
    int currentFrame;
    QTimer *timer;
};

#endif // SPRITES_H
