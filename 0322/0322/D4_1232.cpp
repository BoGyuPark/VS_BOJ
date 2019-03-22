#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<stack>
using namespace std;
stack<double> st;
int LeftChild[1001], RightChild[1001];
void postorder(vector<string> &a, int start) {
	if (start <= 1001 && a[start] != "\0") {
		postorder(a, LeftChild[start]);
		postorder(a, RightChild[start]);
		if (a[start] == "+" || a[start] == "-" || a[start] == "*" || a[start] == "/") {
			double t1, t2;
			t2 = st.top(); st.pop();
			t1 = st.top(); st.pop();
			if (a[start] == "+") a[start] = to_string(t1 + t2);
			else if (a[start] == "-")	a[start] = to_string(t1 - t2);
			else if (a[start] == "*") a[start] = to_string(t1 * t2);
			else if (a[start] == "/") a[start] = to_string(t1 / (double)t2);
			st.push(stod(a[start]));
		}
		else st.push(stod(a[start]));
	}
}
int main() {
	for (int tc = 1; tc <= 10; tc++) {
		int n; cin >> n; cin.ignore();
		vector<string> arr(1001);
		for (int i = 1; i <= n; i++) {
			string s;
			getline(cin, s);
			char t[100] = { 0, };
			for (int j = 0; j < s.size(); j++) t[j] = s[j];
			char *ptr = strtok(t, "  ");
			ptr = strtok(NULL, " ");
			int first = true;
			int cnt = 1;
			while (ptr != NULL) {
				if (first) {
					arr[i] = ptr;
					first = false;
				}
				else {
					if (cnt == 1) {
						LeftChild[i] = stoi(ptr);
						cnt++;
					}
					else RightChild[i] = stoi(ptr);
				}
				ptr = strtok(NULL, " ");
			}
		}
		postorder(arr, 1);
		cout << '#' << tc << ' ' << stoi(arr[1]) << '\n';
		memset(RightChild, 0, sizeof(RightChild));
		memset(LeftChild, 0, sizeof(LeftChild));
	}
}