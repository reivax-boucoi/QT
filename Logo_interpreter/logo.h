#ifndef LOGO_H
#define LOGO_H

#include "turtle.h"
#include <QDebug>
class Logo{
public:
    Logo(Turtle* t);
    void execute(QString str);
private:
    Turtle* t;
    typedef void (*fn_ptr)(float);
    std::map<QString , fn_ptr> cmdLookUp;
    void command(QString cmd, int arg);
};
#endif // LOGO_H
