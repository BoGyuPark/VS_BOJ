/*BOJ 1935 후위 표기식2*/
#include<iostream>
#include<stack>
#include<map>
#include<string>
using namespace std;
int n, arr[27];
int char_check[120];
int main() {
	cin >> n;
	string str;
	cin >> str;
	for (int i = 0; i < n; i++) cin >> arr[i];
	map<char, int> m;
	stack<double> st;

	//알파벳에 맞는 값 입력
	int j = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			if (char_check[str[i]] == false) {
				char_check[str[i]] = true;
				m[str[i]] = arr[j];
				j++;
			}
		}
	}

	/*for (auto i : m) {
		cout << i.first << ' ' << i.second << '\n';
	}*/

	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			st.push(m[str[i]]);
		}
		else {
			double o1, o2;	//o1 * o2
			o2 = st.top();	st.pop();
			o1 = st.top(); st.pop();
			char op = str[i];
			double result = 0;
			switch (op)
			{
			case '*':
				result = o1 * o2;
				break;
			case '+':
				result = o1 + o2;
				break;
			case '/':
				result = o1 / o2;
				break;
			case '-':
				result = o1 - o2;
				break;
			}
			st.push(result);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << st.top();
}