#ifndef VIDEOCARD_H
#define VIDEOCARD_H

#include <string>

using namespace std;

class videocard
{
public:
    videocard();
    videocard(string name, string series, double price, int benchScore);

    void setName(string name) { this->name = name; };
    string getName() { return name; };

    void setSeries(string series) { this->series = series; };
    string getSeries() { return series; };

    void setPrice(double price);
    double getPrice() { return price; };

    void setBenchScore(int benchScore) { this->benchScore = benchScore; };
    int getBenchScore() { return benchScore; };

    void printInfo();

private:
    string name;
    string series;
    double price;
    int benchScore;
};

#endif // VIDEOCARD_H
