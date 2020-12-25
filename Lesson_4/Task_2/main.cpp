#include <iostream>

using namespace std;

void drawLine(int num)
{
    if (num < 0) return;
    cout << "*";
    num--;
    drawLine(num);
}

void drawSpaces(int num)
{
    if (num < 0) return;
    cout << " ";
    num--;
    drawSpaces(num);
}

void drawFigure3(int num)
{
    num--;
    if (num < 0) { cout << endl; return; }
    drawLine(num);
    cout << endl;
    drawFigure3(num);
}

void drawFigure1(int num, int counter)
{
    if (counter >= num) { cout << endl; return; }
    drawLine(counter);
    cout << endl;
    counter++;
    drawFigure1(num, counter);
}

void drawFigure2(int num, int counter)
{
    if (num < 0) { cout << endl; return; }
    if (counter != 0)
    {
        drawSpaces(num - 1);
        drawLine(counter -  1);
        cout << endl;
    }
    drawFigure2(--num, ++counter);
}

void drawFigure4(int num, int counter)
{
    if (num < 0) { cout << endl; return; }
    drawSpaces(counter - 1);
    drawLine(num - 1);
    cout << endl;
    drawFigure4(--num, ++counter);

}

void drawSquare(int num, int counter)
{
    if (counter >= num) { cout << endl; return; }
    drawLine(num);
    cout << endl;
    counter++;
    drawSquare(num, counter);
}

void drawFigure1(int num)
{
    drawFigure1(num, 0);
}

void drawFigure2(int num)
{
    drawFigure2(num, 0);
}

void drawFigure4(int num)
{
    drawFigure4(num, 0);
}

void drawSquare(int num)
{
    drawSquare(num, 0);
}



int main()
{
    int num = 7;

    drawSquare(num);

    drawFigure1(num);

    drawFigure2(num);

    drawFigure3(num);

    drawFigure4(num);

    return 0;
}
