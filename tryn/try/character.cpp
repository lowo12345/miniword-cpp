#include "Character.h"
#include <QString>
Character::Character()
{
        int i=0;
        for(i=0;i<100;i++)
          ch[i]='0';



}
/*
void Character::save(QChar c)
{
    int i=0;
    for(i=0;ch[i]!='0';i++);
       ch[i]=c;

}

QString Character::display()
{
    QString str;
    int i=0;
    for(i=0;ch[i]!='0';i++);
    this->n=i;
    str=ch[i];
    return str=QString(str);
}
*/
