#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <QMutex>
#include <world.h>
#include <QMouseEvent>
#define WSize 100
namespace Ui {
class game;
}

class game : public QWidget
{
    Q_OBJECT
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
public:
    explicit game(QWidget *parent = nullptr);
    ~game();
public slots:
    void gamerule();
    void stop();
    void startgame();
private:
    Ui::game *ui;
    world universe;
    world generation;
    QTimer *timer;

};

#endif // GAME_H
