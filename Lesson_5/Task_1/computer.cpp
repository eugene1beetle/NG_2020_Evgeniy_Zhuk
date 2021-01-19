#include "computer.h"
#include <regex>

computer::computer() {}
computer::computer(motherboard mb, processor cpu, videocard gpu)
{
    setMotherboard(mb);
    this->gpu = gpu;
    setProcessor(cpu);
}

void computer::setProcessor(processor processor)
{
    if (this->getMotherboard().getSocket() != "NOSOCKET" && this->getMotherboard().getSocket() == processor.getSocket()) {
        this->cpu = processor;
    } else {
        printf("can't install processor, motherboard's socket is different\n");
    }
}

void computer::setMotherboard(motherboard motherboard)
{
    processor exampleProcessor;
    if (this->cpu.getCreator() == exampleProcessor.getCreator() &&
        this->cpu.getFrequency() == exampleProcessor.getFrequency() &&
        this->cpu.getGeneration() == exampleProcessor.getGeneration() &&
        this->cpu.getPrice() == exampleProcessor.getPrice())
    {
        this->mb = motherboard;
        return;
    }


    if (getProcessor().getSocket() != "NOSOCKET" && this->getProcessor().getSocket() == motherboard.getSocket()) {
        this->mb = motherboard;
    } else {
        printf("can't connect motherboard and processor\n");
    }
}

double computer::getPriceAll()
{
    return mb.getPrice() + cpu.getPrice() + gpu.getPrice();
}

void computer::printInfoAll()
{
    this->mb.printInfo();
    this->cpu.printInfo();
    this->gpu.printInfo();
}

