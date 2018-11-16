#ifndef LOGO_H
#define LOGO_H

#include "turtle.h"
#include <QDebug>
class Logo{
    struct cmd_t{
        QString name;
        int nb_args;
    };
    typedef struct cmd_t cmd_t;
public:
    Logo(Turtle* t);
    void execute(QString str);
    private:

        Turtle* t;
        void command(QString cmd, int arg);
};

#endif // LOGO_H
