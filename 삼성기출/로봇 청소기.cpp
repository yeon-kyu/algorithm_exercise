#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int mat[51][51];
int ans = 0;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void brute(int y, int x, int d) {
	if (mat[y][x] == 0) {
		mat[y][x] = -1; // visited now
		ans++;
	}
	//d 0:북, 1:동 2: 남 3:서
	
	for (int i = 1; i <= 4; i++) {
		int nd = d + 4 - i;
		nd = nd % 4;

		//다음으로 볼 칸
		int Y = y + dy[nd];
		int X = x + dx[nd];
		if (Y < 0 || Y >= N || X < 0 || X >= M) {
			continue;
		}

		if (mat[Y][X] != 0) {
			continue;
		}
		else { 
			brute(Y, X, nd);
			return;
		}
	}
	//네 방향 모두 청소가 되거나 벽이었다.

	//뒤로 이동
	int nd = (d + 2) % 4;

	int Y = y + dy[nd];
	int X = x + dx[nd];
	if (Y < 0 || Y >= N || X < 0 || X >= M) { //벽인 경우
		return;
	}
	else if (mat[Y][X] == 1) { //벽인 경우
		return;
	}
	else { //청소만 한 경우(방향은 그대로)
		brute(Y, X, d);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	int r, c, d;

	cin >> r >> c >> d;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mat[i][j];
		}
	}

	brute(r, c, d);

	cout << ans;
}