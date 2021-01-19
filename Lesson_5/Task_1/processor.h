#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <string>

using namespace std;

class processor
{
public:
    processor();
    processor(string creator, int frequency, string generation, string socket, int benchScore, double value);

    void setSocket(string socket) { this->socket = socket; };
    string getSocket() { return socket; };

    void setCreator(string creator) { this->creator = creator; };
    string getCreator() { return creator; };

    void setGeneration(string generation) { this->generation = generation; };
    string getGeneration() { return generation; };

    void setFrequency(int frequency);
    int getFrequency() { return frequency; };

    void setPrice(double price);
    double getPrice() { return price; };

    void setBenchScore(int benchScore) { this->benchScore = benchScore; };
    int getBenchScore() { return benchScore; };

    void printInfo();

private:
    string socket;
    string creator;
    string generation;
    int benchScore;
    int frequency;
    double price;
};

#endif // PROCESSOR_H
