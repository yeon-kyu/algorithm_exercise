#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int mat[21][21];
bool visited[21][21];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0,0,-1, 1 };

int w, h;
int start;

int dist[401][401];

struct Pos {
	int y;
	int x;
	int dist;
};

void refresh() {
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			visited[i][j] = false;
		}
	}
}

int bfs(int from, int to) {
	refresh();

	int startY = from / w;
	int startX = from % w;
	int toY = to / w;
	int toX = to % w;
	queue<Pos> q;
	q.push({ startY, startX, 0 });
	visited[startY][startX] = true;

	while (q.empty() == false) {
		Pos cur = q.front();
		q.pop();

		if (cur.y == toY && cur.x == toX) {
			return cur.dist;
		}
		
		for (int k = 0; k < 4; k++) {
			int ny = cur.y + dy[k];
			int nx = cur.x + dx[k];

			if (ny >= 0 && ny < h && nx >= 0 && nx < w) {
				if (visited[ny][nx] == false && mat[ny][nx] != 'x') {
					q.push({ ny, nx, cur.dist + 1 });
					visited[ny][nx] = true;
				}
			}
		}
	}
	return -1;
}

void calcDistance(vector<int> trash) {

	int size = trash.size();
	for (int i = 0; i < size; i++) {
		dist[start][trash[i]] = bfs(start, trash[i]);
	}

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			dist[trash[i]][trash[j]] = bfs(trash[i], trash[j]);
			dist[trash[j]][trash[i]] = dist[trash[i]][trash[j]];
		}
	}
}

int getDistance(vector<int> trash) {
	
	// 첫 로봇 위치 부터 첫 먼지까지 거리 더하기
	int sum = dist[start][trash[0]];

	if (sum == -1) {
		return -1;
	}

	// 첫 먼지부터 마지막 먼지까지 거리 더하기
	int size = trash.size();
	for (int i = 1; i < size; i++) {
		int d = dist[trash[i - 1]][trash[i]];
		if (d == -1) {
			return -1;
		}
		sum += d;
	}
	return sum;
}

int solve(int w, int h) {
	int dirtyCnt = 0;
	vector<int> trash;
	for (int i = 0; i < h; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < w; j++) {
			mat[i][j] = str[j];
			if (mat[i][j] == 'o') {
				mat[i][j] = '.';
				start = i * w + j;
			}
			else if (mat[i][j] == '*') {
				dirtyCnt++;
				trash.push_back(i*w + j);
			}
		}
	}

	if (trash.size() == 0) { // 엣지케이스 : 먼지가 없는 경우
		return 0;
	}

	// 모든 먼지 정점까지의 거리 계산
	calcDistance(trash);

	int minDist = 500;
	do {
		int dist = getDistance(trash);
		if (dist == -1) {
			minDist = -1;
			break;
		}
		minDist = min(minDist, dist);
	} while (next_permutation(trash.begin(), trash.end()));

	return minDist;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) {
			break;
		}

		cout << solve(w, h) << endl;
	}
}