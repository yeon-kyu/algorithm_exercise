#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int N, M;
int mat[100][100];
bool visited[100][100];

bool allMelt() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mat[i][j] == 1) {
				return false;
			}
		}
	}
	return true;
}

void refresh() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
		}
	}
}

void startMelt() {
	int dx[4] = { 1,-1, 0,0 };
	int dy[4] = { 0, 0, -1, 1 };

	//치즈 내부의 공간을 0 로 만들자.치즈 외부의 공간을 -1로 만들자.
	refresh();
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		mat[y][x] = -1;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
				if (visited[ny][nx] == false && mat[ny][nx] == 0) {
					visited[ny][nx] = true;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}

	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mat[i][j] == 1) {
				int outerCnt = 0;
				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
						if (mat[ny][nx] == -1) {
							outerCnt++;
						}
					}
				}
				if (outerCnt >= 2) {
					v.push_back(make_pair(i, j));
				}
			}
		}
	}

	//치즈의 녹는 부분을 0으로 만들자. with v
	for (auto it : v) {
		int y = it.first;
		int x = it.second;
		mat[y][x] = 0;
	}

	// 치즈 외부공간인 -1을 원상복귀하자.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mat[i][j] == -1) {
				mat[i][j] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mat[i][j];
		}
	}

	int answer = 0;
	while (!allMelt()) {
		startMelt();
		answer++;
	}

	cout << answer;
}