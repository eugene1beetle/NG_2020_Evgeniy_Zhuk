#ifndef COMPUTER_H
#define COMPUTER_H

#include "motherboard.h"
#include "processor.h"
#include "videocard.h"

class computer
{
public:
    computer();
    computer(motherboard mb, processor cpu, videocard gpu);

    void setMotherboard(motherboard mb);
    motherboard getMotherboard() { return mb; };

    void setProcessor(processor cpu);
    processor getProcessor() { return cpu; };

    void setVideocard(videocard gpu) { this->gpu = gpu; };
    videocard getVideocard() { return gpu; };

    double getPriceAll();
    void printInfoAll();

private:
    motherboard mb;
    processor cpu;
    videocard gpu;
};

#endif // COMPUTER_H
