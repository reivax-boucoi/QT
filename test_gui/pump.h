#ifndef PUMP_H
#define PUMP_H


class Pump
{
public:
    Pump();
    void initialize();
    void setPosition(int p,char mode);
protected :

private :
    char address =1;
    int pos=0;
};

#endif // PUMP_H
