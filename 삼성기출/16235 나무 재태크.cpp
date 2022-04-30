#include <string>
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

int N, M, K;
int A[10][10];
vector<int> tree[10][10];
int feed[10][10];
int dead[10][10];

int dy[8] = { -1, -1, -1, 0, 0, 1,1,1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0,1 };

void init() {
	cin >> N >> M >> K;

	// 겨울마다 추가될 양분 할당
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}

	// 나무 비워냄
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			vector<int> temp;
			tree[i][j] = temp;
		}
	}

	// 나무 초기값
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tree[a - 1][b - 1].push_back(c);
	}

	// 양분 추가
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			feed[i][j] = 5;
		}
	}

	// 죽은 나무 저장할 값 초기화
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dead[i][j] = 0;
		}
	}
}

void spring() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// 나이가 어린 순으로 정렬
			sort(tree[i][j].begin(), tree[i][j].end());

			vector<int>& v = tree[i][j]; // 나무의 나이들
			int size = v.size();
			for (int k = 0; k < size; k++) {
				if (feed[i][j] >= v[k]) {
					feed[i][j] -= v[k];
					v[k]++;
				}
				else {
					dead[i][j] += v[k] / 2;
					v.erase(v.begin() + k);
					k--;
					size--;
				}
			}
		}
	}
}

void summer() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			feed[i][j] += dead[i][j];
			dead[i][j] = 0;
		}
	}
}

void newBaby(int y, int x) {
	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
			tree[ny][nx].push_back(1);
		}
	}
}

void fall() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int size = tree[i][j].size();
			for (int k = 0; k < size; k++) {
				if (tree[i][j][k] % 5 == 0) {
					newBaby(i, j);
				}
			}
		}
	}
}

void winder() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			feed[i][j] += A[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// N*N 크기의 땅
	// 로봇은 각 칸에 있는 양분을 조사해 상도에게 전송
	// 처음에 양분은 모든 칸에 5만큼 들어있다.

	// M개의 나무를 구매.
	
	// 봄
	// 나무는 자신의 나이만큼 양분을 먹고, 나이 1증가
	// 각 나무는 1 크기의 칸에 있는 양분만 먹을 수 있다.
	// 하나의 칸에 여러개의 나무가 있다면 나이가 어린 나무부터 양분을 먹는다.
	// 땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 
	// 양분을 먹지 못하고 즉시 죽는다.

	// 여름
	// 봄에 죽은 나무가 양분으로 변한다.
	// 죽은 나무의 나이를 2로 나눈 값이 양분으로 추가된다.

	// 가을
	// 나이가 5의 배수인 나무가 번식한다.
	// 인접한 8개의 칸에 나이가 1인 나무가 생긴다.

	// 겨울
	// 로봇이 땅을 돌아다니며 양분을 추가한다.
	// 각 칸에 추가되는 양분의 양은 A[r][c]

	init();

	for (int i = 0; i < K; i++) {
		spring();
		summer();
		fall();
		winder();
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			answer += tree[i][j].size();
		}
	}
	cout << answer;
}