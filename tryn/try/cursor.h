#ifndef CURSOR_H
#define CURSOR_H


class Cursor
{
public:

    int x,y;
    int now;



public:
    Cursor();
    int showcursor();
    void left();
    void right();
};

#endif // CURSOR_H
