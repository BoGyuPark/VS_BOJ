/*BOJ 2075 N번째 큰 수*/
#include<iostream>
#include<queue>
using namespace std;
int n;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	//min-heap
	priority_queue<int,vector<int>, greater<int>> pq;
	for (int i = 0; i < n*n; i++) {
		int temp;
		cin >> temp;
		pq.push(temp);
		if (pq.size() > n) {
			pq.pop();
		}
	}
	cout << pq.top();
} 
//*BOJ 2075 N번째 큰 수*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int n;
//vector<int> v1, v2, sum, temp;
//int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
//	cin >> n;
//	v1.resize(n); v2.resize(n); temp.resize(n);
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) cin >> temp[j];
//		sort(temp.begin(), temp.end());
//		if (i == 0) {
//			v1 = temp;
//			continue;
//		}
//		v2 = temp;
//		//비교
//		for (int z = 0; z < n; z++) {
//			if (v1[v1.size() - 1] < v2[v2.size() - 1]) {
//				sum.push_back(v2[v2.size() - 1]);
//				v2.pop_back();
//			}
//			else {
//				sum.push_back(v1[v1.size() - 1]);
//				v1.pop_back();
//			}
//		}
//		reverse(sum.begin(), sum.end());
//		v1 = sum;
//		sum.clear();
//	}
//	cout << v1[0];
//}