/*BOJ 16235 나무 재테크*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m, k, A[11][11], map[11][11], deathTree[11][11], ans;
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
vector<int> tree[11][11];

void addTree(int x, int y) {
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		tree[nx][ny].push_back(1);
	}
}

void eat(int i, int j) {
	int TreeSize = tree[i][j].size();

	for (int z = 0; z < TreeSize; z++) {
		int age = tree[i][j][z];

		if (map[i][j] >= age) {
			map[i][j] -= age;
			tree[i][j][z]++;
		}
		else {
			//죽는 나무부터 나머지 나무 전부 다 pop
			for (int b = TreeSize - 1; b >= z; b--) {
				age = tree[i][j][b];
				deathTree[i][j] += (age / 2);
				tree[i][j].pop_back();
			}
			return;
		}
	}
	
}

void spring() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sort(tree[i][j].begin(), tree[i][j].end());
			eat(i, j);
		}
	}
}

void fall() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			for (int z = 0; z < tree[i][j].size(); z++) {
				if (tree[i][j][z] % 5 == 0) {
					addTree(i,j);
				}
			}

		}
	}
}

void summerAndWinter() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] += (A[i][j] + deathTree[i][j]);
		}
	}
	memset(deathTree, 0, sizeof(deathTree));
}

int findAns() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cnt += tree[i][j].size();
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
			map[i][j] = 5;
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		tree[x - 1][y - 1].push_back(z);
	}

	//k년 후
	for (int i = 0; i < k; i++) {
		spring();
		fall();
		summerAndWinter();
	}

	cout<<findAns();

}