#include <string>
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

int N, M;
int mat[51][51];
int cloud[51][51];

int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

int diaY[4] = { -1, -1, 1, 1 };
int diaX[4] = { -1, 1, -1, 1 };

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cloud[i][j] = 0;
		}
	}

	// 초기 구름
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cloud[N - 1 - i][j] = 1;
		}
	}
}

void moveCloud(int s, int d) {
	int temp[51][51];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = 0;
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (cloud[i][j] == 1) {
				int ny = i + s * dy[d - 1];
				int nx = j + s * dx[d - 1];

				while (ny < 0) {
					ny += N;
				}
				while (nx < 0) {
					nx += N;
				}
				ny = ny % N;
				nx = nx % N;

				temp[ny][nx] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cloud[i][j] = temp[i][j];
		}
	}
}

void rain() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (cloud[i][j] == 1) {
				mat[i][j]++;
			}
		}
	}
}

void copyWater() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (cloud[i][j] == 1) {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int ny = i + diaY[k];
					int nx = j + diaX[k];
					if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
						if (mat[ny][nx] > 0) {
							cnt++;
						}
					}
				}
				mat[i][j] += cnt;
			}
		}
	}
}

void makeCloud() {
	int temp[51][51]; // 새로운 구름
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (mat[i][j] >= 2 && cloud[i][j] == 0) {
				mat[i][j] -= 2;
				temp[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cloud[i][j] = temp[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mat[i][j];
		}
	}

	init();

	for (int i = 0; i < M; i++) {
		int d, s;
		cin >> d >> s;
	
		// 1단계
		moveCloud(s, d);

		// 2단계
		rain();

		// 3단계
		// 여기서 삭제하면 안됨. 4단계에서 cloud가 사용됨

		// 4단계
		copyWater();

		// 5단계
		makeCloud();
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			answer += mat[i][j];
		}
	}
	cout << answer;
}