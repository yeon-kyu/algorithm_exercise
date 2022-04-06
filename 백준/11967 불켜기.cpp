#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

struct Pos {
	int y;
	int x;
};
vector<Pos> node[101][101];
bool visited[101][101];
bool turnOn[101][101];

int dy[4] = { 1,-1, 0,0 };
int dx[4] = { 0,0,1,-1 };
bool retryFlag = false;

void refresh() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visited[i][j] = false;
		}
	}

	retryFlag = false;
}

void dfs(int y, int x) {
	visited[y][x] = true;

	// 밝힐 수 있는 불을 밝힌다.
	for (Pos pos : node[y][x]) {
		if (turnOn[pos.y][pos.x] == false) {
			turnOn[pos.y][pos.x] = true;
			retryFlag = true;
		}
	}

	//이동할 수 있는 방으로 이동한다.
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 1 && ny <= N && nx >= 1 && nx <= N) {
			if (visited[ny][nx] == false && turnOn[ny][nx] == true) {
				dfs(ny, nx);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, A, B;
		cin >> a >> b >> A >> B;

		node[a][b].push_back({ A, B });
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			turnOn[i][j] = false;
		}
	}
	turnOn[1][1] = true;

	while (true) {
		refresh();
		dfs(1, 1);
		if (retryFlag == false) {
			break;
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (turnOn[i][j] == true) {
				ans++;
			}
		}
	}
	cout << ans;
}