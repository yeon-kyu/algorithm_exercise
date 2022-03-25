#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int mat[5][5];
bool visited[5][5];

int dy[4] = { 1,-1, 0,0 };
int dx[4] = { 0, 0, -1, -1 };

int answer = 0;

void dfs(int num, int sum) {
	int r = num / M;
	int c = num % M;

	if (num == N * M) {
		answer = max(answer, sum);
		return;
	}

	if (r - 1 >= 0 && c - 1 >= 0) {
		if (!visited[r][c] && !visited[r - 1][c] && !visited[r][c - 1]) {
			int w = 2 * mat[r][c] + mat[r - 1][c] + mat[r][c - 1];
			visited[r][c] = true;
			visited[r - 1][c] = true;
			visited[r][c - 1] = true;
			dfs(num + 1, sum + w);
			visited[r][c] = false;
			visited[r - 1][c] = false;
			visited[r][c - 1] = false;
		}
	}
	if (r - 1 >= 0 && c + 1 < M) {
		if (!visited[r][c] && !visited[r - 1][c] && !visited[r][c + 1]) {
			int w = 2 * mat[r][c] + mat[r - 1][c] + mat[r][c + 1];
			visited[r][c] = true;
			visited[r - 1][c] = true;
			visited[r][c + 1] = true;
			dfs(num + 1, sum + w);
			visited[r][c] = false;
			visited[r - 1][c] = false;
			visited[r][c + 1] = false;
		}
	}
	if (r + 1 < N && c - 1 >= 0) {
		if (!visited[r][c] && !visited[r + 1][c] && !visited[r][c - 1]) {
			int w = 2 * mat[r][c] + mat[r + 1][c] + mat[r][c - 1];
			visited[r][c] = true;
			visited[r + 1][c] = true;
			visited[r][c - 1] = true;
			dfs(num + 1, sum + w);
			visited[r][c] = false;
			visited[r + 1][c] = false;
			visited[r][c - 1] = false;
		}
	}
	if (r + 1 < N && c + 1 < M) {
		if (!visited[r][c] && !visited[r + 1][c] && !visited[r][c + 1]) {
			int w = 2 * mat[r][c] + mat[r + 1][c] + mat[r][c + 1];
			visited[r][c] = true;
			visited[r + 1][c] = true;
			visited[r][c + 1] = true;
			dfs(num + 1, sum + w);
			visited[r][c] = false;
			visited[r + 1][c] = false;
			visited[r][c + 1] = false;
		}
	}
	dfs(num + 1, sum);
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
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
		}
	}

	int maxNum = N * M;
	for (int i = 0; i < maxNum; i++) {
		dfs(i, 0);
	}
	
	cout << answer;
}