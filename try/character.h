#ifndef KEYQ_H
#define KEYQ_H
#include <fstream>
#include <QPainter>
#include <QRect>
#include <QBrush>
#include <QFont>
#include <QDebug>
#include <QMainWindow>
#include <QWidget>
#include <QKeyEvent>
#include <QString>

namespace Ui {
class MainWindow;
}

class Character
{
public:
 char  ch[102];
 Character* left,*right;  //如果内存超出限制则此指针指向新申请的内存
 Character* up,*down;
 char  c;
 int   seq[2];    //第一位是行号为 第二位是第几列

public:
    Character();
    void Display(QPainter &paint);
    void save(char c);
    QString display();


private:


};



#endif // KEYQ_H

