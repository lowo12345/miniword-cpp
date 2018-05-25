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

public:
    Chapter();
    void saveCharRight(char c);
    void newLine();
    QString display(Character*);
    void deletech();
};





#endif // CHAPTER_H
