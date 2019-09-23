/*BOJ 14003 가장 긴 증가하는 부분 수열 5 (LIS, lower_bound)*/
// lower_bound로는 LIS의 길이만 구할 수 있다.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, arr[1'000'001];
vector<int> v, lis, ans;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	v.push_back(-1'000'000'001);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		int t = arr[i];
		if (v.back() < t) {
			v.push_back(t);
			lis.push_back(v.size() - 1);
		}
		else {
			//이진 탐색 기반의 탐색, 정렬되어있어야함,
			//t보다 크거나 같은 값 중 최솟값의 iterator를 반환
			auto iter = lower_bound(v.begin(), v.end(), t);

			//v벡터에 들어있는 값이 LIS를 이루는 요소와 무관하다.
			v[iter - v.begin()] = t;
			//lis벡터에 v 벡터에 있는 인덱스 저장
			lis.push_back(iter - v.begin());
		}
	}
	cout << v.size() - 1 << '\n';
	
	//lis에 인덱스를 통해 뒤에서 부터 처리해준다.
	int len = v.size() - 1;
	for (int i = lis.size() - 1; i >= 0; i--) {
		if (len > 0 && len == lis[i]) {
			ans.push_back(arr[i]);
			len--;
		}
		else if (len <= 0) break;
	}
	for (int i = ans.size()-1; i>=0; i--) cout << ans[i] << ' ';
}