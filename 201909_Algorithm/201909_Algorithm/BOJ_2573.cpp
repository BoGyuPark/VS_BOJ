/*BOJ 2573 ����*/
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int n, m, map[301][301], check[301][301], t, iceSize, ans;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
struct info {
	int x, y, Size;
};
vector<info> v;
queue<pair<int, int>> q;
void reduceIce() {
	//������ ũ�⸦ ���̱� ���� 4���� Ž���Ͽ� ���� ��� �κ� üũ
	for (int i = 0; i < v.size(); i++) {
		if (v[i].Size <= 0) continue;
		int x = v[i].x, y = v[i].y;
		int waterCnt = 0;
		for (int j = 0; j < 4; j++) {
			int nx = x + dx[j], ny = y + dy[j];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] <= 0) waterCnt++;
		}
		v[i].Size -= waterCnt;
		
		//������ �κ��� �������� ����ũ�� ����
		if (v[i].Size <= 0) iceSize--;
	}

	//���� ��� ũ�⸸ŭ �ش� ��ǥ���� ���ش�.
	for (int i = 0; i < v.size(); i++) {
		if (map[v[i].x][v[i].y] <= 0) continue;
		map[v[i].x][v[i].y] = v[i].Size;
	}
}

bool IceSizeCheck() {
	int cnt = 0;
	memset(check, 0, sizeof(check));
	for (int i = 0; i < v.size(); i++) {
		if (v[i].Size <= 0) continue;
		if (check[v[i].x][v[i].y] == true) continue;

		q.push({ v[i].x,v[i].y });
		check[v[i].x][v[i].y] = true;

		cnt++;
		if (cnt > 1) return true;
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j], ny = y + dy[j];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (check[nx][ny]) continue;
				if (map[nx][ny] > 0) {
					q.push({ nx,ny });
					check[nx][ny] = true;
				}
			}
		}
	}
	return false;
}

int main() {

	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) v.push_back({ i,j,map[i][j] });
		}
	}

	iceSize = v.size();

	while (true) {
		t++;
		//���� ���̱�
		reduceIce();
		if (iceSize == 0) {
			ans = 0;
			break;
		}

		//���� ��� üũ
		if (IceSizeCheck()) {
			ans = t;
			break;
		}
	}
	cout << ans;
}