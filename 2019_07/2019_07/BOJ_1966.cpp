/*BOJ 1966 ������ ť*/
#include<iostream>
#include<queue>
using namespace std;
int T, n, m;
deque<pair<int, int>> dq;	//�켱����, �ε���
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n >> m;
		for (int j = 0; j < n; j++) {
			int priority;
			cin >> priority;
			dq.push_back({ priority,j });
		}
		
		int ans = 0, cnt = 0;
		while (true)
		{
			int dis = -1;
			for (int j = 1; j < dq.size(); j++) {
				//������ ť���� ���纸�� �켱������ ���� ���� ����
				if (dq.front().first < dq[j].first) {
					dis = j;
					break;
				}
			}

			//������������
			if (dis == -1) {
				cnt++;
				if (dq.front().second == m) {
					ans = cnt;
					break;
				}
				dq.pop_front();
			}
			//������
			else {
				for (int z = 0; z < dis; z++) {
					dq.push_back(dq.front());
					dq.pop_front();
				}
			}
		}	
		cout << ans << '\n';
		dq = deque<pair<int, int>>();
	}
}