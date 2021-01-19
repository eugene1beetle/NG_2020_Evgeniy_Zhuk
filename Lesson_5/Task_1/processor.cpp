#include "processor.h"

processor::processor(string creator, int frequency, string generation, string socket, int benchScore, double value)
{
    setCreator(creator);
    setFrequency(frequency);
    setGeneration(generation);
    setSocket(socket);
    setBenchScore(benchScore);
    setPrice(value);
}

processor::processor()
{
    setCreator("NOCREATOR");
    setFrequency(0);
    setGeneration("NOGEN");
    setSocket("NOCOCKET");
    setBenchScore(0);
    setPrice(0);
}

void processor::setPrice(double value)
{
    if (value > 0) this->price = value;
    else this->price = 0;
}

void processor::setFrequency(int frequency)
{
    if (frequency > 0) this->frequency = frequency;
    else this->frequency = 0;
}

void processor::printInfo()
{
    printf("Processor:\n");
    printf("\tCreator: %s\n", getCreator().c_str());
    printf("\tFrequency: %d\n", getFrequency());
    printf("\tGeneration: %s\n", getGeneration().c_str());
    printf("\tSocket: %s\n", getSocket().c_str());
    printf("\tBench score: %d\n", getBenchScore());
    printf("\tPrice: %.2f\n", getPrice());
}
