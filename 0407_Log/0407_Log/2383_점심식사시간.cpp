#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int T, tc, n, a[10][10], sel[10], st1x, st1y, st2x, st2y, st1Value, st2Value;
int ans;
vector<pair<int, int>> person, st;
//     Ÿ��
vector<int> st1List, st2List;
//   ������ �ð�, ��������
queue<pair<int, int>> waitSt1, waitSt2;
queue<int> stair1, stair2;
void FinishStair(queue<int> &q, int time) {
	//�� ��ܿ��� ������ �ð��� üũ�ؼ� pop���ش�.
	while (!q.empty()) {
		if (time == q.front()) q.pop();
		else return;
	}
}

void EnterStair(queue<pair<int, int>> &wait, queue<int> &stair, int time, int StairSize) {
	//��� ���ť�� Ȯ���Ͽ� ���ť�� Ǫ��
	while (!wait.empty()) {
		if (time == wait.front().first) {
			//���ť�� 3�������� Ǫ���Ѵ�.
			if (stair.size() < 3) {
				//����ߴ� ����� �ٷ� ����.
				if (wait.front().second == 1) {
					stair.push({ wait.front().first + StairSize });
				}
				else {
					stair.push({ wait.front().first + 1 + StairSize });
				}
				wait.pop();
			}
			//�̹� 3���� ���ִٸ� �����½ð��� +1������ ���ť�� �ִ� ���͵���
			else {
				int Qsize = wait.size();
				//��ܿ� ������ ����� flag�� �ش�.
				while (Qsize--) {
					int t = wait.front().first; wait.pop();
					if (t == time) wait.push({ t + 1, 1 });
					else wait.push({ t + 1 ,0 });
				}
				return;
			}
		}
		else return;
	}
}

void simulation() {
	//�������� ���ť�� �־�д�.
	for (int i = 0; i < st1List.size(); i++) waitSt1.push({ st1List[i] , 0 });
	for (int i = 0; i < st2List.size(); i++) waitSt2.push({ st2List[i] , 0 });
	int t = 0;

	while (true) {
		EnterStair(waitSt1, stair1, t, st1Value);
		EnterStair(waitSt2, stair2, t, st2Value);
		t++;

		FinishStair(stair1, t);
		FinishStair(stair2, t);
		//���� ����
		if (stair1.size() == 0 && stair2.size() == 0 && waitSt1.size() == 0 && waitSt2.size() == 0) break;
	}
	if (ans > t) ans = t;
}
void dfs(int index) {
	if (index == person.size()) {
		if (sel[0] == 0 && sel[1] == 1 && sel[2] == 1 && sel[3] == 1
			&& sel[4] == 1 && sel[5] == 0 && sel[6] == 0 && sel[7] == 1
			&& sel[8] == 1 && sel[9] == 1)
			cout << 'a';

		//0�� ��� 1��, 1�� ��� 2��
		for (int j = 0; j < index; j++) {
			int x = person[j].first, y = person[j].second;
			if (sel[j] == 0) {
				int dist = abs(st1x - x) + abs(st1y - y);
				st1List.push_back(dist);
			}
			else {
				int dist = abs(st2x - x) + abs(st2y - y);
				st2List.push_back(dist);
			}
		}
		sort(st1List.begin(), st1List.end());
		sort(st2List.begin(), st2List.end());
		simulation();
		st1List.clear();
		st2List.clear();
		return;
	}
	for (int i = 0; i < 2; i++) {
		sel[index] = i;
		dfs(index + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				if (a[i][j] == 1) person.push_back({ i,j });
				else if (a[i][j] >= 2) st.push_back({ i,j });
			}
		}
		st1x = st[0].first, st1y = st[0].second;
		st1Value = a[st1x][st1y];
		st2x = st[1].first, st2y = st[1].second;
		st2Value = a[st2x][st2y];
		ans = 2147483647;
		dfs(0);
		cout << '#' << tc << ' ' << ans << '\n';
		person.clear();
		st.clear();
	}
}


