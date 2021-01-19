#include "videocard.h"

videocard::videocard(string name, string series, double price, int benchScore)
{
    setName(name);
    setSeries(series);
    setPrice(price);
    setBenchScore(benchScore);
}

videocard::videocard()
{
    setName("NONAME");
    setSeries("NOSERIES");
    setPrice(0);
    setBenchScore(0);
}

void videocard::setPrice(double price)
{
    if (price > 0) this->price = price;
    else this->price = 0;
}

void videocard::printInfo()
{
    printf("Videocard:\n");
    printf("\tName: %s\n", getName().c_str());
    printf("\tSeries: %s\n", getSeries().c_str());
    printf("\tBenchScore: %d\n", getBenchScore());
    printf("\tPrice: %.2f\n", getPrice());
}
