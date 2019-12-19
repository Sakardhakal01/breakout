#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(850, 700);
    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-400, -300, 800, 600);
    scene->setBackgroundBrush(Qt::black);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    padObj = new paddle;
    padObj->setPos(0, 300);
    scene->addItem(padObj);

    ballObj = new ball;
    ballObj->setPos(0, -100);
    scene->addItem(ballObj);

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            blockObj[0] = new block;
            blockObj[0]->setPos(-350+100*j, -300+20*i);
            scene->addItem(blockObj[0]);
         }
    }

    /*QTimer* timer = new QTimer;
    connect(timer, SIGNAL(timeout()), ballObj, SLOT(move()));
    timer->setInterval(1000/33);
    timer->start();*/
    updateTimer = QObject::startTimer(10);
    QTimerEvent* event = new QTimerEvent(updateTimer);
    QCoreApplication::postEvent(this, event);

    updateTimer2 = QObject::startTimer(20);
    QTimerEvent* event2 = new QTimerEvent(updateTimer2);
    QCoreApplication::postEvent(this, event2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int step = 10;
    if(!event)
        return;

    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent *k = static_cast<QKeyEvent*>(event);
        if(k->key() == Qt::Key_A)
        {

            if(!(padObj->pos().rx() <= -350))
                moveRight = true;

            //padObj->move(-step);
        }
        if(k->key() == Qt::Key_D)
        {

            if(!(padObj->pos().rx() >= 350))
                moveLeft = true;
            //padObj->move(step);
        }
    }
    else
       return QWidget::keyPressEvent(event);
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(!event)
        return;

    if(event->type() == QEvent::KeyRelease)
    {
        if(event->key() == Qt::Key_A || event->key() == Qt::Key_D)
        {
            moveLeft = false;
            moveRight = false;
        }
    }
    else
        return QWidget::keyReleaseEvent(event);

}

void MainWindow::timerEvent(QTimerEvent *event)
{
    if(!event)
        return;
    if(event->timerId() == updateTimer2)
    {
        if(moveLeft)
        {
            padObj->move(10);
        }
        if(moveRight)
        {
            padObj->move(-10);
        }
    }

    if(event->timerId() == updateTimer)
    {
        if(!scene->collidingItems(ballObj).isEmpty())
        {
            if(scene->collidingItems(ballObj).front() == padObj)
            {
                if(padObj->pos().rx() - ballObj->pos().rx() >= -75 && padObj->pos().rx() - ballObj->pos().rx() < -37.5)
                {
                    ballObj->awrtx = 30;
                    ballObj->dir = UP;
                }
                else if(padObj->pos().rx() - ballObj->pos().rx() >= -37.5 && padObj->pos().rx() - ballObj->pos().rx() < 0)
                {
                    ballObj->awrtx = 60;
                    ballObj->dir = UP;
                }
                else if(padObj->pos().rx() - ballObj->pos().rx() >= 0 && padObj->pos().rx() - ballObj->pos().rx() < 37.5)
                {
                    ballObj->awrtx = -60;
                    ballObj->dir = UP;
                }
                else if(padObj->pos().rx() - ballObj->pos().rx() >= 37.5 && padObj->pos().rx() - ballObj->pos().rx() <= 75)
                {
                    ballObj->awrtx = -30;
                    ballObj->dir = UP;
                }
                ballObj->move();
            }
            else
            {
                if(scene->collidingItems(ballObj).front()->pos().rx() - ballObj->pos().rx() >= 55 ||
                    scene->collidingItems(ballObj).front()->pos().rx() - ballObj->pos().rx() <= -55)
                {
                    ballObj->awrtx = -ballObj->awrtx;
                }
                else
                {
                    ballObj->dir = DOWN;
                }
                delete scene->collidingItems(ballObj).front();
                ballObj->move();
            }
        }
        else if(ballObj->pos().rx() > 400 || ballObj->pos().rx() < -400)
        {
            ballObj->awrtx = -ballObj->awrtx;
            ballObj->move();
        }
        else if(ballObj->pos().ry() > 300 || ballObj->pos().ry() < -300)
        {

            ballObj->dir = DOWN;
            if(ballObj->pos().ry() > 300)
            {
                ballObj->setPos(0, -100);
            }
            ballObj->move();

        }
        else
        {
            ballObj->move();
        }
    }
}
