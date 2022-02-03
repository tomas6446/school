#include <iostream>
#include <fstream>
const char FV[] = "U2.txt";
const char FD[] = "U2rez.txt";
using namespace std;

void sortstring(string &x, string &y)
{
    string t = x;
    x = y;
    y = t;
}

void sortint(int &x, int &y)
{
    int t = x;
    x = y;
    y = t;
}

int main(int argc, char** argv)
{
	ifstream fin(FV);

    string miest[30], apskr[30], uniqueapskr[30];
    int n, temp = 1;
    int sk[30], uniquesk[30] = {0};
    int minimum[30];

	fin >> n;
	for(int i = 0; i < n; i++)
    {
        fin >> miest[i] >> apskr[i] >> sk[i];
        uniqueapskr[i] = apskr[i];
    }

    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(uniqueapskr[i] > uniqueapskr[j])
            {
                sortstring(uniqueapskr[i], uniqueapskr[j]);
                sortstring(apskr[i], apskr[j]);
                sortint(sk[i], sk[j]);
            }
            else if(uniqueapskr[i] == uniqueapskr[j])
            {
                if(sk[i] > sk[j])
                {
                    sortint(sk[i], sk[j]);
                }
            }
        }
    }

    minimum[0] = sk[0];
    for(int i = 0; i < n-1; i++)
    {
        if(uniqueapskr[i] != uniqueapskr[i+1])
        {
            uniqueapskr[temp] = uniqueapskr[i+1];
            minimum[temp] = sk[i+1];
            temp++;
        }
    }

    for(int i = 0; i < temp; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(uniqueapskr[i] == apskr[j])
            {
                uniquesk[i] += sk[j];
            }
        }
    }

    for(int i = 0; i < temp-1; i++)
    {
        for(int j = i+1; j < temp; j++)
        {
            if(minimum[i] > minimum[j])
            {
                sortint(minimum[i], minimum[j]);
            }
            else if(minimum[i] == minimum[j])
            {
                if(uniqueapskr[i] > uniqueapskr[j])
                {
                    sortstring(uniqueapskr[i], uniqueapskr[j]);
                }
            }
        }
    }

    for(int i = 0; i < temp; i++)
    {
        cout << uniqueapskr[i] << " " << minimum[i] << " " << uniquesk[i] << endl;
    }


	fin.close();
	return 0;
}
