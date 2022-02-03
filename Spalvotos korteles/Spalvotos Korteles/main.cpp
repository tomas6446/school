#include <iostream>
#include <fstream>
using namespace std;
const int N = 100;

struct Korteles {
    string spalva; // цвет
    char sp; // первая буква цвета
    int num, parengta = 0, teisingai = 0, kiek; // номер цвета, сколько карточек использовано, сколько правельных, сколько карточек осталось
} kort[N]; // карточек от 1 до 10

struct Mokyniai {
    string vardas; // имя
    char sp[11]; // первая буква цвета
    int num[11], teisingai = 0; // номер цвета, сколько правельных карточек.
} mok[N];

void skaityti(int &n, int &m, int &p) {
    char eil[15];
    ifstream fin("Pradiniai duomenys.txt");
    fin >> n;
    for(int i = 0; i < n; i++) {
        fin.ignore();
        fin.get(eil, sizeof eil);
        kort[i].spalva = eil;
        fin >> kort[i].sp >> kort[i].num >> kort[i].kiek;
    }
    fin >> m >> p;
    for(int i = 0; i < m; i++) {
        fin.ignore();
        fin.get(eil, sizeof eil);
        mok[i].vardas = eil;
        for(int j = 0; j < p; j++) {
            fin >> mok[i].sp[j] >> mok[i].num[j];
        }
    }
    fin.close();
}
void informacija(int n, int m, int p) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < p; j++) {
            for(int x = 0; x < n; x++) {
                if(kort[x].sp == mok[i].sp[j]) { // первая буква цвета совпадает с буквой у ученика
                    kort[x].kiek--; // всего карточек этого цвета на один меньше
                    kort[x].parengta++; // сколько карточек использовано
                    if(kort[x].num == mok[i].num[j]) { // правильно написал цифру
                        mok[i].teisingai++; // сколько ученик написал правильно
                        kort[x].teisingai++; // сколько таких цветов написали правильно
                    }
                }
            }
        }
    }
}
void rezultatas(int m, int n) {
    ofstream fout("Rezultatai.txt");
    for(int i = 0; i < m; i++) {
        fout << mok[i].vardas << " " << mok[i].teisingai << endl;
    }
    for(int i = 0; i < n; i++) {
        fout << kort[i].spalva << kort[i].parengta << " " << kort[i].teisingai << " "<< kort[i].kiek << endl;
    }
    fout.close();
}
int main()
{
    int n, m, p, teisingai;
    skaityti(n, m, p);
    informacija(n, m, p);
    rezultatas(m, n);
    return 0;
}
