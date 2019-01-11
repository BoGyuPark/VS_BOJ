//BOJ_9375_KingOfFashion
#include<bits/stdc++.h>
using namespace std;
int main(){
	int N; cin >> N;
	for (int a = 0; a < N; a++) {
		int n;	cin >> n;
		map<string, int> m;
		map<string, int>::iterator it;
		while (n--) {
			string t1, t2;
			cin >> t1 >> t2;
			//Key에 해당하는 value 증가.
			m[t2]++;
		}
		int s = m.size();
		int ans = 1;
		for (it = m.begin(); it != m.end(); it++) {
			ans *= (it->second + 1);
		}
		cout << ans - 1 << "\n";
	}
	return 0;
}