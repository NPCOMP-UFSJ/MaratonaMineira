#include <bits/stdc++.h>

using namespace std;

#define ll long long 

ll sieve_size;
bitset<100000010> bs;
vector<int> primes;

void sieve(ll upperbound){
	sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2; i <= sieve_size; ++i){
		if(bs[i]){
			for(ll j = i * i; j <= sieve_size; j += i) bs[j] = 0;
			primes.push_back((int) i);
		}
	}
}

vector<int> primeFactors(ll N){
	vector<int> factors;
	ll PF_idx = 0;
	ll PF = primes[PF_idx];
	while(PF * PF <= N){
		while(N % PF == 0){
			N /= PF;
			factors.push_back(PF);
		}	
		PF = primes[++PF_idx];
	}	
	if(N != 1) factors.push_back(N);
	return factors;
}

int main(){
	int n; cin >> n;
	vector<int> numbers (n);
	for(auto & x : numbers) cin >> x;

	sieve(1000000);

	long long ans = 0;
	long long vans = 0;

	map<int, int> mp;
	for(auto & x : numbers){
		vector<int> factors = primeFactors(x);

		if(mp[factors[0]]) mp[factors[0]] += 1;
		else mp[factors[0]] = 1;

		if(mp[factors[0]] > ans){
			ans = mp[factors[0]];
			vans = factors[0];
		}

		for(int i = 1; i < factors.size(); ++i){
			if(factors[i] == factors[i-1]) continue;	

			if(mp[factors[i]]) mp[factors[i]] += 1;
			else mp[factors[i]] = 1;

			if(mp[factors[i]] > ans){
				ans = mp[factors[i]];
				vans = factors[i];
			}
		}
	}

	cout << vans << endl;

	return 0;
}
