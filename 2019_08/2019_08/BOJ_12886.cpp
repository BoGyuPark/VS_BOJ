#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int arr[3], check[1000][1000], ans = 0;
typedef struct {
	int a, b, c;
}info;
queue<info> q;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 3; i++) cin >> arr[i];
	sort(arr, arr + 3);
	int temp[3] = { 0, };
	q.push({ arr[0],arr[1],arr[2] });
	check[arr[0]][arr[1]]= arr[2];
	while (!q.empty()) {
		int a = q.front().a, b = q.front().b, c = q.front().c;
		q.pop();
		if (a == b && b == c && a == c) {
			ans = 1;
			break;
		}
		//a,b
		int t1, t2, t3;
		if (a < b) {
			t1 = a + a;		t2 = b - a;		t3 = c;	
		}
		else {
			t1 = b + b;		t2 = a - b;		t3 = c;
		}
		temp[0] = t1, temp[1] = t2, temp[2] = t3;
		sort(temp, temp + 3);
		if (check[temp[0]][temp[1]] == 0) {
			q.push({ temp[0],temp[1],temp[2] });
			check[temp[0]][temp[1]] = temp[2];
		}

		//b,c
		if (b < c) {
			t1 = b + b;		t2 = c - b;		t3 = a;
		}
		else {
			t1 = c + c;		t2 = b - c;		t3 = a;
		}
		temp[0] = t1, temp[1] = t2, temp[2] = t3;
		sort(temp, temp + 3);
		if (check[temp[0]][temp[1]] == 0) {
			q.push({ temp[0],temp[1],temp[2] });
			check[temp[0]][temp[1]] = temp[2];
		}

		//a,c
		if (a < c) {
			t1 = a + a;		t2 = c - a;		t3 = b;
		}
		else {
			t1 = c + c;		t2 = a - c;		t3 = b;
		}
		temp[0] = t1, temp[1] = t2, temp[2] = t3;
		sort(temp, temp + 3);
		if (check[temp[0]][temp[1]] == 0) {
			q.push({ temp[0],temp[1],temp[2] });
			check[temp[0]][temp[1]] = temp[2];
		}
	}
	cout << ans;
}