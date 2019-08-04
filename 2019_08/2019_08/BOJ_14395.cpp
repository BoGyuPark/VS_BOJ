/*BOJ 14395 4연산*/
#include<iostream>
#include<queue>
#include<string>
#include<set>
using namespace std;
int s, t;
#define MAX 1'000'000'001
set<int> check;
set<int>::iterator iter;
queue<pair<int,string>> q;
string ans;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s >> t;
	if (s == t) {
		cout << 0;
		return 0;
	}
	q.push({ s,"" });
	while (!q.empty()) {
		int now = q.front().first;
		string nowStr = q.front().second;
		q.pop();
		if (now == t) {
			ans = nowStr;
			break;
		}

		int next;
		// *
		if (now < 31623) {
			next = now * now;
			iter = check.find(next);
			string nextStr = nowStr + "*";
			if (iter == check.end()) {
				check.insert(next);
				q.push({ next, nextStr });
			}
		}

		// +
		if (now <= MAX / 2) {
			next = now + now;
			iter = check.find(next);
			string nextStr = nowStr + "+";
			if (iter == check.end()) {
				check.insert(next);
				q.push({ next, nextStr });
			}
		}

		// /
		next = 1;
		iter = check.find(next);
		string nextStr = nowStr + "/";
		if (iter == check.end()) {
			check.insert(next);
			q.push({ next, nextStr });
		}
	}
	if (ans == "") ans = "-1";
	cout << ans;
	return 0;
}
///*BOJ 14395 4연산*/
//#include<iostream>
//#include<queue>
//#include<cstring>
//#include<vector>
//#include<map>
//#define MAX 1'000'000'001
//using namespace std;
//int s, t;
//queue<int> q;
//map<int,int> hs;
//map<int,int>::iterator iter;
//map<int, pair<int, char>> m;
//vector<char> ans;
//int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
//	cin >> s >> t;
//	if (s == t) {
//		cout << 0;
//		return 0;
//	}
//	q.push(s);
//	hs.insert({ s,1 });
//	while (!q.empty()) {
//		int now = q.front(); q.pop();
//		if (now == t) break;
//		
//		int next;
//		// *
//		if (now < 31623) {
//			next = now * now;
//			iter = hs.find(next);
//			if (iter == hs.end()) {
//				hs.insert({ next,1 });
//				q.push(next);
//				m.insert({ next,{now,'*'}});
//			}
//		}
//
//		// +
//		if (now <= MAX/2) {
//			next = now + now;
//			iter = hs.find(next);
//			if (iter == hs.end()) {
//				hs.insert({ next,1 });
//				q.push(next);
//				m.insert({ next,{now,'+'} });
//			}
//		}
//
//		// /
//		next = 1;
//		iter = hs.find(next);
//		if (iter == hs.end()) {
//			hs.insert({ next,1 });
//			q.push(next);
//			m.insert({ next,{now,'/'} });
//		}
//	}
//	iter = hs.find(t);
//	if (iter == hs.end()) {
//		cout << -1;
//		return 0;
//	}
//	else {
//		int temp = t;
//		int idx;
//		char value;
//		while (true) {
//			idx = m.find(temp)->second.first;
//			value = m.find(temp)->second.second;
//			//cout << idx << " " << value << '\n';
//			ans.push_back(value);
//			temp = idx;
//			if (idx == s) break;
//		}
//		for (int i = ans.size() - 1; i >= 0; i--) {
//			cout << ans[i];
//		}
//	}
//	return 0;
//}