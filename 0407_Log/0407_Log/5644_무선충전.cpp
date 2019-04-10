#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int T, tc, M, A, alist[101], blist[101], C, P, cx, cy;
int c[8][10][10];
int dx[] = { 0,-1,0,1,0 };
int dy[] = { 0,0,1,0,-1 };
typedef struct info {
	int x, y, idx, area, per;
};
//     BC번호
vector<int> Ainfo, Binfo, maxList;
vector<info> BCinfo;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> M >> A;
		for (int i = 0; i < M; i++) cin >> alist[i];
		for (int i = 0; i < M; i++) cin >> blist[i];
		//배터리의 정보를 입력받는다.
		for (int i = 0; i < A; i++) {
			cin >> cy >> cx >> C >> P;
			BCinfo.push_back({ cx - 1,cy - 1, i, C, P });
		}

		//i초일때마다 i+1초으로 이동할 방향을 가져온다.
		int ASum = 0, ax = 0, ay = 0;
		int BSum = 0, bx = 9, by = 9;
		for (int i = 0; i <= M; i++) {
			
			//i초일때 무선충전기와 거리를 계산하여 가능한 BC를 얻는다.
			for (int j = 0; j < A; j++) {
				//A좌표와 비교
				int dist = abs(ax - BCinfo[j].x) + abs(ay - BCinfo[j].y);
				if (dist <= BCinfo[j].area) Ainfo.push_back(j);
				dist = abs(bx - BCinfo[j].x) + abs(by - BCinfo[j].y);
				if (dist <= BCinfo[j].area) Binfo.push_back(j);
			}
			int bp = 0;
			if (Ainfo.size() == 0) {
				//B리스트중에 가장 큰것을 더한다
				for (int j = 0; j < Binfo.size(); j++) {
					if (bp < BCinfo[Binfo[j]].per) bp = BCinfo[Binfo[j]].per;
				}
				BSum += bp;
			}
			int ap = 0;
			if (Binfo.size() == 0) {
				//A리스트중에 가장 큰것을 더한다
				for (int j = 0; j < Ainfo.size(); j++) {
					if (ap < BCinfo[Ainfo[j]].per) ap = BCinfo[Ainfo[j]].per;
				}
				ASum += ap;
			}

			//각각 한개만 있는 경우
			if (Ainfo.size() == 1 && Binfo.size() == 1) {
				//같은 BC에 있다.
				if (Ainfo[0] == Binfo[0]) {
					ASum += BCinfo[Ainfo[0]].per / 2;
					BSum += BCinfo[Binfo[0]].per / 2;
				}
				//다른 BC에 있는 경우
				else {
					ASum += BCinfo[Ainfo[0]].per;
					BSum += BCinfo[Binfo[0]].per;
				}
			}
			//각각 여러개인 경우
			else if (Ainfo.size() > 0 && Binfo.size() > 0) {
				// A리스트와 B리스트의 조합을 통해 가장 최대값을 구한다.
				for (int j = 0; j < Ainfo.size(); j++) {
					for (int z = 0; z < Binfo.size(); z++) {
						//같은 BC에 있을 경우
						if (Ainfo[j] == Binfo[z]) {
							maxList.push_back(BCinfo[Ainfo[j]].per);	//겹친것에 대한 합
						}
						else {
							maxList.push_back(BCinfo[Ainfo[j]].per + BCinfo[Binfo[z]].per);
						}
					}
				}
				//조합중에 가장 큰것을 찾는다.
				//ASum이나 BSum 둘중하나에 더한다.
				sort(maxList.begin(), maxList.end());
				ASum += maxList[maxList.size() - 1];
			}
			//다음 좌표로 이동
			ax += dx[alist[i]], ay += dy[alist[i]];
			bx += dx[blist[i]], by += dy[blist[i]];
			Ainfo.clear();
			Binfo.clear();
			maxList.clear();
			//cout << ASum << ' ' << BSum << '\n';
		}
		cout << '#' << tc << ' ' << ASum + BSum << '\n';
		BCinfo.clear();
	}
}