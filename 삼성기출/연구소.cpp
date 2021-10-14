#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int mat[9][9];

struct posInfo {
	int y;
	int x;
};
vector<posInfo> v;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int ans = 0;

void do_bfs(vector<posInfo> temp) { //temp에는 막을 기둥의 좌표가 들어있음
	int m[9][9];

	vector<posInfo> two_vector;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			m[i][j] = mat[i][j];
			if (m[i][j] == 2) {
				two_vector.push_back({ i,j });
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		m[temp[i].y][temp[i].x] = 1;
	}

	for (auto it = two_vector.begin(); it != two_vector.end(); it++) {

		int y = it->y;
		int x = it->x;

		queue<posInfo> q;
		q.push({ y,x });
		while (!q.empty()) {
			posInfo front = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int Y = front.y + dy[i];
				int X = front.x + dx[i];
				if (Y >= 0 && Y < N && X >= 0 && X < M) {
					if (m[Y][X] == 0) {
						m[Y][X] = 2;
						q.push({ Y, X });
					}
				}
			}
		}
	}

	//남은 0 세기
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (m[i][j] == 0) {
				cnt++;
			}
		}
	}

	ans = max(cnt, ans);
}

void get_all_case(vector<posInfo> temp, int pos) {
	if (temp.size() == 3) {
		do_bfs(temp);
		return;
	}

	int size = v.size();
	if (pos == size) {
		return;
	}

	get_all_case(temp, pos + 1);
	temp.push_back(v[pos]);
	get_all_case(temp, pos + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 0) {
				v.push_back({ i,j });
			}
		}
	}
	vector<posInfo> temp;
	get_all_case(temp, 0);

	cout << ans;
}