#ifndef WAGON_H
#define WAGON_H

#include <string>

class Wagon{
    private:
        int id;
        std::string cargoType; 
    public:
        Wagon* nextWagon;
        Wagon();
        Wagon(std::string cargoType, int Id);
        Wagon* getNext();
        void setNext(Wagon* nextWagon);
        std::string getCargoType();
        int getId();
        void setCargoType(std::string cargoType);
        void setCargoIndex(int id);
};

#endif