#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int R, C;
char mat[10001][501];
int visited[10001][501] = { false };

int dy[3] = { -1, 0, 1 };
int dx[3] = { 1, 1, 1 };

int answer = 0;

bool dfs(int r, int c) {
	int cur = r * C + c;
	visited[r][c] = true;
	if (c == C - 1) {
		answer++;
		return true;
	}

	bool findFlag = false;
	for (int i = 0; i < 3; i++) {
		int ny = r + dy[i];
		int nx = c + dx[i];
		if (ny >= 0 && ny < R) {
			if (mat[ny][nx] == '.' && visited[ny][nx] == false) {
				findFlag = dfs(ny, nx);
				if (findFlag == true) {
					break;
				}
			}
		}
	}

	return findFlag;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 오른쪽, 오른쪽 위 대각선, 오른쪽 아래 대각선으로 이동

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> mat[i][j];
		}
	}

	for (int i = 0; i < R; i++) {
		dfs(i, 0);
	}

	cout << answer;
}