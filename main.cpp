#include "train.h"
#include <iostream>
#include <fstream>

void consoleIn(Train* trainToFill){
    
    int size;
    std::cin >> size;
    for (int i = 0; i < size; i++)
    {
        std::string str;
        int wId;
        Wagon* wagon = new Wagon;
        std::cout << ">> Train: " << size - i <<"\n";
        std::cout << ">> Type of Train: \n < ";
        std::cin >> str;
        wagon->setCargoType(str);
        std::cout << ">> Train Id: \n < ";
        std::cin >> wId;
        wagon->setCargoIndex(wId);
        trainToFill->push(wagon);
        std::cout << "___\n";
    }
}

void fileIn(Train* trainToFill){

    std::ifstream file("train.txt");
    int fSize;
    std::string ftype;
    int findex;
    file >> fSize;
    for(int i = 0; i < fSize; i++)
    {
        Wagon* wagon = new Wagon;
        file >> ftype >> findex;
        wagon->setCargoType(ftype);
        wagon->setCargoIndex(findex);
        trainToFill->push(wagon);
    }
}

int main()
{
    Train trainToSort, Sorted1, Sorted2;
    int sw;
    std::cout << "Enter 1 for Console Input, Enter 2 for File Input\n";
    std::cin>> sw;
    switch (sw)
    {
    case 1:
        consoleIn(&trainToSort);
        break;
    case 2:
        fileIn(&trainToSort);
        break;
    default:
        fileIn(&trainToSort);
        break;
    }
    Wagon* Current;
    int size = trainToSort.getSize();
    std::cout << "Size of Initial Train: " << size << '\n';
    for (int i = 0; i < size; i++)
    {
        Current = trainToSort.at(0);
        trainToSort.pop();

        if (Current->getCargoType() == "coal")
        {
            Sorted1.push(Current);
        }
        else 
        {
            Sorted2.push(Current);
        }
    }
        std::cout << "Sort finished: \n"
            << "Initial Train: " << trainToSort.getSize() << '\n' 
                << "Coal trains: " << Sorted1.getSize() << '\n' 
                    << "Wood trains: " << Sorted2.getSize() << '\n';
        int size_sr1 = Sorted1.getSize(), size_sr2 = Sorted2.getSize();
        for (int i = 0; i < size_sr1; i++)
        {
            std::cout << "Cargo: " << Sorted1.at(i)->getCargoType() 
                    << " |Id: " << Sorted1.at(i)->getId() << "\n";
        }
        std::cout << "========================\n";
        for (int i = 0; i < size_sr2; i++)
        {
            std::cout << "Cargo: " << Sorted2.at(i)->getCargoType() 
                    << " |Id: " << Sorted2.at(i)->getId() << "\n";
        }

    return 0;
}
