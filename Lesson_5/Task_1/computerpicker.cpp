#include "computerpicker.h"

ComputerPicker::ComputerPicker()
{

}

void ComputerPicker::addComputer(computer computer)
{
    computers.push_back(computer);
}

void ComputerPicker::clearComputers()
{
    computers.clear();
}

void ComputerPicker::delLast()
{
    computers.pop_back();
}

void ComputerPicker::showHigherCPUBench(int benchScore)
{
    printf("Starting search pc by CPU bench score highter than %d...\n", benchScore);
    int counter = 1;
    for (computer tmp : computers) {
        if (tmp.getProcessor().getBenchScore() > benchScore) {
            printf("Found %dst computer, stats:\n", counter);
            tmp.printInfoAll();
            counter++;
        }
    }
}

void ComputerPicker::showHigherGPUBench(int benchScore)
{
    printf("Starting search pc by GPU bench score highter than %d...\n", benchScore);
    int counter = 1;
    for (computer tmp : computers) {
        if (tmp.getVideocard().getBenchScore() > benchScore) {
            printf("Found %dst computer, stats:\n", counter);
            tmp.printInfoAll();
            counter++;
        }
    }
}

void ComputerPicker::showByLowerPrice(int price)
{
    printf("Starting search pc that costs lower than %d...\n", price);
    int counter = 1;
    for (computer tmp : computers) {
        double tmpAllPrice = tmp.getPriceAll();
        if (tmpAllPrice < price) {
            printf("Found %dst computer, stats:\n", counter);
            tmp.printInfoAll();
            printf("Total price: %.2f\n", tmpAllPrice);
            counter++;
        }
    }
}

