#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Transportas {
	string pavad; // название
	int marsrutu_sk; // сколько маршрутов на остановке
	int marsruto_numeris; // номер маршрута
} transp[100];

int ilgiausias(int n, int marsrutu_is_viso) {
    int kiek_marsrutu[marsrutu_is_viso] = {0}, maximum = 0, maximum_sk = kiek_marsrutu[0];
    for(int i = 0; i < marsrutu_is_viso; i++) {
        for(int j = 0; j < marsrutu_is_viso; j++) {
            if(transp[i].marsruto_numeris == transp[j].marsruto_numeris) {
                kiek_marsrutu[i]++; // сколко едениц, двоек, троек и т.д
            }
        }
        if(kiek_marsrutu[i] > maximum_sk) {
            maximum = i; // максимум
            maximum_sk = kiek_marsrutu[i];
        }
    }
    return maximum;
}
void read(int &n, int &marsrutu_is_viso) {
	char eil[20];
	ifstream fin("U2.txt");
	fin >> n;
	for(int i = 0; i < n; i++)
	{
        fin.ignore();
		fin.get(eil, sizeof eil);
		transp[i].pavad = eil;
		fin >> transp[i].marsrutu_sk;
		for(int j = marsrutu_is_viso; j < marsrutu_is_viso+transp[i].marsrutu_sk; j++) // все маршруты засунул в один массив
		{
			fin >> transp[j].marsruto_numeris;
		}
		marsrutu_is_viso += transp[i].marsrutu_sk;
	}
	fin.close();
}
void write(int n, int ilg) {
    ofstream fout("U2rez.txt");
    int marsrutu_is_viso = 0;
    fout << transp[ilg].marsruto_numeris << endl;
    for(int i = 0; i < n; i++) {
        for(int j = marsrutu_is_viso; j < marsrutu_is_viso+transp[i].marsrutu_sk; j++) {
           if(transp[j].marsruto_numeris == transp[ilg].marsruto_numeris) {
               fout << transp[i].pavad << endl;
           }
        }
        marsrutu_is_viso += transp[i].marsrutu_sk;
    }
    fout.close();
}
int main(int argc, char** argv) {
	int n, marsrutu_is_viso = 0;
	read(n, marsrutu_is_viso);
	int ilg = ilgiausias(n, marsrutu_is_viso);
	write(n, ilg);
	return 0;
}
