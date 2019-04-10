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
//     BC��ȣ
vector<int> Ainfo, Binfo, maxList;
vector<info> BCinfo;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> M >> A;
		for (int i = 0; i < M; i++) cin >> alist[i];
		for (int i = 0; i < M; i++) cin >> blist[i];
		//���͸��� ������ �Է¹޴´�.
		for (int i = 0; i < A; i++) {
			cin >> cy >> cx >> C >> P;
			BCinfo.push_back({ cx - 1,cy - 1, i, C, P });
		}

		//i���϶����� i+1������ �̵��� ������ �����´�.
		int ASum = 0, ax = 0, ay = 0;
		int BSum = 0, bx = 9, by = 9;
		for (int i = 0; i <= M; i++) {
			
			//i���϶� ����������� �Ÿ��� ����Ͽ� ������ BC�� ��´�.
			for (int j = 0; j < A; j++) {
				//A��ǥ�� ��
				int dist = abs(ax - BCinfo[j].x) + abs(ay - BCinfo[j].y);
				if (dist <= BCinfo[j].area) Ainfo.push_back(j);
				dist = abs(bx - BCinfo[j].x) + abs(by - BCinfo[j].y);
				if (dist <= BCinfo[j].area) Binfo.push_back(j);
			}
			int bp = 0;
			if (Ainfo.size() == 0) {
				//B����Ʈ�߿� ���� ū���� ���Ѵ�
				for (int j = 0; j < Binfo.size(); j++) {
					if (bp < BCinfo[Binfo[j]].per) bp = BCinfo[Binfo[j]].per;
				}
				BSum += bp;
			}
			int ap = 0;
			if (Binfo.size() == 0) {
				//A����Ʈ�߿� ���� ū���� ���Ѵ�
				for (int j = 0; j < Ainfo.size(); j++) {
					if (ap < BCinfo[Ainfo[j]].per) ap = BCinfo[Ainfo[j]].per;
				}
				ASum += ap;
			}

			//���� �Ѱ��� �ִ� ���
			if (Ainfo.size() == 1 && Binfo.size() == 1) {
				//���� BC�� �ִ�.
				if (Ainfo[0] == Binfo[0]) {
					ASum += BCinfo[Ainfo[0]].per / 2;
					BSum += BCinfo[Binfo[0]].per / 2;
				}
				//�ٸ� BC�� �ִ� ���
				else {
					ASum += BCinfo[Ainfo[0]].per;
					BSum += BCinfo[Binfo[0]].per;
				}
			}
			//���� �������� ���
			else if (Ainfo.size() > 0 && Binfo.size() > 0) {
				// A����Ʈ�� B����Ʈ�� ������ ���� ���� �ִ밪�� ���Ѵ�.
				for (int j = 0; j < Ainfo.size(); j++) {
					for (int z = 0; z < Binfo.size(); z++) {
						//���� BC�� ���� ���
						if (Ainfo[j] == Binfo[z]) {
							maxList.push_back(BCinfo[Ainfo[j]].per);	//��ģ�Ϳ� ���� ��
						}
						else {
							maxList.push_back(BCinfo[Ainfo[j]].per + BCinfo[Binfo[z]].per);
						}
					}
				}
				//�����߿� ���� ū���� ã�´�.
				//ASum�̳� BSum �����ϳ��� ���Ѵ�.
				sort(maxList.begin(), maxList.end());
				ASum += maxList[maxList.size() - 1];
			}
			//���� ��ǥ�� �̵�
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