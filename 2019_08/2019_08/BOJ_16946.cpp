/*BOJ 16946 벽 부수고 이동하기4*/
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int n, m, check[1001][1001];
pair<int,int> dist[1001][1001];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
char map[1001][1001];
bool groupCheck[1'000'001];
int groupNum = 1;
vector<pair<int, int>> one, zero, temp;
queue<pair<int, int>> q;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == '1') {
				one.push_back({ i,j });
			}
			else if(map[i][j]=='0') {
				zero.push_back({ i,j });
			}
		}
	}

	for (int i = 0; i < zero.size(); i++) {
		int cnt = 1;
		if (check[zero[i].first][zero[i].second]) continue;
		q.push({ zero[i].first,zero[i].second });
		check[zero[i].first][zero[i].second] = true;
		temp.push_back({ zero[i].first,zero[i].second });
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j], ny = y + dy[j];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (check[nx][ny]) continue;
				if (map[nx][ny] == '0') {
					temp.push_back({ nx,ny });
					check[nx][ny] = true;
					cnt++;
					q.push({ nx,ny });
				}
			}
		}
		//상하좌우를 체크하는데 상하좌우 0의 영역을 체크하는데 같은 그룹인지도 체크해야한다.
		for (int j = 0; j < temp.size(); j++) {
			dist[temp[j].first][temp[j].second] = { groupNum, cnt };
		}
		temp.clear();
		groupNum++;
	}


	//cout << 'a';
	for (int i = 0; i < one.size(); i++) {
		int value = 1;
		int x = one[i].first, y = one[i].second;
		for (int j = 0; j < 4; j++) {
			int nx = x + dx[j], ny = y + dy[j];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (groupCheck[dist[nx][ny].first] == false) {
				value += dist[nx][ny].second;
				v.push_back(dist[nx][ny].first);
				groupCheck[dist[nx][ny].first] = true;
			}
			//value += dist[nx][ny];
		}
		value = value % 10;
		map[x][y] = value + '0';
		for (int j = 0; j < v.size(); j++) {
			groupCheck[v[j]] = false;
		}
		v.clear();
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << map[i][j];
		cout << '\n';
	}
}