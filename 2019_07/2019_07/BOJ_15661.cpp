/*BOJ 15661 링크와 스타트*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, arr[20][20];
vector<int> st, li;
int ans = 2147483647;
void go(int index) {
	if (index == n) {
		int stSum = 0, liSum = 0;
		for (int a = 0; a < st.size(); a++) {
			for (int b = a + 1; b < st.size(); b++) {
				stSum += (arr[st[a]][st[b]]+ arr[st[b]][st[a]]);
			}
		}
		for (int a = 0; a < li.size(); a++) {
			for (int b = a + 1; b < li.size(); b++) {
				liSum += (arr[li[a]][li[b]] + arr[li[b]][li[a]]);
			}
		}
		ans = min(ans, abs(stSum - liSum));
	}
	if (st.size() < n - 1) {
		st.push_back(index);
		go(index + 1);
		st.pop_back();
	}
	
	if (li.size() < n - 1) {
		li.push_back(index);
		go(index + 1);
		li.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> arr[i][j];
	go(0);
	cout << ans;
}