#ifndef CURSOR_H
#define CURSOR_H


class cursor
{

    int x,y;  //存储鼠标坐标
public:
    cursor();
    void cursorLeft();
    void cursorRight();
    void cursorUp();
    void cursorDown();
    void cursorMouseMove();
    void display();
};

#endif // CURSOR_H
