#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N, M;
char mat[11][11];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

struct Ball {
	int ry, rx;
	int by, bx;
	int cnt;
};

int get_diff(int a, int b) {
	int diff = a - b;
	if (diff < 0) {
		diff = diff * -1;
	}
	return diff;
}

int do_bfs(Ball start) {
	int answer = -1;

	queue<Ball> q;
	q.push(start);
	
	while (!q.empty()) {
		Ball cur = q.front();
		q.pop();

		//종결조건
		if (cur.cnt >= 11) {
			break;
		}
		if (mat[cur.by][cur.bx] == 'O') {
			continue;
		}
		if (mat[cur.ry][cur.rx] == 'O') {
			return cur.cnt;
		}

		for (int i = 0; i < 4; i++) { //네 방향에 대해서 탐색
			int temp_ry = cur.ry;
			int temp_rx = cur.rx;
			int temp_by = cur.by;
			int temp_bx = cur.bx;

			while (true) { //빨간 공 이동
				char next = mat[temp_ry + dy[i]][temp_rx + dx[i]];
				if (next == '#') {
					break;
				}
				else if (next == '.') {
					temp_ry += dy[i];
					temp_rx += dx[i];
				}
				else if (next == 'O') {
					temp_ry += dy[i];
					temp_rx += dx[i];
					break;
				}
			}

			while (true) { //파란 공 이동
				//cout << "!";
				char next = mat[temp_by + dy[i]][temp_bx + dx[i]];
				//cout << next << endl;
				if (next == '#') {
					break;
				}
				else if (next == '.') {
					temp_by += dy[i];
					temp_bx += dx[i];
				}
				else if (next == 'O') {
					temp_by += dy[i];
					temp_bx += dx[i];
					break;
				}
			}

			if (temp_ry == temp_by && temp_rx == temp_bx) { //둘이 위치가 같을 때
				if (mat[temp_ry][temp_rx] == 'O') { //위치가 같은데 동시에 구멍에 들어간 경우
					
				}
				else {
					if (dy[i] != 0) { //y축으로 움직인 경우
						int a = get_diff(temp_ry, cur.ry); //빨간 공이 움직인 거리
						int b = get_diff(temp_by, cur.by); //파란 공이 움직인 거리
						if (a > b) {
							temp_ry -= dy[i];
						}
						else {
							temp_by -= dy[i];
						}
					}
					else { // x축으로 움직인 경우
						int a = get_diff(temp_rx, cur.rx);
						int b = get_diff(temp_bx, cur.bx);
						if (a > b) {
							temp_rx -= dx[i];
						}
						else {
							temp_bx -= dx[i];
						}
					}
				}
			}

			Ball next_ball;
			next_ball.ry = temp_ry;
			next_ball.rx = temp_rx;
			next_ball.by = temp_by;
			next_ball.bx = temp_bx;
			next_ball.cnt = cur.cnt + 1;
			q.push(next_ball);
		}
	}
	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 빨간구슬을 꺼내야함. 파란구슬을 꺼내면 안됨

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < M; j++) {
			mat[i][j] = str[j];
		}
	}

	Ball start;
	start.cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mat[i][j] == 'R') {
				start.ry = i;
				start.rx = j;
				mat[i][j] = '.';
			}
			else if (mat[i][j] == 'B') {
				start.by = i;
				start.bx = j;
				mat[i][j] = '.';
			}
		}
	}

	cout << do_bfs(start);
}