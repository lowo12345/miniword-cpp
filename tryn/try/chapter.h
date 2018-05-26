#ifndef CHAPTER_H
#define CHAPTER_H
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
#include <Character.h>
#include "Cursor.h"

namespace Ui {
class MainWindow;
}
class Chapter
{
public:
    int Cnewline;
    Character a1;
    Character* a1ptr;
    Character* rightest;
    Character* nowline;
    Cursor cur;
    Character* ptr[100][20];
    int charpos[100];
    int linepos=0;
    QChar cha[100];
public:
    Chapter();
    void saveCharRight(QChar c);
    void newLine();
    QString display(Character*);
    void deletech();
    void saveCharpos(QChar c);
    void deleteCharpos();
    void cursorUp();
    void cursorDown();
};





#endif // CHAPTER_H
