#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
const char RE[]="Rez.txt";
const char DM[]="duom.txt";
const int CN=103;

// Apsk - apskrities pavadinimas
// mazGyv - maziausio miesto apskrities gyventoju skaicius
// Gyv - visos apskrities gyventoju skaicius

struct Miestai {
    string Miestas;
    string Apsk;
    int Gyven;
};
struct Apskrtis {
    string Apsk;
    int mazGyv;
    int Gyv;
};
int main()
{
    Miestai M[CN];
    int n;
    // n - miestu kiekis
    ifstream dm(DM);
    dm >> n;
    for(int i = 0; i<n; i++)
      dm >> M[i].Miestas >> M[i].Apsk >> M[i].Gyven;
    dm.close();
    // rikevimas
    for(int i = 0; i < n; i++)
    {
    	for(int j = i+1; j < n; j++)
    	{
    		if(M[i].Apsk > M[j].Apsk)
    		{
    			swap(M[i], M[j]);
			}
		}      
	} 
    ofstream re(RE);
	for(int i = 0; i < n; i++) 
	{
		re << setw(13) << left << M[i].Miestas << "  " << M[i].Apsk << "  " << M[i].Gyven <<endl;
	}
    Apskrtis A[CN];
	int t = 0;
    A[t].Apsk = M[0].Apsk;
    A[t].mazGyv = M[0].Gyven;
    A[t].Gyv = M[0].Gyven;
    for(int i = 1; i < n; i++)
    {
        if(M[i].Apsk == A[t].Apsk)
        {
            if(A[t].mazGyv > M[i].Gyven)
			{
				A[t].mazGyv = M[i].Gyven;
			}
            A[t].Gyv = A[t].Gyv + M[i].Gyven;
        }
        else
        {
            t++;
            A[t].Apsk = M[i].Apsk;
            A[t].mazGyv = M[i].Gyven;
            A[t].Gyv = M[i].Gyven;
        }
    }
    t=t+1; //kolicestvo okrugov
    for(int i = 0; i < t-1; i++)
    {
    	for(int j = i+1; j < t; j++)
    	{
    		if(A[i].mazGyv > A[j].mazGyv)
    		{
    			swap (A[i], A[j]);
			} 
		}  
	}
    cout << t << endl;
    for(int i=0; i<t; i++)
    {
        cout << setw(13) << left << A[i].Apsk << A[i].mazGyv << " " << A[i].Gyv << endl;
    }
    re.close();
    return 0;
}
//70 min
