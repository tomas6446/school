#include <iostream>
#include <fstream>

using namespace std;

struct Staciakampiai {
    int x, y, dx, dy;
    int R, G, B;
};

struct Piesinys {
    int R[100];
    int G[100];
    int B[100];
};

void Paint(Staciakampiai st[], Piesinys pies[], int a, int b, int i) // risuju
{
    //cout << st[i].R << " " << st[i].G << " " << st[i].B << endl; // dlia proverki
    for(int j = st[i].y; j < (st[i].y+st[i].dy); j++)
    {
        for(int z = st[i].x; z < (st[i].x+st[i].dx); z++)
        {
            //cout << "{ " << z << "; " << j << " }" << endl; // dlia proverki
            pies[j].R[z] = st[i].R;
            pies[j].G[z] = st[i].G;
            pies[j].B[z] = st[i].B;
        }
    }
}

void maxXY(int n, int &a, int &b, Staciakampiai st[]) // nahozhu razmer risunka
{
    a = st[0].y + st[0].dy;
    b = st[0].x + st[0].dx;
    for(int i = 0; i < n; i++)
    {
        if(a < (st[i].dy + st[i].y))
            a = st[i].dy + st[i].y;
        if(b < (st[i].dx + st[i].x))
            b = st[i].dx + st[i].x;
    }

}

void skaityti(int &n, Staciakampiai st[], Piesinys pies[], int &a, int &b)
{
    ifstream fin("U2.txt");
    fin >> n;

    for(int i = 0; i < n; i++)
    {
        fin >> st[i].x >> st[i].y >> st[i].dx >> st[i].dy;
        fin >> st[i].R >> st[i].G >> st[i].B;
    }

    maxXY(n, a, b, st);

    for(int i = 0; i < a; i++) // delaju list belym
    {
        for(int j = 0; j < b; j++)
        {
            pies[i].R[j] = 255, pies[i].G[j] = 255, pies[i].B[j] = 255;
        }
    }

    for(int i = 0; i < n; i++) // risuju
    {
        Paint(st, pies, a, b, i);
    }

    fin.close();
}

void rezultatas(int a, int b, Piesinys pies[])
{
    ofstream fout("U2rez.txt");
    fout << a << " " << b << endl;
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < b; j++)
        {
            fout << pies[i].R[j] << " " << pies[i].G[j] << " " << pies[i].B[j] << endl;
        }
    }
    fout.close();
}

int main()
{
    Staciakampiai st[100];
    Piesinys pies[100];

    int n, a, b;

    skaityti(n, st, pies, a, b);
    rezultatas(a, b, pies);

    return 0;
}

