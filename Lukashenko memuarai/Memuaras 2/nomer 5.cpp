#include <iostream>
using namespace std;

int main() {
	int s, c, v, tv;
	cout << "s = ";
	cin >> s;
	cout << "c = ";
	cin >> c; 
	cout << "v = ";
	cin >> v;
	v = v*100;
	if(tv > v)
		cout << "Tarakonas greitesnis uz muse" << endl;
	else if(s*c < v)
        cout << "Muse greitesne uz tarakona";
    else
        cout << "Greitis vienodas";
	
	return 0;
}
