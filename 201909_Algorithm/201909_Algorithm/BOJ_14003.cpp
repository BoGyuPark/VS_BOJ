/*BOJ 14003 ���� �� �����ϴ� �κ� ���� 5 (LIS, lower_bound)*/
// lower_bound�δ� LIS�� ���̸� ���� �� �ִ�.
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
			//���� Ž�� ����� Ž��, ���ĵǾ��־����,
			//t���� ũ�ų� ���� �� �� �ּڰ��� iterator�� ��ȯ
			auto iter = lower_bound(v.begin(), v.end(), t);

			//v���Ϳ� ����ִ� ���� LIS�� �̷�� ��ҿ� �����ϴ�.
			v[iter - v.begin()] = t;
			//lis���Ϳ� v ���Ϳ� �ִ� �ε��� ����
			lis.push_back(iter - v.begin());
		}
	}
	cout << v.size() - 1 << '\n';
	
	//lis�� �ε����� ���� �ڿ��� ���� ó�����ش�.
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