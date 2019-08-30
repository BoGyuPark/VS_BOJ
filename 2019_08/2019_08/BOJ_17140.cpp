/* BOJ 17140 ������ �迭�� ���� */
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int r, c, k, map[101][101], numCnt[101], t, ans;
int maxRow, maxCol;
//    ����Ƚ�� , ���� ����
vector<pair<int, int>> v;

void rowCal() {

	//R�����ϸ� col�� ����
	int C = maxCol;
	for (int i = 0; i < maxRow; i++) {
		
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 0) continue;
			if (numCnt[map[i][j]] == 0) {
				v.push_back({ 0,map[i][j] });
			}
			numCnt[map[i][j]]++;
		}

		//���� Ƚ���� ����
		for (int j = 0; j < v.size(); j++) {
			swap(v[j].first, numCnt[v[j].second]);
		}

		//���� �� �ٽ� ����
		sort(v.begin(), v.end());
		for (int j = 0; j < v.size(); j++) {
			int col = j * 2;
			map[i][col] = v[j].second;
			map[i][col + 1] = v[j].first;
			if (col >= 100) break;
		}
		for (int j = v.size() * 2; j < maxCol; j++) map[i][j] = 0;

		//�ִ� row,col���� ����
		if (maxCol < v.size() * 2) {
			if (v.size() * 2 <= 100) maxCol = v.size() * 2;
			else maxCol = 100;
		}
		v.clear();
	}
}
void colCal() {

	//C�����ϸ� row�� ����
	int R = maxRow;
	for (int j = 0; j < maxCol; j++) {

		for (int i = 0; i < R; i++) {
			if (map[i][j] == 0) continue;
			if (numCnt[map[i][j]] == 0) {
				v.push_back({ 0,map[i][j] });
			}
			numCnt[map[i][j]]++;
		}

		//���� Ƚ���� ����
		for (int i = 0; i < v.size(); i++) {
			swap(v[i].first, numCnt[v[i].second]);
		}

		//���� �� �ٽ� ����
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) {
			int row = i * 2;
			map[row][j] = v[i].second;
			map[row+1][j] = v[i].first;
			if (row >= 100) break;
		}
		for (int i = v.size() * 2; i < maxRow; i++) map[i][j] = 0;

		//�ִ� row,col���� ����
		if (maxRow < v.size() * 2) {
			if (v.size() * 2 <= 100) maxRow = v.size() * 2;
			else maxRow = 100;
		}
		v.clear();
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) cin >> map[i][j];
	maxRow = maxCol = 3;
	ans = -1;
	if (map[r - 1][c - 1] == k) ans = 0;
	else {
		for (t = 1; t <= 100; t++) {
			if (maxRow >= maxCol) rowCal();
			else colCal();
			if (map[r - 1][c - 1] == k) {
				ans = t;
				break;
			}
		}
	}
	cout << ans;
}