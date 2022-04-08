#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int W, H;
int mat[101][101];
int dy[4] = { 1,-1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
bool visited[101][101];
int mini[101][101];

void dfs(int y, int x, int cnt, int dir) {
	visited[y][x] = true;

	if (cnt > mini[y][x]) {
		return;
	}
	else {
		mini[y][x] = cnt;
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && ny < H && nx >= 0 && nx < W) {
			if (visited[ny][nx] == false && mat[ny][nx] != '*') {
				if (i == dir) {
					dfs(ny, nx, cnt, i);
				}
				else {
					dfs(ny, nx, cnt + 1, i);
				}
				visited[ny][nx] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> W >> H;

	vector<pair<int, int>> v;
	for (int i = 0; i < H; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < W; j++) {
			mat[i][j] = str[j];
			if (mat[i][j] == 'C') {
				v.push_back(make_pair(i, j));
			}
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			visited[i][j] = false;
			mini[i][j] = 987654321;
		}
	}

	for (int i = 0; i < 4; i++) {
		dfs(v[0].first, v[0].second, 0, i);
	}

	cout << mini[v[1].first][v[1].second];
}