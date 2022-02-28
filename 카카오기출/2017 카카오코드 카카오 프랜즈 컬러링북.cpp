#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool visited[101][101];
int M, N;

int areaCnt;

struct Position {
	int y, x;
};

int do_bfs(vector<vector<int>> &picture, int Y, int X) {
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };

	int areaSize = 1;
	areaCnt++;
	visited[Y][X] = true;

	vector<Position> q;
	q.push_back(Position{ Y, X });

	while (!q.empty()) {
		int y = q[0].y;
		int x = q[0].x;
		q.erase(q.begin());

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= M || nx < 0 || nx >= N) {
				continue;
			}
			if (visited[ny][nx]) {
				continue;
			}
			int newNum = picture[ny][nx];
			int oldNum = picture[y][x];
			if (newNum == oldNum) {
				q.push_back(Position{ ny, nx });
				visited[ny][nx] = true;
				areaSize++;
			}
		}
	}

	return areaSize;

}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	vector<int> answer(2);

	M = m;
	N = n;
	areaCnt = 0;

	for (int i = 0; i<m; i++) {
		for (int j = 0; j<n; j++) {
			visited[i][j] = false;
		}
	}

	int maxAreaSize = 0;

	for (int i = 0; i<m; i++) {
		for (int j = 0; j<n; j++) {
			int num = picture[i][j];
			if (visited[i][j] == false && num != 0) {
				int areaSize = do_bfs(picture, i, j);
				maxAreaSize = max(areaSize, maxAreaSize);
			}
		}
	}

	answer[0] = areaCnt;
	answer[1] = maxAreaSize;

	return answer;
}