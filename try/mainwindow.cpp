#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPainter>
#include <QRect>
#include <QBrush>
#include <QFont>
#include <iostream>
#include <QMessageBox>
#include "Character.h"
#include "Chapter.h"

char ch='0';
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::update()
{
    this->repaint();
}

void  MainWindow ::keyPressEvent (QKeyEvent *e)
{

        if(e->modifiers () == Qt::ControlModifier)
        {
            if(e->key () == Qt::Key_W)
            {

                qDebug()<<tr("快捷键W");

            }
            if(e->key () == Qt::Key_S)
            {
                qDebug()<<tr("快捷键S");
            }
            if(e->key () == Qt::Key_A)
            {
                qDebug()<<tr("快捷键A");
            }
            if(e->key () == Qt::Key_D)
            {
                qDebug()<<tr("快捷键D");
            }
        }
        else if(e->key()==16777220)
            {

               qDebug()<<"huiche";
               a.newLine();

               this->update();

            }
        else if(e->key()==16777235)
            {

               qDebug()<<"shang";

               this->update();
                 //MainWindow::paintEvent(true);
            }

        else if(e->key()==16777234)
            {
               qDebug()<<"zuo";

               this->update();
                 //MainWindow::paintEvent(true);
            }
        else if(e->key()==16777236)
            {
               qDebug()<<"you";

               this->update();
                 //MainWindow::paintEvent(true);
            }
        else if(e->key()==16777237)
            {
               qDebug()<<"xia";

               this->update();
                 //MainWindow::paintEvent(true);  16777219
            }
        else if(e->key()==16777219)  //删除操作
            {
               qDebug()<<"delete";
               a.deletech();

               this->update();
                 //MainWindow::paintEvent(true);  16777219
            }
        else if(e->key())
            {
               a.saveCharRight(e->key());
               qDebug()<<e->key();

               this->update();
                 //MainWindow::paintEvent(true);
            }


}

/*
void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);


QPainter paint(this);
paint.begin(this);
Q.Display(paint);
paint.end();
}
*/


void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    // 设置画笔颜色
    painter.setPen(QColor(100, 160, 230));

    // 设置字体：微软雅黑、点大小50、斜体
    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setPointSize(20);
    painter.setFont(font);

    // 绘制文本
  /*  if(Cnewline)
    {
        Cnewline=0;
        QRectF* nowrect;
        nowrect=new QRectF;
    }*/
    Character* paintch,* paintch1,* paintch2;
    paintch=a.a1ptr;
    paintch1=a.a1ptr;
    paintch2=a.a1ptr;
    qDebug()<<paintch->seq[0];

    QRectF rect1(10,20+a.a1ptr->seq[0]*30,3000,3000);

    painter.drawText(rect1, a.display(a.a1ptr));          // 创建QPainter一个对象

    qDebug()<<(20+(a.nowline->seq[0]*30));

    while(paintch->down!=NULL&&a.nowline->seq[0]==1)
    {
        paintch=paintch->down;
    }

    QRectF rect2(10,20+(paintch->seq[0]*30),3000,3000);
    qDebug()<<paintch->seq[0];
    painter.drawText(rect2, a.display(paintch));          // 创建QPainter一个对象

    while(paintch1->down!=NULL&&a.nowline->seq[0]==2)
    {
        paintch1=paintch1->down;
    }
    QRectF rect3(10,20+(paintch1->seq[0]*30),3000,3000);
    qDebug()<<a.nowline->seq[0];
    painter.drawText(rect3, a.display(paintch1));          // 创建QPainter一个对象

    while(paintch2->down!=NULL&&a.nowline->seq[0]==3)
    {
        paintch2=paintch2->down;
    }
    QRectF rect4(10,20+(paintch2->seq[0]*30),3000,3000);
    qDebug()<<a.nowline->seq[0];
    painter.drawText(rect4, a.display(paintch2));          // 创建QPainter一个对象


/*
   // 画一条直线
    QPen pen;
    pen.setColor(Qt::yellow);           // 设置画笔为黄色
    painter.setPen(pen);                // 设置画笔


    // 画一个空心矩形
    pen.setColor(Qt::darkRed);
    painter.setPen(pen);
    painter.drawRect(QRect(1, 1, 100, 100));

*/

}

void MainWindow::on_pushButton_clicked()
{
    qDebug()<<tr("快捷键Saaa");
}
