#include "Cursor.h"

Cursor::Cursor()
{
    x=0;y=0;
}

void Cursor::left()
{
    this->x--;
}

void Cursor::right()
{
    this->x++;
}
