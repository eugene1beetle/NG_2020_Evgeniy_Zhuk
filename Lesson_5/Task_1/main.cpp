#include <iostream>

#include "videocard.h"
#include "processor.h"
#include "processor.h"
#include "computer.h"
#include "computerpicker.h"

using namespace std;

int main()
{
    motherboard mb = *new motherboard("MSI", "A-PRO MAX", "AM4", 50);
    processor cpu = *new processor("AMD", 3400, "ZEN+", "AM4", 50, 100);
    videocard gpu = *new videocard("1060 3GB", "GTX", 150, 75);

    computer pc = *new computer(mb, cpu, gpu);

    ComputerPicker picker;
    picker.addComputer(pc);

    processor modifedCPU = pc.getProcessor();
    modifedCPU.setBenchScore(78);
    pc.setProcessor(modifedCPU);

    mb = *new motherboard("Gigabyte", "B450m-s2h", "AM4", 25);
    cpu = *new processor("AMD", 3700, "ZEN", "AM4", 60, 40);
    gpu = *new videocard("1030", "GTX", 80, 50);

    pc = *new computer(mb, cpu, gpu);

    picker.addComputer(pc);

    picker.showByLowerPrice(300);

    picker.showHigherCPUBench(50);

    return 0;
}
