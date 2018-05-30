#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPainter>
#include <QRect>
#include <QBrush>
#include <QFont>
#include <iostream>
#include <QMessageBox>
#include <QScrollArea>
#include "Character.h"
#include "Chapter.h"
#include "Cursor.h"
#define XSTART 5
#define CXSTART 16
#define CURADD 17
char ch='0';
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("我们的miniword");
    QObject::connect(ui->actionOPEN,SIGNAL(triggered()),this, SLOT(openFileSlot()));
    QObject::connect(ui->actionOpen,SIGNAL(triggered()),this, SLOT(openFileSlot()));
    QObject::connect(ui->actionSAVE,SIGNAL(triggered()),this, SLOT(saveFileSlot()));
    QObject::connect(ui->actionSave,SIGNAL(triggered()),this, SLOT(openFileSlot()));
    QObject::connect(ui->actionNEW,SIGNAL(triggered()),this, SLOT(newFileSlot()));
    QObject::connect(ui->actionNew,SIGNAL(triggered()),this, SLOT(openFileSlot()));

    QObject::connect(ui->verticalScrollBar,SIGNAL(valueChanged(int)),this,SLOT(slot_ScroolWidget(int)));

   // mybar.start(30);
   // connect(&mybar,SIGNAL(timeout()),this,SLOT(update()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::update()
{
    this->repaint();
}


void MainWindow::mousePressEvent(QMouseEvent*e)
{
    int x=e->x(); int y=e->y();
    a.whetherMousevalid(x,y);
   // a.cur.judge(x,y);
    this->update();
    qDebug()<<x<<"shubiaox"<<y<<"shubiaoy";

}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    int x=e->x();
    int y=e->y();
    a.realeasePos(x,y);
    this->update();
    qDebug()<<x<<y<<"weizhi";
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


void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    if(a.cur.x2!=0)
    {
        QPen pen;  // creates a default pen
        pen.setWidth(26);
        pen.setBrush(Qt::blue);
        painter.setPen(pen);
        int tempx=0,tempy=0;
        int y=a.cur.y2;
        qDebug()<<a.cur.y2<<"y2";
        qDebug()<<a.cur.y<<"y";
        if((a.cur.y2>a.cur.y)||((a.cur.y2==a.cur.y)&&(a.cur.x2>a.cur.x)))
            {
               for(tempy=a.cur.y;tempy<=a.cur.y2;tempy++)
                if(tempy>a.cur.y&&tempy<a.cur.y2)
                {
                    for(int j=tempy;j<a.cur.y2;j++)
                    painter.drawLine(CXSTART,78+j*30,XSTART+a.charpos[tempy]*CURADD,78+j*30);
                    qDebug()<<a.cur.x2<<"x1";
                }
                else if(tempy==a.cur.y&&a.cur.y2>a.cur.y)
                {
                    painter.drawLine(CXSTART+a.cur.x*CURADD,78+tempy*30,XSTART+a.charpos[tempy]*CURADD,78+tempy*30);
                    qDebug()<<a.cur.x2<<"x2";
                }
                else if(tempy==a.cur.y&&a.cur.y2==a.cur.y)
                {
                    painter.drawLine(CXSTART+a.cur.x*CURADD,78+tempy*30,XSTART+a.cur.x2*CURADD,78+tempy*30);

                }
                else if(tempy==a.cur.y2&&a.cur.y2!=a.cur.y)
                {
                    painter.drawLine(CXSTART,78+tempy*30,XSTART+a.cur.x2*CURADD,78+tempy*30);
                    qDebug()<<a.cur.x2<<"x3";
                }
            }
        else if((y<=a.cur.y)||((a.cur.y2==a.cur.y)&&(a.cur.x2<a.cur.x)))
                {
                qDebug()<<"jinrule";
                    if(y==a.cur.y)
                    {
                        painter.drawLine(CXSTART+a.cur.x2*CURADD,78+a.cur.y*30,XSTART+a.cur.x*CURADD,78+a.cur.y*30);
                        qDebug()<<a.cur.x2<<"x2";
                        qDebug()<<"jinrule1";
                    }
                qDebug()<<y<<"inty";
                qDebug()<<a.cur.y2<<"y2";
                qDebug()<<a.cur.y<<"y";
                    if(y<a.cur.y)
                    {
                        for(tempy=a.cur.y;tempy>=y;tempy--)
                        {
                            if(tempy==y)
                            {
                                painter.drawLine(CXSTART+a.cur.x2*CURADD, 78+tempy*30, XSTART+a.charpos[tempy]*CURADD , 78+tempy*30);
                                qDebug()<<tempy<<"tempy1";
                                qDebug()<<"jinrule2";
                            }
                            else if(tempy==a.cur.y)
                            {
                                painter.drawLine(CXSTART, 78+tempy*30 , XSTART+a.cur.x*CURADD , 78+tempy*30);
                                qDebug()<<tempy<<"tempy2";
                                qDebug()<<"jinrule3";
                            }
                            else if(tempy<a.cur.y&&tempy>y)
                            {
                                for(int j=tempy;j>y;j--)
                                    painter.drawLine(CXSTART,78+j*30 , XSTART+a.charpos[tempy]*CURADD , 78+j*30);
                                qDebug()<<tempy<<"tempy3";
                                qDebug()<<"jinrule4";
                            }

                        }

                    }
                }

    }

    QTime current_time =QTime::currentTime();
    int msec = current_time.msec();//当前的毫秒
    if(msec<=500)
    painter.setPen(QColor(0, 0, 0));
    else
    painter.setPen(QColor(240, 240, 240));

    painter.drawLine(5+a.cur.x*different,65+a.cur.y*30-LineShowStart*5000,5+a.cur.x*different,90+a.cur.y*30-LineShowStart*5000);//画直线
    //0+a.cur.x*different,90+a.cur.y*30-LineShowStart*5000

    qDebug()<<a.cur.x<<"2ci";
    painter.setPen(QColor(100, 160, 230));

    // 设置字体：微软雅黑、点大小50、斜体
    QFont font;
    font.setFamily("宋体");
    font.setPointSize(18);
    font.setLetterSpacing(QFont::AbsoluteSpacing, 2);
    font.setCapitalization(QFont::SmallCaps);
    painter.setFont(font);



    for(int i=0;a.ptr[i][0]!=NULL;i++)
    {
        QPoint pt(XSTART,90+a.ptr[i][0]->seq[0]*30-LineShowStart*5000);
        painter.drawText(pt, a.display(a.ptr[i][0]));          // 创建QPainter一个对象
    }

}

