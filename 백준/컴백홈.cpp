#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int R, C, K;
char mat[5][5];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int answer = 0;
int minDist = 50;

void dfs(int r, int c, vector<int> visited) {
	int cur = r * C + c;
	if (cur == C - 1) {
		int dist = visited.size() + 1;
		if (dist == K) {
			answer++;
		}
		return;
	}
	visited.push_back(cur);

	for (int i = 0; i < 4; i++) {
		int ny = r + dy[i];
		int nx = c + dx[i];
		if (ny >= 0 && ny < R && nx >= 0 && nx < C) {
			if (mat[ny][nx] == 'T') {
				continue;
			}
			if (find(visited.begin(), visited.end(), ny*C + nx) == visited.end()) {
				dfs(ny, nx, visited);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> K;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> mat[i][j];
		}
	}

	vector<int> visited;
	dfs(R - 1, 0, visited);
	cout << answer;
}