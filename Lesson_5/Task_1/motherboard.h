#ifndef MOTHERBOARD_H
#define MOTHERBOARD_H

#include <string>
#include <vector>

using namespace std;

class motherboard
{
public:
    motherboard();
    motherboard(string creator, string name, string socket, double value);

    void setCreator(string creator) { this->creator = creator; };
    string getCreator() { return creator; };

    void setName(string name) { this->name = name; };
    string getName() { return name; };

    void setSocket(string socket) { this->socket = socket; };
    string getSocket() { return socket; };

    void setPrice(double price);
    double getPrice() { return price; };

    void printInfo();

private:
    string creator;
    string name;
    string socket;
    double price;
};

#endif // MOTHERBOARD_H
