#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int tc, T, n, k;
void Rotate(char arr[30], int Size) {
	int temp = arr[Size - 1];
	for (int i = Size - 1; i > 0; i--) arr[i] = arr[i - 1];
	arr[0] = temp;
}

int main() {
	cin >> tc;
	for (T = 1; T <= tc; T++) {
		cin >> n >> k;
		char a[30] = { 0, };
		vector<string> vs;
		for (int i = 0; i < n; i++) cin >> a[i];
		/*for (int i = 0; i < n; i++) cout << a[i] << ' ';
		cout << '\n';*/

		int len = n / 4;
		//각변의 생성될 값을 vs에 넣는다.
		int LimitRotate = len;
		for (int i = 0; i < LimitRotate; i++) {
			for (int i = 0; i < n; i += len) {
				string s = "";
				for (int j = 0; j < len; j++) s += a[i + j];
				vs.push_back(s);
			}
			//회전을 시켜준다.
			if (i != LimitRotate - 1)	Rotate(a, n);
		}
		sort(vs.begin(), vs.end());

		vs.erase(unique(vs.begin(), vs.end()), vs.end());
		reverse(vs.begin(), vs.end());
		string ans = vs[k - 1];

		//10진수로 변경
		long long sum = 0, mul = 1;
		// A  B  C  D  E  F 
		// 10 11 12 13 14 15
		for (int i = ans.size() - 1; i >=0; i--) {
			if (ans[i]-'0' < 10) sum += (ans[i]-'0') * mul;
			else sum += (ans[i] - 'A' + 10) * mul;
			mul *= 16;
		}
		cout << '#' << T << ' ' << sum << '\n';
	}
}