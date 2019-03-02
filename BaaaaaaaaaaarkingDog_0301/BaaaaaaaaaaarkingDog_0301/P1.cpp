#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int n = 5, map[5][5][5], cpy[5][5][5], a[5], cnt, t[5][5][5];
int dx[] = { 0,0,-1,1,0,0 };
int dy[] = { 1,-1,0,0,0,0 };
int dz[] = { 0,0,0,0,-1,1 };
vector<int> ans;
typedef struct info {
	int x, y, z;
};
void Rotate(int f, int dir) {
	int temp[5][5][5] = { 0, };
	//cpy행렬을 돌린다.
	//0인경우 회전 안한다.
	if (dir == 0) return;
	//1인경우 시계방향으로 1회전 , 2인경우 시계방향으로 2회전
	//3인 경우 시계방향으로 3회전
	if (dir == 1) {
		//회전
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) 
				temp[f][j][n - i - 1] = cpy[f][i][j];
		}
	}
	else if (dir == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) 
				temp[f][n - i - 1][n - j - 1] = cpy[f][i][j];
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) 
				temp[f][n - j - 1][i] = cpy[f][i][j];
		}
	}
	//temp배열을 다시 복사
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cpy[f][i][j]= temp[f][i][j];
	}
}

int bfs() {
	int c[5][5][5];
	memset(c, -1, sizeof(c));
	if (t[0][0][0] == 0) return -1;
	queue<info> q;
	q.push({ 0,0,0 });
	c[0][0][0] = 0;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, z = q.front().z;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= n || nz >= n) continue;
			if (c[nz][nx][ny] != -1) continue;
			if (t[nz][nx][ny] == 1) {
				c[nz][nx][ny] = c[z][x][y] + 1;
				q.push({ nx, ny, nz });
			}
		}
	}
	return c[4][4][4];
}
void dfs(int index) {
	if (index == n) {
		//각 판을 회전시킨다.
		for (int j = 0; j < n; j++) Rotate(j, a[j]);
		int arr[5] = { 0,1,2,3,4 };
		//회전시킨후 floor를 섞는다.....
		do {
			//5개의 층을 섞는다.
			for (int k = 0; k < 5; k++) {
				//k층에 오리지널 맵의 arr[k]층을 복사한다.
				for (int q = 0; q < 5; q++) {
					for (int w = 0; w < 5; w++) {
						t[k][q][w] = cpy[arr[k]][q][w];
					}
				}
			}
			if (t[0][0][0] == 1) {
				//회전 + 섞은 후 bfs시작
				int temp = bfs();
				ans.push_back(temp);
				/*if (temp == 18) {
					cout << "Rotate" << '\n';
					for (int i = 0; i < 5; i++) {
						cout << a[i] << ' ';
					}
					cout << '\n';

					cout << "floor" << '\n';
					for (int i = 0; i < 5; i++) {
						cout << arr[i] << ' ';
					}
					cout << '\n';

					cout << "\n\n\n";
				}*/
			}
		} while (next_permutation(arr,arr+5));

		//맵 다시 복사
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int z = 0; z < n; z++) {
					cpy[i][j][z] = map[i][j][z];
				}
			}
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		a[index] = i;
		dfs(index + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//맵복사
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int z = 0; z < n; z++) {
				cin >> map[i][j][z];
				cpy[i][j][z] = map[i][j][z];
			}
		}
	}
	cnt = 2147483647;
	dfs(0);
	sort(ans.begin(), ans.end());
	int result = -1;
	for (auto i : ans) {
		if (i != -1) {result = i; break;}
	}
	cout << result;
}