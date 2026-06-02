#include <bits/stdc++.h>

using namespace std;

#define MOD (long long) (1e9 + 7)

int main(){
	int n; cin >> n;

	long long sum = 0;
	long long mult = 1;

	while(n--){
		char c; cin >> c;
		int x; cin >> x;

		if(c == '+'){
			sum = (sum + x) % MOD;	
		} else if (c == '*'){
			mult = (mult * x) % MOD;
			sum = (sum * x) % MOD;
		} else {
			long long r = (sum + (mult * x) % MOD) % MOD;
			cout << r << endl;
		}
	}

	return 0;
}
