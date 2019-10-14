#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int r, c, k, map[101][101], rowMax, colMax, numCnt[101], ans;
//        등장횟수, 수
vector<pair<int, int>> v;
void RowCal() {
	int maxLen = rowMax;

	for (int i = 0; i < colMax; i++) {
		memset(numCnt, 0, sizeof(numCnt));

		for (int j = 0; j < rowMax; j++) {
			if (map[i][j] == 0) continue;
			if (numCnt[map[i][j]] == 0) {
				v.push_back({ 0,map[i][j] });
			}
			numCnt[map[i][j]]++;
		}
		//수와 등장횟수 갱신
		for (int j = 0; j < v.size(); j++) {
			v[j].first = numCnt[v[j].second];
		}
		sort(v.begin(), v.end());
		int Vsize = v.size();
		for (int j = 0, z = 0; j < v.size(); j++) {
			if (j > 50) {
				Vsize = 50;
				break;
			}
			map[i][z] = v[j].second;
			map[i][z + 1] = v[j].first;
			z += 2;
		}

		for (int j = Vsize * 2; j < rowMax; j++) map[i][j] = 0;

		maxLen = max(maxLen, Vsize * 2);
		v.clear();
	}
	
	rowMax = max(rowMax, maxLen);
}

void ColCal() {
	int maxLen = colMax;

	//열
	for (int j = 0; j < rowMax; j++) {
		memset(numCnt, 0, sizeof(numCnt));

		for (int i = 0; i < colMax; i++) {
			if (map[i][j] == 0) continue;
			if (numCnt[map[i][j]] == 0) {
				v.push_back({ 0,map[i][j] });
			}
			numCnt[map[i][j]]++;
		}
		//수와 등장횟수 갱신
		for (int i = 0; i < v.size(); i++) {
			v[i].first = numCnt[v[i].second];
		}
		sort(v.begin(), v.end());
		int Vsize = v.size();
		for (int i = 0, z = 0; i < v.size(); i++) {
			if (i > 50) {
				Vsize = 50;
				break;
			}
			map[z][j] = v[i].second;
			map[z+1][j] = v[i].first;
			z += 2;
		}
		for (int i = Vsize * 2; i < colMax; i++) map[i][j] = 0;

		maxLen = max(maxLen, Vsize * 2);
		v.clear();
	}

	colMax = max(colMax, maxLen);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) cin >> map[i][j];
	rowMax = colMax = 3;
	int flag = false;
	for (int i = 0; i <= 100; i++) {
		if (map[r - 1][c - 1] == k) {
			ans = i;
			flag = true;
			break;
		}

		if (rowMax <= colMax) RowCal();
		else ColCal();
	}
	if (!flag) ans = -1;
	cout << ans;
}