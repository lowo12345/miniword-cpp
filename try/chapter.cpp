#include "Chapter.h"
#include "Character.h"
#include "mainwindow.h"
Chapter::Chapter()
{
    a1ptr=&a1;
    nowline=&a1;
    rightest=&a1;
    qDebug()<<a1ptr;
    qDebug()<<rightest;
    qDebug()<<nowline;
    a1ptr->seq[0] = 0;
    a1.seq[1] = 0;
    a1.left = NULL;
    a1.right = NULL;
    a1.up = NULL;
    a1.down = NULL;
    qDebug()<<"chapter init";

}


void Chapter::saveCharRight(char c)
{
    int i=0;
    for(i=0;rightest->ch[i]!='0';i++);
    if(i==99)
    {
        qDebug()<<i;
        qDebug()<<"100la";
        Character* now;
        now=new Character;
        rightest->right=now;
        now->left=rightest;
        now->seq[0]=rightest->seq[0];
        now->seq[1]=rightest->seq[1]+1;
        now->ch[0]=c;
        rightest=now;
        rightest->down=NULL;
        rightest->up=NULL;
        rightest->right=NULL;
        qDebug()<<now->seq[1];
        qDebug()<<"zheshiseq1dezhi";
    }
    else
    {
        rightest->ch[i]=c;
        qDebug()<<i;

    }

}

void Chapter::newLine()
{
    Character* now;
    now=new Character;
    nowline->down=now;
    rightest=now;
    now->up=nowline;
    now->seq[0]=nowline->seq[0]+1;
    now->seq[1]=nowline->seq[1];
    now->down=NULL;
    now->left=NULL;
    now->right=NULL;
    for(int i=0;i<100;i++)
      now->ch[i]='0';


    nowline=now;
    qDebug()<<now->seq[0];
}



QString Chapter::display(Character* nowptr)
{
    QString str;
    int i=0,j=0;
//    for()
    for(i=0;nowptr->ch[i]!='0';i++);

    //str=nowline->ch[i];
    return str = QString::fromLocal8Bit(nowptr->ch,i);
}


void Chapter::deletech()
{
    int i=0;
    for(i=0;rightest->ch[i]!='0';i++);
    i--;
    rightest->ch[i]='0';
    qDebug()<<i;


}

