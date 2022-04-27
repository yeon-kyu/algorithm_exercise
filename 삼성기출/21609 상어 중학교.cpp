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
int mat[21][21];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
bool visited[21][21];

const int DEL = -2;

int answer;

struct Pos {
	int y;
	int x;
};

void refresh() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}
}

vector<int> getSize(int y, int x) {
	refresh();
	int cnt = 1;
	int rainbow = 0;
	int color = mat[y][x];

	queue<Pos> q;
	q.push({ y, x });
	visited[y][x] = true;
	int baseBlock = y * N + x;

	while (!q.empty()) {
		Pos cur = q.front(); 
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = cur.y + dy[k];
			int nx = cur.x + dx[k];
			if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
				if (mat[ny][nx] == color || mat[ny][nx] == 0) {
					if (visited[ny][nx] == false) {
						q.push({ ny, nx });
						visited[ny][nx] = true;
						cnt++;
						if (mat[ny][nx] == 0) {
							rainbow++;
						}
						else {
							baseBlock = min(baseBlock, ny * N + nx);
						}
					}
				}
			}
		}
	}
	vector<int> v = { cnt, rainbow, baseBlock };
	return v;
}

Pos getBiggestBlock(int cnt, int rainbow) {
	// 기준 블록 : 무지개 블록이 아닌 블록중에 행과 열이 가장 작은 블록
	set<int> s; // 기준 블록들의 모음
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (mat[i][j] >= 1) {
				vector<int> v = getSize(i, j);
				int size = v[0];
				if (size == cnt && v[1] == rainbow) {
					s.insert(v[2]);
				}
			}
		}
	}
	// 기준 블록들 중, 행과 열이 가장 큰 것을 반환해야함
	int maxi = *s.begin();
	for (auto it = s.begin(); it != s.end(); it++) {
		if (*it > maxi) {
			maxi = *it;
		}
	}
	return Pos{ maxi / N, maxi%N };
}

void deleteBlock(int y, int x) {
	refresh();
	int color = mat[y][x];

	queue<Pos> q;
	q.push({ y, x });
	visited[y][x] = true;
	mat[y][x] = DEL;

	while (!q.empty()) {
		Pos cur = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = cur.y + dy[k];
			int nx = cur.x + dx[k];
			if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
				if (mat[ny][nx] == color || mat[ny][nx] == 0) {
					if (visited[ny][nx] == false) {
						q.push({ ny, nx });
						visited[ny][nx] = true;
						mat[ny][nx] = DEL;
					}
				}
			}
		}
	}
}

void applyGravity() {
	for (int i = N - 2; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			if (mat[i][j] >= 0) {
				int k;
				for (k = i + 1; k < N; k++) {
					if (mat[k][j] == DEL) {
						continue;
					} 
					else {
						break;
					}
				}
				// 바꿔야할 인덱스 : k-1
				int temp = mat[k-1][j];
				mat[k-1][j] = mat[i][j];
				mat[i][j] = temp;
			}
		}
	}
}

void rotate() {
	int temp[21][21];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[N - 1 - j][i] = mat[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			mat[i][j] = temp[i][j];
		}
	}
}

bool autoPlay() {
	// 1단계
	int maxCount = 0;
	int maxRainbow = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (mat[i][j] >= 1) {

				vector<int> v = getSize(i, j);
				int size = v[0];
				if (maxCount < size) {
					maxCount = size;
					maxRainbow = v[1];
				}
				else if (maxCount == size) {
					maxRainbow = max(maxRainbow, v[1]);
				}
			}
		}
	}
	
	if (maxCount < 2) {
		return true;
	}

	int add = maxCount * maxCount;
	answer += add;

	Pos biggestBlock = getBiggestBlock(maxCount, maxRainbow);

	// 2단계
	deleteBlock(biggestBlock.y, biggestBlock.x);

	// 3단계
	applyGravity();

	// 4단계
	rotate();

	// 5단계
	applyGravity();
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	answer = 0;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mat[i][j];
		}
	}

	while (true) {
		bool finishFlag = autoPlay();
		if (finishFlag == true) {
			break;
		}
	}
	cout << answer;
}