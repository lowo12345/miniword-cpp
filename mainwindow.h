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
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QTextStream>
#include <QScrollBar>
#include <QTime>
#include <QTimer>
#define different 17
#define linemax 50
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Chapter a;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    void wheelEvent(QWheelEvent *event);
    void mousePressEvent(QMouseEvent *e);
    //void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent (QKeyEvent *e);
private:
    Ui::MainWindow *ui;
    double LineShowStart=0;
    QTimer mybar;


//protected:
  //  void paintEvent(QPaintEvent *);

public slots:
    //bool  eventFilter (QObject *obj,QEvent *E);
private slots:
    void update();
    void openFileSlot();
    void saveFileSlot();
    void newFileSlot();
    void on_pushButton_clicked();
    slot_ScroolWidget(int);

};

#endif // MAINWINDOW_H
