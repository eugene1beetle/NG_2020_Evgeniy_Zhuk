#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string s = " whuujydwi, ishyfj ayttyu. tutius yi wbqt je adem, jxqj oek fqiiut vyhij fqhj ev ekh juij qdt icqhj udekwx, je xubf ki.\n mu xqsaut ydiytu oekh jhqydydw fhewhqc, je vydt dum qwudji. yv oek mqdj tyw tuufuh yd jxu hqrryj xebu... mubsecu je jxu tqha duj :3\n yv oek mqdj cehu ydjuhuijydw ijkvv - zkij fkix oekh tushofjyed setu je oekh wyj hufe ydiytu \"busjyed_3\" vebtuh qdt dqcu yj \"sqhhej.sff\". edsu oek tedu jxqj - jxuhu'i de mqo rqsa.\n hucucruh: dereto ixekbt adem qrekj oekh setu eh ekh \"byjjbu\" sxqj. ijqo jkdut :3";

    int strLenght = s.length();
    char charArray[strLenght];
    strcpy(charArray, s.c_str());

    int cezar = 10;
    for (int i = 0; i < strLenght; i++)
    {
        if (charArray[i] >= 'a' && charArray[i] <= 'z')
        {
            charArray[i] += cezar;
            if (charArray[i] > 'z') charArray[i] -= 26;
            if (charArray[i] < 'a') charArray[i] += 26;
            if (charArray[i] < 0) charArray[i] += 204;
        }
    }

    for (int i = 0; i < strLenght; i++) cout << charArray[i];
    cout << endl;
    return 0;
}
