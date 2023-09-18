#ifndef TRAIN_H
#define TRAIN_H

#include "wagon.h"//wagon

class Train:public Wagon{//train
    private:
        Wagon* first;
        int size;
    public:
        Train();
        Wagon* at(int i = 0); 
        void pop();
        void push(Wagon* wagonP);
        int getSize();
};

#endif