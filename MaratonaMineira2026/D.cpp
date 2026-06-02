#include <bits/stdc++.h>

using namespace std;

int main(){
	int d, m; cin >> d >> m;

	if(d > 12 or d == m)
		cout << "DATA SEGURA" << endl;
	else
		cout << "DATA INCERTA" << endl;

	return 0;
}
