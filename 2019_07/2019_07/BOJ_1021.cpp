/*BOJ 1021 회전하는 큐*/
#include<iostream>
#include<deque>
using namespace std;
deque<int> dq;
int n, m, cnt, target[51], target_idx[51];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) dq.push_back(i + 1);
	for (int i = 0; i < m; i++) {
		cin >> target[i];
		target_idx[i] = target[i];
	}
	
	int now_idx, l_cnt, r_cnt;	//타겟기준 움직여야할 왼쪽, 오른쪽 횟수
	for(int idx=0; idx<m; idx++) {
		now_idx = target_idx[idx];
		l_cnt = now_idx - 1;
		r_cnt = dq.size() - now_idx + 1;

		if (l_cnt <= r_cnt) {
			while (dq.front() != target[idx]) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
			dq.pop_front();
			cnt += l_cnt;
			for (int j = idx + 1; j < m; j++) {
				target_idx[j] -= (l_cnt + 1);
				if (target_idx[j] <= 0) {
					target_idx[j] += dq.size() + 1;
				}
			}
		}
		else {
			while (dq.front() != target[idx]) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
			dq.pop_front();
			cnt += r_cnt;
			for (int j = idx + 1; j < m; j++) {
				target_idx[j] += (r_cnt - 1);
				target_idx[j] %= dq.size() + 1;
			}
		}
	}
	cout << cnt;
}