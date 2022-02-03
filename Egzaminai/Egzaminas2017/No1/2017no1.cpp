#include <iostream>
#include <fstream>
using namespace std;
void Konvertavimas(int skaicius, int &pirmas, int &antras)
{
    pirmas = skaicius/16;
    antras = skaicius%16;
}
int main()
{
    ifstream fin("U1.txt");
    ofstream fout("U1rez.txt");
    int a, b, skaicius, pirmas, antras;
	fin >> a >> b;
	for(int i = 0; i < a*b; i++)
	{
	    if(i == a+1)
            cout << endl;
        else if(i+1 != a+1)
            cout << ";";
		for(int y = 0; y < b; y++)
        {
            fin >> skaicius;
            Konvertavimas(skaicius, pirmas, antras);
            if(pirmas >= 10 && pirmas <= 15)
            {
                switch(pirmas)
                {
                    case 10: cout << "A";
                        break;
                    case 11: cout << "B";
                        break;
                    case 12: cout << "C";
                        break;
                    case 13: cout << "D";
                        break;
                    case 14: cout << "E";
                        break;
                    case 15: cout << "F";
                        break;
                };
            }
            else cout << pirmas;
            if(antras >= 10 && antras <= 15)
            {
                switch(pirmas)
                {
                    case 10: cout << "A";
                        break;
                    case 11: cout << "B";
                        break;
                    case 12: cout << "C";
                        break;
                    case 13: cout << "D";
                        break;
                    case 14: cout << "E";
                        break;
                    case 15: cout << "F";
                        break;
                };
            }
            else cout << antras;
        }

	}
	fin.close();
    return 0;
}
