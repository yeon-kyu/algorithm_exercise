#include <string>
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <iostream>

using namespace std;

int N;
int N2;
int mat[21][21];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0,0,1, -1 };

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			mat[i][j] = 0;
		}
	}
}

struct Pos {
	int y;
	int x;
};

Pos getBestPosition(int a, int b, int c, int d) {
	// 1. 반복을 돌면서 a, b, c, d가 근처에 최대가 되는 곳을 찾는다
	int maxCount = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (mat[i][j] != 0) {
				continue;
			}
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
					int tar = mat[ny][nx];
					if (tar == a || tar == b || tar == c || tar == d) {
						cnt++;
					}
				}
			}
			if (maxCount < cnt) {
				maxCount = cnt;
			}
		}
	}
	// 최대가 되는 곳이 여러개인지 확인
	vector<Pos> v;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (mat[i][j] != 0) {
				continue;
			}
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
					int tar = mat[ny][nx];
					if (tar == a || tar == b || tar == c || tar == d) {
						cnt++;
					}
				}
			}
			if (cnt == maxCount) {
				v.push_back({ i, j });
			}
		}
	}

	// 최대가 되는 곳이 1개이면 끝.
	if (v.size() == 1) {
		return v[0];
	}

	// 2. 1번을 만족하는 칸이 여러개이면, 인접한 칸중에 빈 칸이 가장 많은 칸으로 정한다.
	maxCount = -1;
	for (int i = 0; i < v.size(); i++) {
		int y = v[i].y;
		int x = v[i].x;
		int cnt = 0;
		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
				int tar = mat[ny][nx];
				if (tar == 0) {
					cnt++;
				}
			}
		}
		if (maxCount < cnt) {
			maxCount = cnt;
		}
	}

	vector<Pos> v2;
	for (int i = 0; i < v.size(); i++) {
		int y = v[i].y;
		int x = v[i].x;
		int cnt = 0;
		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
				int tar = mat[ny][nx];
				if (tar == 0) {
					cnt++;
				}
			}
		}
		if (cnt == maxCount) {
			v2.push_back({ y, x });
		}
	}

	if (v2.size() == 1) {
		return v2[0];
	}

	// 3. 2단계까지 만족하는 칸이 여러개인 경우, 
	// 행번호가 가장작은 칸, 같은 칸에 대해서는 가장 열번호가 작은 칸을 반환
	return v2[0];
}

int getSum(vector<int> v) {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (mat[i][j] == v[0]) {
				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
						int tar = mat[ny][nx];
						if (tar == v[1] || tar == v[2] || tar == v[3] || tar == v[4]) {
							cnt++;
						}
					}
				}
			}
		}
	}
	if (cnt == 0) {
		return 0;
	}
	else if (cnt == 1) {
		return 1;
	}
	else if (cnt == 2) {
		return 10;
	}
	else if (cnt == 3) {
		return 100;
	}
	else {
		return 1000;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	N2 = N * N;

	init();

	vector<vector<int>> preferInfo;

	for (int i = 0; i < N2; i++) {
		int stu, a, b, c, d;
		cin >> stu;
		cin >> a >> b >> c >> d;

		Pos cur = getBestPosition(a, b, c, d);
		mat[cur.y][cur.x] = stu;

		vector<int> v = { stu, a, b, c, d };
		preferInfo.push_back(v);
	}
	int answer = 0;
	for (int i = 0; i < N2; i++) {
		int ans = getSum(preferInfo[i]);
		answer += ans;
	}
	cout << answer;
}