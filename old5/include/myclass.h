#ifndef __MYCLASS_H
#define __MYCLASS_H

class Mynumber {
    public:
        Mynumber(double i);
        Mynumber();
        void setter(double i);
        double getter();
    
    private:
        double num;
};

#endif