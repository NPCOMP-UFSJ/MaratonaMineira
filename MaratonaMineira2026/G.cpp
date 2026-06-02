#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, g; cin >> n >> g;

	int single_groups = (g-1) * 2;
	cout << single_groups + (n - (g-1) + 1) << endl;
	return 0;
}
