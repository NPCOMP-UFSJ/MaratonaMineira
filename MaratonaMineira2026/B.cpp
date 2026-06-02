#include <bits/stdc++.h>

using namespace std;

int merge(int a, int b){
	if(a == -1) return b;
	if(b == -1) return a;
	return min(a, b);
}

int main(){
	int t; cin >> t;

	while(t--){
		int n; cin >> n;
		string world; cin >> world;

		if(world[0] == '.' or world[n-1] == '.'){
			cout << -1 << endl;
			continue;
		}

		vector<pair<int, int>> sections;

		world += '.';
		int section_len = 0;
		const char block = 'x';
		for(int i = 0; i <= n; ++i){
			if(world[i] == block){
				section_len += 1;
				continue;
			} 
			sections.push_back(make_pair(i - section_len, section_len));
			section_len = 0;
		}

		reverse(sections.begin(), sections.end());	

		// <start, len, ans>
		vector<tuple<int, int, int>> viable_sections;
		viable_sections.push_back(make_tuple(sections[0].first, 
						     sections[0].second,
						     0));

		int ans = sections.size() > 1 ? -1 : 0;

		for(int i = 1; i < sections.size(); ++i){
			auto &[spos, slen] = sections[i];
			int max_range = spos + slen*2 - 1;

			int smin_jumps = -1;
			for(int j = viable_sections.size() - 1; j >= 0; --j){
				auto & [vsi, vslen, vsans] = viable_sections[j];

				if(vsi > max_range) break;

				smin_jumps = merge(smin_jumps, vsans + 1);
			}

			if(smin_jumps != -1){
				viable_sections.push_back(make_tuple(spos,
								     slen,
								     smin_jumps));
			}

			if(i == sections.size()-1)
				ans = smin_jumps; 
		}
		
		cout << ans << endl;
	}

	return 0;
}
