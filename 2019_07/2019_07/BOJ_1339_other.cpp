/*BOJ 1339 �Ǵٸ� ���̵��*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int n, alpha_value[30];
string s;
long long ans = 0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			//�ش� ���ĺ��� �ڸ����� ���صд�.
			alpha_value[s[j] - 'A'] += pow(10, s.size() - 1 - j);
		}
	}
	vector<int> v;
	for (int i = 0; i < 27; i++) {
		if (alpha_value[i] > 0) {
			v.push_back(alpha_value[i]);
		}
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	int num = 9;
	for (int i = 0; i < v.size(); i++) {
		ans += v[i] * num;
		num--;
	}
	cout << ans;
}
