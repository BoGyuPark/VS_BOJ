#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	queue<string> q;
	vector<long long> v;
	q.push("");
	while (true) {
		string temp = q.front(); q.pop();
		string t1 = temp + "4";
		string t2 = temp + "7";
		q.push(t1);	q.push(t2);
		v.push_back(stol(t1)); v.push_back(stol(t2));
		if (t1.size() > 8) break;
	}
	sort(v.begin(), v.end());
	for (int i = v.size() - 1; i >= 0; i--) {
		if (v[i] <= n) {
			cout << v[i];	break;
		}
	}
}