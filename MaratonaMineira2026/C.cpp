#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;

	int c;
	vector<int> cards;
	cards.push_back(0);

	map<int, int> card_idx;
	set<int> s; 

	int start_seq = 1;

	for(int i = 1; i <= n; ++i){
		cin >> c;
		cards.push_back(c);

		if(card_idx[c] != 0){
			int aux = card_idx[c] + 1;
			for(int j = start_seq; j <= card_idx[c]; ++j){
				card_idx[cards[j]] = 0;
				s.erase(-cards[j]);
			}
			start_seq = aux;
		}
		s.insert(-c);
		card_idx[c] = i;

		int ans = -*s.begin();	

		cout << ans << ' ' << card_idx[ans] << endl;
	}

	return 0;
}
