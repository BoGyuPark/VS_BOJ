/* BOJ 1799 ºñ¼ó*/
#include<iostream>
#include<vector>
using namespace std;
int n, map[11][11], check[101], ans,dig1[22],dig2[22];
int dx[] = { -1,1,-1,1 };
int dy[] = { -1,1,1,-1 };
vector<pair<int, int>> black,white;
bool isPossible(int r, int c) {
	if (dig1[r + c]) return false;
	if (dig2[r + (n - 1 - c)]) return false;
	return true;
}

void go(int cnt, int start , vector<pair<int,int>> v) {
	if (ans < cnt) ans = cnt;
	for (int i = start; i < v.size(); i++) {
		int x = v[i].first, y = v[i].second;
		if (check[i]) continue;
		check[i] = true;
		if (isPossible(x, y)) {
			dig1[x + y] = dig2[x + (n - 1 - y)] = true;
			map[x][y] = 2;
			go(cnt + 1, i, v);
			map[x][y] = 1;
			dig1[x + y] = dig2[x + (n - 1 - y)] = false;
		}
		check[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				if ((i + j) % 2 == 0) black.push_back({ i,j });
				else white.push_back({ i,j });
			}
		}
	}
	go(0, 0, white);
	int whiteCnt = ans;
	ans = 0;
	go(0, 0, black);
	cout << whiteCnt + ans;
}