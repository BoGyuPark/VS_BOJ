#include<iostream>
#include<vector>
#include<string>
typedef struct info {
	int n, xp, yp, dir;
};
using namespace std;
int A, B, N, M, x, y, dir, r, num, a[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int lturn[] = { 3,2,0,1 };
int rturn[] = { 2,3,1,0 };
vector<pair<int, int>> p;
char d, order;

void simulate(vector<info> &v) {
	//시뮬레이션
	for (int i = 0; i < M; i++) {
		cin >> num >> order >> r;
		x = v[num].xp; y = v[num].yp; dir = v[num].dir;
		if (order == 'F') {
			while (r--) {
				if (x + dx[dir] >= 0 && y + dy[dir] >= 0 && x + dx[dir] < B && y + dy[dir] < A) {
					//전진 중에 다른 로봇과 부딪힌 경우
					if (a[x + dx[dir]][y + dy[dir]] != 0) {
						p.push_back({ num,a[x + dx[dir]][y + dy[dir]] });
						return;
					}
					else {
						a[x][y] = 0;
						x += dx[dir];
						y += dy[dir];
						a[x][y] = num;
						v[num].xp = x;
						v[num].yp = y;
					}
				}
				//wall인경우 -1
				else {
					p.push_back({ num,-1 });
					return;
				}
			}
		}
		else if (order == 'L') {
			while (r--) {
				v[num].dir = lturn[dir];
				dir = v[num].dir;
			}
		}
		else {
			while (r--) {
				v[num].dir = rturn[dir];
				dir = v[num].dir;
			}
		}
	}
}
int main() {
	cin >> A >> B >> N >> M;
	vector<info> v(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> y >> x >> d;
		a[B - x][y - 1] = i;
		int temp;
		if (d == 'E') temp = 0;
		else if (d == 'W') temp = 1;
		else if (d == 'S') temp = 2;
		else temp = 3;
		v[i] = { i,B - x,y - 1,temp };
	}
	simulate(v);
	if (p.size() == 0) cout << "OK";
	else if (p[0].second == -1) cout << "Robot " << p[0].first << " crashes into the wall";
	else cout << "Robot " << p[0].first << " crashes into robot " << p[0].second;
}