#ifndef COMPUTERPICKER_H
#define COMPUTERPICKER_H

#include <vector>
#include <computer.h>


class ComputerPicker
{
public:
    ComputerPicker();
    void addComputer(computer computer);
    void clearComputers();
    void delLast();
    void showHigherCPUBench(int benchScore);
    void showHigherGPUBench(int benchScore);
    void showByLowerPrice(int price);


private:
    vector<computer> computers;
};

#endif // COMPUTERPICKER_H
