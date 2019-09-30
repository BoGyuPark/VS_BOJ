#include <iostream>
#include <stack>
using namespace std;

#define LIM 99999999999
int N;
long long ans, cur, beforeCnt, beforeNum;
stack<long long> st;

void calc() {
	beforeNum = beforeCnt = 0;

	while (1) {
		int flag = (st.top() == LIM ? 2 : 0) + (cur == LIM ? 1 : 0);
		if (st.top() < cur) {
			if (beforeNum != st.top()) {
				ans += beforeCnt * (beforeCnt - 1) / 2;
				switch (flag) {
				case 0: ans += 2 * beforeCnt; break;
				case 1: case 2: ans += beforeCnt; break;
				case 3: break;
				}

				beforeNum = st.top();
				beforeCnt = 1;
			}
			else beforeCnt++;
			st.pop();
		}
		else {
			ans += beforeCnt * (beforeCnt - 1) / 2;
			switch (flag) {
			case 0: ans += 2 * beforeCnt; break;
			case 2: ans += beforeCnt; break;
			default: break;
			}
			break;
		}
	}
	st.push(cur);
}

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	st.push(LIM);
	while (N--) {
		cin >> cur;
		calc();
	}
	cur = LIM;
	calc();

	cout << ans << '\n';
}