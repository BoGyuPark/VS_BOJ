//BOJ_11652_Card
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
	int n; cin >> n;
	map<long long, int> m;
	long long temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		m[temp]++;
	}
	long long ans, max = -1;
	for (auto &q : m) {
		if (max < q.second) {
			max = q.second;
			ans = q.first;
		}
	}
	cout << ans;
	return 0;
}


//sort Ç®ÀÌ
//long long arr[1000001];
//int main()
//{
//	int n; cin >> n;
//	for (int i = 0; i < n; i++) cin >> arr[i];
//
//	sort(arr, arr + n);
//	int ans_cnt = 1, max_cnt = 1;
//	long long ans = arr[0];
//	for (int i = 1; i < n; i++) {
//		if (arr[i] == arr[i - 1])
//			ans_cnt++;
//		else 
//			ans_cnt = 1;
//
//		if (max_cnt < ans_cnt) {
//			max_cnt = ans_cnt;
//			ans = arr[i];
//		}
//	}
//	cout << ans;
//	return 0;
//}