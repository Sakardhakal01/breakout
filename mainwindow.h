#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include "ball.h"
#include "paddle.h"
#include "block.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    void timerEvent(QTimerEvent* event);

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    paddle* padObj;
    ball* ballObj;
    block* blockObj[32];
    int updateTimer;
    int updateTimer2;
    bool moveLeft, moveRight;
};

#endif // MAINWINDOW_H
