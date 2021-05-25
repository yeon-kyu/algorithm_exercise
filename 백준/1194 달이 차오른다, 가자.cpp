#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int n, m;
char mat[51][51];
struct node {
	int x, y;
	int key, cnt;
};
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int answer;
bool visited[51][51][65] = { false };

bool isKey(char c) {
	if (c <= 'f' && c >= 'a') {
		return true;
	}
	return false;
}
bool isDoor(char c) {
	if (c <= 'F' && c >= 'A') {
		return true;
	}
	return false;
}
bool isSafe(int x, int y) {
	if (x >= 0 && x < n && y>=0 && y < m) {
		return true;
	}
	return false;
}

void BFS(int r, int c) {
	queue<struct node> Q;
	Q.push({r,c,0,0});

	int x, y, key, cnt;
	while (!Q.empty()) {
		x = Q.front().x;
		y = Q.front().y;
		key = Q.front().key;
		cnt = Q.front().cnt;
		Q.pop();

		if (mat[x][y] == '1') {
			answer = cnt;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int xpos = x + dx[i];
			int ypos = y + dy[i];
	
			if (isSafe(xpos, ypos) && visited[xpos][ypos][key]==false) {
				if (mat[xpos][ypos] == '.' || mat[xpos][ypos] == '0' || mat[xpos][ypos] == '1') {
					visited[xpos][ypos][key] = true;
					Q.push({ xpos,ypos,key,cnt + 1 });
				}
				else if (isKey(mat[xpos][ypos])) { //키를 찾음
					if ((key&(1 << mat[xpos][ypos] - 'a')) != (1 << mat[xpos][ypos] - 'a')) { //키를 처음 찾음
						int newKey = key + (1 << mat[xpos][ypos] - 'a');
						visited[xpos][ypos][key] = true;
						Q.push({ xpos,ypos,newKey,cnt + 1 });
					}
					else { //키가 이미 있었음
						visited[xpos][ypos][key] = true;
						Q.push({ xpos,ypos,key,cnt + 1 });
					}
				}
				else if (isDoor(mat[xpos][ypos])) { //문을 찾음
					if ((key&(1 << mat[xpos][ypos] - 'A')) == (1 << mat[xpos][ypos] - 'A')) { //문 통과 가능
						visited[xpos][ypos][key] = true;
						Q.push({ xpos,ypos,key,cnt + 1 });
					}
					else { //문을 찾았으나 키가없음
						
					}
				}
				else { // 벽만남
					
				}
			}
		
		}
	}
	answer = -1;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == '0') {
				x = i;
				y = j;
			}
		}
	}
	BFS(x, y);
	cout << answer;

	return 0;
}