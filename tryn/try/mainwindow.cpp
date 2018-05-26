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
#include "Cursor.h"
char ch='0';
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->actionOPEN,SIGNAL(triggered()),this, SLOT(openFileSlot()));
    QObject::connect(ui->actionOpen,SIGNAL(triggered()),this, SLOT(openFileSlot()));
    QObject::connect(ui->actionSAVE,SIGNAL(triggered()),this, SLOT(saveFileSlot()));
    QObject::connect(ui->actionSave,SIGNAL(triggered()),this, SLOT(openFileSlot()));
    QObject::connect(ui->actionNEW,SIGNAL(triggered()),this, SLOT(newFileSlot()));
    QObject::connect(ui->actionNew,SIGNAL(triggered()),this, SLOT(openFileSlot()));
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
               a.cursorUp();
               this->update();

            }

        else if(e->key()==16777234)
            {
               qDebug()<<"zuo";
               a.cur.left();
                qDebug()<<a.cur.x<<"1ci";
               this->update();

            }
        else if(e->key()==16777236)
            {
               qDebug()<<"you";
               if(a.cur.x<a.charpos[a.cur.y])
                a.cur.right();
               this->update();

            }
        else if(e->key()==16777237)
            {
                qDebug()<<"xia";
                a.cursorDown();
                this->update();

            }
        else if(e->key()==16777219)  //删除操作
            {
               qDebug()<<"delete";
               if(a.cur.x==a.charpos[a.cur.y])
               {
                a.deletech();
                qDebug()<<"rigtdel";
               }

               else
               {
                 a.deleteCharpos();
                qDebug()<<"insightdel";
               }



               this->update();
                 //MainWindow::paintEvent(true);  16777219
            }
        else if(e->key()>=32&&e->key()<=126)
            {
                if(a.cur.x==a.charpos[a.cur.y])
                {
                 a.saveCharRight(e->key());
                 qDebug()<<"rigthsave";
                }
                else
                {
                 a.saveCharpos(e->key());
                 qDebug()<<"insightsave";
                }

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
     painter.drawLine(5+a.cur.x*17,55+a.cur.y*30,5+a.cur.x*17,80+a.cur.y*30);//画直线
    qDebug()<<a.cur.x<<"2ci";
    painter.setPen(QColor(100, 160, 230));

    // 设置字体：微软雅黑、点大小50、斜体
    QFont font;
    font.setFamily("宋体");
    font.setPointSize(18);
    font.setLetterSpacing(QFont::AbsoluteSpacing, 2);
    font.setCapitalization(QFont::SmallCaps);
    painter.setFont(font);

    // 绘制文本
  /*  if(Cnewline)
    {
        Cnewline=0;
        QRectF* nowrect;
        nowrect=new QRectF;
    }*/

    int i;
    for(i=0;a.ptr[i][0]!=NULL;i++)
    {
        QPoint pt(5,80+a.ptr[i][0]->seq[0]*30);
        painter.drawText(pt, a.display(a.ptr[i][0]));          // 创建QPainter一个对象

    }

/*

    for(int i=0;paintch->down!=NULL&&a.nowline->seq[0]>=1&&i<1;i++)
    {
        paintch=paintch->down;
    }
    if(a.nowline->seq[0]>=1)
    {
        QPoint pt(5,60+paintch->seq[0]*30);
        qDebug()<<paintch->seq[0];
        qDebug()<<"this is paintch";
        painter.drawText(pt, a.display(paintch));          // 创建QPainter一个对象
    }




    for(int i=0;paintch1->down!=NULL&&a.nowline->seq[0]>=2&&i<2;i++)
    {
        paintch1=paintch1->down;
    }
    if(a.nowline->seq[0]>=2)
    {
        QPoint pt(5,paintch1->seq[0]*30+60);
        qDebug()<<paintch1->seq[0];
        qDebug()<<"this is paintch1";
        painter.drawText(pt, a.display(paintch1));          // 创建QPainter一个对象
    }




    for(int i=0;paintch2->down!=NULL&&a.nowline->seq[0]>=3&&i<3;i++)
    {
        paintch2=paintch2->down;
    }
    if(a.nowline->seq[0]>=3)
    {
        QPoint pt(5,paintch2->seq[0]*30+60);
        qDebug()<<paintch2->seq[0];
        qDebug()<<"this is paintch2";
        painter.drawText(pt, a.display(paintch2));          // 创建QPainter一个对象

    }

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

void MainWindow::newFileSlot()
{
    if(a.a1.ch[0]!=0)
    {
        QMessageBox::StandardButton button = QMessageBox::information(this,
                                                   "尚未保存", "是否要保存?",QMessageBox::Save |
                                                    QMessageBox::Discard | QMessageBox::Cancel);
                 switch(button)
                 {
                     case QMessageBox::Save:{
                         saveFileSlot();
                         break;
                     }
                     case QMessageBox::Cancel:{
                         return;
                     }
                     case QMessageBox::Discard:{
                         break;
                     }
                 }
     }
      for(int j=0;a.ptr[j][0]!=NULL;j++)
       for(int i=0;i<100;i++)
        a.ptr[j][0]->ch[i]='0';//清理幕布
      a.cur.y=0;
      a.cur.x=0;
}


void MainWindow::openFileSlot()
{
     QString fileName = QFileDialog::getOpenFileName(this,tr("打开文件"),QDir::currentPath());
     //qDebug()<<"the file name is "<<fileName;
     if(fileName.isEmpty()){
        QMessageBox::information(this,"错误文件","请重新选择一个文本文件");
        return;
         }
     QFile *file = new QFile;
     file->setFileName(fileName);
     bool ok=file->open(QIODevice::ReadOnly);//只写文件的一种权限
     if(ok){
         QTextStream in(file);//文本流和文件相结合
         QString str;
         while(!in.atEnd())
         {
             str=in.read(100);
             memcpy(a.a1.ch, str.data(), sizeof(QChar)*str.length());
             this->update();
         }

         for(int i=0;i<30;i++)
         qDebug()<<a.cha[i];
         qDebug()<<str;
         file->close();
         delete file;
     }
     else{
         QMessageBox::information(this,"错误文件","文件打开失败"+file->errorString());
         return;
     }
}

void MainWindow::saveFileSlot()
{
     QString fileName = QFileDialog::getSaveFileName(this,tr("保存文件"),QDir::currentPath());
     //qDebug()<<"the file name is "<<fileName;
     if(fileName.isEmpty()){
        QMessageBox::information(this,"错误文件","请重新选择一个文本文件");
        return;
         }
     QFile *file = new QFile;
     file->setFileName(fileName);
     bool ok=file->open(QIODevice::Text|QIODevice::WriteOnly);//只写文件的一种权限
     if(ok){
         QTextStream out(file);//文本流和文件相结合
         for(int i=0;a.ptr[i][0]!=NULL;i++)
         {
         out<< a.display(a.ptr[i][0])<<endl;
         }
         file->close();
         delete file;
     }
     else{
         QMessageBox::critical(this,"错误文件","文件保存失败"+file->errorString());
         return;
     }
}


