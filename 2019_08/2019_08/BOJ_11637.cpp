/*BOJ 16637 괄호 추가하기*/
#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;
typedef long long ll;
int n, m;
long long ans = -2147483647;
int sel[11], check[20];
vector<ll> num, tempNum;
vector<char> op, tempOp;
string s;
ll cal(ll a, ll b, char c) {
	if (c == '+') return a + b;
	else if (c == '-') return a - b;
	else if (c == '*') return a * b;
}

void go(int index, int start, int dest) {
	if (index == dest) {
		/*for (int j = 0; j < dest; j++) {
			cout << sel[j] << ' ';
		}
		cout << '\n';*/

		//값을 미리 변경
		for (int j = 0; j < dest; j++) {
			num[sel[j]] = cal(num[sel[j]], num[sel[j] + 1], op[sel[j]]);
			num[sel[j] + 1] = 0;
			op[sel[j]] = '+';
		}

		/*for (int j = 0; j < op.size(); j++) {
			cout << num[j] << op[j];
		}
		cout << num[op.size()];*/


		//계산
		ll result = num[0];
		for (int j = 0; j < op.size(); j++) {
			result = cal(result, num[j + 1], op[j]);
		}
		//cout << "= " << result << '\n';
		if (ans < result) ans = result;

		//복원
		for (int j = 0; j < num.size(); j++) num[j] = tempNum[j];
		for (int j = 0; j < op.size(); j++) op[j] = tempOp[j];

		return;
	}
	for (int i = start; i < op.size(); i++) {
		if (check[i]) continue;
		check[i] = true;
		if (index == 0 || sel[index - 1] != i - 1) {
			sel[index] = i;
			go(index + 1, i, dest);
		}
		check[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	cin >> s;
	if (n == 1) cout << s;
	else {
		for (int i = 0; i < s.size(); i++) {
			if (i % 2 == 1) {
				op.push_back(s[i]);
				tempOp.push_back(s[i]);
			}
			else {
				num.push_back(s[i] - '0');
				tempNum.push_back(s[i] - '0');
			}
		}
		int MAX = ceil(op.size() / 2.0);
		for (int i = 1; i <= MAX; i++) go(0, 0, i);
		cout << ans;
	}
}