//#include<iostream>
//#include<algorithm>
//#include<queue>
//#include<vector>
//using namespace std;
//int T, tc, n, a[10][10], sel[10], st1x, st1y, st2x, st2y, st1Value, st2Value;
//int ans;
//vector<pair<int, int>> person, st;
////     Ÿ��
//vector<int> st1List, st2List;
////   ������ �ð�, ��������
//queue<pair<int, int>> waitSt1, waitSt2;
//queue<int> stair1, stair2;
//
//void arriveCheck(queue<pair<int, int>> &wait, queue<int> &stair, int time, int StairSize) {
//	int Qsize = wait.size();
//	while (Qsize--) {
//		//������ ǥ�ø��Ѵ�.
//		int t = wait.front().first; wait.pop();
//		if (t == time) wait.push({ t + 1,1 });
//		else wait.push({ t + 1 ,0 });
//	}
//	return;
//}
//
//void FinishStair(queue<int> &q, int time) {
//	//�� ��ܿ��� ������ �ð��� üũ�ؼ� pop���ش�.
//	while (!q.empty()) {
//		if (time == q.front()) q.pop();
//		else return;
//	}
//}
//
//void EnterStair(queue<pair<int, int>> &wait, queue<int> &stair, int time, int StairSize) {
//	//��� ���ť�� Ȯ���Ͽ� ���ť�� Ǫ��
//	while (!wait.empty()) {
//		if (time == wait.front().first) {
//			//���ť�� 3�������� Ǫ���Ѵ�.
//			if (stair.size() < 3) {
//				//�̵̹������� �ٷν���
//				if (wait.front().second == 1) {
//					stair.push({ wait.front().first + StairSize });
//				}
//				else{
//					stair.push({ wait.front().first + StairSize + 1; });
//				}
//				wait.pop();
//			}
//			//�̹� 3���� ���ִٸ� �����½ð��� +1������ ���ť�� �ִ� ���͵���
//			else {
//				int Qsize = wait.size();
//				//��ܿ� ������ ����� flag�� 1�� �ش�.
//				//�̸� ��ܿ� �����ѻ���� ���߿� �ٷ� ����� ��������.
//				while (Qsize--) {
//					int t = wait.front().first; wait.pop();
//					if (t == time) wait.push({ t + 1,1 });
//					else wait.push({ t + 1 ,0 });
//				}
//				return;
//			}
//		}
//		else return;
//	}
//}
//
//void simulation() {
//	//�������� ���ť�� �־�д�.
//	for (int i = 0; i < st1List.size(); i++) waitSt1.push({ st1List[i] , 0 });
//	for (int i = 0; i < st2List.size(); i++) waitSt2.push({ st2List[i] , 0 });
//	
//	int t = 0;
//	
//	while (true) {
//		t++;
//		//��ܿ� �����ߴ��� üũ�Ѵ�.
//		arriveCheck(waitSt1, stair1, t, st1Value);
//		arriveCheck(waitSt2, stair2, t, st2Value);
//		//��ܿ� �ִ°ͺ��� ó���Ѵ�.
//		FinishStair(stair1, t);
//		FinishStair(stair2, t);
//		//���� ����
//		if (stair1.size() == 0 && stair2.size() == 0 && waitSt1.size() == 0 && waitSt2.size() == 0) break;
//		//�ð��� ���ť�� �ִ� �ð��� ���Ͽ� �� ��ܿ� �ִ´�.
//		EnterStair(waitSt1, stair1, t, st1Value);
//		EnterStair(waitSt2, stair2, t, st2Value);
//	}
//	/*for (int i = 0; i < 10; i++) cout << sel[i] << ' ';
//	cout << '\n';
//	cout << t << '\n';*/
//	if (ans > t) ans = t;
//}
//void dfs(int index) {
//	//��Ž ó��
//	if (index == person.size()) {
//		/*if (sel[0] == 0 && sel[1] == 1 && sel[2] == 1 && sel[3] == 1 
//			&& sel[4] == 1 && sel[5] == 0 && sel[6] == 0 && sel[7] == 1
//			&& sel[8] == 1 && sel[9] == 1)
//			cout << 'a';*/
//		if (sel[0] == 0 && sel[1] == 0 && sel[2] == 0 && sel[3] == 0
//			&& sel[4] == 1 && sel[5] == 1)
//			cout << 'a';
//
//		//0�� ��� 1��, 1�� ��� 2��
//		for (int j = 0; j < index; j++) {
//			int x = person[j].first, y = person[j].second;
//			if (sel[j] == 0) {
//				int dist = abs(st1x - x) + abs(st1y - y);
//				st1List.push_back(dist);
//			}
//			else {
//				int dist = abs(st2x - x) + abs(st2y - y);
//				st2List.push_back(dist);
//			}
//		}
//		//���� �Ÿ��� ��Ʈ�� �Ѵ�.
//		sort(st1List.begin(), st1List.end());
//		sort(st2List.begin(), st2List.end());
//		//���� �ùķ��̼��� ����
//		simulation();
//		st1List.clear();
//		st2List.clear();
//		return;
//	}
//	for (int i = 0; i < 2; i++) {
//		sel[index] = i;
//		dfs(index + 1);
//	}
//}
//int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
//	cin >> T;
//	for (tc = 1; tc <= T; tc++) {
//		cin >> n;
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				cin >> a[i][j];
//				if (a[i][j] == 1) person.push_back({ i,j });
//				else if (a[i][j] >= 2) st.push_back({ i,j });
//			}
//		}
//		st1x = st[0].first, st1y = st[0].second;
//		st1Value = a[st1x][st1y];
//		st2x = st[1].first, st2y = st[1].second;
//		st2Value = a[st2x][st2y];
//		ans = 2147483647;
//		dfs(0);
//		cout << '#' << tc << ' ' << ans + 1 << '\n';
//		person.clear();
//		st.clear();
//	}
//}