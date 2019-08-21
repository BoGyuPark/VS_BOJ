/*BOJ 17143 ���ÿ�*/
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int R, C, m, ans, check[101][101];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
int transDir[] = { 1,0,3,2 };
typedef struct {
	int r, c, s, d, z;
}info;

vector<info> v;	// shark

void findShark(int col) {
	int idx = -1;
	int minRow = R;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].z == -1) continue;			//���� ���
		if (v[i].c == col) {
			if (minRow > v[i].r) minRow = v[i].r, idx = i;
		}
	}
	//��� ���̱�
	if (idx != -1) {
		ans += v[idx].z;
		v[idx].z = -1;
	}
	return;
}
void removeOverlapShark(int x, int y, int idx) {

	if (check[x][y] == -1) check[x][y] = idx;
	else {
		int preIdx = check[x][y];
		if (v[idx].z > v[preIdx].z) {
			check[x][y] = idx;
			v[preIdx].z = -1;
		}
		else v[idx].z = -1;
	}
	return;
}

void moveShark() {
	memset(check, -1, sizeof(check));
	
	for (int i = 0; i < v.size(); i++) {
		if (v[i].z == -1) continue;			//���� ���
		int nx, ny;
		int dir = v[i].d;
		int s = v[i].s;
		int dist = 0;

		//���Ͽ���
		if (dir == 0) dist = v[i].r;
		else if (dir == 1) dist = R - 1 - v[i].r;
		else if (dir == 2) dist = C - 1 - v[i].c;
		else dist = v[i].c;

		//ó���� �ѹ����̵����� �� �̻� �̵�����
		if (dist < s) {
			//�ѹ� ������ �̵�
			nx = v[i].r + dx[dir] * dist, ny = v[i].c + dy[dir] * dist;

			s -= dist;

			//���� ������ �̵��Ÿ�
			if (dir == 0 || dir == 1) dist = R - 1;	
			else dist = C - 1;

			//�� �̵��ϴ� �� ������.
			int cnt = 0, remainCnt = 0;
			if (dist < s) {
				cnt = s / dist;
				remainCnt = s % dist;
				if (cnt % 2 == 1) {
					//�ݴ� ������ �̵�
					dir = transDir[dir];
					nx += dx[dir] * dist, ny += dy[dir] * dist;	
				}
				dir = transDir[dir];
				nx += dx[dir] * remainCnt, ny += dy[dir] * remainCnt;
			}
			else {
				dir = transDir[dir];
				nx += dx[dir] * s, ny += dy[dir] * s;
			}
		}
		//���̻� ������ �̵��������� ���
		else {
			nx = v[i].r + dx[dir] * s, ny = v[i].c + dy[dir] * s;
		}

		v[i].r = nx, v[i].c = ny, v[i].d = dir;
		
		//�ߺ�����
		removeOverlapShark(nx, ny, i);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> R >> C >> m;
	for (int i = 0; i < m; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		v.push_back({ r - 1,c - 1,s,d - 1,z });
	}
	for (int i = 0; i < C; i++) {
		findShark(i);			//�� ����
		moveShark();			//��� �̵�
	}
	cout << ans;
}