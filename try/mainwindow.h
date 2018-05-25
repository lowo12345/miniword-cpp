#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QString>
#include <QMainWindow>
#include <QWidget>
#include <QKeyEvent>
#include <QDebug>
#include <QPainter>
#include <QRect>
#include <QBrush>
#include <QFont>
#include <iostream>
#include <QMessageBox>
#include "paint.h"
#include "Character.h"
#include "Chapter.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Character Q;
    Chapter a;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void keyPressEvent (QKeyEvent *);
     void paintEvent(QPaintEvent *event);

private:
    Ui::MainWindow *ui;

//protected:
  //  void paintEvent(QPaintEvent *);


private slots:
    void update();

    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
