#include <iostream>
#include <fstream>
using namespace std;

int komplektas(int komplekt[])
{
    int temp = 0;
    while(komplekt[0] >= 8 && komplekt[1] >= 2 && komplekt[2] >= 2 && komplekt[3] >= 2 && komplekt[4] >= 1 && komplekt[5] >= 1)
    {
        komplekt[0] -= 8;
        komplekt[1] -= 2;
        komplekt[2] -= 2;
        komplekt[3] -= 2;
        komplekt[4] -= 1;
        komplekt[5] -= 1;
        temp++;
    }
    return temp;
}

int main()
{
    ifstream fin("U1.txt");
    int komplekt[6] = {0};
    int n, pest, boks, zirg, rik, karal, vald;
    fin >> n;
    for(int i = 0; i < n; i++)
    {
        fin >> pest >> boks >> zirg >> rik >> karal >> vald;
        komplekt[0] += pest;
        komplekt[1] += boks;
        komplekt[2] += zirg;
        komplekt[3] += rik;
        komplekt[4] += karal;
        komplekt[5] += vald;
    }
    int komp = komplektas(komplekt);
    cout << komp << endl;
    fin.close();
    return 0;
}
