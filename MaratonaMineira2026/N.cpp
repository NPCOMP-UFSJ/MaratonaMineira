#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> board;
vector<pair<int, int>> bob;

int gans;

int di[] = {1, 1, -1, -1};
int dj[] = {1, -1, 1, -1};

bool inside(int i, int j){
	if(i < 0 or j < 0 or i >= n or j >= n) return false;
	return true;
}

void solve(int i, int j, int ans){
	gans = max(ans, gans);
	for(int k = 0; k < 4; ++k){
		int ei = i + di[k];
		int ej = j + dj[k];

		if(not inside(ei, ej)) continue;
		if(board[ei][ej] != 2) continue;

		int ni = i + 2*di[k];
		int nj = j + 2*dj[k];

		if(not inside(ni, nj)) continue;
		if(board[ni][nj] != 0) continue;

		board[i][j] = 0;
		board[ei][ej] = 0;
		board[ni][nj] = 1;
		solve(ni, nj, ans + 1);
		board[ni][nj] = 0;
		board[ei][ej] = 2;
		board[i][j] = 1;
	}
}

int main(){
	cin >> n;
	board.resize(n);

	for(int i = 0; i < n; ++i){
		string s; cin >> s;
		for(auto & c : s){
			int val = 0;
			if(c == 'B') val = 1;
			if(c == 'P') val = 2;

			board[i].push_back(val);
		}	
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(board[i][j] == 1){
				bob.push_back(make_pair(i, j));
			}
		}
	}

	for(auto &[i, j] : bob){
		solve(i, j, 0);
	}

	cout << gans << endl;	

	return 0;
}
