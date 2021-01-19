#include "motherboard.h"

motherboard::motherboard()
{
    setCreator("NOCREATOR");
    setName("NONAME");
    setSocket("NOSOCKET");
    setPrice(0);
}

motherboard::motherboard(string creator, string name, string socket, double value)
{
    setCreator(creator);
    setName(name);
    setSocket(socket);
    setPrice(value);
}

void motherboard::setPrice(double price)
{
    if (price > 0) this->price = price;
    else this->price = 0;
}

void motherboard::printInfo()
{
    printf("Motherboard:\n");
    printf("\tCreator: %s\n", getCreator().c_str());
    printf("\tName: %s\n", getName().c_str());
    printf("\tSocket: %s\n", getSocket().c_str());
    printf("\tPrice: %.2f\n", getPrice());
}
