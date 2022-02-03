#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int n;
    double masse[21];
    ifstream fin("Pradiniai duomenys.txt");
    fin >> n;
    for(int i = 1; i <= n; i++) {
        fin >> masse[i];
    }
    fin.close();
    double maxnum = masse[0];
    int maxim1 = 0, maxim2 = 0;
    for(int i = 1; i <= n; i++) {
        if(masse[i-1] + masse[i] > maxnum && masse[i-1] != 0 && masse[i] != 0) {
            maxnum = masse[i-1] + masse[i];
            maxim1 = i-1;
            maxim2 = i;
        }
    }
    ofstream fout("Rezultatai.txt");
    if(maxim1 == 0 && maxim2 == 0) {
        fout << "Poru nesurasta" << endl;
    }
    else {
        fout << maxim1 << " " << masse[maxim1] << endl;
        fout << maxim2 << " " << masse[maxim2] << endl;
    }
    fout.close();
    return 0;
}
