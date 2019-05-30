#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int r, c, k, a[100][100];
int row = 3, col = 3, t;
vector<pair<int, int>> v;		//등장 횟수, 넣을 수
map<int, int> m;
void RowSort() {
	int Limit = col;
	int maxCol = 0;
	for (int i = 0; i < row; i++) {
		//한 행마다 좌표만든다.
		for (int j = 0; j < Limit; j++) {
			if (a[i][j] > 0) {
				m[a[i][j]]++;
				a[i][j] = 0;
			}
		}
		//맵을 확인하면서 벡터만들어주기 및 소팅
		for (auto z : m) v.push_back({ z.second, z.first });
		sort(v.begin(), v.end());

		if(maxCol < v.size() * 2)	maxCol = v.size() * 2;
		int temp = 0;
		for (int z = 0; z < v.size(); z++) {
			if (temp >= 100) {
				break;
			}
			a[i][temp] = v[z].second;
			a[i][temp + 1] = v[z].first;
			temp += 2;
		}
		v.clear();
		m.clear();
	}
	if (maxCol >= 100) col = 100;
	else col = maxCol;
}

void ColSort() {
	int Limit = row;
	int maxRow = 0;

	for (int j = 0; j < col; j++) {
		//한 열마다 좌표만든다.
		for (int i = 0; i < Limit; i++) {
			if (a[i][j] > 0) {
				m[a[i][j]]++;
				a[i][j] = 0;
			}
		}
		//맵을 확인하면서 벡터만들어주기 및 소팅
		for (auto z : m) v.push_back({ z.second, z.first });
		sort(v.begin(), v.end());

		if (maxRow < v.size() * 2)	maxRow = v.size() * 2;
	
		int temp = 0;
		for (int z = 0; z < v.size(); z++) {
			if (temp >= 100) {
				break;
			}
			a[temp][j] = v[z].second;
			a[temp+1][j] = v[z].first;
			temp += 2;
		}
		v.clear();
		m.clear();
	}
	if (maxRow >= 100) row = 100;
	else row = maxRow;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) cin >> a[i][j];
	}
	for (t = 0; t <= 100; t++) {
		if (a[r - 1][c - 1] == k) break;	
		if (row >= col) RowSort();
		else ColSort();
	}
	if (t == 101) t = -1;
	cout << t;
}