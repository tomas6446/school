#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("U1duom.txt");
    int n, m, num;
    bool nebuvo = true;
    int Lina[500] = {0}, Jurgis[500] = {0};
    fin >> n >> m;
    for(int i = 0; i < n; i++) { // Lina
        fin >> num;
        Lina[num]++;
    }
    for(int i = 0; i < m; i++) { // Jurgis
        fin >> num;
        Jurgis[num]++;
    }
    fin.close();

    ofstream fout("U1rez.txt");
    for(int i = 0; i < 500; i++) {
        if(Lina[i] > 1 && Jurgis[i] == 0) { // Linos pasiulymas
            fout << i << " ";
            nebuvo = false;
        }
    }
    if(nebuvo == true) {
        fout << "0 ";
    }
    fout << endl;
    nebuvo = true;
    for(int i = 0; i < 500; i++) {
        if(Jurgis[i] > 1 && Lina[i] == 0) { // Jurgio pasiulymas
            fout << i << " ";
            nebuvo = false;
        }
    }
    if(nebuvo == true) {
        fout << "0 ";
    }
    fout << endl;
    for(int i = 0; i < 500; i++) {
        if(Lina[i] != 0 || Jurgis[i] != 0) { // Bendras sarasas
            fout << i << " ";
        }
    }
    fout << endl;
    fout.close();
    return 0;
}

