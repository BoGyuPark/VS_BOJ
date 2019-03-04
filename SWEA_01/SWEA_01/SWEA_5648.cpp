#include<iostream>
#include<vector>
using namespace std;
int Test, T, n;
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,-1,1 };
typedef struct info {
	int x, y, dir, k;
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> Test;
	for (T = 1; T <= Test; T++) {
		cin >> n;
		int t1, t2, t3, t4;
		vector<info> now(n), prev(n);
		for (int i = 0; i < n; i++) {
			cin >> t1 >> t2 >> t3 >> t4;
			now[i] = { t1,t2,t3,t4 };
		}
		int ans = 0, t = 4003;
		while (t--) {
			//������ ��ǥ�� prev�� ����
			prev = now;
			//�� ��ǥ�� ���ο� ��ǥ�� �̵� (�ѹ��� �̵�)
			for (int i = 0; i < n; i++) {
				if (now[i].k == -1) continue;
				now[i].x += dx[now[i].dir];
				now[i].y += dy[now[i].dir];
			}

			//1.5�� �� �浹�Ͽ����� üũ�Ѵ�.
			for (int i = 0; i < n; i++) {
				if (now[i].k == -1) continue;
				//������ i��°�� �ִ� ��ǥ
				int x = now[i].x, y = now[i].y;
				int collision = now[i].k;
				bool col = false;
				for (int j = 0; j < n; j++) {
					if (i == j || now[j].k == -1) continue;
					//1.5�� �Ŀ� �浹�ϴ� ���
					if (x == prev[j].x && y == prev[j].y) {
						if (now[j].x == prev[i].x && now[j].y == prev[i].y) {
							collision += now[j].k;
							now[j].k = -1;
							col = true;
						}
					}
				}
				//�ش���ǥ���� �浹�� �Ͼ��� ���ڸ� ���ش�.
				if (col) {
					now[i].k = -1;
					ans += collision;
				}
			}
			//�浹�Ͽ����� üũ�Ѵ�.
			for (int i = 0; i < n; i++) {
				if (now[i].k == -1) continue;
				//������ i��°�� �ִ� ��ǥ
				int x = now[i].x, y = now[i].y;
				int collision = now[i].k;
				bool col = false;
				for (int j = 0; j < n; j++) {
					if (i == j || now[j].k == -1) continue;
					//�浹�ߴ�!
					if (x == now[j].x && y == now[j].y) {
						collision += now[j].k;
						//�浹���� ��ǥ�� ���ڴ� -1�� ����
						now[j].k = -1;
						col = true;
					}
				}
				//�ش���ǥ���� �浹�� �Ͼ��� ���ڸ� ���ش�.
				if (col) {
					now[i].k = -1;
					ans += collision;
				}
			}

		}
		cout << '#' << T << ' ' << ans << '\n';
	}
}

