#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
typedef long long ll;
int n, m, k, tree_size, h;
vector<ll> arr,tree;

ll init(int nodeNum, int start, int end) {
	if (start == end) {
		return tree[nodeNum] = arr[start];
	}
	else {
		int mid = (start + end) / 2;
		return tree[nodeNum] = init(nodeNum * 2, start, mid) + init(nodeNum * 2 + 1, mid + 1, end);
	}
}

void update(int nodeNum, int start, int end, int target_idx, ll diff) {
	if (target_idx < start || target_idx > end) return;
	tree[nodeNum] += diff;
	if (start != end) {
		int mid = (start + end) / 2;
		update(nodeNum * 2, start, mid, target_idx, diff);
		update(nodeNum * 2 + 1, mid + 1, end, target_idx, diff);
	}
}

ll sum(int nodeNum, int start, int end, int nodeL, int nodeR) {
	//포함 전혀 안되는 경우
	if (nodeL > end || nodeR < start) return 0;
	
	//완전히 포함된 경우
	if (nodeL <= start && end <= nodeR) return tree[nodeNum];

	//일부분 포함된 경우, 양쪽으로 나눈다.
	int mid = (start + end) / 2;
	return sum(nodeNum * 2, start, mid, nodeL, nodeR) 
		+ sum(nodeNum * 2 + 1, mid + 1, end, nodeL, nodeR);
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	arr.resize(n);

	h = (int)ceil(log2(n));
	tree_size = (1 << (h + 1));
	tree.resize(tree_size);

	for (int i = 0; i < n; i++) cin >> arr[i];
	
	//세그먼트 트리 초기화
	init(1, 0, n - 1);

	for (int i = 0; i < m + k; i++) {
		int t1, t2, t3;
		cin >> t1;
		//업데이트
		if (t1 == 1) {
			int t2;
			ll t3;
			cin >> t2 >> t3;
			t2--;
			ll diff = t3 - arr[t2];
			arr[t2] = t3;
			update(1, 0, n - 1, t2, diff);
		}
		//구간 합
		else if (t1 == 2) {
			int t2, t3;
			cin >> t2 >> t3;
			cout << sum(1, 0, n - 1, t2 - 1, t3 - 1) << '\n';
		}
	}
}