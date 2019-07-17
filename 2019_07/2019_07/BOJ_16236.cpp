/*BOJ 16236 아기상어*/
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int n, m, arr[21][21];
int check[21][21];
int sx, sy, shirk_size;
typedef struct info{
	int dist, row, col;
};
vector<info> fishList;
bool cmp(info &a, info &b) {
	if (a.dist < b.dist) return true;
	else if(a.dist==b.dist)
	{
		if (a.row < b.row) {
			return true;
		}
		else if(a.row==b.row){
			if (a.col < b.col) {
				return true;
			}
			else return false;
		}
		else return false;
	}
	else return false;
}

void printMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				sx = i, sy = j;
				arr[i][j] = 0;
			}
		}
	}
	queue<pair<int, int>> q;
	shirk_size = 2;
	int eat_cnt = 0;
	int timeValue = 0;
	while (true) {
		memset(check, -1, sizeof(check));
		q.push({ sx,sy });
		check[sx][sy] = 0;
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (check[nx][ny]!=-1) continue;
				if (shirk_size >= arr[nx][ny]) {
					q.push({ nx,ny });
					check[nx][ny] = check[x][y] + 1;
					if (shirk_size > arr[nx][ny] && arr[nx][ny] != 0) {
						fishList.push_back({ check[nx][ny],nx,ny });
					}
				}
			}
		}
		//fish 감별
		if (fishList.size() > 1) {
			sort(fishList.begin(), fishList.end(), cmp);
		}
		else if(fishList.size()==0){
			break;
		}
		sx = fishList[0].row, sy = fishList[0].col;
		arr[sx][sy] = 0;
		eat_cnt++;
		timeValue += fishList[0].dist;
		
		if (shirk_size == eat_cnt) {
			shirk_size++;
			eat_cnt = 0;
		}
		//printMap();
		fishList.clear();
	}
	cout << timeValue;
}