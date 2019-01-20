//BOJ_2667_StickNum
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int arr[30][30];
int num = 2;
int cnt = 0;
int direction[2][4] = { {-1,1,0,0},{0,0,-1,1} }; //상 하 좌 우
void dfs(int x, int y)
{
	arr[x][y] = num;
	cnt++;
	int nx, ny;
	for (int i = 0; i < 4; i++) {
		//행렬 범위 안에 있을 경우
		if (x + direction[0][i] >= 0 && y + direction[1][i] >= 0) {
			nx = x + direction[0][i];
			ny = y + direction[1][i];
			if (arr[nx][ny] == 1) {
				dfs(nx, ny);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	string s;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) {
				dfs(i, j);
				v.push_back(cnt);
				cnt = 0;
				num++;
			}
		}
	}
	cout << num - 2 << '\n';
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';
	return 0;
}