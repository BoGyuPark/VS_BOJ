#include<iostream>
#include<vector>
#include<deque>
#include<cstring>
using namespace std;
int n, k, x, y, l, a[101][101], check[101][101], dir = 0, time = 0;;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
deque<pair<int, char>> dirinfo;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		a[x - 1][y - 1] = -1;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int t; char t1;
		cin >> t >> t1;
		dirinfo.push_back({ t,t1 });
	}
	deque<pair<int, int>> s;
	s.push_back({ 0,0 });
	while (true) {
		//�ʱ� ���� ��ġ���� check�Ѵ�.
		for (int i = 0; i < s.size(); i++) 	check[s[i].first][s[i].second] = true;
		if (dirinfo.size() > 0) {
			if (time == dirinfo.front().first) {
				char c = dirinfo.front().second;
				if (c == 'L') 	dir = (dir + 3) % 4;
				else dir = (dir + 1) % 4;
				dirinfo.pop_front();
			}
		}
		x = s.front().first; y = s.front().second;
		int nx = x + dx[dir], ny = y + dy[dir];
		if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
			//���� ���� �����̸� �÷� �Ӹ��� ����ĭ�� ��ġ��Ų��.
			if (check[nx][ny] == false) {
				s.push_front({ nx,ny });
				//����� �ִٸ� �� ĭ�� �ִ� ����� �������� ������ �������� �ʴ´�.
				if (a[nx][ny] == -1) a[nx][ny] = 0;
				else s.pop_back();
			}
			//�ڱ��ڽ��� ���� �ε����� ��
			else break;
		}
		//���� �ε����� ��
		else break;
		memset(check, 0, sizeof(check));
		time++;
	}
	cout << time + 1;
}