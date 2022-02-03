#include <iostream>
#include <fstream>
using namespace std;

struct Geles {
    int index, dien, pabdien;
} gel[30];

const int MAXDIENU = 92;

int turnIndays(int men){
    if(men == 7) // do sedjmogo mesiaca 30 dnej
        return 30; // 0 v massive chitajetsia kak pervoje chislo v date
    else if(men == 8)
        return 61;
    else
        return 0;
}

void kiekdidz(int n, int &x, int &maximum, int dienos[]){
    maximum = 0;
    int indexofmax;

    for(int i = 0; i < MAXDIENU; i++) {
        if(maximum < dienos[i])
        {
            maximum = dienos[i]; // maximum cvetov
            indexofmax = i; // nachalo periuda kogda maximum cvetov
        }
    }
    for(int i = 0; i < n; i++) {
       if(gel[i].dien-1 == indexofmax)
           x = i;
    }
}

void read(int &n, int dienos[]){
    ifstream fin("U1.txt");
    fin >> n;

    for(int i = 0; i < n; i++)
    {
        int men, pabmen;
        fin >> gel[i].index >> men >> gel[i].dien >> pabmen >> gel[i].pabdien;
        gel[i].dien += turnIngays(n, men); // <---- gay
        gel[i].pabdien += turnIndays(n, pabmen);

        for(int j = gel[i].dien-1; j < gel[i].pabdien; j++)
            dienos[j] += 1;

        cout << gel[i].index << " " << gel[i].dien << " "  << gel[i].pabdien << " dnej: " << gel[i].pabdien - gel[i].dien << " { " << gel[i].dien << " ; " << gel[i].pabdien << " } " << endl;
        for(int j = 0; j < MAXDIENU; j++) // chtoby posmotretj kak ja zapolnial massiv
        {
            cout << dienos[j] << " ";
            if(j%7 == 0 || j == 0) // dlia udobstva smotretj
                cout << endl;
            else if(j != 0 && j%7 != 0)
                cout << " ";
        }
        cout << endl;
    }
    fin.close();
}

void result(int x, int k, int maximum){
    ofstream fout("U1rez.txt");
    fout << maximum << endl;

    if(gel[x].dien > 61)
        fout << "8 " << gel[x].dien-61 << " ";
    else if(gel[x].dien > 30)
        fout << "7 " << gel[x].dien-30 << " ";
    else
        fout << "6 " << gel[x].dien << " ";


    if(gel[x].dien+k > 61)
        fout << "8 " << gel[x].dien+k-61 << " ";
    else if(gel[x].dien+k > 30)
        fout << "7 " << gel[x].dien+k-30 << " ";
    else
        fout << "6 " << gel[x].dien+k << " ";

    fout.close();
}

int main(){
    int dienos[MAXDIENU] = {0};
    int n, prad, pab, x, maximum, k = 0;
    read(n, dienos);
    kiekdidz(n, x, maximum, dienos);
    for(int i = 0; i < MAXDIENU; i++)
    {
        if(dienos[i] == maximum)
        {
            k++;
            if(dienos[i+1] != maximum)
                break;
        }
    }

    //ti pidoras zasosi huj pidrila
    // ty medlinyj huj idi nahui
    // gandon ebannyj
    result(n, x, k-1, maximum);
    return 0;
}