MainWindow::slot_ScroolWidget(int value)
{
   double p=static_cast<double>(value)/static_cast<double>(ui->verticalScrollBar->maximum());
   //ui->background->move(0,-(ui->background->height()-350)*p);
   LineShowStart=p;

   this->update();
   return value;
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    int para=event->angleDelta().y();//获得鼠标滚轮的滚动距离para，para<0向下滚动，>0向上滚动
    int p=2;//设定鼠标滚轮每滚动一个单位，滑块就移动p个单位
    if (para<0)
    {

        //向下滚动，设定鼠标滚轮每滚动一个单位，滑块就移动p个单位
        //加入此判断的理由是，若当时滑块处于90的位置上，一旦继续下滑20个单位，就会超过最大范围100，show界面就会移动超出范围。
        if (ui->verticalScrollBar->value()+p<=100)
        {
            //发射verticalScrollBar的信号valueChange（value+20），连接到了我们之前写的slot_ScrollWidget(int)槽上
            emit ui->verticalScrollBar->valueChanged(ui->verticalScrollBar->value()+p);//verticalScrollBar的信号valueChange（value+20）;
            //设定滚动之后的滑块位置
            ui->verticalScrollBar->setSliderPosition(ui->verticalScrollBar->value()+p);
        }
        else
        {
            emit ui->verticalScrollBar->valueChanged(ui->verticalScrollBar->maximum());
            ui->verticalScrollBar->setSliderPosition(ui->verticalScrollBar->maximum());
        }
    }
    else
    {
        //向上滚动
        if (ui->verticalScrollBar->value()-p>=0)
        {
            emit ui->verticalScrollBar->valueChanged(ui->verticalScrollBar->value()-p);
            ui->verticalScrollBar->setSliderPosition(ui->verticalScrollBar->value()-p);
        }
        else
        {
            emit ui->verticalScrollBar->valueChanged(ui->verticalScrollBar->minimum());
            ui->verticalScrollBar->setSliderPosition(ui->verticalScrollBar->minimum());
        }
    }
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
             int i=0,j=0,k=0;
             str=in.read(100);
             memcpy(a.cha, str.data(), sizeof(QChar)*str.length());
             while(a.cha[i]!='0')
             {
                 if(a.cha[i]=='\xa')
                 {
                     a.ptr[k][0]->ch[j]=a.cha[i];
                     qDebug()<<"yes";
                     a.newLine();
                     a.charpos[k]=j-1;
                     k++;
                     j=0;
                     i++;
                 }
                 else
                 {
                 a.ptr[k][0]->ch[j]=a.cha[i];
                 i++;j++;
                 }
             }


             this->update();
         }

         for(int i=0;i<20;i++)
         {
             if(a.a1.ch[i]=='\xd')
                  qDebug()<<"yes";
         qDebug()<<a.a1.ch[i];
         }
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


