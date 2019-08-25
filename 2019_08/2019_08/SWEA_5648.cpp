/*5648. [���� SW �����׽�Ʈ] ���� �Ҹ� �ùķ��̼�*/
#include<iostream>
#include<vector>
using namespace std;
#define MAX 4002
int T, tc, n;
int boomValue[MAX][MAX];
int ans, liveCnt;
typedef struct {
	int x, y, dir, k, live;
}info;
vector<info> v;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int centerX = 2000, centerY = 2000;
void moveAtom() {
	for (int i = 0; i < v.size(); i++) {
		if (v[i].live == 0) continue;
		int dir = v[i].dir;
		int nx = v[i].x + dx[dir], ny = v[i].y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= 4001 || ny >= 4001) {
			v[i].live = 0;
			liveCnt--;
			continue;
		}
		v[i].x = nx, v[i].y = ny;
		boomValue[nx][ny] += v[i].k;
	}
}

void boomCheck() {
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].x, y = v[i].y;
		if (v[i].live == 0) continue;
		//�ش� �ڸ��� �Ѱ��� ���ڸ� ����
		if (boomValue[x][y] == v[i].k) {
			boomValue[x][y] = 0;
		}
		//���� ������ ��� , �浹�� �Ͼ ù��° ���ڿ��� ��� ���ϰ�
		//���߿� �浹�Ͼ ���ڴ� ���� 0�̱� ������ �������.
		else {
			ans += boomValue[x][y];
			v[i].live = 0;
			liveCnt--;
			boomValue[x][y] = 0;
		}
	}
}

void simulate() {
	liveCnt = v.size();
	
	while (liveCnt != 0) {
		//���� �̵�
		for (int i = 0; i < 2; i++) {
			//��ĭ �̵� �� �浹���� �Ǵ�.
			moveAtom();
			//boom
			boomCheck();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x, y, dir, k;
			cin >> y >> x >> dir >> k;
			v.push_back({ x * -2 + centerX, y * 2 +centerY ,dir,k,1 });
		}
		ans = 0;

		simulate();
		cout << '#' << tc << ' ' << ans << '\n';
		v.clear();
	}
}