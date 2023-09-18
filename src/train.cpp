#include "train.h"
#include <iostream>

Train::Train(){
    this->size=0;
    this->first=nullptr;
}

Wagon* Train::at(int i){
    if (i >= this->size) return nullptr;
    Wagon* ans = this->first;
    while(i > 0)
    {
        if (ans->nextWagon == nullptr) return nullptr;
        ans = ans->nextWagon;
        i--;
    }
    return ans;
}

void Train::pop(){

    if(this->size != 0)
    {
        this->first = this->first->getNext();
        this->size--;
    }
    else
    {
        this->first = nullptr;
        this->size = 0;
    }
}

void Train::push(Wagon* wagonP){
    if(size == 0){
        this->first = wagonP;
        this->size++;
    }
    else
    {
        wagonP->setNext(this->first);
        this->first = wagonP;
        this->size++;
    }
}

int Train::getSize(){
    return this->size;
}

