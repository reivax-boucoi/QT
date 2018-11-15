#ifndef LOGO_H
#define LOGO_H

#include "turtle.h"
#include "cmd.h"
#include <QDebug>
class Logo{
public:
    Logo(Turtle* t);
    void execute(QString str);
private:
    Turtle* t;
    Cmd cmds[];
    void command(QString cmd, int arg);
};
#endif // LOGO_H
