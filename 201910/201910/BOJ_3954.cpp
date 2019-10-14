/*BOJ_3954 Brainf**k 인터프리터*/
#include<iostream>
#include<string>
#include<stack>
#include<cstring>
using namespace std;
int T, tc, n, m, c, memo[100'001];
int jumpLeft[100'001], jumpRight[100'001];
string s, order;
bool simulate() {
	int charIdx = 0, orderIdx = 0, p = 0;
	while (orderIdx!=m) {
		char state = order[orderIdx];
		int flag = false;
		switch (state)
		{
		case '-':
			memo[p] = (memo[p] - 1) % (1 << 8);
			break;
		case '+':
			memo[p] = (memo[p] + 1) % (1 << 8);
			break;
		case '<':
			if (p == 0) p = n;
			p = p - 1;
			break;
		case '>':
			p = (p + 1) % n;
			break;
		case '[':
			if (memo[p] == 0) {
				cout << orderIdx << " -> " << jumpLeft[orderIdx] <<" "<<memo[p]<<" "<<'\n';
				orderIdx = jumpLeft[orderIdx];
				flag = true;
			}
			break;
		case ']':
			if (memo[p] != 0) {
				cout << orderIdx << " <- " << jumpRight[orderIdx] << " " << memo[p] << " " << '\n';
				orderIdx = jumpRight[orderIdx];
				flag = true;
			}
			break;
		case '.':
			break;
		case ',':
			if (s.size() <= charIdx) memo[p] = 255;
			else {
				memo[p] = s[charIdx];
				charIdx++;
			}
			break;
		}
		if(!flag) orderIdx++;
	}
	return true;
}
int main() {
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> n >> m >> c >> order >> s;
		stack<int> st;
		memset(jumpLeft, -1, sizeof(jumpLeft));
		memset(jumpRight, -1, sizeof(jumpRight));
		for (int i = 0; i < order.size(); i++) {
			if (order[i] == '[') st.push(i);
			else if (order[i] == ']') {
				jumpLeft[st.top()] = i;
				jumpRight[i] = st.top();
				st.pop();
			}
		}
		if (simulate()) cout << "Terminates" << '\n';
		else {

		}
		memset(memo, 0, sizeof(memo));
	}
}