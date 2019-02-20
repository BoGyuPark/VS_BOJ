#include<iostream>
#include<string>
using namespace std;
int n, kx, ky, sx, sy, dir;
int dx[] = { 0,0,-1,1,-1,-1,1,1 };
int dy[] = { 1,-1,0,0,-1,1,-1,1 };
int main() {
	string ks, ss, t; cin >> ks >> ss >> n;
	ky = ks[0] - 'A'; sy = ss[0] - 'A';
	kx = 8 - (ks[1] - '0'); sx = 8 - (ss[1] - '0');
	for (int z = 0; z < n; z++) {
		cin >> t;
		if (t == "R") dir = 0;
		else if (t == "L") dir = 1;
		else if (t == "T") dir = 2;
		else if (t == "B") dir = 3;
		else if (t == "LT") dir = 4;
		else if (t == "RT") dir = 5;
		else if (t == "LB") dir = 6;
		else if (t == "RB") dir = 7;
		int nkx = kx + dx[dir], nky = ky + dy[dir];
		if (nkx >= 0 && nky >= 0 && nkx < 8 && nky < 8) {
			if (nkx == sx && nky == sy) {
				if (sx + dx[dir] >= 0 && sy + dy[dir] >= 0 && sx + dx[dir] < 8 && sy + dy[dir] < 8) {
					sx += dx[dir]; sy += dy[dir];
					kx = nkx; ky = nky;
				}
			}
			else {
				kx = nkx; ky = nky;
			}
		}
	}
	cout << (char)(ky + 'A') << 8 - kx << '\n';
	cout << (char)(sy + 'A') << 8 - sx;
}