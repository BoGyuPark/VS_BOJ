#include<iostream>
#include<algorithm>
#define MAX 20
using namespace std;
int n, k, map[10][10], order[4][21], sel[MAX], ans = 0;
int Winner, noEnter, wins[4], maxi;
void fight(int w, int no, int R) {
	//w와 no 대결
	int t = map[order[w][R]][order[no][R]];
	//w가 승자
	if (t == 2) {
		Winner = w;
		noEnter = (6 - w - no);
	}
	//w가 진경우
	else if (t == 0) {
		Winner = no;
		noEnter = (6 - no - w);
	}
	//w와 no가 비긴경우
	else {
		Winner = max(w, no);
		noEnter = (6 - w - no);
	}
	wins[Winner]++;
}

void solve() {
	// 1은 A, 2은 B, 3는 C
	Winner = 1; noEnter = 2;
	for (int r = 0; r < maxi; r++) {
		fight(Winner, noEnter,r);
		for (int x = 1; x <= 3; x++) {
			if (wins[x] >= k && x == 1) {
				ans = 1;
				return;
			}
		}
	}
}


void go(int index) {
	if (index == maxi) {
		int cnt = 0;
		for (int j = 1; j < maxi; j++) {
			if (sel[j - 1] == sel[j]) cnt++;
		}
		/*if (cnt == 0) {
			for (int j = 0; j < maxi; j++) cout << sel[j] << ' ';
			cout << '\n';
		}*/
		
		//손동작이 연속되지 않은 경우 solve한다.
		if (cnt == 0) {
			for (int j = 0; j < maxi; j++) order[1][j] = sel[j];
			solve();
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		sel[index] = i + 1;
		go(index + 1);	
	}
}


int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> map[i][j];
	for (int i = 2; i < 4; i++) {
		for (int j = 0; j < 20; j++) {
			cin >> order[i][j];
		}
	}
	maxi = (3 * (k - 1) + 1);
	go(0);
	cout << ans;
}