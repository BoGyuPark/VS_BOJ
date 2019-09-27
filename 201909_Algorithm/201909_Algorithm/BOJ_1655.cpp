/*BOJ 1655 가운데를 말해요*/
#include<iostream>
#include<queue>
using namespace std;
int n,t;
queue<int> q;
priority_queue<int,vector<int>,greater<int>> minHeap;
priority_queue<int> maxHeap;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (maxHeap.size() ==  minHeap.size()) {
			//초기
			if (maxHeap.empty()) maxHeap.push(t);
			else {
				//left
				if (t <= minHeap.top()) maxHeap.push(t);
				else {
					maxHeap.push(minHeap.top());
					minHeap.pop();
					minHeap.push(t);
				}
			}
		}
		else if (maxHeap.size() > minHeap.size()) {
			//left
			if (maxHeap.top() >= t) {
				minHeap.push(maxHeap.top());
				maxHeap.pop();
				maxHeap.push(t);
			}
			//right
			else minHeap.push(t);
		}
		cout << maxHeap.top() << '\n';
	}
}