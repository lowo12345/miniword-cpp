#include "Chapter.h"
#include "Character.h"
#include "mainwindow.h"
#include "Cursor.h"
Chapter::Chapter()
{
    int i,j;
    for(i=0;i<100;i++)
        for(j=0;j<20;j++)
        {
            ptr[i][j]=NULL;
        }
    for(i=0;i<100;i++)
        this->charpos[i]=0;
    for(i=0;i<100;i++)
        cha[i]='0';
    QChar cha[100];
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
    ptr[0][0]=a1ptr;

}


void Chapter::saveCharRight(QChar c)
{
    int i=0;
    for(i=0;ptr[cur.y][0]->ch[i]!='0';i++);
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
        ptr[now->seq[0]][now->seq[1]]=rightest;
    }
    else
    {
        ptr[cur.y][0]->ch[i]=c;
        qDebug()<<i;

    }
    for(i=0;ptr[cur.y][0]->ch[i]!='0';i++);
    cur.x=i;
    charpos[cur.y]=i;
    qDebug()<<i<<"charpos";
}

void Chapter::newLine()
{
    int i;
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
    ptr[nowline->seq[0]][nowline->seq[1]]=nowline;

    cur.y=now->seq[0];

    charpos[cur.y]=0;
    linepos++;
    cur.x=0;

}



QString Chapter::display(Character* nowptr)
{
    QString str;
    int i=0,j=0;
//    for()
    for(i=0;nowptr->ch[i]!='0';i++);
    //str=nowline->ch[i];
    return str = QString(nowptr->ch,i);
}

void Chapter::saveCharpos(QChar c)
{
    int i=0,j=0;
    for(j=0;ptr[cur.y][0]->ch[j]!='0';j++);
    qDebug()<<cur.y<<"asvecharlimiandecury";
    i=cur.x-1;j--;
    for(;j>i;j--)
    {
        ptr[cur.y][0]->ch[j+1]=ptr[cur.y][0]->ch[j];
    }

    ptr[cur.y][0]->ch[i+1]=c;
        qDebug()<<i;
    charpos[cur.y]++;
    cur.x=i+2;
}

void Chapter::deletech()
{
    int i=0;
    for(i=0;ptr[cur.y][0]->ch[i]!='0';i++);
    i--;
    ptr[cur.y][0]->ch[i]='0';

    cur.x--;
    charpos[cur.y]--;
    qDebug()<<i;


}

void Chapter::deleteCharpos()
{
    int i=0,j=0;
    for(j=0;ptr[cur.y][0]->ch[j]!='0';j++);
    i=this->cur.x;j--;
    for(;i<=j;i++)
    {
        ptr[cur.y][0]->ch[i]=ptr[cur.y][0]->ch[i+1];
    }
    charpos[cur.y]--;
    cur.x--;
}

void Chapter::cursorUp()
{
    if(cur.y>0&&charpos[cur.y-1]>=cur.x)
    {
        cur.y--;
    }
    else if(cur.y>0&&charpos[cur.y-1]<cur.x)
    {
        cur.y--;
        cur.x=charpos[cur.y];
        for(int i=0;i<4;i++)
            qDebug()<<charpos[i]<<"charpos";
    }
}

void Chapter::cursorDown()
{
    if(cur.y<linepos&&charpos[cur.y+1]>=cur.x)
    {
        cur.y++;
    }
    else if(cur.y<linepos&&charpos[cur.y+1]<cur.x)
    {
        cur.y++;
        cur.x=charpos[cur.y];
        for(int i=0;i<4;i++)
            qDebug()<<charpos[i]<<"charpos";
    }
}
