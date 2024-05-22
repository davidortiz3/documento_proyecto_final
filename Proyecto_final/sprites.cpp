#include "sprites.h"

Sprites::Sprites(QString mainPixmapPath, int frameWidth, int frameHeight, QObject *parent)
    : QObject(parent), currentFrame(0) {
    mainPixmap.load(mainPixmapPath);

    // Assuming the image is a grid of frames
    for (int y = 0; y < mainPixmap.height(); y += frameHeight) {
        for (int x = 0; x < mainPixmap.width(); x += frameWidth) {
            addFrame(QRect(x, y, frameWidth, frameHeight));
        }
    }

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Sprites::advanceFrame);
    timer->start(100); // Change frame every 100 ms
}

void Sprites::addFrame(QRect frameRect) {
    frames.push_back(mainPixmap.copy(frameRect));
}

QPixmap Sprites::getCurrentFrame() {
    return frames[currentFrame];
}

void Sprites::advanceFrame() {
    currentFrame = (currentFrame + 1) % frames.size();
}
